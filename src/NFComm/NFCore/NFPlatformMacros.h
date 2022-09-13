// -------------------------------------------------------------------------
//    @FileName         :    NFPlatformMacros.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// ------------------------------------------------------------------------

#pragma once

#define NF_PLATFORM_WIN 1
#define NF_PLATFORM_LINUX 2

#define NF_COMPILER_MSVC 1
#define NF_COMPILER_GNUC 2

#define NF_ENDIAN_LITTLE 1
#define NF_ENDIAN_BIG 2

#define NF_ARCHITECTURE_32 1
#define NF_ARCHITECTURE_64 2

/* Finds the compiler type and version.
*/
#if defined( _MSC_VER )
#   define NF_COMPILER NF_COMPILER_MSVC
#   define NF_COMP_VER _MSC_VER
#elif defined( __GNUC__ )
#   define NF_COMPILER NF_COMPILER_GNUC
#   define NF_COMP_VER (((__GNUC__)*100) + \
                        (__GNUC_MINOR__*10) + \
                        __GNUC_PATCHLEVEL__)
#else
#   pragma error "No known compiler. Abort! Abort!"
#endif

/* Finds the current platform */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined( __WIN32__ ) || defined( _WIN32 ) || defined(_WINDOWS) || defined(WIN) || defined(_WIN64) || defined( __WIN64__ )
#   define NF_PLATFORM NF_PLATFORM_WIN
//////////////////////////////////////////////////////////////////////////
#else
#   define NF_PLATFORM NF_PLATFORM_LINUX
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Find the arch type */
#if NF_PLATFORM == NF_PLATFORM_WIN

#if defined(_WIN64) || defined(__WIN64__)
#   define NF_ARCH_TYPE NF_ARCHITECTURE_64
#else
#   define NF_ARCH_TYPE NF_ARCHITECTURE_32
#endif

#elif NF_PLATFORM == NF_PLATFORM_LINUX

#if defined(__x86_64__)
#   define NF_ARCH_TYPE NF_ARCHITECTURE_64
#else
#   define NF_ARCH_TYPE NF_ARCHITECTURE_32
#endif

#endif

//----------------------------------------------------------------------------
// Windows Settings
#if NF_PLATFORM == NF_PLATFORM_WIN

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#endif

#pragma warning(disable:4091)
#include <Windows.h>
#define NF_EXPORT extern "C"  __declspec(dllexport)

#include <Dbghelp.h>

// Win32 compilers use _DEBUG for specifying debug builds.
// for MinGW, we set DEBUG
#   if defined(_DEBUG) || defined(DEBUG)
#       define NF_DEBUG_MODE 1
#   endif

//#define NF_STATIC_PLUGIN 1

#ifndef NF_STATIC_PLUGIN
#define NF_DYNAMIC_PLUGIN 1
#endif

// If we're not including this from a client build, specify that the stuff
// should get exported. Otherwise, import it.
#   if defined( NF_STATIC_PLUGIN )
// Linux compilers don't have symbol import/export directives.
#       define _NFExport
#       define _NFPrivate
#   else
#       if defined( NF_NONCLIENT_BUILD )
#           define _NFExport __declspec( dllexport )
#       else
#           if defined( __MINGW32__ )
#               define _NFExport
#           else
#               define _NFExport __declspec( dllimport )
#           endif
#       endif
#       define _NFPrivate
#   endif

// Disable unicode support on MingW for GCC 3, poorly supported in stdlibc++
// STLPORT fixes this though so allow if found
// MinGW C++ Toolkit supports unicode and sets the define __MINGW32_TOOLBOX_UNICODE__ in _mingw.h
// GCC 4 is also fine
#if defined(__MINGW32__)
# if NF_COMP_VER < 400
#  if !defined(_STLPORT_VERSION)
#   include<_mingw.h>
#   if defined(__MINGW32_TOOLBOX_UNICODE__) || NF_COMP_VER > 345
#    define NF_UNICODE_SUPPORT 1
#   else
#    define NF_UNICODE_SUPPORT 0
#   endif
#  else
#   define NF_UNICODE_SUPPORT 1
#  endif
# else
#  define NF_UNICODE_SUPPORT 1
# endif
#else
#  define NF_UNICODE_SUPPORT 1
#endif

#endif // NF_PLATFORM == NF_PLATFORM_WIN


//----------------------------------------------------------------------------
// Linux/Apple/iOs/Android/Symbian/Tegra2/NaCl Settings
#if NF_PLATFORM == NF_PLATFORM_LINUX

#if !defined(NF_GCC)
#if defined(__GNUC__)
#define NF_GCC 1
#else
#define NF_GCC 0
#endif
#endif // THERON_GCC

//#include <syswait.h>

//#define NF_STATIC_PLUGIN 1

#ifndef NF_STATIC_PLUGIN
#define NF_DYNAMIC_PLUGIN 1
#endif

// Enable GCC symbol visibility
#   if defined( NF_GCC_VISIBILITY )
#       define _NFExport  __attribute__ ((visibility("default")))
#       define _NFPrivate __attribute__ ((visibility("hidden")))
#   else
#       define _NFExport
#       define _NFPrivate
#   endif

// A quick define to overcome different names for the same function
#   define stricmp strcasecmp

// Unlike the Win32 compilers, Linux compilers seem to use DEBUG for when
// specifying a debug build.
// (??? this is wrong, on Linux debug builds aren't marked in any way unless
// you mark it yourself any way you like it -- zap ???)
#   if defined(_DEBUG) || defined(DEBUG)
#       define NF_DEBUG_MODE 1
#   endif

// Always enable unicode support for the moment
// Perhaps disable in old versions of gcc if necessary
#define NF_UNICODE_SUPPORT 1
#define MAX_PATH 255

#define NF_EXPORT extern "C" __attribute ((visibility("default")))

#endif

/* See if we can use __forceinline or if we need to use __inline instead */

#if !defined(NF_FORCEINLINE)
#if NF_DEBUG_MODE
#define NF_FORCEINLINE inline
#else // NF_DEBUG_MODE
#if NF_COMPILER == NF_COMPILER_MSVC
#   if NF_COMP_VER >= 1200
#       define NF_FORCEINLINE __forceinline
#   endif
#elif defined(__MINGW32__)
#   if !defined(NF_FORCEINLINE)
#       define NF_FORCEINLINE __inline
#   endif
#elif NF_GCC
#define NF_FORCEINLINE inline __attribute__((always_inline))
#else
#define NF_FORCEINLINE inline
#endif
#endif // THERON_DEBUG
#endif // THERON_FORCEINLINE

//----------------------------------------------------------------------------
// Endian Settings
// check for BIG_ENDIAN config flag, set NF_ENDIAN correctly
#ifdef NF_CONFIG_BIG_ENDIAN
#    define NF_ENDIAN NF_ENDIAN_BIG
#else
#    define NF_ENDIAN NF_ENDIAN_LITTLE
#endif

