/*
 * Copyright (C) Tildeslash Ltd. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 *
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.
 */


#ifndef CONNECTIONPOOL_INCLUDED
#define CONNECTIONPOOL_INCLUDED


/**
 * A <b>ConnectionPool</b> represent a database connection pool.
 *
 * A connection pool can be used to get a connection to a database and
 * execute statements. This class opens a number of database
 * connections and allow callers to obtain and use a database connection in
 * a reentrant manner. Applications can instantiate as many ConnectionPool
 * objects as needed and against as many different database systems as needed.
 * The following diagram gives an overview of the library's components and
 * their method-associations:
 *
 *  <center><img src="database.png"></center>
 *
 * The method ConnectionPool_getConnection() is used to obtain a new
 * connection from the pool. If there are no connections available a new
 * connection is created and returned. If the pool has already handed out
 * <i>maxConnections</i> Connections, the next call to 
 * ConnectionPool_getConnection() will return NULL. Use Connection_close()
 * to return a connection to the pool so it can be reused.
 *
 * A connection pool is created default with 5 initial connections and 
 * with 20 maximum connections. These values can be changed by the property 
 * methods ConnectionPool_setInitialConnections() and 
 * ConnectionPool_setMaxConnections(). 
 *
 * <h2>Supported database systems:</h2>
 * This library may be built with support for many different database 
 * systems. To test if a particular system is supported use the method 
 * Connection_isSupported().  
 *
 * <h2>Life-cycle methods:</h2>
 * Clients should call ConnectionPool_start() to establish the connection pool 
 * against the database server before using the pool. To shutdown 
 * connections from the database server use ConnectionPool_stop(). Set
 * preferred properties <em>before</em> calling ConnectionPool_start(). Some 
 * properties can also be changed dynamically after the pool was started such as
 * changing the maximum number of connections or the number of initial connections. 
 * Changing and tuning these properties at runtime is most useful if the pool was 
 * started with a reaper-thread (see below) since the reaper dynamically change the
 * size of the pool
 
 *
 * <h2>Connection URL:</h2>
 * The URL given to a Connection Pool at creation time specify a database 
 * connection on the standard URL format. The format of the connection URL 
 * is defined as:
 *
 * \htmlonly
 * <center><code>
 * database://[user:password@][host][:port]/database[?propertyName1][=propertyValue1][&propertyName2][=propertyValue2]...
 * </code></center>
 * \endhtmlonly
 * 
 * The property names <code>user</code> and <code>password</code> are always
 * recognized and specify how to login to the database. Other properties 
 * depends on the database server in question. User name and password can 
 * alternatively be specified in the auth-part of the URL. If port number is 
 * omitted, the default port number for the database server is used.
 *
 * <h4>MySQL:</h4>
 *
 * Here is an example on how to connect to a <a href="http://www.mysql.org/">
 * MySQL</a> database server:
 *
 * \htmlonly
 * <dt><dd><code>
 * mysql://localhost:3306/test?user=root&password=swordfish<br/>
 * </code></dd></dt>
 * \endhtmlonly
 *
 * In this case the username, <code>root</code> and password, <code>swordfish
 * </code> are specified as properties to the URL. An alternative is to 
 * use the auth-part of the URL to specify authentication information:
 *
 * \htmlonly
 * <dt><dd><code>
 * mysql://root:swordfish@localhost:3306/test
 * </code></dd></dt>
 * \endhtmlonly
 *
 * See <a href="mysqloptions.html">mysql options</a> for all properties that
 * can be set for a mysql connection URL.
 *
 * <h4>SQLite:</h4>
 *
 * For a <a href="http://www.sqlite.org/">SQLite</a> database the connection 
 * URL should simply specify a database file, since a SQLite database 
 * is just a file in the filesystem. SQLite uses 
 * <a href="http://sqlite.org/pragma.html">pragma commands</a> for 
 * performance tuning and other special purpose database commands. Pragma 
 * syntax on the form, <code>name=value</code> can be added as properties 
 * to the URL and will be set when the Connection is created. In addition 
 * to pragmas, the following properties are supported:
 * <ul>
 * <li><code>heap_limit=value</code> - Make SQLite auto-release unused memory 
 * if memory usage goes above the specified value [KB].</li> 
 * </ul>
 * An URL for 
 * connecting to a SQLite database might look like:
 *
 * \htmlonly
 * <dt><dd><code>
 * sqlite:///var/sqlite/test.db?synchronous=normal&heap_limit=8000&foreign_keys=on
 * </code></dd></dt>
 * \endhtmlonly
 *
 * <h4>PostgreSQL:</h4>
 *
 * The URL for connecting to a <a href="http://www.postgresql.org/">
 * PostgreSQL</a> database server might look like:
 *
 * \htmlonly
 * <dt><dd><code>
 * postgresql://localhost:5432/test?user=root&password=swordfish<br/>
 * </code></dd></dt>
 * \endhtmlonly
 *
 * As with the MySQL URL, the username and password are specified as 
 * properties to the URL. Likewise, the auth-part of the URL can be used 
 * instead to specify the username and the password:
 *
 * \htmlonly
 * <dt><dd><code>
 * postgresql://root:swordfish@localhost/test?use-ssl=true
 * </code></dd></dt>
 * \endhtmlonly
 * 
 * In this example we have also omitted the port number to the server, in
 * which case the default port number, <i>5432</i>, for PostgreSQL is used. In
 * addition we have added an extra parameter to the URL, so connection to 
 * the server is done over a secure SSL connection.
 *
 * See <a href="postgresoptions.html">postgresql options</a> for all properties that
 * can be set for a postgresql connection URL.
 *
 * <h4>Oracle:</h4>
 *
 * The URL for connecting to an <a href="http://www.oracle.com/">
 * Oracle</a> database server might look like:
 *
 * \htmlonly
 * <dt><dd><code>
 * oracle://localhost:1521/test?user=scott&password=tiger<br/>
 * </code></dd></dt>
 * \endhtmlonly
 *
 * The auth-part of the URL can be used instead to specify the username 
 * and the password. In addition, you may specify a service name in the URL
 * instead if you have setup a <code>tnsnames.ora</code> configuration file.
 *
 * \htmlonly
 * <dt><dd><code>
 * oracle:///servicename?user=scott&password=tiger
 * </code></dd></dt>
 * \endhtmlonly
 *  
 * <h2>Example:</h2>
 * To obtain a connection pool for a MySQL database, the code below can be
 * used. The exact same code can be used for PostgreSQL, SQLite and Oracle, 
 * the only change needed is to modify the Connection URL. Here we connect
 * to the database test on localhost and start the pool with the default 5
 * initial connections.
 *
 * \htmlonly
 * <dt><dd><code>
 * <pre>
 * URL_T url = URL_new("mysql://localhost/test?user=root&password=swordfish");
 * ConnectionPool_T pool = ConnectionPool_new(url);
 * ConnectionPool_start(pool);
 * [..]
 * <b>Connection_T con = ConnectionPool_getConnection(pool);</b>
 * ResultSet_T result = Connection_executeQuery(con, "select id, name, image from employee where salary>%d", anumber);
 * while (ResultSet_next(result)) 
 * {
 *      int id = ResultSet_getInt(result, 1);
 *      const char *name = ResultSet_getString(result, 2);
 *      int blobSize;
 *      const void *image = ResultSet_getBlob(result, 3, &blobSize);
 *      [..]
 * }
 * <b>Connection_close(con);</b>
 * [..]
 * ConnectionPool_free(&pool);
 * URL_free(&url);
 * </pre>
 * </code></dd></dt>
 * \endhtmlonly
 * 
 * <h2>Optimizing the pool size:</h2>
 * The pool can be setup to dynamically change the number of active 
 * Connections in the pool depending on the load. A single <code>reaper</code> 
 * thread can be activated at startup to sweep through the pool at a regular
 * interval and close Connections that have been inactive for a specified time
 * or for some reasons no longer respond. Only inactive Connections will be closed
 * and no more than the initial number of Connections the pool was started with
 * are closed. The property method, ConnectionPool_setReaper(), is used to specify
 * that a reaper thread should be started when the pool is started. This method 
 * <strong>must</strong> be called <i>before</i> ConnectionPool_start(), otherwise 
 * the pool will not start with a reaper thread.
 * 
 * Clients can also call the method, ConnectionPool_reapConnections(), to
 * bonsai the pool directly if the reaper thread is not activated.
 *
 * It is recommended to start the pool with a reaper-thread, especially if
 * the pool maintains TCP/IP Connections.
 *
 * <h2>Realtime inspection:</h2>
 * Two methods can be used to inspect the pool at runtime. The method 
 * ConnectionPool_size() returns the number of connections in the pool, that is,
 * both active and inactive connections. The method ConnectionPool_active() 
 * returns the number of active connections, i.e. those connections in 
 * current use by your application. 
 *
 * <i>This ConnectionPool is thread-safe.</i>
 *
 * @see Connection.h ResultSet.h URL.h PreparedStatement.h SQLException.h
 * @file
 */


#define T ConnectionPool_T
typedef struct ConnectionPool_S *T;

/**
 * Library Debug flag. If set to true, emit debug output 
 */
extern int ZBDEBUG;


/**
 * Create a new ConnectionPool. The pool is created with default 5
 * initial connections. Maximum connections is set to 20. Property
 * methods in this interface can be used to change the default values.
 * @param url The database connection url. It is a checked runtime error
 * for the url parameter to be NULL.
 * @return A new ConnectionPool object
 * @see URL.h
 */
T ConnectionPool_new(URL_T url);


/**
 * Disconnect and destroy the pool and release allocated resources.
 * @param P A ConnectionPool object reference
 */
void ConnectionPool_free(T *P);

/** @name Properties */
//@{

/**
 * Returns this Connection Pool URL
 * @param P A ConnectionPool object
 * @return This Connection Pool URL
 * @see URL.h
 */
URL_T ConnectionPool_getURL(T P);


/**
 * Set the number of initial connections to start the pool with
 * @param P A ConnectionPool object
 * @param connections The number of initial pool connections
 * @see Connection.h
 */
void ConnectionPool_setInitialConnections(T P, int connections);


/**
 * Get the number of initial connections to start the pool with
 * @param P A ConnectionPool object
 * @return The number of initial pool connections
 * @see Connection.h
 */
int ConnectionPool_getInitialConnections(T P);


/**
 * Set the maximum number of connections this connection pool will
 * create. If max connections has been served, ConnectionPool_getConnection()
 * will return NULL on the next call. 
 * @param P A ConnectionPool object
 * @param maxConnections The maximum number of connections this
 * connection pool will create. It is a checked runtime error for
 * maxConnections to be less than initialConnections.
 * @see Connection.h
 */
void ConnectionPool_setMaxConnections(T P, int maxConnections);


/**
 * Get the maximum number of connections this Connection pool will create. 
 * @param P A ConnectionPool object
 * @return The maximum number of connections this connection pool will create.
 * @see Connection.h
 */
int ConnectionPool_getMaxConnections(T P);


/**
 * Set a Connection inactive timeout value in seconds. The method,
 * ConnectionPool_reapConnections(), if called will close inactive 
 * Connections in the pool which has not been in use since 
 * <code>connectionTimeout</code> seconds. Default connectionTimeout is 
 * 30 seconds. The reaper thread if in use, see ConnectionPool_setReaper(), 
 * also use this value when closing inactive Connections. It is a 
 * checked runtime error for <code>connectionTimeout</code> to be less than, 
 * or equal to zero.
 * @param P A ConnectionPool object
 * @param connectionTimeout The number of <code>seconds</code> a Connection 
 * can be inactive, i.e. not in use, before the reaper close the Connection. 
 * (value > 0)
 */
void ConnectionPool_setConnectionTimeout(T P, int connectionTimeout);


/**
 * Returns the connection timeout value in seconds. 
 * @param P A ConnectionPool object
 * @return The time an inactive Connection may live before it is closed
 */
int ConnectionPool_getConnectionTimeout(T P);


/**
 * Set the function to call if a fatal error occurs in the library. In 
 * practice this means Out-Of-Memory errors or uncatched exceptions.
 * Clients may optionally provide this function. If not provided
 * the library will call <code>abort(3)</code> upon encountering a 
 * fatal error if ZBDEBUG is set, otherwise exit(1) is called. This
 * method provide clients with means to close down execution gracefully.
 * It is an unchecked runtime error to continue using the library after 
 * the <code>abortHandler</code> was called.
 * @param P A ConnectionPool object
 * @param abortHandler The handler function to call should a fatal 
 * error occur during processing. An explanatory error message is passed 
 * to the handler function in the string <code>error</code>
 * @see Exception.h
 */
void ConnectionPool_setAbortHandler(T P, void(*abortHandler)(const char *error));


/**
 * Specify that a reaper thread should be used by the pool. This thread 
 * will close all inactive Connections in the pool, down to initial 
 * connections. An inactive Connection is closed if and only if its 
 * <code>connectionTimeout</code> has expired <i>or</i> if the Connection
 * failed the ping test. Active Connections, that is, connections in current
 * use by your application are <i>never </i> closed by this thread. This 
 * method sets the reaper thread sweep property, but does not start the
 * thread. This is done in ConnectionPool_start(). So, if the pool should 
 * use a reaper thread, remember to call this method <b>before</b> 
 * ConnectionPool_start(). It is a checked runtime error for 
 * <code>sweepInterval</code> to be less than, or equal to zero.
 * @param P A ConnectionPool object
 * @param sweepInterval Number of <code>seconds</code> between sweeps of the 
 * reaper thread (value > 0) 
 */
void ConnectionPool_setReaper(T P, int sweepInterval);


/**
 * Returns the current number of connections in the pool. The number of 
 * both active and inactive connections are returned.
 * @param P A ConnectionPool object
 * @return The number of connections in the pool
 */
int ConnectionPool_size(T P);


/**
 * Returns the number of active connections in the pool. I.e. connections
 * in use by clients.
 * @param P A ConnectionPool object
 * @return The number of active connections in the pool
 */
int ConnectionPool_active(T P);

//@}

/**
 * Prepare for the beginning of active use of this component. This method
 * must be called before the pool is used and will connect to the database
 * server and create the initial connections for the pool. This method will
 * also start the reaper thread if specified via ConnectionPool_setReaper().
 * @param P A ConnectionPool object
 * @exception SQLException If a database error occurs.
 * @see SQLException.h
 */
void ConnectionPool_start(T P);


/**
 * Gracefully terminate the active use of the public methods of this
 * component. This method should be the last one called on a given instance
 * of this component. Calling this method close down all connections in the 
 * pool, disconnect the pool from the database server and stop the reaper
 * thread if it was started.
 * @param P A ConnectionPool object
 */
void ConnectionPool_stop(T P);


/**
 * Get a connection from the pool
 * @param P A ConnectionPool object
 * @return A connection from the pool or NULL if maxConnection is reached
 * @see Connection.h
 */
Connection_T ConnectionPool_getConnection(T P);


/**
 * Returns a connection to the pool. The same as calling Connection_close()
 * @param P A ConnectionPool object
 * @param connection A Connection object
 * @see Connection.h
 */
void ConnectionPool_returnConnection(T P, Connection_T connection);


/**
 * Close all inactive Connections in the pool, down to initial connections. 
 * Inactive Connection are closed if and only if its 
 * <code>connectionTimeout</code> has expired <i>or</i> if the Connection 
 * failed the ping test against the database. Active Connections are 
 * <i>not</i> closed by this method. 
 * @param P A ConnectionPool object
 * @return The number of Connections that was closed
 */
int ConnectionPool_reapConnections(T P);


/** @name Class methods */
//@{

/**
 * <b>Class method</b>, returns this library version information 
 * @return Library version information
 */
const char *ConnectionPool_version(void);

// @}

#undef T
#endif
