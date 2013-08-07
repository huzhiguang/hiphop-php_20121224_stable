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

#include <test/test_ext_mongodb.h>
#include <runtime/ext/ext_mongodb.h>

IMPLEMENT_SEP_EXTENSION_TEST(Mongodb);
///////////////////////////////////////////////////////////////////////////////

bool TestExtMongodb::RunTests(const std::string &which) {
  bool ret = true;

  RUN_TEST(test_Mongo);
  RUN_TEST(test_MongoDB);
  RUN_TEST(test_MongoCollection);
  RUN_TEST(test_MongoCursor);
  RUN_TEST(test_MongoDate);

  return ret;
}

///////////////////////////////////////////////////////////////////////////////

bool TestExtMongodb::test_Mongo() {
  return Count(true);
}

bool TestExtMongodb::test_MongoDB() {
  return Count(true);
}

bool TestExtMongodb::test_MongoCollection() {
  return Count(true);
}

bool TestExtMongodb::test_MongoCursor() {
  return Count(true);
}

bool TestExtMongodb::test_MongoDate() {
  return Count(true);
}
