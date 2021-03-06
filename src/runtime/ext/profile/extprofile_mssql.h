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

#ifndef __EXTPROFILE_MSSQL_H__
#define __EXTPROFILE_MSSQL_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <runtime/ext/ext_mssql.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

inline Variant x_mssql_connect(CStrRef server = null_string, CStrRef username = null_string, CStrRef password = null_string, bool new_link = false) {
  FUNCTION_INJECTION_BUILTIN(mssql_connect);
  return f_mssql_connect(server, username, password, new_link);
}

inline Variant x_mssql_pconnect(CStrRef server = null_string, CStrRef username = null_string, CStrRef password = null_string, bool new_link = false) {
  FUNCTION_INJECTION_BUILTIN(mssql_pconnect);
  return f_mssql_pconnect(server, username, password, new_link);
}

inline bool x_mssql_close(CVarRef link_identifier = null) {
  FUNCTION_INJECTION_BUILTIN(mssql_close);
  return f_mssql_close(link_identifier);
}

inline bool x_mssql_select_db(CStrRef database_name = null, CVarRef link_identifier = null) {
  FUNCTION_INJECTION_BUILTIN(mssql_select_db);
  return f_mssql_select_db(database_name, link_identifier);
}

inline Variant x_mssql_query(CStrRef query = null, CVarRef link_identifier = null, int64 batch_size = 0) {
  FUNCTION_INJECTION_BUILTIN(mssql_query);
  return f_mssql_query(query, link_identifier, batch_size);
}

inline Variant x_mssql_num_rows(CVarRef result = null) {
  FUNCTION_INJECTION_BUILTIN(mssql_num_rows);
  return f_mssql_num_rows(result);
}

inline Variant x_mssql_rows_affected(CVarRef result = null) {
  FUNCTION_INJECTION_BUILTIN(mssql_rows_affected);
  return f_mssql_rows_affected(result);
}

inline Variant x_mssql_fetch_row(CVarRef result = null) {
  FUNCTION_INJECTION_BUILTIN(mssql_fetch_row);
  return f_mssql_fetch_row(result);
}

inline Variant x_mssql_fetch_assoc(CVarRef result = null) {
  FUNCTION_INJECTION_BUILTIN(mssql_fetch_assoc);
  return f_mssql_fetch_assoc(result);
}

inline Variant x_mssql_free_result(CVarRef result = null) {
  FUNCTION_INJECTION_BUILTIN(mssql_free_result);
  return f_mssql_free_result(result);
}

inline Variant x_mssql_get_last_message() {
  FUNCTION_INJECTION_BUILTIN(mssql_get_last_message);
  return f_mssql_get_last_message();
}


///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXTPROFILE_MSSQL_H__
