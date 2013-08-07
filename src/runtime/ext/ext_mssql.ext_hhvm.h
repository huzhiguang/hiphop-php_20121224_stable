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

/*
bool HPHP::f_mssql_close(HPHP::Variant const&)
_ZN4HPHP13f_mssql_closeERKNS_7VariantE

(return value) => rax
link_identifier => rdi
*/

bool fh_mssql_close(TypedValue* link_identifier) asm("_ZN4HPHP13f_mssql_closeERKNS_7VariantE");

/*
bool HPHP::f_mssql_select_db(HPHP::String const&, HPHP::Variant const&)
_ZN4HPHP17f_mssql_select_dbERKNS_6StringERKNS_7VariantE

(return value) => rax
database_name => rdi
link_identifier => rsi
*/

bool fh_mssql_select_db(Value* database_name, TypedValue* link_identifier) asm("_ZN4HPHP17f_mssql_select_dbERKNS_6StringERKNS_7VariantE");

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

/*
HPHP::Variant HPHP::f_mssql_num_rows(HPHP::Variant const&)
_ZN4HPHP16f_mssql_num_rowsERKNS_7VariantE

(return value) => rax
_rv => rdi
result => rsi
*/

TypedValue* fh_mssql_num_rows(TypedValue* _rv, TypedValue* result) asm("_ZN4HPHP16f_mssql_num_rowsERKNS_7VariantE");

/*
HPHP::Variant HPHP::f_mssql_rows_affected(HPHP::Variant const&)
_ZN4HPHP21f_mssql_rows_affectedERKNS_7VariantE

(return value) => rax
_rv => rdi
result => rsi
*/

TypedValue* fh_mssql_rows_affected(TypedValue* _rv, TypedValue* result) asm("_ZN4HPHP21f_mssql_rows_affectedERKNS_7VariantE");

/*
HPHP::Variant HPHP::f_mssql_fetch_row(HPHP::Variant const&)
_ZN4HPHP17f_mssql_fetch_rowERKNS_7VariantE

(return value) => rax
_rv => rdi
result => rsi
*/

TypedValue* fh_mssql_fetch_row(TypedValue* _rv, TypedValue* result) asm("_ZN4HPHP17f_mssql_fetch_rowERKNS_7VariantE");

/*
HPHP::Variant HPHP::f_mssql_fetch_assoc(HPHP::Variant const&)
_ZN4HPHP19f_mssql_fetch_assocERKNS_7VariantE

(return value) => rax
_rv => rdi
result => rsi
*/

TypedValue* fh_mssql_fetch_assoc(TypedValue* _rv, TypedValue* result) asm("_ZN4HPHP19f_mssql_fetch_assocERKNS_7VariantE");

/*
HPHP::Variant HPHP::f_mssql_free_result(HPHP::Variant const&)
_ZN4HPHP19f_mssql_free_resultERKNS_7VariantE

(return value) => rax
_rv => rdi
result => rsi
*/

TypedValue* fh_mssql_free_result(TypedValue* _rv, TypedValue* result) asm("_ZN4HPHP19f_mssql_free_resultERKNS_7VariantE");

/*
HPHP::Variant HPHP::f_mssql_get_last_message()
_ZN4HPHP24f_mssql_get_last_messageEv

(return value) => rax
_rv => rdi
*/

TypedValue* fh_mssql_get_last_message(TypedValue* _rv) asm("_ZN4HPHP24f_mssql_get_last_messageEv");


} // !HPHP

