#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <lua.h>

#ifndef LUA_EXTERN
# if defined(WIN32) || defined(_WIN32)
	/*  Building shared library. */
#   define LUA_EXTERN __declspec(dllexport)
# elif __GNUC__ >= 4
#  define LUA_EXTERN __attribute__((visibility("default")))
# else
#  define LUA_EXTERN /* nothing */
# endif
#endif

LUA_EXTERN int luaopen_gen_pb (lua_State *L);

#ifdef __cplusplus
}
#endif
