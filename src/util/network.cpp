/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#include "network.h"
#include "lock.h"
#include "process.h"
#include "util.h"

#include <netinet/in.h>
#include <arpa/nameser.h>
#include <resolv.h>

#include <net/if.h>
#include <sys/ioctl.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////
// without calling res_init(), any call to getaddrinfo() may leak memory:
//  http://sources.redhat.com/ml/libc-hacker/2004-02/msg00049.html

class ResolverLibInitializer {
public:
  ResolverLibInitializer() {
    res_init();
    // We call sethostent with stayopen = 1 to keep /etc/hosts open across calls
    // to prevent mmap contention inside the kernel.  Two calls are necessary to
    // properly initialize the stayopen flag in glibc.
    sethostent(1);
    sethostent(1);
  }
};
static ResolverLibInitializer _resolver_lib_initializer;
///////////////////////////////////////////////////////////////////////////////
// thread-safe network functions

std::string Util::safe_inet_ntoa(struct in_addr &in) {
  char buf[256];
  memset(buf, 0, sizeof(buf));
  inet_ntop(AF_INET, &in, buf, sizeof(buf)-1);
  return buf;
}

bool Util::safe_gethostbyname(const char *address, HostEnt &result) {
#if defined(__APPLE__)
  struct hostent *hp = gethostbyname(address);

  if (!hp) {
    return false;
  }

  result.hostbuf = *hp;
  freehostent(hp);
  return true;
#else
  struct hostent *hp;
  int res;

  size_t hstbuflen = 1024;
  result.tmphstbuf = (char*)malloc(hstbuflen);
  while ((res = gethostbyname_r(address, &result.hostbuf, result.tmphstbuf,
                                hstbuflen, &hp, &result.herr)) == ERANGE) {
    hstbuflen *= 2;
    result.tmphstbuf = (char*)realloc(result.tmphstbuf, hstbuflen);
  }
  return !res && hp;
#endif
}

///////////////////////////////////////////////////////////////////////////////

std::string Util::GetPrimaryIP() {
  struct utsname buf;
  uname((struct utsname *)&buf);

  HostEnt result;
  if (!safe_gethostbyname(buf.nodename, result)) {
    return buf.nodename;
  }

  struct in_addr in;
  memcpy(&in.s_addr, *(result.hostbuf.h_addr_list), sizeof(in.s_addr));
  return safe_inet_ntoa(in);
}

/** yfliulei@360buy.com on 2012-11-2
 original method(GetPrimaryIP) has a problem:
 on machine: 192.168.12.34 (hostname: BP-YZH-1-xxxx.360buy.com)
 output:
 IP Address : 202.106.199.39
 so it is need to write a new emthod
 */
std::string Util::GetPrimaryIP_ioctl() {
	int s ;
	struct ifconf conf;
	struct ifreq *ifr;
	char buff[BUFSIZ];
	int num ;
	int i ;
	std::string sPrimaryIP ;

	s = socket(PF_INET, SOCK_DGRAM, 0);
	conf.ifc_len = BUFSIZ;
	conf.ifc_buf = buff;

	ioctl(s, SIOCGIFCONF, &conf);
	num = conf.ifc_len / sizeof(struct ifreq);
	ifr = conf.ifc_req;

	for (i = 0; i < num; i++) {
		struct sockaddr_in *sin = (struct sockaddr_in *) (&ifr->ifr_addr);
		ioctl(s, SIOCGIFFLAGS, ifr);
		if (((ifr->ifr_flags & IFF_LOOPBACK) == 0) && (ifr->ifr_flags & IFF_UP) && ifr->ifr_name) {
			sPrimaryIP.append(inet_ntoa(sin->sin_addr)) ;
			break ;
		}
		ifr++;
	}
	return sPrimaryIP ;
}

bool Util::GetNetworkStats(const char *iface, int &in_bps, int &out_bps) {
  ASSERT(iface && *iface);

  const char *argv[] = {"", "1", "1", "-n", "DEV", NULL};
  string out;
  Process::Exec("sar", argv, NULL, out);

  vector<string> lines;
  Util::split('\n', out.c_str(), lines, true);
  for (unsigned int i = 0; i < lines.size(); i++) {
    string &line = lines[i];
    if (line.find(iface) != string::npos) {
      vector<string> fields;
      Util::split(' ', line.c_str(), fields, true);
      if (fields[1] == iface) {
        in_bps = atoll(fields[4].c_str());
        out_bps = atoll(fields[5].c_str());
        return true;
      }
    }
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////
}
