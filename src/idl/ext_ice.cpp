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

#include <runtime/ext/ext_ice.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

Object f_ice_initialize() {
  throw NotImplementedException(__func__);
}

Object f_icephp_defineproxy(CObjRef classobj) {
  throw NotImplementedException(__func__);
}

Object f_icephp_declareclass(CStrRef id /* = null */) {
  throw NotImplementedException(__func__);
}

Object f_icephp_defineexception(CStrRef id /* = null */, CStrRef name /* = null */, CVarRef base /* = null */, CVarRef members /* = null */) {
  throw NotImplementedException(__func__);
}

Variant f_create_typeinfobyid(int id /* = 0 */) {
  throw NotImplementedException(__func__);
}

String f_icephp_stringifyexception(CObjRef value /* = null */, CObjRef target /* = null */) {
  throw NotImplementedException(__func__);
}

String f_icephp_stringify(CObjRef value /* = null */, CObjRef target /* = null */) {
  throw NotImplementedException(__func__);
}

Object f_icephp_definesequence(CStrRef id /* = null */, CVarRef elementtype /* = null */) {
  throw NotImplementedException(__func__);
}

Object f_icephp_defineclass(CStrRef id, CStrRef name, bool isabstract /* = true */, CObjRef base /* = null */, CVarRef interfaces /* = null */, CVarRef members /* = null */) {
  throw NotImplementedException(__func__);
}

void f_icephp_defineoperation(CObjRef classobj /* = null */, CStrRef funname /* = null */, int mode /* = null */, int sendmode /* = null */, CVarRef inparams /* = null */, CVarRef outparams /* = null */, CVarRef returntype /* = null */, CVarRef exceptions /* = null */) {
  throw NotImplementedException(__func__);
}

Object f_ice_find(CStrRef ice_name /* = null */) {
  throw NotImplementedException(__func__);
}

bool f_ice_register(CObjRef ice_object, CStrRef ice_name /* = null */, int64 expires /* = null */) {
  throw NotImplementedException(__func__);
}


///////////////////////////////////////////////////////////////////////////////
}
