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

#include <runtime/ext/ext_mssql.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

Variant f_mssql_connect(CStrRef server /* = null_string */, CStrRef username /* = null_string */, CStrRef password /* = null_string */, bool new_link /* = false */) {
  throw NotImplementedException(__func__);
}

Variant f_mssql_pconnect(CStrRef server /* = null_string */, CStrRef username /* = null_string */, CStrRef password /* = null_string */, bool new_link /* = false */) {
  throw NotImplementedException(__func__);
}

bool f_mssql_close(CVarRef link_identifier /* = null */) {
  throw NotImplementedException(__func__);
}

bool f_mssql_select_db(CStrRef database_name /* = null */, CVarRef link_identifier /* = null */) {
  throw NotImplementedException(__func__);
}

Variant f_mssql_query(CStrRef query /* = null */, CVarRef link_identifier /* = null */, int64 batch_size /* = 0 */) {
  throw NotImplementedException(__func__);
}

Variant f_mssql_num_rows(CVarRef result /* = null */) {
  throw NotImplementedException(__func__);
}

Variant f_mssql_rows_affected(CVarRef result /* = null */) {
  throw NotImplementedException(__func__);
}

Variant f_mssql_fetch_row(CVarRef result /* = null */) {
  throw NotImplementedException(__func__);
}

Variant f_mssql_fetch_assoc(CVarRef result /* = null */) {
  throw NotImplementedException(__func__);
}

Variant f_mssql_free_result(CVarRef result /* = null */) {
  throw NotImplementedException(__func__);
}

Variant f_mssql_get_last_message() {
  throw NotImplementedException(__func__);
}


///////////////////////////////////////////////////////////////////////////////
}
