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
HPHP::Variant HPHP::f_mssql_connect(HPHP::String const&, HPHP::String const&, HPHP::String const&, bool)
_ZN4HPHP15f_mssql_connectERKNS_6StringES2_S2_b

(return value) => rax
_rv => rdi
server => rsi
username => rdx
password => rcx
new_link => r8
*/

TypedValue* fh_mssql_connect(TypedValue* _rv, Value* server, Value* username, Value* password, bool new_link) asm("_ZN4HPHP15f_mssql_connectERKNS_6StringES2_S2_b");

TypedValue * fg1_mssql_connect(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_mssql_connect(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  switch (count) {
  default: // count >= 4
    if ((args-3)->m_type != KindOfBoolean) {
      tvCastToBooleanInPlace(args-3);
    }
  case 3:
    if (!IS_STRING_TYPE((args-2)->m_type)) {
      tvCastToStringInPlace(args-2);
    }
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
  fh_mssql_connect((rv), (count > 0) ? (Value*)(args-0) : (Value*)(&null_string), (count > 1) ? (Value*)(args-1) : (Value*)(&null_string), (count > 2) ? (Value*)(args-2) : (Value*)(&null_string), (count > 3) ? (bool)(args[-3].m_data.num) : (bool)(false));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_mssql_connect(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 4LL) {
      if ((count <= 3 || (args-3)->m_type == KindOfBoolean) && (count <= 2 || IS_STRING_TYPE((args-2)->m_type)) && (count <= 1 || IS_STRING_TYPE((args-1)->m_type)) && (count <= 0 || IS_STRING_TYPE((args-0)->m_type))) {
        fh_mssql_connect((&(rv)), (count > 0) ? (Value*)(args-0) : (Value*)(&null_string), (count > 1) ? (Value*)(args-1) : (Value*)(&null_string), (count > 2) ? (Value*)(args-2) : (Value*)(&null_string), (count > 3) ? (bool)(args[-3].m_data.num) : (bool)(false));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 4);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_mssql_connect(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 4);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("mssql_connect", 4, 1);
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
HPHP::Variant HPHP::f_mssql_pconnect(HPHP::String const&, HPHP::String const&, HPHP::String const&, bool)
_ZN4HPHP16f_mssql_pconnectERKNS_6StringES2_S2_b

(return value) => rax
_rv => rdi
server => rsi
username => rdx
password => rcx
new_link => r8
*/

TypedValue* fh_mssql_pconnect(TypedValue* _rv, Value* server, Value* username, Value* password, bool new_link) asm("_ZN4HPHP16f_mssql_pconnectERKNS_6StringES2_S2_b");

TypedValue * fg1_mssql_pconnect(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_mssql_pconnect(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  switch (count) {
  default: // count >= 4
    if ((args-3)->m_type != KindOfBoolean) {
      tvCastToBooleanInPlace(args-3);
    }
  case 3:
    if (!IS_STRING_TYPE((args-2)->m_type)) {
      tvCastToStringInPlace(args-2);
    }
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
  fh_mssql_pconnect((rv), (count > 0) ? (Value*)(args-0) : (Value*)(&null_string), (count > 1) ? (Value*)(args-1) : (Value*)(&null_string), (count > 2) ? (Value*)(args-2) : (Value*)(&null_string), (count > 3) ? (bool)(args[-3].m_data.num) : (bool)(false));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_mssql_pconnect(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 4LL) {
      if ((count <= 3 || (args-3)->m_type == KindOfBoolean) && (count <= 2 || IS_STRING_TYPE((args-2)->m_type)) && (count <= 1 || IS_STRING_TYPE((args-1)->m_type)) && (count <= 0 || IS_STRING_TYPE((args-0)->m_type))) {
        fh_mssql_pconnect((&(rv)), (count > 0) ? (Value*)(args-0) : (Value*)(&null_string), (count > 1) ? (Value*)(args-1) : (Value*)(&null_string), (count > 2) ? (Value*)(args-2) : (Value*)(&null_string), (count > 3) ? (bool)(args[-3].m_data.num) : (bool)(false));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 4);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_mssql_pconnect(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 4);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("mssql_pconnect", 4, 1);
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
bool HPHP::f_mssql_close(HPHP::Variant const&)
_ZN4HPHP13f_mssql_closeERKNS_7VariantE

(return value) => rax
link_identifier => rdi
*/

bool fh_mssql_close(TypedValue* link_identifier) asm("_ZN4HPHP13f_mssql_closeERKNS_7VariantE");

TypedValue* fg_mssql_close(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 1LL) {
      rv._count = 0;
      rv.m_type = KindOfBoolean;
      Variant defVal0;
      rv.m_data.num = (fh_mssql_close((count > 0) ? (args-0) : (TypedValue*)(&defVal0))) ? 1LL : 0LL;
      frame_free_locals_no_this_inl(ar, 1);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("mssql_close", 1, 1);
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
bool HPHP::f_mssql_select_db(HPHP::String const&, HPHP::Variant const&)
_ZN4HPHP17f_mssql_select_dbERKNS_6StringERKNS_7VariantE

(return value) => rax
database_name => rdi
link_identifier => rsi
*/

bool fh_mssql_select_db(Value* database_name, TypedValue* link_identifier) asm("_ZN4HPHP17f_mssql_select_dbERKNS_6StringERKNS_7VariantE");

TypedValue * fg1_mssql_select_db(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_mssql_select_db(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfBoolean;
  tvCastToStringInPlace(args-0);
  String defVal0 = null;
  Variant defVal1;
  rv->m_data.num = (fh_mssql_select_db((count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1))) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_mssql_select_db(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 2LL) {
      if ((count <= 0 || IS_STRING_TYPE((args-0)->m_type))) {
        rv._count = 0;
        rv.m_type = KindOfBoolean;
        String defVal0 = null;
        Variant defVal1;
        rv.m_data.num = (fh_mssql_select_db((count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1))) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_mssql_select_db(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("mssql_select_db", 2, 1);
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
HPHP::Variant HPHP::f_mssql_query(HPHP::String const&, HPHP::Variant const&, long long)
_ZN4HPHP13f_mssql_queryERKNS_6StringERKNS_7VariantEx

(return value) => rax
_rv => rdi
query => rsi
link_identifier => rdx
batch_size => rcx
*/

TypedValue* fh_mssql_query(TypedValue* _rv, Value* query, TypedValue* link_identifier, long long batch_size) asm("_ZN4HPHP13f_mssql_queryERKNS_6StringERKNS_7VariantEx");

TypedValue * fg1_mssql_query(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) __attribute__((noinline,cold));
TypedValue * fg1_mssql_query(TypedValue* rv, HPHP::VM::ActRec* ar, long long count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  switch (count) {
  default: // count >= 3
    if ((args-2)->m_type != KindOfInt64) {
      tvCastToInt64InPlace(args-2);
    }
  case 2:
  case 1:
    if (!IS_STRING_TYPE((args-0)->m_type)) {
      tvCastToStringInPlace(args-0);
    }
  case 0:
    break;
  }
  String defVal0 = null;
  Variant defVal1;
  fh_mssql_query((rv), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1), (count > 2) ? (long long)(args[-2].m_data.num) : (long long)(0));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_mssql_query(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 3LL) {
      if ((count <= 2 || (args-2)->m_type == KindOfInt64) && (count <= 0 || IS_STRING_TYPE((args-0)->m_type))) {
        String defVal0 = null;
        Variant defVal1;
        fh_mssql_query((&(rv)), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1), (count > 2) ? (long long)(args[-2].m_data.num) : (long long)(0));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_mssql_query(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("mssql_query", 3, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 3);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_mssql_num_rows(HPHP::Variant const&)
_ZN4HPHP16f_mssql_num_rowsERKNS_7VariantE

(return value) => rax
_rv => rdi
result => rsi
*/

TypedValue* fh_mssql_num_rows(TypedValue* _rv, TypedValue* result) asm("_ZN4HPHP16f_mssql_num_rowsERKNS_7VariantE");

TypedValue* fg_mssql_num_rows(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 1LL) {
      Variant defVal0;
      fh_mssql_num_rows((&(rv)), (count > 0) ? (args-0) : (TypedValue*)(&defVal0));
      if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
      frame_free_locals_no_this_inl(ar, 1);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("mssql_num_rows", 1, 1);
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
HPHP::Variant HPHP::f_mssql_rows_affected(HPHP::Variant const&)
_ZN4HPHP21f_mssql_rows_affectedERKNS_7VariantE

(return value) => rax
_rv => rdi
result => rsi
*/

TypedValue* fh_mssql_rows_affected(TypedValue* _rv, TypedValue* result) asm("_ZN4HPHP21f_mssql_rows_affectedERKNS_7VariantE");

TypedValue* fg_mssql_rows_affected(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 1LL) {
      Variant defVal0;
      fh_mssql_rows_affected((&(rv)), (count > 0) ? (args-0) : (TypedValue*)(&defVal0));
      if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
      frame_free_locals_no_this_inl(ar, 1);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("mssql_rows_affected", 1, 1);
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
HPHP::Variant HPHP::f_mssql_fetch_row(HPHP::Variant const&)
_ZN4HPHP17f_mssql_fetch_rowERKNS_7VariantE

(return value) => rax
_rv => rdi
result => rsi
*/

TypedValue* fh_mssql_fetch_row(TypedValue* _rv, TypedValue* result) asm("_ZN4HPHP17f_mssql_fetch_rowERKNS_7VariantE");

TypedValue* fg_mssql_fetch_row(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 1LL) {
      Variant defVal0;
      fh_mssql_fetch_row((&(rv)), (count > 0) ? (args-0) : (TypedValue*)(&defVal0));
      if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
      frame_free_locals_no_this_inl(ar, 1);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("mssql_fetch_row", 1, 1);
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
HPHP::Variant HPHP::f_mssql_fetch_assoc(HPHP::Variant const&)
_ZN4HPHP19f_mssql_fetch_assocERKNS_7VariantE

(return value) => rax
_rv => rdi
result => rsi
*/

TypedValue* fh_mssql_fetch_assoc(TypedValue* _rv, TypedValue* result) asm("_ZN4HPHP19f_mssql_fetch_assocERKNS_7VariantE");

TypedValue* fg_mssql_fetch_assoc(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 1LL) {
      Variant defVal0;
      fh_mssql_fetch_assoc((&(rv)), (count > 0) ? (args-0) : (TypedValue*)(&defVal0));
      if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
      frame_free_locals_no_this_inl(ar, 1);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("mssql_fetch_assoc", 1, 1);
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
HPHP::Variant HPHP::f_mssql_free_result(HPHP::Variant const&)
_ZN4HPHP19f_mssql_free_resultERKNS_7VariantE

(return value) => rax
_rv => rdi
result => rsi
*/

TypedValue* fh_mssql_free_result(TypedValue* _rv, TypedValue* result) asm("_ZN4HPHP19f_mssql_free_resultERKNS_7VariantE");

TypedValue* fg_mssql_free_result(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 1LL) {
      Variant defVal0;
      fh_mssql_free_result((&(rv)), (count > 0) ? (args-0) : (TypedValue*)(&defVal0));
      if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
      frame_free_locals_no_this_inl(ar, 1);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("mssql_free_result", 1, 1);
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
HPHP::Variant HPHP::f_mssql_get_last_message()
_ZN4HPHP24f_mssql_get_last_messageEv

(return value) => rax
_rv => rdi
*/

TypedValue* fh_mssql_get_last_message(TypedValue* _rv) asm("_ZN4HPHP24f_mssql_get_last_messageEv");

TypedValue* fg_mssql_get_last_message(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 0LL) {
      fh_mssql_get_last_message((&(rv)));
      if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
      frame_free_locals_no_this_inl(ar, 0);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("mssql_get_last_message", 0, 1);
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



HPHP::VM::Instance* new_MssqlResult_Instance(HPHP::VM::Class* cls) {
  size_t nProps = cls->numDeclProperties();
  size_t builtinPropSize = sizeof(c_MssqlResult) - sizeof(ObjectData);
  size_t size = HPHP::VM::Instance::sizeForNProps(nProps) + builtinPropSize;
  HPHP::VM::Instance *inst = (HPHP::VM::Instance*)ALLOCOBJSZ(size);
  new ((void *)inst) c_MssqlResult(ObjectStaticCallbacks::encodeVMClass(cls));
  return inst;
}

/*
void HPHP::c_MssqlResult::t___construct()
_ZN4HPHP13c_MssqlResult13t___constructEv

this_ => rdi
*/

void th_11MssqlResult___construct(ObjectData* this_) asm("_ZN4HPHP13c_MssqlResult13t___constructEv");

TypedValue* tg_11MssqlResult___construct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv.m_data.num = 0LL;
        rv._count = 0;
        rv.m_type = KindOfNull;
        th_11MssqlResult___construct((this_));
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("MssqlResult::__construct", 0, 1);
      }
    } else {
      throw_instance_method_fatal("MssqlResult::__construct");
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
HPHP::String HPHP::c_MssqlResult::t___tostring()
_ZN4HPHP13c_MssqlResult12t___tostringEv

(return value) => rax
_rv => rdi
this_ => rsi
*/

Value* th_11MssqlResult___toString(Value* _rv, ObjectData* this_) asm("_ZN4HPHP13c_MssqlResult12t___tostringEv");

TypedValue* tg_11MssqlResult___toString(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv._count = 0;
        rv.m_type = KindOfString;
        th_11MssqlResult___toString((Value*)(&(rv)), (this_));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("MssqlResult::__toString", 0, 1);
      }
    } else {
      throw_instance_method_fatal("MssqlResult::__toString");
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

