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

#include <test/>
#include <runtime/ext/ext_mssql.h>

IMPLEMENT_SEP_EXTENSION_TEST(Mssql);
///////////////////////////////////////////////////////////////////////////////

bool TestExtMssql::RunTests(const std::string &which) {
  bool ret = true;

  RUN_TEST(test_mssql_connect);
  RUN_TEST(test_mssql_pconnect);
  RUN_TEST(test_mssql_close);
  RUN_TEST(test_mssql_select_db);
  RUN_TEST(test_mssql_query);
  RUN_TEST(test_mssql_num_rows);
  RUN_TEST(test_mssql_rows_affected);
  RUN_TEST(test_mssql_fetch_row);
  RUN_TEST(test_mssql_fetch_assoc);
  RUN_TEST(test_mssql_free_result);
  RUN_TEST(test_mssql_get_last_message);
  RUN_TEST(test_MssqlResult);

  return ret;
}

///////////////////////////////////////////////////////////////////////////////

bool TestExtMssql::test_mssql_connect() {
  return Count(true);
}

bool TestExtMssql::test_mssql_pconnect() {
  return Count(true);
}

bool TestExtMssql::test_mssql_close() {
  return Count(true);
}

bool TestExtMssql::test_mssql_select_db() {
  return Count(true);
}

bool TestExtMssql::test_mssql_query() {
  return Count(true);
}

bool TestExtMssql::test_mssql_num_rows() {
  return Count(true);
}

bool TestExtMssql::test_mssql_rows_affected() {
  return Count(true);
}

bool TestExtMssql::test_mssql_fetch_row() {
  return Count(true);
}

bool TestExtMssql::test_mssql_fetch_assoc() {
  return Count(true);
}

bool TestExtMssql::test_mssql_free_result() {
  return Count(true);
}

bool TestExtMssql::test_mssql_get_last_message() {
  return Count(true);
}

bool TestExtMssql::test_MssqlResult() {
  return Count(true);
}
