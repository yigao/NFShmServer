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


#ifndef URL_INCLUDED
#define URL_INCLUDED


/**
 * <b>URL</b> represent an immutable Uniform Resource Locator. 
 * A Uniform Resource Locator (URL), is used to uniquely identify a
 * resource on the Internet. The URL is a compact text string with a
 * restricted syntax that consists of four main components:
 * <center><code>
 * &lt;protocol&gt;://&lt;authority&gt;&lt;path&gt;?&lt;query&gt;
 * </code></center>
 *
 * The &lt;protocol&gt; part is mandatory, the other components may or
 * may not be present in an URL string. For instance the
 * <code>file</code> protocol only use the path component while a
 * <code>http</code> protocol may use all components. Here is an
 * example where all components are used:
 *
 * <pre>
 * http://user:password@www.foo.bar:8080/document/index.csp?querystring#ref
 * </pre>
 *
 * The following URL components are automatically unescaped according to the escaping
 * mechanism defined in RFC 2396; <code>credentials</code>, <code>path</code> and parameter
 * <code>values</code>.
 *
 * An <i>IPv6 address</i> can be used for host as defined in
 * <a href="http://www.ietf.org/rfc/rfc2732.txt">RFC2732</a> by enclosing the 
 * address in [brackets]. For instance, mysql://[2010:836B:4179::836B:4179]:3306/test
 *
 * For more information about the URL syntax and specification, see,
 * <a href="ftp://ftp.rfc-editor.org/in-notes/rfc2396.txt">RFC2396 -
 * Uniform Resource Identifiers (URI): Generic Syntax</a>
 *
 * @file
 */


#define T URL_T
typedef struct URL_S *T;


/**
 * Create a new URL object from the <code>url</code> parameter
 * string. The url string <i>must</i> start with a protocol
 * specifier, such as <code>http://</code> or <code>ftp://</code>
 * @param url A string specifying the URL
 * @return A URL object or NULL if the <code>url</code> parameter
 * cannot be parsed as an URL.
 */
T URL_new(const char *url);


/**
 * Factory method for building an URL object using a variable argument
 * list. <i>Important</i>: since the '%%' character is used as a format
 * specifier (e.g. %%s for string, %%d for integer and so on),
 * submitting an URL escaped string (i.e. a %%HEXHEX encoded string)
 * in the <code>url</code> parameter can produce undesired results. In
 * this case, use either the URL_new() method or URL_unescape() the
 * <code>url</code> parameter first.
 * @param url A string specifying the URL
 * @return A URL object or NULL if the <code>url</code> parameter
 * cannot be parsed as an URL.
 */
T URL_create(const char *url, ...) __attribute__((format (printf, 1, 2)));


/**
 * Destroy a URL object. 
 * @param U A URL object reference
 */
void URL_free(T *U);


/** @name Properties */
//@{

/**
 * Get the protocol of the URL.
 * @param U An URL object
 * @return The protocol name
 */
const char *URL_getProtocol(T U);


/**
 * Get the user name from the authority part of the URL.
 * @param U An URL object
 * @return A username specified in the URL or NULL if not found
 */
const char *URL_getUser(T U);


/**
 * Get the password from the authority part of the URL.
 * @param U An URL object
 * @return A password specified in the URL or NULL if not found
 */
const char *URL_getPassword(T U);


/**
 * Get the hostname of the URL.
 * @param U An URL object
 * @return The hostname of the URL or NULL if not found
 */
const char *URL_getHost(T U);


/**
 * Get the port of the URL.
 * @param U An URL object
 * @return The port number of the URL or -1 if not specified
 */
int URL_getPort(T U);


/**
 * Get the path of the URL.
 * @param U An URL object
 * @return The path of the URL or NULL if not found
 */
const char *URL_getPath(T U);


/**
 * Get the query string of the URL. 
 * @param U An URL object
 * @return The query string of the URL or NULL if not found
 */
const char *URL_getQueryString(T U);


/**
 * Returns an array of string objects with the names of the
 * parameters contained in this URL. If the URL has no parameters, 
 * the method returns NULL. The last value in the array is NULL.
 * To print all parameter names and their values contained in this 
 * URL, the following code can be used:
 * <pre>
 *   const char **params = URL_getParameterNames(U);
 *   if (params) 
 *           for (int i = 0; params[i]; i++)
 *                   printf("%s = %s\n", params[i], URL_getParameter(U, params[i]));
 * </pre>
 * @param U An URL object
 * @return An array of string objects, each string containing the name
 * of a URL parameter; or NULL if the URL has no parameters
 */
const char **URL_getParameterNames(T U);


/**
 * Returns the value of a URL parameter as a string, or NULL if
 * the parameter does not exist. If you use this method with a 
 * multi-valued parameter, the value returned is the first value found. 
 * Lookup is <i>case-sensitive</i>.
 * @param U An URL object
 * @param name The parameter name to lookup
 * @return The parameter value or NULL if not found
 */
const char *URL_getParameter(T U, const char *name);

//@}


/**
 * Returns a string representation of this URL object
 * @param U An URL object
 * @return The URL string
 */
const char *URL_toString(T U);


/** @name Class methods */
//@{

/**
 * <b>Class method</b>, unescape an url string. The <code>url</code>
 * parameter is modified by this method.
 * @param url an escaped url string
 * @return A pointer to the unescaped <code>url</code> string
 */
char *URL_unescape(char *url);


/**
 * <b>Class method</b>, escape an url string converting unsafe 
 * characters to a hex (%%HEXHEX) representation. The following URL unsafe
 * characters are encoded: <pre><>\"#%%{}|\\^ [] `</pre> as well as 
 * characters in the interval 00-1F hex (0-31 decimal) and in the interval
 * 7F-FF (127-255 decimal) <i>The caller must free the returned string.</i> 
 * If the <code>url</code> parameter is NULL then this method returns NULL, 
 * if it is the empty string "" a <i>new</i> empty string is returned.
 * @param url an url string
 * @return the escaped string
 */
char *URL_escape(const char *url);

// @}

#undef T
#endif
