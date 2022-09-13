/*
** $Id: lualib.h,v 1.45 2017/01/12 17:14:26 roberto Exp $
** Lua standard libraries
** See Copyright Notice in lua.h
*/


#ifndef lualib_h
#define lualib_h

#include "lua.h"


/* version suffix for environment variable names */
#define LUA_VERSUFFIX          "_" LUA_VERSION_MAJOR "_" LUA_VERSION_MINOR


LUAMOD_API int (luaopen_base) (lua_State *L);

#define LUA_COLIBNAME	"coroutine"
LUAMOD_API int (luaopen_coroutine) (lua_State *L);

#define LUA_TABLIBNAME	"table"
LUAMOD_API int (luaopen_table) (lua_State *L);

#define LUA_IOLIBNAME	"io"
LUAMOD_API int (luaopen_io) (lua_State *L);

#define LUA_OSLIBNAME	"os"
LUAMOD_API int (luaopen_os) (lua_State *L);

#define LUA_STRLIBNAME	"string"
LUAMOD_API int (luaopen_string) (lua_State *L);

#define LUA_UTF8LIBNAME	"utf8"
LUAMOD_API int (luaopen_utf8) (lua_State *L);

#define LUA_BITLIBNAME	"bit32"
LUAMOD_API int (luaopen_bit32) (lua_State *L);

#define LUA_MATHLIBNAME	"math"
LUAMOD_API int (luaopen_math) (lua_State *L);

#define LUA_DBLIBNAME	"debug"
LUAMOD_API int (luaopen_debug) (lua_State *L);

#define LUA_LOADLIBNAME	"package"
LUAMOD_API int (luaopen_package) (lua_State *L);

#define LUA_CJSONLIBNAME "cjson"  
LUALIB_API int (luaopen_cjson) (lua_State *L);

#define LUA_LPEG "lpeg"  
LUALIB_API int (luaopen_lpeg) (lua_State *L);

#define LUA_LUALFS "luaopen_lfs"
LUALIB_API int (luaopen_lfs)(lua_State *L);

#define LUA_LUAGENPB "gen_pb"
LUALIB_API int (luaopen_gen_pb)(lua_State *L);

#define LUA_LUA_PB_IO "pb_io"
LUALIB_API int (luaopen_pb_io)(lua_State *L);

#define LUA_LUA_PB_CONV "pb_conv"
LUALIB_API int (luaopen_pb_conv)(lua_State *L);

#define LUA_LUA_PB_BUFFER "pb_buffer"
LUALIB_API int (luaopen_pb_buffer)(lua_State *L);

#define LUA_LUA_PB_SLICE "pb_slice"
LUALIB_API int (luaopen_pb_slice)(lua_State *L);

#define LUA_LUA_PB "pb"
LUALIB_API int (luaopen_pb)(lua_State *L);

#define LUA_LUA_PB_UNSAFE "pb_unsafe"
LUALIB_API int (luaopen_pb_unsafe)(lua_State *L);

/* open all previous libraries */
LUALIB_API void (luaL_openlibs) (lua_State *L);



#if !defined(lua_assert)
#define lua_assert(x)	((void)0)
#endif


#endif
