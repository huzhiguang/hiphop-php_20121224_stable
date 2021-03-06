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

#ifndef __EXT_MONGODB_H__
#define __EXT_MONGODB_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<
#define MONGO_HAVE_STDINT 1;
#include <runtime/base/base_includes.h>
#include "mongodb_c_liulei/mongo.h"
#include <pthread.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/**
 * generate bson object
 */
void bson_append_value(bson *bson_obj,const char *key,Variant value) ;

/**
 * translate array to bson
 */
void array2basebson(bson* bson, CArrRef arr) ;

/**
 bson to Array
 */
void findraw_to_array(mongo_cursor *cursor, Array &array_value) ;

///////////////////////////////////////////////////////////////////////////////
// class Mongo

FORWARD_DECLARE_CLASS_BUILTIN(Mongo);
class c_Mongo : public ExtObjectDataFlags<ObjectData::UseGet>, public Sweepable {
	public:
		mongo *m_conn ;
		static mongo_con_manager* manager ;
		static mongo_replica_set *servers ;
		static char* server_spec ;
//		Mutex m_mutex ;
		pthread_mutex_t *m_lock ;
 public:
  DECLARE_CLASS(Mongo, Mongo, ObjectData)

  // need to implement
  public: c_Mongo(const ObjectStaticCallbacks *cb = &cw_Mongo);
  public: ~c_Mongo();
  public: void t___construct(CStrRef server = "mongodb://localhost:27017", CVarRef options = null);
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t___get(Variant val);
  DECLARE_METHOD_INVOKE_HELPERS(__get);
  public: Variant t_selectdb(CStrRef name);
  DECLARE_METHOD_INVOKE_HELPERS(selectdb);
  public: Variant t___destruct();
  DECLARE_METHOD_INVOKE_HELPERS(__destruct);
  public: bool t_close();
  DECLARE_METHOD_INVOKE_HELPERS(close);

  // implemented by HPHP
  public: c_Mongo *create(String server = "mongodb://localhost:27017", Variant options = null);

};

///////////////////////////////////////////////////////////////////////////////
// class MongoDB
///////////////////////////////////////////////////////////////////////////////
FORWARD_DECLARE_CLASS_BUILTIN(MongoDB);
class c_MongoDB : public ExtObjectDataFlags<ObjectData::UseGet>, public Sweepable {
	public:
		String* m_dbname ;
		c_Mongo* m_mongo ;
 public:
  DECLARE_CLASS(MongoDB, MongoDB, ObjectData)

  // need to implement
  public: c_MongoDB(const ObjectStaticCallbacks *cb = &cw_MongoDB);
  public: ~c_MongoDB();
  public: void t___construct(CObjRef conn, CStrRef name);
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t___get(Variant name);
  DECLARE_METHOD_INVOKE_HELPERS(__get);
  public: Variant t_selectcollection(CStrRef name);
  DECLARE_METHOD_INVOKE_HELPERS(selectcollection);
  public: Variant t___destruct();
  DECLARE_METHOD_INVOKE_HELPERS(__destruct);

  // implemented by HPHP
  public: c_MongoDB *create(Object conn, String name);

};

///////////////////////////////////////////////////////////////////////////////
// class MongoCollection
///////////////////////////////////////////////////////////////////////////////
FORWARD_DECLARE_CLASS_BUILTIN(MongoCollection);
class c_MongoCollection : public ExtObjectData, public Sweepable {
	public:
		String* m_colname ;
		c_MongoDB* m_db ;
 public:
  DECLARE_CLASS(MongoCollection, MongoCollection, ObjectData)

  // need to implement
  public: c_MongoCollection(const ObjectStaticCallbacks *cb = &cw_MongoCollection);
  public: ~c_MongoCollection();
  public: void t___construct(CObjRef db, CStrRef name);
  DECLARE_METHOD_INVOKE_HELPERS(__construct);

  /**
   @param fields Fields of the results to return. The array is in the format array('fieldname' => true, 'fieldname2' => true). The _id field is always returned.
   */
  public: Variant t_find(CArrRef query = null_array, CArrRef fields = null_array);
  DECLARE_METHOD_INVOKE_HELPERS(find);
  public: Variant t___destruct();
  DECLARE_METHOD_INVOKE_HELPERS(__destruct);

  // implemented by HPHP
  public: c_MongoCollection *create(Object db, String name);

};

///////////////////////////////////////////////////////////////////////////////
//
// class MongoCursor
//
///////////////////////////////////////////////////////////////////////////////
FORWARD_DECLARE_CLASS_BUILTIN(MongoCursor);
class c_MongoCursor : public ExtObjectData, public Sweepable {
	public:
		c_MongoCollection* m_col ;

		/** whether have fetched data from mongodb server */
		bool m_isLoad ;

		/** m_position */
		uint64 m_position;

		/** received data for iterating */
		Array m_array;

		/** mongo query condition */
		Array m_query_array ;

		/** for info function*/
		Array m_fields_array ;

		/** query condition */
		bson *m_query_bson ;

		bson *m_order_bson ;
		bson *m_fields_bson ;

		/** mongo cursor */
		mongo_cursor *m_mongo_cursor ;

		/** info: namespace, limit, skip, query, and fields for this cursor*/
		uint32 m_limit ;
		uint32 m_skip ;
		uint32 m_batchSize ;


 public:
  DECLARE_CLASS(MongoCursor, MongoCursor, ObjectData)

  // need to implement
  public: c_MongoCursor(const ObjectStaticCallbacks *cb = &cw_MongoCursor);
  public: ~c_MongoCursor();
  public: void t___construct(CObjRef connection, CStrRef ns, CArrRef query = null_array, CArrRef fields = null_array);
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t_current();
  DECLARE_METHOD_INVOKE_HELPERS(current);
  public: int64 t_key();
  DECLARE_METHOD_INVOKE_HELPERS(key);
  public: void t_next();
  DECLARE_METHOD_INVOKE_HELPERS(next);
  public: void t_rewind();
  DECLARE_METHOD_INVOKE_HELPERS(rewind);
  public: bool t_valid();
  DECLARE_METHOD_INVOKE_HELPERS(valid);
  public: Object t_limit(int64 num);
  DECLARE_METHOD_INVOKE_HELPERS(limit);
  public: Variant t_sort(CArrRef fields);
  DECLARE_METHOD_INVOKE_HELPERS(sort);
  public: Variant t_skip(int num);
  DECLARE_METHOD_INVOKE_HELPERS(skip);
  public: Array t_info();
  DECLARE_METHOD_INVOKE_HELPERS(info);
  public: Variant t___destruct();
  DECLARE_METHOD_INVOKE_HELPERS(__destruct);

  // implemented by HPHP
  public: c_MongoCursor *create(Object connection, String ns, Array query = null_array, Array fields = null_array);

};

///////////////////////////////////////////////////////////////////////////////
// class MongoDate

FORWARD_DECLARE_CLASS_BUILTIN(MongoDate);
class c_MongoDate : public ExtObjectDataFlags<ObjectData::UseGet|ObjectData::UseSet> {
 public:
  DECLARE_CLASS(MongoDate, MongoDate, ObjectData)

  // properties
  public: int64 m_sec;
  public: int64 m_usec;

  // need to implement
  public: c_MongoDate(const ObjectStaticCallbacks *cb = &cw_MongoDate);
  public: ~c_MongoDate();
  public: void t___construct(int64 sec, int64 usec);
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t___get(Variant val);
  DECLARE_METHOD_INVOKE_HELPERS(__get);
  public: Variant t___set(Variant name, Variant value);
  DECLARE_METHOD_INVOKE_HELPERS(__set);

  // implemented by HPHP
  public: c_MongoDate *create(int64 sec, int64 usec);
  public: static const ClassPropTable os_prop_table;

};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXT_MONGODB_H__
