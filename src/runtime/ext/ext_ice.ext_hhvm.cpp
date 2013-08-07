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
#include <runtime/ext_hhvm/ext_hhvm.h>
#include <runtime/base/builtin_functions.h>
#include <runtime/base/array/array_init.h>
#include <runtime/ext/ext.h>
#include <runtime/vm/class.h>
#include <runtime/vm/runtime.h>
#include <exception>

namespace HPHP {

/*
HPHP::Object HPHP::f_ice_initialize()
_ZN4HPHP16f_ice_initializeEv

(return value) => rax
_rv => rdi
*/

Value* fh_ice_initialize(Value* _rv) asm("_ZN4HPHP16f_ice_initializeEv");

TypedValue* fg_ice_initialize(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 0LL) {
      rv._count = 0;
      rv.m_type = KindOfObject;
      fh_ice_initialize((Value*)(&(rv)));
      if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
      frame_free_locals_no_this_inl(ar, 0);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("ice_initialize", 0, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Object HPHP::f_icephp_defineproxy(HPHP::Object const&)
_ZN4HPHP20f_icephp_defineproxyERKNS_6ObjectE

(return value) => rax
_rv => rdi
classobj => rsi
*/

Value* fh_icephp_defineproxy(Value* _rv, Value* classobj) asm("_ZN4HPHP20f_icephp_defineproxyERKNS_6ObjectE");

TypedValue * fg1_icephp_defineproxy(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_icephp_defineproxy(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  tvCastToObjectInPlace(args-0);
  fh_icephp_defineproxy((Value*)(rv), (Value*)(args-0));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_icephp_defineproxy(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      if ((args-0)->m_type == KindOfObject) {
        rv._count = 0;
        rv.m_type = KindOfObject;
        fh_icephp_defineproxy((Value*)(&(rv)), (Value*)(args-0));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_icephp_defineproxy(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("icephp_defineproxy", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Object HPHP::f_icephp_declareclass(HPHP::String const&)
_ZN4HPHP21f_icephp_declareclassERKNS_6StringE

(return value) => rax
_rv => rdi
id => rsi
*/

Value* fh_icephp_declareclass(Value* _rv, Value* id) asm("_ZN4HPHP21f_icephp_declareclassERKNS_6StringE");

TypedValue * fg1_icephp_declareclass(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_icephp_declareclass(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  tvCastToStringInPlace(args-0);
  String defVal0 = null;
  fh_icephp_declareclass((Value*)(rv), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_icephp_declareclass(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 1LL) {
      if ((count <= 0 || IS_STRING_TYPE((args-0)->m_type))) {
        rv._count = 0;
        rv.m_type = KindOfObject;
        String defVal0 = null;
        fh_icephp_declareclass((Value*)(&(rv)), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_icephp_declareclass(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("icephp_declareclass", 1, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Object HPHP::f_icephp_defineexception(HPHP::String const&, HPHP::String const&, HPHP::Variant const&, HPHP::Variant const&)
_ZN4HPHP24f_icephp_defineexceptionERKNS_6StringES2_RKNS_7VariantES5_

(return value) => rax
_rv => rdi
id => rsi
name => rdx
base => rcx
members => r8
*/

Value* fh_icephp_defineexception(Value* _rv, Value* id, Value* name, TypedValue* base, TypedValue* members) asm("_ZN4HPHP24f_icephp_defineexceptionERKNS_6StringES2_RKNS_7VariantES5_");

TypedValue * fg1_icephp_defineexception(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_icephp_defineexception(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  switch (count) {
  default: // count >= 4
  case 3:
  case 2:
    if (!IS_STRING_TYPE((args-1)->m_type)) {
      tvCastToStringInPlace(args-1);
    }
  case 1:
    if (!IS_STRING_TYPE((args-0)->m_type)) {
      tvCastToStringInPlace(args-0);
    }
  case 0:
    break;
  }
  String defVal0 = null;
  String defVal1 = null;
  Variant defVal2;
  Variant defVal3;
  fh_icephp_defineexception((Value*)(rv), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (Value*)(args-1) : (Value*)(&defVal1), (count > 2) ? (args-2) : (TypedValue*)(&defVal2), (count > 3) ? (args-3) : (TypedValue*)(&defVal3));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_icephp_defineexception(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 4LL) {
      if ((count <= 1 || IS_STRING_TYPE((args-1)->m_type)) && (count <= 0 || IS_STRING_TYPE((args-0)->m_type))) {
        rv._count = 0;
        rv.m_type = KindOfObject;
        String defVal0 = null;
        String defVal1 = null;
        Variant defVal2;
        Variant defVal3;
        fh_icephp_defineexception((Value*)(&(rv)), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (Value*)(args-1) : (Value*)(&defVal1), (count > 2) ? (args-2) : (TypedValue*)(&defVal2), (count > 3) ? (args-3) : (TypedValue*)(&defVal3));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 4);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_icephp_defineexception(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 4);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("icephp_defineexception", 4, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 4);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_create_typeinfobyid(int)
_ZN4HPHP21f_create_typeinfobyidEi

(return value) => rax
_rv => rdi
id => rsi
*/

TypedValue* fh_create_typeinfobyid(TypedValue* _rv, int id) asm("_ZN4HPHP21f_create_typeinfobyidEi");

TypedValue * fg1_create_typeinfobyid(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_create_typeinfobyid(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToInt64InPlace(args-0);
  fh_create_typeinfobyid((rv), (count > 0) ? (int)(args[-0].m_data.num) : (int)(0));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_create_typeinfobyid(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 1LL) {
      if ((count <= 0 || (args-0)->m_type == KindOfInt64)) {
        fh_create_typeinfobyid((&(rv)), (count > 0) ? (int)(args[-0].m_data.num) : (int)(0));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_create_typeinfobyid(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("create_typeinfobyid", 1, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::String HPHP::f_icephp_stringifyexception(HPHP::Object const&, HPHP::Object const&)
_ZN4HPHP27f_icephp_stringifyexceptionERKNS_6ObjectES2_

(return value) => rax
_rv => rdi
value => rsi
target => rdx
*/

Value* fh_icephp_stringifyexception(Value* _rv, Value* value, Value* target) asm("_ZN4HPHP27f_icephp_stringifyexceptionERKNS_6ObjectES2_");

TypedValue * fg1_icephp_stringifyexception(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_icephp_stringifyexception(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfString;
  switch (count) {
  default: // count >= 2
    if ((args-1)->m_type != KindOfObject) {
      tvCastToObjectInPlace(args-1);
    }
  case 1:
    if ((args-0)->m_type != KindOfObject) {
      tvCastToObjectInPlace(args-0);
    }
  case 0:
    break;
  }
  Object defVal0 = null;
  Object defVal1 = null;
  fh_icephp_stringifyexception((Value*)(rv), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (Value*)(args-1) : (Value*)(&defVal1));
  if (rv->m_data.num == 0LL) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_icephp_stringifyexception(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 2LL) {
      if ((count <= 1 || (args-1)->m_type == KindOfObject) && (count <= 0 || (args-0)->m_type == KindOfObject)) {
        rv._count = 0;
        rv.m_type = KindOfString;
        Object defVal0 = null;
        Object defVal1 = null;
        fh_icephp_stringifyexception((Value*)(&(rv)), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (Value*)(args-1) : (Value*)(&defVal1));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_icephp_stringifyexception(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("icephp_stringifyexception", 2, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::String HPHP::f_icephp_stringify(HPHP::Object const&, HPHP::Object const&)
_ZN4HPHP18f_icephp_stringifyERKNS_6ObjectES2_

(return value) => rax
_rv => rdi
value => rsi
target => rdx
*/

Value* fh_icephp_stringify(Value* _rv, Value* value, Value* target) asm("_ZN4HPHP18f_icephp_stringifyERKNS_6ObjectES2_");

TypedValue * fg1_icephp_stringify(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_icephp_stringify(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfString;
  switch (count) {
  default: // count >= 2
    if ((args-1)->m_type != KindOfObject) {
      tvCastToObjectInPlace(args-1);
    }
  case 1:
    if ((args-0)->m_type != KindOfObject) {
      tvCastToObjectInPlace(args-0);
    }
  case 0:
    break;
  }
  Object defVal0 = null;
  Object defVal1 = null;
  fh_icephp_stringify((Value*)(rv), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (Value*)(args-1) : (Value*)(&defVal1));
  if (rv->m_data.num == 0LL) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_icephp_stringify(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 2LL) {
      if ((count <= 1 || (args-1)->m_type == KindOfObject) && (count <= 0 || (args-0)->m_type == KindOfObject)) {
        rv._count = 0;
        rv.m_type = KindOfString;
        Object defVal0 = null;
        Object defVal1 = null;
        fh_icephp_stringify((Value*)(&(rv)), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (Value*)(args-1) : (Value*)(&defVal1));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_icephp_stringify(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("icephp_stringify", 2, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Object HPHP::f_icephp_definesequence(HPHP::String const&, HPHP::Variant const&)
_ZN4HPHP23f_icephp_definesequenceERKNS_6StringERKNS_7VariantE

(return value) => rax
_rv => rdi
id => rsi
elementtype => rdx
*/

Value* fh_icephp_definesequence(Value* _rv, Value* id, TypedValue* elementtype) asm("_ZN4HPHP23f_icephp_definesequenceERKNS_6StringERKNS_7VariantE");

TypedValue * fg1_icephp_definesequence(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_icephp_definesequence(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  tvCastToStringInPlace(args-0);
  String defVal0 = null;
  Variant defVal1;
  fh_icephp_definesequence((Value*)(rv), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_icephp_definesequence(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 2LL) {
      if ((count <= 0 || IS_STRING_TYPE((args-0)->m_type))) {
        rv._count = 0;
        rv.m_type = KindOfObject;
        String defVal0 = null;
        Variant defVal1;
        fh_icephp_definesequence((Value*)(&(rv)), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_icephp_definesequence(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("icephp_definesequence", 2, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Object HPHP::f_icephp_defineclass(HPHP::String const&, HPHP::String const&, bool, HPHP::Object const&, HPHP::Variant const&, HPHP::Variant const&)
_ZN4HPHP20f_icephp_defineclassERKNS_6StringES2_bRKNS_6ObjectERKNS_7VariantES8_

(return value) => rax
_rv => rdi
id => rsi
name => rdx
isabstract => rcx
base => r8
interfaces => r9
members => st0
*/

Value* fh_icephp_defineclass(Value* _rv, Value* id, Value* name, bool isabstract, Value* base, TypedValue* interfaces, TypedValue* members) asm("_ZN4HPHP20f_icephp_defineclassERKNS_6StringES2_bRKNS_6ObjectERKNS_7VariantES8_");

TypedValue * fg1_icephp_defineclass(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_icephp_defineclass(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  switch (count) {
  default: // count >= 6
  case 5:
  case 4:
    if ((args-3)->m_type != KindOfObject) {
      tvCastToObjectInPlace(args-3);
    }
  case 3:
    if ((args-2)->m_type != KindOfBoolean) {
      tvCastToBooleanInPlace(args-2);
    }
  case 2:
    break;
  }
  if (!IS_STRING_TYPE((args-1)->m_type)) {
    tvCastToStringInPlace(args-1);
  }
  if (!IS_STRING_TYPE((args-0)->m_type)) {
    tvCastToStringInPlace(args-0);
  }
  Object defVal3 = null;
  Variant defVal4;
  Variant defVal5;
  fh_icephp_defineclass((Value*)(rv), (Value*)(args-0), (Value*)(args-1), (count > 2) ? (bool)(args[-2].m_data.num) : (bool)(true), (count > 3) ? (Value*)(args-3) : (Value*)(&defVal3), (count > 4) ? (args-4) : (TypedValue*)(&defVal4), (count > 5) ? (args-5) : (TypedValue*)(&defVal5));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_icephp_defineclass(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count >= 2LL && count <= 6LL) {
      if ((count <= 3 || (args-3)->m_type == KindOfObject) && (count <= 2 || (args-2)->m_type == KindOfBoolean) && IS_STRING_TYPE((args-1)->m_type) && IS_STRING_TYPE((args-0)->m_type)) {
        rv._count = 0;
        rv.m_type = KindOfObject;
        Object defVal3 = null;
        Variant defVal4;
        Variant defVal5;
        fh_icephp_defineclass((Value*)(&(rv)), (Value*)(args-0), (Value*)(args-1), (count > 2) ? (bool)(args[-2].m_data.num) : (bool)(true), (count > 3) ? (Value*)(args-3) : (Value*)(&defVal3), (count > 4) ? (args-4) : (TypedValue*)(&defVal4), (count > 5) ? (args-5) : (TypedValue*)(&defVal5));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 6);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_icephp_defineclass(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 6);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("icephp_defineclass", count, 2, 6, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 6);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
void HPHP::f_icephp_defineoperation(HPHP::Object const&, HPHP::String const&, int, int, HPHP::Variant const&, HPHP::Variant const&, HPHP::Variant const&, HPHP::Variant const&)
_ZN4HPHP24f_icephp_defineoperationERKNS_6ObjectERKNS_6StringEiiRKNS_7VariantES8_S8_S8_

classobj => rdi
funname => rsi
mode => rdx
sendmode => rcx
inparams => r8
outparams => r9
returntype => st0
exceptions => st8
*/

void fh_icephp_defineoperation(Value* classobj, Value* funname, int mode, int sendmode, TypedValue* inparams, TypedValue* outparams, TypedValue* returntype, TypedValue* exceptions) asm("_ZN4HPHP24f_icephp_defineoperationERKNS_6ObjectERKNS_6StringEiiRKNS_7VariantES8_S8_S8_");

TypedValue * fg1_icephp_defineoperation(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_icephp_defineoperation(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_data.num = 0LL;
  rv->_count = 0;
  rv->m_type = KindOfNull;
  switch (count) {
  default: // count >= 8
  case 7:
  case 6:
  case 5:
  case 4:
    if ((args-3)->m_type != KindOfInt64) {
      tvCastToInt64InPlace(args-3);
    }
  case 3:
    if ((args-2)->m_type != KindOfInt64) {
      tvCastToInt64InPlace(args-2);
    }
  case 2:
    if (!IS_STRING_TYPE((args-1)->m_type)) {
      tvCastToStringInPlace(args-1);
    }
  case 1:
    if ((args-0)->m_type != KindOfObject) {
      tvCastToObjectInPlace(args-0);
    }
  case 0:
    break;
  }
  Object defVal0 = null;
  String defVal1 = null;
  Variant defVal4;
  Variant defVal5;
  Variant defVal6;
  Variant defVal7;
  fh_icephp_defineoperation((count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (Value*)(args-1) : (Value*)(&defVal1), (count > 2) ? (int)(args[-2].m_data.num) : (int)(null), (count > 3) ? (int)(args[-3].m_data.num) : (int)(null), (count > 4) ? (args-4) : (TypedValue*)(&defVal4), (count > 5) ? (args-5) : (TypedValue*)(&defVal5), (count > 6) ? (args-6) : (TypedValue*)(&defVal6), (count > 7) ? (args-7) : (TypedValue*)(&defVal7));
  return rv;
}

TypedValue* fg_icephp_defineoperation(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 8LL) {
      if ((count <= 3 || (args-3)->m_type == KindOfInt64) && (count <= 2 || (args-2)->m_type == KindOfInt64) && (count <= 1 || IS_STRING_TYPE((args-1)->m_type)) && (count <= 0 || (args-0)->m_type == KindOfObject)) {
        rv.m_data.num = 0LL;
        rv._count = 0;
        rv.m_type = KindOfNull;
        Object defVal0 = null;
        String defVal1 = null;
        Variant defVal4;
        Variant defVal5;
        Variant defVal6;
        Variant defVal7;
        fh_icephp_defineoperation((count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (Value*)(args-1) : (Value*)(&defVal1), (count > 2) ? (int)(args[-2].m_data.num) : (int)(null), (count > 3) ? (int)(args[-3].m_data.num) : (int)(null), (count > 4) ? (args-4) : (TypedValue*)(&defVal4), (count > 5) ? (args-5) : (TypedValue*)(&defVal5), (count > 6) ? (args-6) : (TypedValue*)(&defVal6), (count > 7) ? (args-7) : (TypedValue*)(&defVal7));
        frame_free_locals_no_this_inl(ar, 8);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_icephp_defineoperation(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 8);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("icephp_defineoperation", 8, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 8);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Object HPHP::f_ice_find(HPHP::String const&)
_ZN4HPHP10f_ice_findERKNS_6StringE

(return value) => rax
_rv => rdi
ice_name => rsi
*/

Value* fh_ice_find(Value* _rv, Value* ice_name) asm("_ZN4HPHP10f_ice_findERKNS_6StringE");

TypedValue * fg1_ice_find(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_ice_find(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  tvCastToStringInPlace(args-0);
  String defVal0 = null;
  fh_ice_find((Value*)(rv), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_ice_find(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 1LL) {
      if ((count <= 0 || IS_STRING_TYPE((args-0)->m_type))) {
        rv._count = 0;
        rv.m_type = KindOfObject;
        String defVal0 = null;
        fh_ice_find((Value*)(&(rv)), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_ice_find(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("ice_find", 1, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_ice_register(HPHP::Object const&, HPHP::String const&, long long)
_ZN4HPHP14f_ice_registerERKNS_6ObjectERKNS_6StringEx

(return value) => rax
ice_object => rdi
ice_name => rsi
expires => rdx
*/

bool fh_ice_register(Value* ice_object, Value* ice_name, long long expires) asm("_ZN4HPHP14f_ice_registerERKNS_6ObjectERKNS_6StringEx");

TypedValue * fg1_ice_register(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_ice_register(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfBoolean;
  switch (count) {
  default: // count >= 3
    if ((args-2)->m_type != KindOfInt64) {
      tvCastToInt64InPlace(args-2);
    }
  case 2:
    if (!IS_STRING_TYPE((args-1)->m_type)) {
      tvCastToStringInPlace(args-1);
    }
  case 1:
    break;
  }
  if ((args-0)->m_type != KindOfObject) {
    tvCastToObjectInPlace(args-0);
  }
  String defVal1 = null;
  rv->m_data.num = (fh_ice_register((Value*)(args-0), (count > 1) ? (Value*)(args-1) : (Value*)(&defVal1), (count > 2) ? (long long)(args[-2].m_data.num) : (long long)(null))) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_ice_register(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count >= 1LL && count <= 3LL) {
      if ((count <= 2 || (args-2)->m_type == KindOfInt64) && (count <= 1 || IS_STRING_TYPE((args-1)->m_type)) && (args-0)->m_type == KindOfObject) {
        rv._count = 0;
        rv.m_type = KindOfBoolean;
        String defVal1 = null;
        rv.m_data.num = (fh_ice_register((Value*)(args-0), (count > 1) ? (Value*)(args-1) : (Value*)(&defVal1), (count > 2) ? (long long)(args[-2].m_data.num) : (long long)(null))) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_ice_register(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("ice_register", count, 1, 3, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 3);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



HPHP::VM::Instance* new_ICE_Instance(HPHP::VM::Class* cls) {
  size_t nProps = cls->numDeclProperties();
  size_t builtinPropSize = sizeof(c_ICE) - sizeof(ObjectData);
  size_t size = HPHP::VM::Instance::sizeForNProps(nProps) + builtinPropSize;
  HPHP::VM::Instance *inst = (HPHP::VM::Instance*)ALLOCOBJSZ(size);
  new ((void *)inst) c_ICE(ObjectStaticCallbacks::encodeVMClass(cls));
  return inst;
}

/*
void HPHP::c_ICE::t___construct()
_ZN4HPHP5c_ICE13t___constructEv

this_ => rdi
*/

void th_3ICE___construct(ObjectData* this_) asm("_ZN4HPHP5c_ICE13t___constructEv");

TypedValue* tg_3ICE___construct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv.m_data.num = 0LL;
        rv._count = 0;
        rv.m_type = KindOfNull;
        th_3ICE___construct((this_));
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("ICE::__construct", 0, 1);
      }
    } else {
      throw_instance_method_fatal("ICE::__construct");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

/*
HPHP::Object HPHP::c_ICE::t_stringtoproxy(HPHP::String const&)
_ZN4HPHP5c_ICE15t_stringtoproxyERKNS_6StringE

(return value) => rax
_rv => rdi
this_ => rsi
str => rdx
*/

Value* th_3ICE_stringToProxy(Value* _rv, ObjectData* this_, Value* str) asm("_ZN4HPHP5c_ICE15t_stringtoproxyERKNS_6StringE");

TypedValue* tg1_3ICE_stringToProxy(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_3ICE_stringToProxy(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  tvCastToStringInPlace(args-0);
  th_3ICE_stringToProxy((Value*)(rv), (this_), (Value*)(args-0));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_3ICE_stringToProxy(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 1LL) {
        if (IS_STRING_TYPE((args-0)->m_type)) {
          rv._count = 0;
          rv.m_type = KindOfObject;
          th_3ICE_stringToProxy((Value*)(&(rv)), (this_), (Value*)(args-0));
          if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_3ICE_stringToProxy(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("ICE::stringToProxy", count, 1, 1, 1);
      }
    } else {
      throw_instance_method_fatal("ICE::stringToProxy");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

HPHP::VM::Instance* new_Proxy_Instance(HPHP::VM::Class* cls) {
  size_t nProps = cls->numDeclProperties();
  size_t builtinPropSize = sizeof(c_Proxy) - sizeof(ObjectData);
  size_t size = HPHP::VM::Instance::sizeForNProps(nProps) + builtinPropSize;
  HPHP::VM::Instance *inst = (HPHP::VM::Instance*)ALLOCOBJSZ(size);
  new ((void *)inst) c_Proxy(ObjectStaticCallbacks::encodeVMClass(cls));
  return inst;
}

/*
void HPHP::c_Proxy::t___construct()
_ZN4HPHP7c_Proxy13t___constructEv

this_ => rdi
*/

void th_5Proxy___construct(ObjectData* this_) asm("_ZN4HPHP7c_Proxy13t___constructEv");

TypedValue* tg_5Proxy___construct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv.m_data.num = 0LL;
        rv._count = 0;
        rv.m_type = KindOfNull;
        th_5Proxy___construct((this_));
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("Proxy::__construct", 0, 1);
      }
    } else {
      throw_instance_method_fatal("Proxy::__construct");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

/*
HPHP::Variant HPHP::c_Proxy::t___call(HPHP::Variant, HPHP::Variant)
_ZN4HPHP7c_Proxy8t___callENS_7VariantES1_

(return value) => rax
_rv => rdi
this_ => rsi
name => rdx
args => rcx
*/

TypedValue* th_5Proxy___call(TypedValue* _rv, ObjectData* this_, TypedValue* name, TypedValue* args) asm("_ZN4HPHP7c_Proxy8t___callENS_7VariantES1_");

TypedValue* tg_5Proxy___call(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 2LL) {
        th_5Proxy___call((&(rv)), (this_), (args-0), (args-1));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_wrong_arguments_nr("Proxy::__call", count, 2, 2, 1);
      }
    } else {
      throw_instance_method_fatal("Proxy::__call");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

/*
HPHP::Object HPHP::c_Proxy::t_ice_oneway()
_ZN4HPHP7c_Proxy12t_ice_onewayEv

(return value) => rax
_rv => rdi
this_ => rsi
*/

Value* th_5Proxy_ice_oneway(Value* _rv, ObjectData* this_) asm("_ZN4HPHP7c_Proxy12t_ice_onewayEv");

TypedValue* tg_5Proxy_ice_oneway(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv._count = 0;
        rv.m_type = KindOfObject;
        th_5Proxy_ice_oneway((Value*)(&(rv)), (this_));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("Proxy::ice_oneway", 0, 1);
      }
    } else {
      throw_instance_method_fatal("Proxy::ice_oneway");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

/*
HPHP::Object HPHP::c_Proxy::t_ice_datagram()
_ZN4HPHP7c_Proxy14t_ice_datagramEv

(return value) => rax
_rv => rdi
this_ => rsi
*/

Value* th_5Proxy_ice_datagram(Value* _rv, ObjectData* this_) asm("_ZN4HPHP7c_Proxy14t_ice_datagramEv");

TypedValue* tg_5Proxy_ice_datagram(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv._count = 0;
        rv.m_type = KindOfObject;
        th_5Proxy_ice_datagram((Value*)(&(rv)), (this_));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("Proxy::ice_datagram", 0, 1);
      }
    } else {
      throw_instance_method_fatal("Proxy::ice_datagram");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

/*
HPHP::Object HPHP::c_Proxy::t_ice_istwoway()
_ZN4HPHP7c_Proxy14t_ice_istwowayEv

(return value) => rax
_rv => rdi
this_ => rsi
*/

Value* th_5Proxy_ice_isTwoway(Value* _rv, ObjectData* this_) asm("_ZN4HPHP7c_Proxy14t_ice_istwowayEv");

TypedValue* tg_5Proxy_ice_isTwoway(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv._count = 0;
        rv.m_type = KindOfObject;
        th_5Proxy_ice_isTwoway((Value*)(&(rv)), (this_));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("Proxy::ice_isTwoway", 0, 1);
      }
    } else {
      throw_instance_method_fatal("Proxy::ice_isTwoway");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

/*
HPHP::Object HPHP::c_Proxy::t_ice_secure(bool)
_ZN4HPHP7c_Proxy12t_ice_secureEb

(return value) => rax
_rv => rdi
this_ => rsi
secure => rdx
*/

Value* th_5Proxy_ice_secure(Value* _rv, ObjectData* this_, bool secure) asm("_ZN4HPHP7c_Proxy12t_ice_secureEb");

TypedValue* tg1_5Proxy_ice_secure(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_5Proxy_ice_secure(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  tvCastToBooleanInPlace(args-0);
  th_5Proxy_ice_secure((Value*)(rv), (this_), (count > 0) ? (bool)(args[-0].m_data.num) : (bool)(false));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_5Proxy_ice_secure(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count <= 1LL) {
        if ((count <= 0 || (args-0)->m_type == KindOfBoolean)) {
          rv._count = 0;
          rv.m_type = KindOfObject;
          th_5Proxy_ice_secure((Value*)(&(rv)), (this_), (count > 0) ? (bool)(args[-0].m_data.num) : (bool)(false));
          if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_5Proxy_ice_secure(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_toomany_arguments_nr("Proxy::ice_secure", 1, 1);
      }
    } else {
      throw_instance_method_fatal("Proxy::ice_secure");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

/*
HPHP::Object HPHP::c_Proxy::t_ice_timeout(long long)
_ZN4HPHP7c_Proxy13t_ice_timeoutEx

(return value) => rax
_rv => rdi
this_ => rsi
lasttime => rdx
*/

Value* th_5Proxy_ice_timeout(Value* _rv, ObjectData* this_, long long lasttime) asm("_ZN4HPHP7c_Proxy13t_ice_timeoutEx");

TypedValue* tg1_5Proxy_ice_timeout(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_5Proxy_ice_timeout(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  tvCastToInt64InPlace(args-0);
  th_5Proxy_ice_timeout((Value*)(rv), (this_), (count > 0) ? (long long)(args[-0].m_data.num) : (long long)(null));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_5Proxy_ice_timeout(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count <= 1LL) {
        if ((count <= 0 || (args-0)->m_type == KindOfInt64)) {
          rv._count = 0;
          rv.m_type = KindOfObject;
          th_5Proxy_ice_timeout((Value*)(&(rv)), (this_), (count > 0) ? (long long)(args[-0].m_data.num) : (long long)(null));
          if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_5Proxy_ice_timeout(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_toomany_arguments_nr("Proxy::ice_timeout", 1, 1);
      }
    } else {
      throw_instance_method_fatal("Proxy::ice_timeout");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

/*
HPHP::Object HPHP::c_Proxy::t_ice_context(HPHP::Array const&)
_ZN4HPHP7c_Proxy13t_ice_contextERKNS_5ArrayE

(return value) => rax
_rv => rdi
this_ => rsi
ctx => rdx
*/

Value* th_5Proxy_ice_context(Value* _rv, ObjectData* this_, Value* ctx) asm("_ZN4HPHP7c_Proxy13t_ice_contextERKNS_5ArrayE");

TypedValue* tg1_5Proxy_ice_context(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_5Proxy_ice_context(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  tvCastToArrayInPlace(args-0);
  Array defVal0 = null;
  th_5Proxy_ice_context((Value*)(rv), (this_), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_5Proxy_ice_context(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count <= 1LL) {
        if ((count <= 0 || (args-0)->m_type == KindOfArray)) {
          rv._count = 0;
          rv.m_type = KindOfObject;
          Array defVal0 = null;
          th_5Proxy_ice_context((Value*)(&(rv)), (this_), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0));
          if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_5Proxy_ice_context(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_toomany_arguments_nr("Proxy::ice_context", 1, 1);
      }
    } else {
      throw_instance_method_fatal("Proxy::ice_context");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

/*
HPHP::Object HPHP::c_Proxy::t_ice_checkedcast(HPHP::String const&, HPHP::Variant const&, HPHP::Variant const&)
_ZN4HPHP7c_Proxy17t_ice_checkedcastERKNS_6StringERKNS_7VariantES6_

(return value) => rax
_rv => rdi
this_ => rsi
classid => rdx
facetOrCtx => rcx
ctx => r8
*/

Value* th_5Proxy_ice_checkedCast(Value* _rv, ObjectData* this_, Value* classid, TypedValue* facetOrCtx, TypedValue* ctx) asm("_ZN4HPHP7c_Proxy17t_ice_checkedcastERKNS_6StringERKNS_7VariantES6_");

TypedValue* tg1_5Proxy_ice_checkedCast(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_5Proxy_ice_checkedCast(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  tvCastToStringInPlace(args-0);
  Variant defVal1;
  Variant defVal2;
  th_5Proxy_ice_checkedCast((Value*)(rv), (this_), (Value*)(args-0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1), (count > 2) ? (args-2) : (TypedValue*)(&defVal2));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_5Proxy_ice_checkedCast(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count >= 1LL && count <= 3LL) {
        if (IS_STRING_TYPE((args-0)->m_type)) {
          rv._count = 0;
          rv.m_type = KindOfObject;
          Variant defVal1;
          Variant defVal2;
          th_5Proxy_ice_checkedCast((Value*)(&(rv)), (this_), (Value*)(args-0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1), (count > 2) ? (args-2) : (TypedValue*)(&defVal2));
          if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 3);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_5Proxy_ice_checkedCast(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 3);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("Proxy::ice_checkedCast", count, 1, 3, 1);
      }
    } else {
      throw_instance_method_fatal("Proxy::ice_checkedCast");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 3);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

/*
HPHP::Object HPHP::c_Proxy::t_ice_uncheckedcast(HPHP::String const&, HPHP::Variant const&)
_ZN4HPHP7c_Proxy19t_ice_uncheckedcastERKNS_6StringERKNS_7VariantE

(return value) => rax
_rv => rdi
this_ => rsi
classid => rdx
facet => rcx
*/

Value* th_5Proxy_ice_uncheckedcast(Value* _rv, ObjectData* this_, Value* classid, TypedValue* facet) asm("_ZN4HPHP7c_Proxy19t_ice_uncheckedcastERKNS_6StringERKNS_7VariantE");

TypedValue* tg1_5Proxy_ice_uncheckedcast(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_5Proxy_ice_uncheckedcast(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  tvCastToStringInPlace(args-0);
  Variant defVal1;
  th_5Proxy_ice_uncheckedcast((Value*)(rv), (this_), (Value*)(args-0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_5Proxy_ice_uncheckedcast(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count >= 1LL && count <= 2LL) {
        if (IS_STRING_TYPE((args-0)->m_type)) {
          rv._count = 0;
          rv.m_type = KindOfObject;
          Variant defVal1;
          th_5Proxy_ice_uncheckedcast((Value*)(&(rv)), (this_), (Value*)(args-0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1));
          if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_5Proxy_ice_uncheckedcast(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("Proxy::ice_uncheckedcast", count, 1, 2, 1);
      }
    } else {
      throw_instance_method_fatal("Proxy::ice_uncheckedcast");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

HPHP::VM::Instance* new_IcePHP_class_Instance(HPHP::VM::Class* cls) {
  size_t nProps = cls->numDeclProperties();
  size_t builtinPropSize = sizeof(c_IcePHP_class) - sizeof(ObjectData);
  size_t size = HPHP::VM::Instance::sizeForNProps(nProps) + builtinPropSize;
  HPHP::VM::Instance *inst = (HPHP::VM::Instance*)ALLOCOBJSZ(size);
  new ((void *)inst) c_IcePHP_class(ObjectStaticCallbacks::encodeVMClass(cls));
  return inst;
}

/*
void HPHP::c_IcePHP_class::t___construct()
_ZN4HPHP14c_IcePHP_class13t___constructEv

this_ => rdi
*/

void th_12IcePHP_class___construct(ObjectData* this_) asm("_ZN4HPHP14c_IcePHP_class13t___constructEv");

TypedValue* tg_12IcePHP_class___construct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv.m_data.num = 0LL;
        rv._count = 0;
        rv.m_type = KindOfNull;
        th_12IcePHP_class___construct((this_));
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("IcePHP_class::__construct", 0, 1);
      }
    } else {
      throw_instance_method_fatal("IcePHP_class::__construct");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

HPHP::VM::Instance* new_TypeInfo_Instance(HPHP::VM::Class* cls) {
  size_t nProps = cls->numDeclProperties();
  size_t builtinPropSize = sizeof(c_TypeInfo) - sizeof(ObjectData);
  size_t size = HPHP::VM::Instance::sizeForNProps(nProps) + builtinPropSize;
  HPHP::VM::Instance *inst = (HPHP::VM::Instance*)ALLOCOBJSZ(size);
  new ((void *)inst) c_TypeInfo(ObjectStaticCallbacks::encodeVMClass(cls));
  return inst;
}

/*
void HPHP::c_TypeInfo::t___construct()
_ZN4HPHP10c_TypeInfo13t___constructEv

this_ => rdi
*/

void th_8TypeInfo___construct(ObjectData* this_) asm("_ZN4HPHP10c_TypeInfo13t___constructEv");

TypedValue* tg_8TypeInfo___construct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv.m_data.num = 0LL;
        rv._count = 0;
        rv.m_type = KindOfNull;
        th_8TypeInfo___construct((this_));
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("TypeInfo::__construct", 0, 1);
      }
    } else {
      throw_instance_method_fatal("TypeInfo::__construct");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}


} // !HPHP

