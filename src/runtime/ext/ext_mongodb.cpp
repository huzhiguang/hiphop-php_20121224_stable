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

#include <runtime/ext/ext_mongodb.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////
//
//common function
//
///////////////////////////////////////////////////////////////////////////////
void bson_append_value(bson *bson_obj, const char *key, Variant value) {
	if (value.isString()) {
		bson_append_string(bson_obj, key, value.toString().data());
	} else if (value.isInteger()) {
		bson_append_int(bson_obj, key, value.toInt32());
	} else if (value.isDouble()) {
		bson_append_double(bson_obj, key, value.toDouble());
	} else if ( value.isBoolean() ) {
		bson_append_bool( bson_obj, key, value.toBoolean());
	} else if (value.isArray()) {
		bson_append_start_object(bson_obj, key);
		for (ArrayIter iter(value); iter; ++iter) {
			Variant key = iter.first();
			Variant val = iter.second();
			if ("$in" == key.toString()) {
				bson_append_start_array(bson_obj, "$in");
				bson_append_value(bson_obj, key.toString().data(), val);
				bson_append_finish_array(bson_obj);
			} else {
				bson_append_value(bson_obj, key.toString().data(), val);
			}
		}
		bson_append_finish_object(bson_obj);
	}
}

void array2basebson(bson* bson, CArrRef arr) {
	for (ArrayIter iter(arr); iter; ++iter) {
		Variant key = iter.first();
		Variant val = iter.second();
		bson_append_value(bson, key.toString().data(), val);
	}
}

//class MongoArray : public Array {
//	String toString () const { 
//		printf( "MongoArray: toString....\n\n" ) ;
//		return m_px ? "Array2" : "";
//	}
//
//} ;

void findraw_to_array(mongo_cursor *cursor, Array& array_value) {
	while (mongo_cursor_next(cursor) == MONGO_OK) {
		bson_iterator i;
		const bson *b = &cursor->current;

		/** debug:
		fprintf( stderr, "    result = \n") ;
		bson_print(b) ;
		 */

		Array cursor_raw;
		bson_iterator_from_buffer(&i, b->data);
		while (bson_iterator_next(&i)) {
			const char *key;
			char oidhex[25];
			bson scope;
			bson_timestamp_t ts;
			bson_type t = bson_iterator_type(&i);
			if (t == 0)
				break;
			key = bson_iterator_key(&i);
			string key_string = key;
			Variant key_variant(key_string);
			string char_to_string_tmp;
			switch (t) {
			case BSON_DOUBLE:
				cursor_raw.set(key_variant, Variant(bson_iterator_double(&i)));
				break;
			case BSON_STRING: {
				char_to_string_tmp = bson_iterator_string(&i);
				cursor_raw.set(key_variant, Variant(char_to_string_tmp));
				break;
			}
			case BSON_SYMBOL:
				break;
			case BSON_OID: {
				bson_oid_to_string(bson_iterator_oid(&i), oidhex);
				char_to_string_tmp = oidhex;
					

				//Variant mongoIdObj ;
				Array mongoIdObj ;
				mongoIdObj.set("$id", char_to_string_tmp) ;

				cursor_raw.set(key_variant, mongoIdObj);
				break;
			}
			case BSON_BOOL:
				cursor_raw.set(key_variant, Variant(bson_iterator_bool(&i)));
				break;
			case BSON_DATE: {
				time_t time_value = bson_iterator_time_t(&i);
				cursor_raw.set(key_variant, Variant(time_value));
				c_MongoDate *mongoDate = NEWOBJ(c_MongoDate);
				mongoDate->m_sec = time_value;
				mongoDate->m_usec = time_value * 1000000;
				cursor_raw.set(key_variant, mongoDate);
				break;
			}
			case BSON_BINDATA:
				break;
			case BSON_UNDEFINED:
				break;
			case BSON_NULL:
				cursor_raw.set(key_variant, Variant(""));
				break;
			case BSON_REGEX:
				break;
			case BSON_CODE:
				break;
			case BSON_CODEWSCOPE:
				bson_iterator_code_scope(&i, &scope);
				break;
			case BSON_INT:
				cursor_raw.set(key_variant, Variant(bson_iterator_int(&i)));
				break;
			case BSON_LONG:
				cursor_raw.set(key_variant, Variant((uint64) bson_iterator_long(&i)));
				break;
			case BSON_TIMESTAMP:
				ts = bson_iterator_timestamp(&i);
				break;
			case BSON_OBJECT:
			case BSON_ARRAY:
				break;
			default:
				break ;
			}
		}
		array_value.append(cursor_raw);
	}
}

///////////////////////////////////////////////////////////////////////////////
//
// class c_Mongo
//
///////////////////////////////////////////////////////////////////////////////


char *c_Mongo::server_spec = NULL ;
mongo_con_manager *c_Mongo::manager = NULL ;
mongo_replica_set *c_Mongo::servers = NULL ;



c_Mongo::c_Mongo(const ObjectStaticCallbacks *cb) :
		ExtObjectDataFlags<ObjectData::UseGet>(cb)
		, m_conn(NULL) {

}
c_Mongo::~c_Mongo() {
}

static pthread_mutex_t server_spec_mutex = PTHREAD_MUTEX_INITIALIZER ;


void c_Mongo::t___construct(CStrRef server, CVarRef options) {
  INSTANCE_METHOD_INJECTION_BUILTIN(Mongo, Mongo::__construct);
  /** to avoid synchronizing data every time.*/
	while ( NULL == c_Mongo::server_spec || 0 != strcmp(server.data(), c_Mongo::server_spec) ) {
		pthread_mutex_lock( &server_spec_mutex) ;
		while ( NULL == c_Mongo::server_spec || 0 != strcmp(server.data(), c_Mongo::server_spec) ) {
				// fprintf( stderr, "\n#debug 1: c_Mongo::t__construct() .... server.data() = %s, c_Mongo::server_spec = %s\n", server.data(), c_Mongo::server_spec ) ; // debug
				const char *new_server_spec = server.data() ;
	
				/** Reset c_Mongo::server_spec */
				unsigned int len_new = strlen(new_server_spec) ;
				if (NULL == c_Mongo::server_spec || len_new > strlen(c_Mongo::server_spec) ) {
  INSTANCE_METHOD_INJECTION_BUILTIN(Mongo, Mongo::_construct);
  c_Mongo::server_spec = (char *)realloc( c_Mongo::server_spec,  len_new+1 ) ;
				}
				unsigned int len_cur = strlen(c_Mongo::server_spec) ;
				memset( c_Mongo::server_spec, 0, len_new > len_cur ? len_new : len_cur ) ;
				memcpy( c_Mongo::server_spec, new_server_spec, len_new+1 ) ;
				// fprintf( stderr, "#debug 2: c_Mongo::t__construct() .... server.data() = %s, c_Mongo::server_spec = %s\n", server.data(), c_Mongo::server_spec ) ; // debug
	
	
				/** Reset c_Mongo::manager */
				if ( NULL != c_Mongo::manager ) {
  INSTANCE_METHOD_INJECTION_BUILTIN(Mongo, Mongo::_construct);
  mongo_manager_deinit( c_Mongo::manager ) ;
				}
				c_Mongo::manager = mongo_manager_init() ;
	
	
				/** Reset c_Mongo::servers */
				if ( NULL != c_Mongo::servers ) {
					mongo_replica_set_deinit( c_Mongo::servers ) ;
				} else {
					c_Mongo::servers = mongo_replica_set_init() ;
				}
				
				/** set timeout */
				int timeout = 1000;
				for (ArrayIter iter(options); iter; ++iter) {
					Variant k = iter.first();
					Variant v = iter.second();
					if (k == "timeout") {
						timeout = v.toInt64Val();
					}
				}
				mongo_replica_set_op_timeout( c_Mongo::servers, timeout) ;
	
				/** parse server spec */
				char *error_message;
				mongo_parse_server_spec( c_Mongo::manager, c_Mongo::servers, c_Mongo::server_spec, (char **)&error_message) ;
	
				/** select primary server */
				mongo_replica_set_find_primary( c_Mongo::manager,  c_Mongo::servers ) ;
		}
		pthread_mutex_unlock( &server_spec_mutex ) ;
	}

	if ( c_Mongo::servers ) {
		m_conn = mongo_replica_set_client( c_Mongo::manager,  c_Mongo::servers ) ;
		if ( m_conn && MONGO_CONN_SUCCESS != m_conn->err) {
			switch ( (int)m_conn->err ) {
				case MONGO_CONN_NO_SOCKET:  raise_error( "no socket" ); 		break;
				case MONGO_CONN_FAIL:       raise_error( "connection failed" ); break;
				case MONGO_CONN_NOT_MASTER: raise_error( "not master" ); 		break;
				case MONGO_CONN_TIMEOUT  :  raise_error("connect timeout");	break;
				case MONGO_NO_LISTEN_ADDR:  raise_error("No one listening on the remote address*");break;
			}
			free( m_conn ) ;
			m_conn = NULL ;	
		}
	//	fprintf( stderr, " #debug: mongo_conn->err = %d\n", m_conn->err) ;
	}
}

Variant c_Mongo::t___destruct() {
  INSTANCE_METHOD_INJECTION_BUILTIN(Mongo, Mongo::__destruct);
  return null;
}
Variant c_Mongo::t___get(Variant val) {
  INSTANCE_METHOD_INJECTION_BUILTIN(Mongo, Mongo::__get);
  if ( val && ( KindOfStaticString == val.getType() || KindOfString == val.getType() ) ) {
		c_MongoDB* mongoDb = NEWOBJ(c_MongoDB);
		mongoDb->m_dbname =  new String(val.toString()) ;
		mongoDb->m_mongo = this;
		return mongoDb;
	}

	return null;
}
Variant c_Mongo::t_selectdb(CStrRef name) {
  INSTANCE_METHOD_INJECTION_BUILTIN(Mongo, Mongo::selectdb);
  if ( NULL == m_conn) {
		return null ;
	}

	c_MongoDB* mongoDb = NEWOBJ(c_MongoDB);
	mongoDb->m_dbname =  new String(name) ;
	mongoDb->m_mongo = this;
	return mongoDb;
}

bool c_Mongo::t_close() {
  INSTANCE_METHOD_INJECTION_BUILTIN(Mongo, Mongo::close);
  return false;
}

///////////////////////////////////////////////////////////////////////////////
//
// c_MongoDB
//
///////////////////////////////////////////////////////////////////////////////
c_MongoDB::c_MongoDB(const ObjectStaticCallbacks *cb) :
		ExtObjectDataFlags<ObjectData::UseGet>(cb), m_dbname(NULL),
		m_mongo(NULL) {
}

c_MongoDB::~c_MongoDB() {
	if ( m_dbname ) {
		//m_dbname->clear();
		delete m_dbname ;
		m_dbname = NULL;
	}
}

void c_MongoDB::t___construct(CObjRef db, CStrRef name) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoDB, MongoDB::__construct);
}

Variant c_MongoDB::t___get(Variant name) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoDB, MongoDB::__get);
  if ( name && ( KindOfStaticString == name.getType() || KindOfString == name.getType() ) ) {
		c_MongoCollection* mongoCollection = NEWOBJ(c_MongoCollection);
		mongoCollection->m_colname = new String( name.toString() ) ;
		mongoCollection->m_db = this;
		return mongoCollection ;
	}
	return null ;
}

Variant c_MongoDB::t_selectcollection(CStrRef name) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoDB, MongoDB::selectcollection);
  c_MongoCollection* mongoCollection = NEWOBJ(c_MongoCollection);
	mongoCollection->m_colname = new String(name) ;
	mongoCollection->m_db = this;
	return mongoCollection ;
}

Variant c_MongoDB::t___destruct() {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoDB, MongoDB::__destruct);
  return null ;
}

///////////////////////////////////////////////////////////////////////////////
//
// c_MongoCollection
//
///////////////////////////////////////////////////////////////////////////////
c_MongoCollection::c_MongoCollection(const ObjectStaticCallbacks *cb) :
		ExtObjectData(cb), m_colname(NULL), m_db(NULL) {
}

c_MongoCollection::~c_MongoCollection() {
	if (NULL != m_colname) {
		//m_colname->clear();
		delete m_colname ;
		m_colname = NULL;
	}
	if (NULL != m_db) {
		m_db = NULL;
	}
}

void c_MongoCollection::t___construct(CObjRef db, CStrRef name) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCollection, MongoCollection::__construct);
  return ;
}

Variant c_MongoCollection::t___destruct() {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCollection, MongoCollection::__destruct);
  return null;
}

Variant c_MongoCollection::t_find(CArrRef query, CArrRef fields) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCollection, MongoCollection::find);
  if ( NULL == m_db->m_mongo->m_conn) {
		return null ;
	}

	c_MongoCursor* tmp_cursor = NEWOBJ(c_MongoCursor);
	tmp_cursor->m_query_array = query ;
	tmp_cursor->m_col = this ;

	bson* bson_query = tmp_cursor->m_query_bson ;
	bson_init(bson_query) ;
	array2basebson(bson_query, tmp_cursor->m_query_array );
	bson_finish(bson_query);

	String ns = *(m_db->m_dbname) + "." + *(m_colname);
	
	// debug: printf(" #log: ns = %s, m_db->m_dbname = %s, m_colname = %s\n", ns.data(), m_db->m_dbname->data(), m_colname->data()) ;

	/** mongo_cursor */
	mongo_cursor* cursor = tmp_cursor->m_mongo_cursor ;
	mongo_cursor_init( cursor, m_db->m_mongo->m_conn, ns.data() );


	/** filter fields */
	if ( !fields.isNull() && fields.size() > 0 ) {
		tmp_cursor->m_fields_array = fields ;
		bson* bson_fields = tmp_cursor->m_fields_bson ;
		bson_init(bson_fields) ;

		array2basebson( bson_fields, tmp_cursor->m_fields_array );
		bson_finish( bson_fields );
		mongo_cursor_set_fields( cursor, bson_fields ) ;

		/** debug:
		fprintf(stderr, "	## bson_fields = \n");
		bson_print(bson_fields);
		 */
	}

	return tmp_cursor;
}

///////////////////////////////////////////////////////////////////////////////
//
// c_MongoCursor
//
///////////////////////////////////////////////////////////////////////////////
c_MongoCursor::c_MongoCursor(const ObjectStaticCallbacks *cb) :
		ExtObjectData(cb),
		m_isLoad(false), m_position(0),m_array(null), m_limit(0), m_skip(0), m_batchSize(0) {

	m_mongo_cursor = mongo_cursor_create() ;
	m_query_bson = bson_create() ;
	m_order_bson = bson_create() ;
	m_fields_bson = bson_create() ;

}

c_MongoCursor::~c_MongoCursor() {

	if ( !m_array.isNull() ) {
		m_array.clear() ;
	}

	if ( !m_query_array.isNull() ) {
		m_query_array.clear() ;
	}

	if ( !m_fields_array.isNull() ) {
		m_fields_array.clear() ;
	}

	if ( m_query_bson ) {
		bson_destroy( m_query_bson ) ;
		bson_dispose( m_query_bson ) ;
		m_query_bson = NULL ;
	}


	if ( m_order_bson ) {
		bson_destroy( m_order_bson ) ;
		bson_dispose( m_order_bson ) ;
		m_order_bson = NULL ;
	}

	if (m_fields_bson) {
		bson_destroy( m_fields_bson ) ;
		bson_dispose( m_fields_bson ) ;
		m_fields_bson = NULL ;
	}

	if ( NULL != m_mongo_cursor ) {
		mongo_cursor_destroy( m_mongo_cursor ) ;
		mongo_cursor_dispose( m_mongo_cursor ) ;
		m_mongo_cursor = NULL ;
	}
}

void c_MongoCursor::t___construct(CObjRef connection, CStrRef ns, CArrRef query, CArrRef fields) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCursor, MongoCursor::__construct);
  return ;
}

Variant c_MongoCursor::t___destruct() {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCursor, MongoCursor::__destruct);
  return null;
}

Variant c_MongoCursor::t_current() {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCursor, MongoCursor::current);
  return m_array.rvalAt((int64)m_position, AccessFlags::Error);
}

int64 c_MongoCursor::t_key() {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCursor, MongoCursor::key);
  return m_position;
}

void c_MongoCursor::t_next() {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCursor, MongoCursor::next);
  ++m_position;
	return ;
}

void c_MongoCursor::t_rewind() {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCursor, MongoCursor::rewind);
  m_position = 0LL;

	if ( !m_isLoad ) {
		m_isLoad = true ;
		if ( m_order_bson && m_order_bson->dataSize > 0 ) {
			mongo_cursor_set_query( m_mongo_cursor, m_order_bson );
			/** debug:
			fprintf( stderr, "    ## bson_orderby = \n") ;
			bson_print( m_order_bson) ;
			 */
		} else {
			mongo_cursor_set_query( m_mongo_cursor, m_query_bson );
			/** debug:
			fprintf(stderr, "	## bson_query = \n");
			bson_print( m_query_bson );
			*/
		}

		/** fetch data by iterating cursor */
		findraw_to_array(m_mongo_cursor, m_array);
	}
}

bool c_MongoCursor::t_valid() {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCursor, MongoCursor::valid);
  return isset(m_array, (int64)m_position);
}

Object c_MongoCursor::t_limit(int64 num) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCursor, MongoCursor::limit);
  m_limit = (uint32)num ;
	mongo_cursor_set_limit( m_mongo_cursor, num) ;
	return this;
}

Variant c_MongoCursor::t_sort(CArrRef fields) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCursor, MongoCursor::sort);
  if ( m_query_bson && m_query_bson->dataSize > 0 ) {
		bson* bson_orderby = m_order_bson ;
		bson_init( bson_orderby ) ;
			bson_append_bson( bson_orderby, "$query", m_query_bson) ;
			bson_append_start_object( bson_orderby, "$orderby") ;
				array2basebson( bson_orderby, fields );
			bson_append_finish_object( bson_orderby ) ;
		bson_finish( bson_orderby ) ;
	}
	return null;
}

Variant c_MongoCursor::t_skip(int num) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCursor, MongoCursor::skip);
  mongo_cursor_set_skip( m_mongo_cursor, num) ;
	m_skip = (uint32)num ;
	return null;
}

/** Returns the namespace, limit, skip, query, and fields for this cursor. */
Array c_MongoCursor::t_info() {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoCursor, MongoCursor::info);
  Array arrInfo = Array::Create();
	String ns = *(m_col->m_db->m_dbname) + "." + *(m_col->m_colname);

	arrInfo.set( "ns", Variant(ns) ) ;
	arrInfo.set( "limit", Variant((uint64)m_limit) ) ;
	arrInfo.set( "batchSize", Variant((uint64)m_batchSize) ) ;
	arrInfo.set( "skip", Variant((uint64)m_skip) ) ;
	arrInfo.set( "flags", Variant( m_mongo_cursor->options) ) ;
	arrInfo.set( "query", Variant(m_query_array) ) ;
	arrInfo.set( "fields", Variant(m_fields_array) ) ;


	if ( m_mongo_cursor->flags & MONGO_CURSOR_QUERY_SENT ) {
		arrInfo.set( "started_iterating", 1 ) ;	
		arrInfo.set( "id", m_mongo_cursor->reply->fields.cursorID ) ;
		arrInfo.set( "at", m_position) ;
		arrInfo.set( "numReturned", m_mongo_cursor->reply->fields.num ) ;
		arrInfo.set( "server", m_mongo_cursor->conn->hash ) ;
	} else {
		arrInfo.set( "started_iterating", 0 ) ;	
	}


	return arrInfo;
}

///////////////////////////////////////////////////////////////////////////////
//
// c_MongoDate
//
///////////////////////////////////////////////////////////////////////////////
c_MongoDate::c_MongoDate(const ObjectStaticCallbacks *cb) :
		ExtObjectDataFlags<ObjectData::UseGet | ObjectData::UseSet>(cb) {
}
c_MongoDate::~c_MongoDate() {

}

void c_MongoDate::t___construct(int64 sec, int64 usec) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoDate, MongoDate::__construct);
  return;
}

Variant c_MongoDate::t___get(Variant val) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoDate, MongoDate::__get);
  if(val.same("sec")){
		return Variant(m_sec);
	}else if(val.same("usec")){
		return Variant(m_usec);
	}
	return null;
}
Variant c_MongoDate::t___set(Variant name, Variant value) {
  INSTANCE_METHOD_INJECTION_BUILTIN(MongoDate, MongoDate::__set);
  return null;
}




///////////////////////////////////////////////////////////////////////////////
}
