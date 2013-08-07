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
namespace HPHP {

/*
HPHP::Object HPHP::f_ice_initialize()
_ZN4HPHP16f_ice_initializeEv

(return value) => rax
_rv => rdi
*/

Value* fh_ice_initialize(Value* _rv) asm("_ZN4HPHP16f_ice_initializeEv");

/*
HPHP::Object HPHP::f_icephp_defineproxy(HPHP::Object const&)
_ZN4HPHP20f_icephp_defineproxyERKNS_6ObjectE

(return value) => rax
_rv => rdi
classobj => rsi
*/

Value* fh_icephp_defineproxy(Value* _rv, Value* classobj) asm("_ZN4HPHP20f_icephp_defineproxyERKNS_6ObjectE");

/*
HPHP::Object HPHP::f_icephp_declareclass(HPHP::String const&)
_ZN4HPHP21f_icephp_declareclassERKNS_6StringE

(return value) => rax
_rv => rdi
id => rsi
*/

Value* fh_icephp_declareclass(Value* _rv, Value* id) asm("_ZN4HPHP21f_icephp_declareclassERKNS_6StringE");

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

/*
HPHP::Variant HPHP::f_create_typeinfobyid(int)
_ZN4HPHP21f_create_typeinfobyidEi

(return value) => rax
_rv => rdi
id => rsi
*/

TypedValue* fh_create_typeinfobyid(TypedValue* _rv, int id) asm("_ZN4HPHP21f_create_typeinfobyidEi");

/*
HPHP::String HPHP::f_icephp_stringifyexception(HPHP::Object const&, HPHP::Object const&)
_ZN4HPHP27f_icephp_stringifyexceptionERKNS_6ObjectES2_

(return value) => rax
_rv => rdi
value => rsi
target => rdx
*/

Value* fh_icephp_stringifyexception(Value* _rv, Value* value, Value* target) asm("_ZN4HPHP27f_icephp_stringifyexceptionERKNS_6ObjectES2_");

/*
HPHP::String HPHP::f_icephp_stringify(HPHP::Object const&, HPHP::Object const&)
_ZN4HPHP18f_icephp_stringifyERKNS_6ObjectES2_

(return value) => rax
_rv => rdi
value => rsi
target => rdx
*/

Value* fh_icephp_stringify(Value* _rv, Value* value, Value* target) asm("_ZN4HPHP18f_icephp_stringifyERKNS_6ObjectES2_");

/*
HPHP::Object HPHP::f_icephp_definesequence(HPHP::String const&, HPHP::Variant const&)
_ZN4HPHP23f_icephp_definesequenceERKNS_6StringERKNS_7VariantE

(return value) => rax
_rv => rdi
id => rsi
elementtype => rdx
*/

Value* fh_icephp_definesequence(Value* _rv, Value* id, TypedValue* elementtype) asm("_ZN4HPHP23f_icephp_definesequenceERKNS_6StringERKNS_7VariantE");

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

/*
HPHP::Object HPHP::f_ice_find(HPHP::String const&)
_ZN4HPHP10f_ice_findERKNS_6StringE

(return value) => rax
_rv => rdi
ice_name => rsi
*/

Value* fh_ice_find(Value* _rv, Value* ice_name) asm("_ZN4HPHP10f_ice_findERKNS_6StringE");

/*
bool HPHP::f_ice_register(HPHP::Object const&, HPHP::String const&, long long)
_ZN4HPHP14f_ice_registerERKNS_6ObjectERKNS_6StringEx

(return value) => rax
ice_object => rdi
ice_name => rsi
expires => rdx
*/

bool fh_ice_register(Value* ice_object, Value* ice_name, long long expires) asm("_ZN4HPHP14f_ice_registerERKNS_6ObjectERKNS_6StringEx");


} // !HPHP

