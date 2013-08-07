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

#ifndef __EXT_ICE_H__
#define __EXT_ICE_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <runtime/base/base_includes.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

Object f_ice_initialize();
Object f_icephp_defineproxy(CObjRef classobj);
Object f_icephp_declareclass(CStrRef id = null);
Object f_icephp_defineexception(CStrRef id = null, CStrRef name = null, CVarRef base = null, CVarRef members = null);
Variant f_create_typeinfobyid(int id = 0);
String f_icephp_stringifyexception(CObjRef value = null, CObjRef target = null);
String f_icephp_stringify(CObjRef value = null, CObjRef target = null);
Object f_icephp_definesequence(CStrRef id = null, CVarRef elementtype = null);
Object f_icephp_defineclass(CStrRef id, CStrRef name, bool isabstract = true, CObjRef base = null, CVarRef interfaces = null, CVarRef members = null);
void f_icephp_defineoperation(CObjRef classobj = null, CStrRef funname = null, int mode = null, int sendmode = null, CVarRef inparams = null, CVarRef outparams = null, CVarRef returntype = null, CVarRef exceptions = null);
Object f_ice_find(CStrRef ice_name = null);
bool f_ice_register(CObjRef ice_object, CStrRef ice_name = null, int64 expires = null);

///////////////////////////////////////////////////////////////////////////////
// class ICE

FORWARD_DECLARE_CLASS_BUILTIN(ICE);
class c_ICE : public ExtObjectData {
 public:
  DECLARE_CLASS(ICE, ICE, ObjectData)

  // need to implement
  public: c_ICE(const ObjectStaticCallbacks *cb = &cw_ICE);
  public: ~c_ICE();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Object t_stringtoproxy(CStrRef str);
  DECLARE_METHOD_INVOKE_HELPERS(stringtoproxy);

  // implemented by HPHP
  public: c_ICE *create();

};

///////////////////////////////////////////////////////////////////////////////
// class Proxy

FORWARD_DECLARE_CLASS_BUILTIN(Proxy);
class c_Proxy : public ExtObjectDataFlags<ObjectData::HasCall> {
 public:
  DECLARE_CLASS(Proxy, Proxy, ObjectData)

  // need to implement
  public: c_Proxy(const ObjectStaticCallbacks *cb = &cw_Proxy);
  public: ~c_Proxy();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t___call(Variant name, Variant args);
  DECLARE_METHOD_INVOKE_HELPERS(__call);
  public: Variant doCall(Variant v_name, Variant v_arguments, bool fatal);
  public: Object t_ice_oneway();
  DECLARE_METHOD_INVOKE_HELPERS(ice_oneway);
  public: Object t_ice_datagram();
  DECLARE_METHOD_INVOKE_HELPERS(ice_datagram);
  public: Object t_ice_istwoway();
  DECLARE_METHOD_INVOKE_HELPERS(ice_istwoway);
  public: Object t_ice_secure(bool secure = false);
  DECLARE_METHOD_INVOKE_HELPERS(ice_secure);
  public: Object t_ice_timeout(int64 lasttime = null);
  DECLARE_METHOD_INVOKE_HELPERS(ice_timeout);
  public: Object t_ice_context(CArrRef ctx = null);
  DECLARE_METHOD_INVOKE_HELPERS(ice_context);
  public: Object t_ice_checkedcast(CStrRef classid, CVarRef facetOrCtx = null, CVarRef ctx = null);
  DECLARE_METHOD_INVOKE_HELPERS(ice_checkedcast);
  public: Object t_ice_uncheckedcast(CStrRef classid, CVarRef facet = null);
  DECLARE_METHOD_INVOKE_HELPERS(ice_uncheckedcast);

  // implemented by HPHP
  public: c_Proxy *create();

};

///////////////////////////////////////////////////////////////////////////////
// class IcePHP_class

FORWARD_DECLARE_CLASS_BUILTIN(IcePHP_class);
class c_IcePHP_class : public ExtObjectData {
 public:
  DECLARE_CLASS(IcePHP_class, IcePHP_class, ObjectData)

  // need to implement
  public: c_IcePHP_class(const ObjectStaticCallbacks *cb = &cw_IcePHP_class);
  public: ~c_IcePHP_class();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);

  // implemented by HPHP
  public: c_IcePHP_class *create();

};

///////////////////////////////////////////////////////////////////////////////
// class TypeInfo

FORWARD_DECLARE_CLASS_BUILTIN(TypeInfo);
class c_TypeInfo : public ExtObjectData, public UnmarshalCallback {
 public:
  DECLARE_CLASS(TypeInfo, TypeInfo, ObjectData)

  // need to implement
  public: c_TypeInfo(const ObjectStaticCallbacks *cb = &cw_TypeInfo);
  public: ~c_TypeInfo();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);

  // implemented by HPHP
  public: c_TypeInfo *create();

};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXT_ICE_H__
