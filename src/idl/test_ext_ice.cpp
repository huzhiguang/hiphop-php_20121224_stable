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
#include <runtime/ext/ext_ice.h>

IMPLEMENT_SEP_EXTENSION_TEST(Ice);
///////////////////////////////////////////////////////////////////////////////

bool TestExtIce::RunTests(const std::string &which) {
  bool ret = true;

  RUN_TEST(test_ice_initialize);
  RUN_TEST(test_icephp_defineproxy);
  RUN_TEST(test_icephp_declareclass);
  RUN_TEST(test_icephp_defineexception);
  RUN_TEST(test_create_typeinfobyid);
  RUN_TEST(test_icephp_stringifyexception);
  RUN_TEST(test_icephp_stringify);
  RUN_TEST(test_icephp_definesequence);
  RUN_TEST(test_icephp_defineclass);
  RUN_TEST(test_icephp_defineoperation);
  RUN_TEST(test_ice_find);
  RUN_TEST(test_ice_register);
  RUN_TEST(test_ICE);
  RUN_TEST(test_Proxy);
  RUN_TEST(test_IcePHP_class);
  RUN_TEST(test_TypeInfo);

  return ret;
}

///////////////////////////////////////////////////////////////////////////////

bool TestExtIce::test_ice_initialize() {
  return Count(true);
}

bool TestExtIce::test_icephp_defineproxy() {
  return Count(true);
}

bool TestExtIce::test_icephp_declareclass() {
  return Count(true);
}

bool TestExtIce::test_icephp_defineexception() {
  return Count(true);
}

bool TestExtIce::test_create_typeinfobyid() {
  return Count(true);
}

bool TestExtIce::test_icephp_stringifyexception() {
  return Count(true);
}

bool TestExtIce::test_icephp_stringify() {
  return Count(true);
}

bool TestExtIce::test_icephp_definesequence() {
  return Count(true);
}

bool TestExtIce::test_icephp_defineclass() {
  return Count(true);
}

bool TestExtIce::test_icephp_defineoperation() {
  return Count(true);
}

bool TestExtIce::test_ice_find() {
  return Count(true);
}

bool TestExtIce::test_ice_register() {
  return Count(true);
}

bool TestExtIce::test_ICE() {
  return Count(true);
}

bool TestExtIce::test_Proxy() {
  return Count(true);
}

bool TestExtIce::test_IcePHP_class() {
  return Count(true);
}

bool TestExtIce::test_TypeInfo() {
  return Count(true);
}
