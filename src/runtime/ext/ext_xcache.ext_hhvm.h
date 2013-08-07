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
bool HPHP::f_xcache_set(HPHP::String const&, HPHP::Variant const&, int)
_ZN4HPHP12f_xcache_setERKNS_6StringERKNS_7VariantEi

(return value) => rax
name => rdi
value => rsi
ttl => rdx
*/

bool fh_xcache_set(Value* name, TypedValue* value, int ttl) asm("_ZN4HPHP12f_xcache_setERKNS_6StringERKNS_7VariantEi");

/*
HPHP::Variant HPHP::f_xcache_get(HPHP::String const&)
_ZN4HPHP12f_xcache_getERKNS_6StringE

(return value) => rax
_rv => rdi
name => rsi
*/

TypedValue* fh_xcache_get(TypedValue* _rv, Value* name) asm("_ZN4HPHP12f_xcache_getERKNS_6StringE");

/*
long long HPHP::f_xcache_inc(HPHP::String const&, long long, int)
_ZN4HPHP12f_xcache_incERKNS_6StringExi

(return value) => rax
name => rdi
value => rsi
ttl => rdx
*/

long long fh_xcache_inc(Value* name, long long value, int ttl) asm("_ZN4HPHP12f_xcache_incERKNS_6StringExi");

/*
bool HPHP::f_xcache_unset(HPHP::String const&)
_ZN4HPHP14f_xcache_unsetERKNS_6StringE

(return value) => rax
name => rdi
*/

bool fh_xcache_unset(Value* name) asm("_ZN4HPHP14f_xcache_unsetERKNS_6StringE");


} // !HPHP

