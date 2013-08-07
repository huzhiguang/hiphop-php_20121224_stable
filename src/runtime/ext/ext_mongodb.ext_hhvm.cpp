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

HPHP::VM::Instance* new_Mongo_Instance(HPHP::VM::Class* cls) {
  size_t nProps = cls->numDeclProperties();
  size_t builtinPropSize = sizeof(c_Mongo) - sizeof(ObjectData);
  size_t size = HPHP::VM::Instance::sizeForNProps(nProps) + builtinPropSize;
  HPHP::VM::Instance *inst = (HPHP::VM::Instance*)ALLOCOBJSZ(size);
  new ((void *)inst) c_Mongo(ObjectStaticCallbacks::encodeVMClass(cls));
  return inst;
}

/*
void HPHP::c_Mongo::t___construct(HPHP::String const&, HPHP::Variant const&)
_ZN4HPHP7c_Mongo13t___constructERKNS_6StringERKNS_7VariantE

this_ => rdi
server => rsi
options => rdx
*/

void th_5Mongo___construct(ObjectData* this_, Value* server, TypedValue* options) asm("_ZN4HPHP7c_Mongo13t___constructERKNS_6StringERKNS_7VariantE");

TypedValue* tg1_5Mongo___construct(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_5Mongo___construct(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_data.num = 0LL;
  rv->_count = 0;
  rv->m_type = KindOfNull;
  tvCastToStringInPlace(args-0);
  String defVal0 = "mongodb://localhost:27017";
  Variant defVal1;
  th_5Mongo___construct((this_), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1));
  return rv;
}

TypedValue* tg_5Mongo___construct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count <= 2LL) {
        if ((count <= 0 || IS_STRING_TYPE((args-0)->m_type))) {
          rv.m_data.num = 0LL;
          rv._count = 0;
          rv.m_type = KindOfNull;
          String defVal0 = "mongodb://localhost:27017";
          Variant defVal1;
          th_5Mongo___construct((this_), (count > 0) ? (Value*)(args-0) : (Value*)(&defVal0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1));
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_5Mongo___construct(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_toomany_arguments_nr("Mongo::__construct", 2, 1);
      }
    } else {
      throw_instance_method_fatal("Mongo::__construct");
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
HPHP::Variant HPHP::c_Mongo::t___get(HPHP::Variant)
_ZN4HPHP7c_Mongo7t___getENS_7VariantE

(return value) => rax
_rv => rdi
this_ => rsi
val => rdx
*/

TypedValue* th_5Mongo___get(TypedValue* _rv, ObjectData* this_, TypedValue* val) asm("_ZN4HPHP7c_Mongo7t___getENS_7VariantE");

TypedValue* tg_5Mongo___get(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 1LL) {
        th_5Mongo___get((&(rv)), (this_), (args-0));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_wrong_arguments_nr("Mongo::__get", count, 1, 1, 1);
      }
    } else {
      throw_instance_method_fatal("Mongo::__get");
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
HPHP::Variant HPHP::c_Mongo::t_selectdb(HPHP::String const&)
_ZN4HPHP7c_Mongo10t_selectdbERKNS_6StringE

(return value) => rax
_rv => rdi
this_ => rsi
name => rdx
*/

TypedValue* th_5Mongo_selectDB(TypedValue* _rv, ObjectData* this_, Value* name) asm("_ZN4HPHP7c_Mongo10t_selectdbERKNS_6StringE");

TypedValue* tg1_5Mongo_selectDB(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_5Mongo_selectDB(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToStringInPlace(args-0);
  th_5Mongo_selectDB((rv), (this_), (Value*)(args-0));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_5Mongo_selectDB(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 1LL) {
        if (IS_STRING_TYPE((args-0)->m_type)) {
          th_5Mongo_selectDB((&(rv)), (this_), (Value*)(args-0));
          if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_5Mongo_selectDB(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("Mongo::selectDB", count, 1, 1, 1);
      }
    } else {
      throw_instance_method_fatal("Mongo::selectDB");
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
HPHP::Variant HPHP::c_Mongo::t___destruct()
_ZN4HPHP7c_Mongo12t___destructEv

(return value) => rax
_rv => rdi
this_ => rsi
*/

TypedValue* th_5Mongo___destruct(TypedValue* _rv, ObjectData* this_) asm("_ZN4HPHP7c_Mongo12t___destructEv");

TypedValue* tg_5Mongo___destruct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        th_5Mongo___destruct((&(rv)), (this_));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("Mongo::__destruct", 0, 1);
      }
    } else {
      throw_instance_method_fatal("Mongo::__destruct");
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
bool HPHP::c_Mongo::t_close()
_ZN4HPHP7c_Mongo7t_closeEv

(return value) => rax
this_ => rdi
*/

bool th_5Mongo_close(ObjectData* this_) asm("_ZN4HPHP7c_Mongo7t_closeEv");

TypedValue* tg_5Mongo_close(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv._count = 0;
        rv.m_type = KindOfBoolean;
        rv.m_data.num = (th_5Mongo_close((this_))) ? 1LL : 0LL;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("Mongo::close", 0, 1);
      }
    } else {
      throw_instance_method_fatal("Mongo::close");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

HPHP::VM::Instance* new_MongoDB_Instance(HPHP::VM::Class* cls) {
  size_t nProps = cls->numDeclProperties();
  size_t builtinPropSize = sizeof(c_MongoDB) - sizeof(ObjectData);
  size_t size = HPHP::VM::Instance::sizeForNProps(nProps) + builtinPropSize;
  HPHP::VM::Instance *inst = (HPHP::VM::Instance*)ALLOCOBJSZ(size);
  new ((void *)inst) c_MongoDB(ObjectStaticCallbacks::encodeVMClass(cls));
  return inst;
}

/*
void HPHP::c_MongoDB::t___construct(HPHP::Object const&, HPHP::String const&)
_ZN4HPHP9c_MongoDB13t___constructERKNS_6ObjectERKNS_6StringE

this_ => rdi
conn => rsi
name => rdx
*/

void th_7MongoDB___construct(ObjectData* this_, Value* conn, Value* name) asm("_ZN4HPHP9c_MongoDB13t___constructERKNS_6ObjectERKNS_6StringE");

TypedValue* tg1_7MongoDB___construct(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_7MongoDB___construct(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_data.num = 0LL;
  rv->_count = 0;
  rv->m_type = KindOfNull;
  if (!IS_STRING_TYPE((args-1)->m_type)) {
    tvCastToStringInPlace(args-1);
  }
  if ((args-0)->m_type != KindOfObject) {
    tvCastToObjectInPlace(args-0);
  }
  th_7MongoDB___construct((this_), (Value*)(args-0), (Value*)(args-1));
  return rv;
}

TypedValue* tg_7MongoDB___construct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 2LL) {
        if (IS_STRING_TYPE((args-1)->m_type) && (args-0)->m_type == KindOfObject) {
          rv.m_data.num = 0LL;
          rv._count = 0;
          rv.m_type = KindOfNull;
          th_7MongoDB___construct((this_), (Value*)(args-0), (Value*)(args-1));
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_7MongoDB___construct(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("MongoDB::__construct", count, 2, 2, 1);
      }
    } else {
      throw_instance_method_fatal("MongoDB::__construct");
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
HPHP::Variant HPHP::c_MongoDB::t___get(HPHP::Variant)
_ZN4HPHP9c_MongoDB7t___getENS_7VariantE

(return value) => rax
_rv => rdi
this_ => rsi
name => rdx
*/

TypedValue* th_7MongoDB___get(TypedValue* _rv, ObjectData* this_, TypedValue* name) asm("_ZN4HPHP9c_MongoDB7t___getENS_7VariantE");

TypedValue* tg_7MongoDB___get(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 1LL) {
        th_7MongoDB___get((&(rv)), (this_), (args-0));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_wrong_arguments_nr("MongoDB::__get", count, 1, 1, 1);
      }
    } else {
      throw_instance_method_fatal("MongoDB::__get");
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
HPHP::Variant HPHP::c_MongoDB::t_selectcollection(HPHP::String const&)
_ZN4HPHP9c_MongoDB18t_selectcollectionERKNS_6StringE

(return value) => rax
_rv => rdi
this_ => rsi
name => rdx
*/

TypedValue* th_7MongoDB_selectCollection(TypedValue* _rv, ObjectData* this_, Value* name) asm("_ZN4HPHP9c_MongoDB18t_selectcollectionERKNS_6StringE");

TypedValue* tg1_7MongoDB_selectCollection(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_7MongoDB_selectCollection(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToStringInPlace(args-0);
  th_7MongoDB_selectCollection((rv), (this_), (Value*)(args-0));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_7MongoDB_selectCollection(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 1LL) {
        if (IS_STRING_TYPE((args-0)->m_type)) {
          th_7MongoDB_selectCollection((&(rv)), (this_), (Value*)(args-0));
          if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_7MongoDB_selectCollection(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("MongoDB::selectCollection", count, 1, 1, 1);
      }
    } else {
      throw_instance_method_fatal("MongoDB::selectCollection");
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
HPHP::Variant HPHP::c_MongoDB::t___destruct()
_ZN4HPHP9c_MongoDB12t___destructEv

(return value) => rax
_rv => rdi
this_ => rsi
*/

TypedValue* th_7MongoDB___destruct(TypedValue* _rv, ObjectData* this_) asm("_ZN4HPHP9c_MongoDB12t___destructEv");

TypedValue* tg_7MongoDB___destruct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        th_7MongoDB___destruct((&(rv)), (this_));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("MongoDB::__destruct", 0, 1);
      }
    } else {
      throw_instance_method_fatal("MongoDB::__destruct");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

HPHP::VM::Instance* new_MongoCollection_Instance(HPHP::VM::Class* cls) {
  size_t nProps = cls->numDeclProperties();
  size_t builtinPropSize = sizeof(c_MongoCollection) - sizeof(ObjectData);
  size_t size = HPHP::VM::Instance::sizeForNProps(nProps) + builtinPropSize;
  HPHP::VM::Instance *inst = (HPHP::VM::Instance*)ALLOCOBJSZ(size);
  new ((void *)inst) c_MongoCollection(ObjectStaticCallbacks::encodeVMClass(cls));
  return inst;
}

/*
void HPHP::c_MongoCollection::t___construct(HPHP::Object const&, HPHP::String const&)
_ZN4HPHP17c_MongoCollection13t___constructERKNS_6ObjectERKNS_6StringE

this_ => rdi
db => rsi
name => rdx
*/

void th_15MongoCollection___construct(ObjectData* this_, Value* db, Value* name) asm("_ZN4HPHP17c_MongoCollection13t___constructERKNS_6ObjectERKNS_6StringE");

TypedValue* tg1_15MongoCollection___construct(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_15MongoCollection___construct(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_data.num = 0LL;
  rv->_count = 0;
  rv->m_type = KindOfNull;
  if (!IS_STRING_TYPE((args-1)->m_type)) {
    tvCastToStringInPlace(args-1);
  }
  if ((args-0)->m_type != KindOfObject) {
    tvCastToObjectInPlace(args-0);
  }
  th_15MongoCollection___construct((this_), (Value*)(args-0), (Value*)(args-1));
  return rv;
}

TypedValue* tg_15MongoCollection___construct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 2LL) {
        if (IS_STRING_TYPE((args-1)->m_type) && (args-0)->m_type == KindOfObject) {
          rv.m_data.num = 0LL;
          rv._count = 0;
          rv.m_type = KindOfNull;
          th_15MongoCollection___construct((this_), (Value*)(args-0), (Value*)(args-1));
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_15MongoCollection___construct(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("MongoCollection::__construct", count, 2, 2, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCollection::__construct");
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
HPHP::Variant HPHP::c_MongoCollection::t_find(HPHP::Array const&, HPHP::Array const&)
_ZN4HPHP17c_MongoCollection6t_findERKNS_5ArrayES3_

(return value) => rax
_rv => rdi
this_ => rsi
query => rdx
fields => rcx
*/

TypedValue* th_15MongoCollection_find(TypedValue* _rv, ObjectData* this_, Value* query, Value* fields) asm("_ZN4HPHP17c_MongoCollection6t_findERKNS_5ArrayES3_");

TypedValue* tg1_15MongoCollection_find(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_15MongoCollection_find(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  switch (count) {
  default: // count >= 2
    if ((args-1)->m_type != KindOfArray) {
      tvCastToArrayInPlace(args-1);
    }
  case 1:
    if ((args-0)->m_type != KindOfArray) {
      tvCastToArrayInPlace(args-0);
    }
  case 0:
    break;
  }
  th_15MongoCollection_find((rv), (this_), (count > 0) ? (Value*)(args-0) : (Value*)(&null_array), (count > 1) ? (Value*)(args-1) : (Value*)(&null_array));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_15MongoCollection_find(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count <= 2LL) {
        if ((count <= 1 || (args-1)->m_type == KindOfArray) && (count <= 0 || (args-0)->m_type == KindOfArray)) {
          th_15MongoCollection_find((&(rv)), (this_), (count > 0) ? (Value*)(args-0) : (Value*)(&null_array), (count > 1) ? (Value*)(args-1) : (Value*)(&null_array));
          if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_15MongoCollection_find(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_toomany_arguments_nr("MongoCollection::find", 2, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCollection::find");
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
HPHP::Variant HPHP::c_MongoCollection::t___destruct()
_ZN4HPHP17c_MongoCollection12t___destructEv

(return value) => rax
_rv => rdi
this_ => rsi
*/

TypedValue* th_15MongoCollection___destruct(TypedValue* _rv, ObjectData* this_) asm("_ZN4HPHP17c_MongoCollection12t___destructEv");

TypedValue* tg_15MongoCollection___destruct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        th_15MongoCollection___destruct((&(rv)), (this_));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("MongoCollection::__destruct", 0, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCollection::__destruct");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

HPHP::VM::Instance* new_MongoCursor_Instance(HPHP::VM::Class* cls) {
  size_t nProps = cls->numDeclProperties();
  size_t builtinPropSize = sizeof(c_MongoCursor) - sizeof(ObjectData);
  size_t size = HPHP::VM::Instance::sizeForNProps(nProps) + builtinPropSize;
  HPHP::VM::Instance *inst = (HPHP::VM::Instance*)ALLOCOBJSZ(size);
  new ((void *)inst) c_MongoCursor(ObjectStaticCallbacks::encodeVMClass(cls));
  return inst;
}

/*
void HPHP::c_MongoCursor::t___construct(HPHP::Object const&, HPHP::String const&, HPHP::Array const&, HPHP::Array const&)
_ZN4HPHP13c_MongoCursor13t___constructERKNS_6ObjectERKNS_6StringERKNS_5ArrayES9_

this_ => rdi
connection => rsi
ns => rdx
query => rcx
fields => r8
*/

void th_11MongoCursor___construct(ObjectData* this_, Value* connection, Value* ns, Value* query, Value* fields) asm("_ZN4HPHP13c_MongoCursor13t___constructERKNS_6ObjectERKNS_6StringERKNS_5ArrayES9_");

TypedValue* tg1_11MongoCursor___construct(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_11MongoCursor___construct(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_data.num = 0LL;
  rv->_count = 0;
  rv->m_type = KindOfNull;
  switch (count) {
  default: // count >= 4
    if ((args-3)->m_type != KindOfArray) {
      tvCastToArrayInPlace(args-3);
    }
  case 3:
    if ((args-2)->m_type != KindOfArray) {
      tvCastToArrayInPlace(args-2);
    }
  case 2:
    break;
  }
  if (!IS_STRING_TYPE((args-1)->m_type)) {
    tvCastToStringInPlace(args-1);
  }
  if ((args-0)->m_type != KindOfObject) {
    tvCastToObjectInPlace(args-0);
  }
  th_11MongoCursor___construct((this_), (Value*)(args-0), (Value*)(args-1), (count > 2) ? (Value*)(args-2) : (Value*)(&null_array), (count > 3) ? (Value*)(args-3) : (Value*)(&null_array));
  return rv;
}

TypedValue* tg_11MongoCursor___construct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count >= 2LL && count <= 4LL) {
        if ((count <= 3 || (args-3)->m_type == KindOfArray) && (count <= 2 || (args-2)->m_type == KindOfArray) && IS_STRING_TYPE((args-1)->m_type) && (args-0)->m_type == KindOfObject) {
          rv.m_data.num = 0LL;
          rv._count = 0;
          rv.m_type = KindOfNull;
          th_11MongoCursor___construct((this_), (Value*)(args-0), (Value*)(args-1), (count > 2) ? (Value*)(args-2) : (Value*)(&null_array), (count > 3) ? (Value*)(args-3) : (Value*)(&null_array));
          frame_free_locals_inl(ar, 4);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_11MongoCursor___construct(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 4);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("MongoCursor::__construct", count, 2, 4, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCursor::__construct");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 4);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

/*
HPHP::Variant HPHP::c_MongoCursor::t_current()
_ZN4HPHP13c_MongoCursor9t_currentEv

(return value) => rax
_rv => rdi
this_ => rsi
*/

TypedValue* th_11MongoCursor_current(TypedValue* _rv, ObjectData* this_) asm("_ZN4HPHP13c_MongoCursor9t_currentEv");

TypedValue* tg_11MongoCursor_current(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        th_11MongoCursor_current((&(rv)), (this_));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("MongoCursor::current", 0, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCursor::current");
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
long long HPHP::c_MongoCursor::t_key()
_ZN4HPHP13c_MongoCursor5t_keyEv

(return value) => rax
this_ => rdi
*/

long long th_11MongoCursor_key(ObjectData* this_) asm("_ZN4HPHP13c_MongoCursor5t_keyEv");

TypedValue* tg_11MongoCursor_key(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv._count = 0;
        rv.m_type = KindOfInt64;
        rv.m_data.num = (long long)th_11MongoCursor_key((this_));
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("MongoCursor::key", 0, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCursor::key");
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
void HPHP::c_MongoCursor::t_next()
_ZN4HPHP13c_MongoCursor6t_nextEv

this_ => rdi
*/

void th_11MongoCursor_next(ObjectData* this_) asm("_ZN4HPHP13c_MongoCursor6t_nextEv");

TypedValue* tg_11MongoCursor_next(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv.m_data.num = 0LL;
        rv._count = 0;
        rv.m_type = KindOfNull;
        th_11MongoCursor_next((this_));
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("MongoCursor::next", 0, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCursor::next");
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
void HPHP::c_MongoCursor::t_rewind()
_ZN4HPHP13c_MongoCursor8t_rewindEv

this_ => rdi
*/

void th_11MongoCursor_rewind(ObjectData* this_) asm("_ZN4HPHP13c_MongoCursor8t_rewindEv");

TypedValue* tg_11MongoCursor_rewind(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv.m_data.num = 0LL;
        rv._count = 0;
        rv.m_type = KindOfNull;
        th_11MongoCursor_rewind((this_));
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("MongoCursor::rewind", 0, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCursor::rewind");
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
bool HPHP::c_MongoCursor::t_valid()
_ZN4HPHP13c_MongoCursor7t_validEv

(return value) => rax
this_ => rdi
*/

bool th_11MongoCursor_valid(ObjectData* this_) asm("_ZN4HPHP13c_MongoCursor7t_validEv");

TypedValue* tg_11MongoCursor_valid(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv._count = 0;
        rv.m_type = KindOfBoolean;
        rv.m_data.num = (th_11MongoCursor_valid((this_))) ? 1LL : 0LL;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("MongoCursor::valid", 0, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCursor::valid");
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
HPHP::Object HPHP::c_MongoCursor::t_limit(long long)
_ZN4HPHP13c_MongoCursor7t_limitEx

(return value) => rax
_rv => rdi
this_ => rsi
num => rdx
*/

Value* th_11MongoCursor_limit(Value* _rv, ObjectData* this_, long long num) asm("_ZN4HPHP13c_MongoCursor7t_limitEx");

TypedValue* tg1_11MongoCursor_limit(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_11MongoCursor_limit(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->_count = 0;
  rv->m_type = KindOfObject;
  tvCastToInt64InPlace(args-0);
  th_11MongoCursor_limit((Value*)(rv), (this_), (long long)(args[-0].m_data.num));
  if (rv->m_data.num == 0LL)rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_11MongoCursor_limit(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 1LL) {
        if ((args-0)->m_type == KindOfInt64) {
          rv._count = 0;
          rv.m_type = KindOfObject;
          th_11MongoCursor_limit((Value*)(&(rv)), (this_), (long long)(args[-0].m_data.num));
          if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_11MongoCursor_limit(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("MongoCursor::limit", count, 1, 1, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCursor::limit");
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
HPHP::Variant HPHP::c_MongoCursor::t_sort(HPHP::Array const&)
_ZN4HPHP13c_MongoCursor6t_sortERKNS_5ArrayE

(return value) => rax
_rv => rdi
this_ => rsi
fields => rdx
*/

TypedValue* th_11MongoCursor_sort(TypedValue* _rv, ObjectData* this_, Value* fields) asm("_ZN4HPHP13c_MongoCursor6t_sortERKNS_5ArrayE");

TypedValue* tg1_11MongoCursor_sort(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_11MongoCursor_sort(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToArrayInPlace(args-0);
  th_11MongoCursor_sort((rv), (this_), (Value*)(args-0));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_11MongoCursor_sort(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 1LL) {
        if ((args-0)->m_type == KindOfArray) {
          th_11MongoCursor_sort((&(rv)), (this_), (Value*)(args-0));
          if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_11MongoCursor_sort(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("MongoCursor::sort", count, 1, 1, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCursor::sort");
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
HPHP::Variant HPHP::c_MongoCursor::t_skip(int)
_ZN4HPHP13c_MongoCursor6t_skipEi

(return value) => rax
_rv => rdi
this_ => rsi
num => rdx
*/

TypedValue* th_11MongoCursor_skip(TypedValue* _rv, ObjectData* this_, int num) asm("_ZN4HPHP13c_MongoCursor6t_skipEi");

TypedValue* tg1_11MongoCursor_skip(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_11MongoCursor_skip(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToInt64InPlace(args-0);
  th_11MongoCursor_skip((rv), (this_), (int)(args[-0].m_data.num));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* tg_11MongoCursor_skip(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 1LL) {
        if ((args-0)->m_type == KindOfInt64) {
          th_11MongoCursor_skip((&(rv)), (this_), (int)(args[-0].m_data.num));
          if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_11MongoCursor_skip(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 1);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("MongoCursor::skip", count, 1, 1, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCursor::skip");
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
HPHP::Array HPHP::c_MongoCursor::t_info()
_ZN4HPHP13c_MongoCursor6t_infoEv

(return value) => rax
_rv => rdi
this_ => rsi
*/

Value* th_11MongoCursor_info(Value* _rv, ObjectData* this_) asm("_ZN4HPHP13c_MongoCursor6t_infoEv");

TypedValue* tg_11MongoCursor_info(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        rv._count = 0;
        rv.m_type = KindOfArray;
        th_11MongoCursor_info((Value*)(&(rv)), (this_));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("MongoCursor::info", 0, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCursor::info");
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
HPHP::Variant HPHP::c_MongoCursor::t___destruct()
_ZN4HPHP13c_MongoCursor12t___destructEv

(return value) => rax
_rv => rdi
this_ => rsi
*/

TypedValue* th_11MongoCursor___destruct(TypedValue* _rv, ObjectData* this_) asm("_ZN4HPHP13c_MongoCursor12t___destructEv");

TypedValue* tg_11MongoCursor___destruct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 0LL) {
        th_11MongoCursor___destruct((&(rv)), (this_));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 0);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_toomany_arguments_nr("MongoCursor::__destruct", 0, 1);
      }
    } else {
      throw_instance_method_fatal("MongoCursor::__destruct");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}

HPHP::VM::Instance* new_MongoDate_Instance(HPHP::VM::Class* cls) {
  size_t nProps = cls->numDeclProperties();
  size_t builtinPropSize = sizeof(c_MongoDate) - sizeof(ObjectData);
  size_t size = HPHP::VM::Instance::sizeForNProps(nProps) + builtinPropSize;
  HPHP::VM::Instance *inst = (HPHP::VM::Instance*)ALLOCOBJSZ(size);
  new ((void *)inst) c_MongoDate(ObjectStaticCallbacks::encodeVMClass(cls));
  return inst;
}

/*
void HPHP::c_MongoDate::t___construct(long long, long long)
_ZN4HPHP11c_MongoDate13t___constructExx

this_ => rdi
sec => rsi
usec => rdx
*/

void th_9MongoDate___construct(ObjectData* this_, long long sec, long long usec) asm("_ZN4HPHP11c_MongoDate13t___constructExx");

TypedValue* tg1_9MongoDate___construct(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) __attribute__((noinline,cold));
TypedValue* tg1_9MongoDate___construct(TypedValue* rv, HPHP::VM::ActRec* ar, long long count, ObjectData* this_) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_data.num = 0LL;
  rv->_count = 0;
  rv->m_type = KindOfNull;
  if ((args-1)->m_type != KindOfInt64) {
    tvCastToInt64InPlace(args-1);
  }
  if ((args-0)->m_type != KindOfInt64) {
    tvCastToInt64InPlace(args-0);
  }
  th_9MongoDate___construct((this_), (long long)(args[-0].m_data.num), (long long)(args[-1].m_data.num));
  return rv;
}

TypedValue* tg_9MongoDate___construct(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 2LL) {
        if ((args-1)->m_type == KindOfInt64 && (args-0)->m_type == KindOfInt64) {
          rv.m_data.num = 0LL;
          rv._count = 0;
          rv.m_type = KindOfNull;
          th_9MongoDate___construct((this_), (long long)(args[-0].m_data.num), (long long)(args[-1].m_data.num));
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        } else {
          tg1_9MongoDate___construct(&rv, ar, count , this_);
          frame_free_locals_inl(ar, 2);
          memcpy(&ar->m_r, &rv, sizeof(TypedValue));
          return &ar->m_r;
        }
      } else {
        throw_wrong_arguments_nr("MongoDate::__construct", count, 2, 2, 1);
      }
    } else {
      throw_instance_method_fatal("MongoDate::__construct");
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
HPHP::Variant HPHP::c_MongoDate::t___get(HPHP::Variant)
_ZN4HPHP11c_MongoDate7t___getENS_7VariantE

(return value) => rax
_rv => rdi
this_ => rsi
val => rdx
*/

TypedValue* th_9MongoDate___get(TypedValue* _rv, ObjectData* this_, TypedValue* val) asm("_ZN4HPHP11c_MongoDate7t___getENS_7VariantE");

TypedValue* tg_9MongoDate___get(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 1LL) {
        th_9MongoDate___get((&(rv)), (this_), (args-0));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_wrong_arguments_nr("MongoDate::__get", count, 1, 1, 1);
      }
    } else {
      throw_instance_method_fatal("MongoDate::__get");
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
HPHP::Variant HPHP::c_MongoDate::t___set(HPHP::Variant, HPHP::Variant)
_ZN4HPHP11c_MongoDate7t___setENS_7VariantES1_

(return value) => rax
_rv => rdi
this_ => rsi
name => rdx
value => rcx
*/

TypedValue* th_9MongoDate___set(TypedValue* _rv, ObjectData* this_, TypedValue* name, TypedValue* value) asm("_ZN4HPHP11c_MongoDate7t___setENS_7VariantES1_");

TypedValue* tg_9MongoDate___set(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    long long count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    ObjectData* this_ = (ar->hasThis() ? ar->getThis() : NULL);
    if (this_) {
      if (count == 2LL) {
        th_9MongoDate___set((&(rv)), (this_), (args-0), (args-1));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        throw_wrong_arguments_nr("MongoDate::__set", count, 2, 2, 1);
      }
    } else {
      throw_instance_method_fatal("MongoDate::__set");
    }
    rv.m_data.num = 0LL;
    rv._count = 0;
    rv.m_type = KindOfNull;
    frame_free_locals_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}


} // !HPHP

