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


#ifndef PREPAREDSTATEMENT_INCLUDED
#define PREPAREDSTATEMENT_INCLUDED
#include <time.h>


/**
 * A <b>PreparedStatement</b> represent a single SQL statement pre-compiled 
 * into byte code for later execution. The SQL statement may contain 
 * <i>in</i> parameters of the form "?". Such parameters represent 
 * unspecified literal values (or "wildcards") to be filled in later by the 
 * various setter methods defined in this interface. Each <i>in</i> parameter has an
 * associated index number which is its sequence in the statement. The first 
 * <i>in</i> '?' parameter has index 1, the next has index 2 and so on. A 
 * PreparedStatement is created by calling Connection_prepareStatement().
 * 
 * Consider this statement: 
 * <pre>
 *  INSERT INTO employee(name, picture) VALUES(?, ?)
 * </pre>
 * There are two <i>in</i> parameters in this statement, the parameter for setting
 * the name has index 1 and the one for the picture has index 2. To set the 
 * values for the <i>in</i> parameters we use a setter method. Assuming name has
 * a string value we use PreparedStatement_setString(). To set the value
 * of the picture we submit a binary value using the 
 * method PreparedStatement_setBlob(). 
 *
 * Note that string and blob parameter values are set by reference and 
 * <b>must</b> not "disappear" before either PreparedStatement_execute()
 * or PreparedStatement_executeQuery() is called. 
 * 
 * <h3>Example:</h3>
 * To summarize, here is the code in context. 
 * <pre>
 * PreparedStatement_T p = Connection_prepareStatement(con, "INSERT INTO employee(name, picture) VALUES(?, ?)");
 * PreparedStatement_setString(p, 1, "Kamiya Kaoru");
 * PreparedStatement_setBlob(p, 2, jpeg, jpeg_size);
 * PreparedStatement_execute(p);
 * </pre>
 * <h3>Reuse:</h3>
 * A PreparedStatement can be reused. That is, the method 
 * PreparedStatement_execute() can be called one or more times to execute 
 * the same statement. Clients can also set new <i>in</i> parameter values and
 * re-execute the statement as shown in this example:
 * <pre>
 * PreparedStatement_T p = Connection_prepareStatement(con, "INSERT INTO employee(name, picture) VALUES(?, ?)");
 * for (int i = 0; employees[i].name; i++) 
 * {
 *        PreparedStatement_setString(p, 1, employees[i].name);
 *        PreparedStatement_setBlob(p, 2, employees[i].picture, employees[i].picture_size);
 *        PreparedStatement_execute(p);
 * }
 * </pre>
 * <h3>Result Sets:</h3>
 * Here is another example where we use a Prepared Statement to execute a query
 * which returns a Result Set:
 * 
 * <pre>
 * PreparedStatement_T p = Connection_prepareStatement(con, "SELECT id FROM employee WHERE name LIKE ?"); 
 * PreparedStatement_setString(p, 1, "%Kaoru%");
 * ResultSet_T r = PreparedStatement_executeQuery(p);
 * while (ResultSet_next(r))
 *        printf("employee.id = %d\n", ResultSet_getInt(r, 1));
 * </pre>
 * 
 * A ResultSet returned from PreparedStatement_executeQuery() "lives" until
 * the Prepared Statement is executed again or until the Connection is
 * returned to the Connection Pool. 
 *
 * <h3>Date and Time</h3>
 * PreparedStatement provides PreparedStatement_setTimestamp() for setting a
 * Unix timestamp value. To set SQL Date, Time or DateTime values, simply use
 * PreparedStatement_setString() with a time string format understood by your
 * database. For instance to set a SQL Date value,
 * <pre>
 *   PreparedStatement_setString(p, parameterIndex, "2013-12-28");
 * </pre>
 *
 * <i>A PreparedStatement is reentrant, but not thread-safe and should only be used by one thread (at the time).</i>
 * 
 * @see Connection.h ResultSet.h SQLException.h
 * @file
 */


#define T PreparedStatement_T
typedef struct PreparedStatement_S *T;


/** @name Parameters */
//@{

/**
 * Sets the <i>in</i> parameter at index <code>parameterIndex</code> to the 
 * given string value. 
 * @param P A PreparedStatement object
 * @param parameterIndex The first parameter is 1, the second is 2,..
 * @param x The string value to set. Must be a NUL terminated string. NULL
 * is allowed to indicate a SQL NULL value. 
 * @exception SQLException If a database access error occurs or if parameter 
 * index is out of range
 * @see SQLException.h
*/
void PreparedStatement_setString(T P, int parameterIndex, const char *x);


/**
 * Sets the <i>in</i> parameter at index <code>parameterIndex</code> to the
 * given int value. 
 * In general, on both 32 and 64 bits architecture, <code>int</code> is 4 bytes
 * or 32 bits and <code>long long</code> is 8 bytes or 64 bits. A
 * <code>long</code> type is usually equal to <code>int</code> on 32 bits
 * architecture and equal to <code>long long</code> on 64 bits architecture.
 * However, the width of integer types are architecture and compiler dependent.
 * The above is usually true, but not necessarily.
 * @param P A PreparedStatement object
 * @param parameterIndex The first parameter is 1, the second is 2,..
 * @param x The int value to set
 * @exception SQLException If a database access error occurs or if parameter
 * index is out of range
 * @see SQLException.h
 */
void PreparedStatement_setInt(T P, int parameterIndex, int x);


/**
 * Sets the <i>in</i> parameter at index <code>parameterIndex</code> to the 
 * given long long value. 
 * In general, on both 32 and 64 bits architecture, <code>int</code> is 4 bytes
 * or 32 bits and <code>long long</code> is 8 bytes or 64 bits. A
 * <code>long</code> type is usually equal to <code>int</code> on 32 bits
 * architecture and equal to <code>long long</code> on 64 bits architecture.
 * However, the width of integer types are architecture and compiler dependent.
 * The above is usually true, but not necessarily.
 * @param P A PreparedStatement object
 * @param parameterIndex The first parameter is 1, the second is 2,..
 * @param x The long long value to set
 * @exception SQLException If a database access error occurs or if parameter 
 * index is out of range
 * @see SQLException.h
 */
void PreparedStatement_setLLong(T P, int parameterIndex, long long x);


/**
 * Sets the <i>in</i> parameter at index <code>parameterIndex</code> to the 
 * given double value. 
 * @param P A PreparedStatement object
 * @param parameterIndex The first parameter is 1, the second is 2,..
 * @param x The double value to set
 * @exception SQLException If a database access error occurs or if parameter 
 * index is out of range
 * @see SQLException.h
 */
void PreparedStatement_setDouble(T P, int parameterIndex, double x);


/**
 * Sets the <i>in</i> parameter at index <code>parameterIndex</code> to the 
 * given blob value. 
 * @param P A PreparedStatement object
 * @param parameterIndex The first parameter is 1, the second is 2,..
 * @param x The blob value to set
 * @param size The number of bytes in the blob 
 * @exception SQLException If a database access error occurs or if parameter 
 * index is out of range
 * @see SQLException.h
 */
void PreparedStatement_setBlob(T P, int parameterIndex, const void *x, int size);


/**
 * Sets the <i>in</i> parameter at index <code>parameterIndex</code> to the
 * given Unix timestamp value. The timestamp value given in <code>x</code>
 * is expected to be in the GMT timezone. For instance, a value returned by
 * time(3) which represents the system's notion of the current Greenwich time.
 * <i class="textinfo">SQLite</i> does not have temporal SQL data types per se
 * and using this method with SQLite will store the timestamp value as a numerical
 * type as-is. This is usually what you want anyway, since it is fast, compact and
 * unambiguous.
 * @param P A PreparedStatement object
 * @param parameterIndex The first parameter is 1, the second is 2,..
 * @param x The GMT timestamp value to set. E.g. a value returned by time(3)
 * @exception SQLException If a database access error occurs or if parameter
 * index is out of range
 * @see SQLException.h ResultSet_getTimestamp
 */
void PreparedStatement_setTimestamp(T P, int parameterIndex, time_t x);

//@}

/**
 * Executes the prepared SQL statement, which may be an INSERT, UPDATE,
 * or DELETE statement or an SQL statement that returns nothing, such
 * as an SQL DDL statement. 
 * @param P A PreparedStatement object
 * @exception SQLException If a database error occurs
 * @see SQLException.h
 */
void PreparedStatement_execute(T P);


/**
 * Executes the prepared SQL statement, which returns a single ResultSet
 * object. A ResultSet "lives" only until the next call to a PreparedStatement 
 * method or until the Connection is returned to the Connection Pool. 
 * <i>This means that Result Sets cannot be saved between queries</i>.
 * @param P A PreparedStatement object
 * @return A ResultSet object that contains the data produced by the prepared
 * statement.
 * @exception SQLException If a database error occurs
 * @see ResultSet.h
 * @see SQLException.h
 */
ResultSet_T PreparedStatement_executeQuery(T P);


/**
 * Returns the number of rows that was inserted, deleted or modified by the
 * most recently completed SQL statement on the database connection. If used
 * with a transaction, this method should be called <i>before</i> commit is
 * executed, otherwise 0 is returned.
 * @param P A PreparedStatement object
 * @return The number of rows changed by the last (DIM) SQL statement
 */
long long PreparedStatement_rowsChanged(T P);


/** @name Properties */
//@{

/**
 * Returns the number of parameters in this prepared statement.
 * @param P A PreparedStatement object
 * @return The number of parameters in this prepared statement
 */
int PreparedStatement_getParameterCount(T P);

//@}

#undef T
#endif
