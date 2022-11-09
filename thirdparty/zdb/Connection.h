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


#ifndef CONNECTION_INCLUDED
#define CONNECTION_INCLUDED


/**
 * A <b>Connection</b> represent a connection to a SQL database system.
 *
 * Use a Connection to execute SQL statements. There are three ways to
 * execute statements: Connection_execute() is used to execute SQL
 * statements that does not return a result set. Such statements are INSERT,
 * UPDATE or DELETE.  Connection_executeQuery() is used to execute a SQL 
 * SELECT statement and return a result set. These methods can only handle
 * values which can be expressed as C-strings. If you need to handle binary
 * data, such as inserting a blob value into the database, use a 
 * PreparedStatement object to execute the SQL statement. The factory method
 * Connection_prepareStatement() is used to obtain a PreparedStatement object. 
 *
 * The method Connection_executeQuery() will return an empty ResultSet (not null)
 * if the SQL statement did not return any values.  A ResultSet lives until the
 * next call to Connection execute or until the Connection is returned
 * to the Connection Pool. If an error occur during execution, an SQLException
 * is thrown.
 *
 * Any SQL statement that changes the database (basically, any SQL
 * command other than SELECT) will automatically start a transaction
 * if one is not already in effect. Automatically started transactions
 * are committed at the conclusion of the command.
 *
 * Transactions can also be started manually using 
 * Connection_beginTransaction(). Such transactions usually persist
 * until the next call to Connection_commit() or Connection_rollback().
 * A transaction will also rollback if the database is closed or if an 
 * error occurs. Nested transactions are not allowed.
 *
 * <i>A Connection is reentrant, but not thread-safe and should only be used by one thread (at the time).</i>
 *
 * @see ResultSet.h PreparedStatement.h SQLException.h
 * @file
 */


#define T Connection_T
typedef struct Connection_S *T;


/** @name Properties */
//@{

/**
 * Sets the number of milliseconds the Connection should wait for a
 * SQL statement to finish if the database is busy. If the limit is
 * exceeded, then the <code>execute</code> methods will return
 * immediately with an error. The default timeout is <code>3
 * seconds</code>.
 * @param C A Connection object
 * @param ms The query timeout limit in milliseconds; zero means
 * there is no limit
 */
void Connection_setQueryTimeout(T C, int ms);


/**
 * Retrieves the number of milliseconds the Connection will wait for a
 * SQL statement object to execute.
 * @param C A Connection object
 * @return The query timeout limit in milliseconds; zero means there
 * is no limit
 */
int Connection_getQueryTimeout(T C);


/**
 * Sets the limit for the maximum number of rows that any ResultSet
 * object can contain. If the limit is exceeded, the excess rows 
 * are silently dropped.
 * @param C A Connection object
 * @param max The new max rows limit; 0 means there is no limit
 */
void Connection_setMaxRows(T C, int max);


/**
 * Retrieves the maximum number of rows that a ResultSet object
 * produced by this Connection object can contain. If this limit is
 * exceeded, the excess rows are silently dropped.
 * @param C A Connection object
 * @return The new max rows limit; 0 means there is no limit
 */
int Connection_getMaxRows(T C);


/**
 * Returns this Connection URL
 * @param C A Connection object
 * @return This Connection URL
 * @see URL.h
 */
URL_T Connection_getURL(T C);

//@}

/**
 * Ping the database server and returns true if this Connection is 
 * alive, otherwise false in which case the Connection should be closed. 
 * @param C A Connection object
 * @return true if Connection is connected to a database server 
 * otherwise false
 */
int Connection_ping(T C);


/**
 * Close any ResultSet and PreparedStatements in the Connection. 
 * Normally it is not necessary to call this method, but for some
 * implementation (SQLite) it <i>may, in some situations,</i> be 
 * necessary to call this method if a execution sequence error occurs.
 * @param C A Connection object
 */
void Connection_clear(T C);


/**
 * Return connection to the connection pool. The same as calling 
 * ConnectionPool_returnConnection() on a connection.
 * @param C A Connection object
 */
void Connection_close(T C);


/**
 * Start a transaction. 
 * @param C A Connection object
 * @exception SQLException If a database error occurs
 * @see SQLException.h
 */
void Connection_beginTransaction(T C);


/**
 * Makes all changes made since the previous commit/rollback permanent
 * and releases any database locks currently held by this Connection
 * object.
 * @param C A Connection object
 * @exception SQLException If a database error occurs
 * @see SQLException.h
 */
void Connection_commit(T C);


/**
 * Undoes all changes made in the current transaction and releases any
 * database locks currently held by this Connection object. This method
 * will first call Connection_clear() before performing the rollback to
 * clear any statements in progress such as selects.
 * @param C A Connection object
 * @exception SQLException If a database error occurs
 * @see SQLException.h
 */
void Connection_rollback(T C);


/**
 * Returns the value for the most recent INSERT statement into a 
 * table with an AUTO_INCREMENT or INTEGER PRIMARY KEY column.
 * @param C A Connection object
 * @return The value of the rowid from the last insert statement
 */
long long Connection_lastRowId(T C);


/**
 * Returns the number of rows that was inserted, deleted or modified
 * by the last Connection_execute() statement. If used with a
 * transaction, this method should be called <i>before</i> commit is
 * executed, otherwise 0 is returned.
 * @param C A Connection object
 * @return The number of rows changed by the last (DIM) SQL statement
 */
long long Connection_rowsChanged(T C);


/**
 * Executes the given SQL statement, which may be an INSERT, UPDATE,
 * or DELETE statement or an SQL statement that returns nothing, such
 * as an SQL DDL statement. Several SQL statements can be used in the
 * sql parameter string, each separated with the <i>;</i> SQL
 * statement separator character. <b>Note</b>, calling this method
 * clears any previous ResultSets associated with the Connection.
 * @param C A Connection object
 * @param sql A SQL statement
 * @exception SQLException If a database error occurs. 
 * @see SQLException.h
 */
void Connection_execute(T C, const char *sql, ...) __attribute__((format (printf, 2, 3)));


/**
 * Executes the given SQL statement, which returns a single ResultSet
 * object. You may <b>only</b> use one SQL statement with this method.
 * This is different from the behavior of Connection_execute() which
 * executes all SQL statements in its input string. If the sql
 * parameter string contains more than one SQL statement, only the
 * first statement is executed, the others are silently ignored.
 * A ResultSet "lives" only until the next call to
 * Connection_executeQuery(), Connection_execute() or until the 
 * Connection is returned to the Connection Pool. <i>This means that 
 * Result Sets cannot be saved between queries</i>.
 * @param C A Connection object
 * @param sql A SQL statement
 * @return A ResultSet object that contains the data produced by the
 * given query. 
 * @exception SQLException If a database error occurs. 
 * @see ResultSet.h
 * @see SQLException.h
 */
ResultSet_T Connection_executeQuery(T C, const char *sql, ...) __attribute__((format (printf, 2, 3)));


/**
 * Creates a PreparedStatement object for sending parameterized SQL 
 * statements to the database. The <code>sql</code> parameter may 
 * contain IN parameter placeholders. An IN placeholder is specified 
 * with a '?' character in the sql string. The placeholders are 
 * then replaced with actual values by using the PreparedStatement's 
 * setXXX methods. Only <i>one</i> SQL statement may be used in the sql 
 * parameter, this in difference to Connection_execute() which may 
 * take several statements. A PreparedStatement "lives" until the 
 * Connection is returned to the Connection Pool. 
 * @param C A Connection object
 * @param sql A single SQL statement that may contain one or more '?' 
 * IN parameter placeholders
 * @return A new PreparedStatement object containing the pre-compiled
 * SQL statement.
 * @exception SQLException If a database error occurs. 
 * @see PreparedStatement.h
 * @see SQLException.h
 */
PreparedStatement_T Connection_prepareStatement(T C, const char *sql, ...) __attribute__((format (printf, 2, 3)));


/**
 * This method can be used to obtain a string describing the last
 * error that occurred. Inside a CATCH-block you can also find
 * the error message directly in the variable Exception_frame.message.
 * It is recommended to use this variable instead since it contains both
 * SQL errors and API errors such as parameter index out of range etc, 
 * while Connection_getLastError() might only show SQL errors
 * @param C A Connection object
 * @return A string explaining the last error
 */
const char *Connection_getLastError(T C);


/** @name Class methods */
//@{

/**
 * <b>Class method</b>, test if the specified database system is 
 * supported by this library. Clients may pass a full Connection URL, 
 * for example using URL_toString(), or for convenience only the protocol
 * part of the URL. E.g. "mysql" or "sqlite".
 * @param url A database url string
 * @return true if supported otherwise false
 */
int Connection_isSupported(const char *url);

// @}

#undef T
#endif
