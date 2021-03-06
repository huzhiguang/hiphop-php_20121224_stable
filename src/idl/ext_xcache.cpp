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

#include <runtime/ext/ext_xcache.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

bool f_xcache_set(CStrRef name, CVarRef value, int ttl /* = 0 */) {
  throw NotImplementedException(__func__);
}

Variant f_xcache_get(CStrRef name) {
  throw NotImplementedException(__func__);
}

int64 f_xcache_inc(CStrRef name, int64 value /* = 1 */, int ttl /* = 0 */) {
  throw NotImplementedException(__func__);
}

bool f_xcache_unset(CStrRef name) {
  throw NotImplementedException(__func__);
}


///////////////////////////////////////////////////////////////////////////////
}
