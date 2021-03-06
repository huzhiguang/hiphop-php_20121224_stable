/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   | Copyright (c) 1997-2010 The PHP Group                                |
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

#ifndef __EXTPROFILE_XCACHE_H__
#define __EXTPROFILE_XCACHE_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <runtime/ext/ext_xcache.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

inline bool x_xcache_set(CStrRef name, CVarRef value, int ttl = 0) {
  FUNCTION_INJECTION_BUILTIN(xcache_set);
  return f_xcache_set(name, value, ttl);
}

inline Variant x_xcache_get(CStrRef name) {
  FUNCTION_INJECTION_BUILTIN(xcache_get);
  return f_xcache_get(name);
}

inline int64 x_xcache_inc(CStrRef name, int64 value = 1, int ttl = 0) {
  FUNCTION_INJECTION_BUILTIN(xcache_inc);
  return f_xcache_inc(name, value, ttl);
}

inline bool x_xcache_unset(CStrRef name) {
  FUNCTION_INJECTION_BUILTIN(xcache_unset);
  return f_xcache_unset(name);
}


///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXTPROFILE_XCACHE_H__
