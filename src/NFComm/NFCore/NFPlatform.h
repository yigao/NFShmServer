// -------------------------------------------------------------------------
//    @FileName         :    NFPlatform.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// ------------------------------------------------------------------------
#pragma once

#include "NFMacros.h"
#include "NFPlatformMacros.h"

#include <stdint.h>
#include <chrono>
#include <string>
#include <memory>
#include <stdio.h>
#include <string>
#include <thread>

#include "common/spdlog/fmt/fmt.h"

using namespace std;

#ifndef NDEBUG
#include <assert.h>
#define NF_ASSERT(condition)					if (!(condition)) NFAssertFail(__FILE__, __LINE__); else { }
#define NF_ASSERT_MSG(condition, msg)			if (!(condition)) NFAssertFail(__FILE__, __LINE__, msg); else { }

inline void NFAssertFail(const char*const file, const unsigned int line, const std::string& message = std::string())
{
	fprintf(stderr, "FAIL in %s (%d)", file, line);
	if (!message.empty())
	{
		fprintf(stderr, ": %s", message.c_str());
	}

	fprintf(stderr, "\n");
	assert(false);
}
#else
#define NF_ASSERT(condition)
#define NF_ASSERT_MSG(condition, msg_)
#endif

#define NF_ASSERT_RET_VAL(exp_, val)   \
    do                                  \
    {                                   \
        if ((exp_)) break;              \
        assert(exp_);                   \
        return val;                     \
    } while (0);

#define NF_ASSERT_BREAK(exp_)          \
    if (!(exp_))                        \
    {                                   \
        assert(exp_);                   \
        break;                          \
    }                                   \
    else {}

#define NF_ASSERT_CONTINUE(exp_)       \
    if (!(exp_))                        \
    {                                   \
        assert(exp_);                   \
        continue;                       \
    }                                   \
    else {}

#define NF_ASSERT_RET_NONE(exp_)       \
    do                                  \
    {                                   \
        if ((exp_)) break;              \
        assert(exp_);                   \
        return;                         \
    } while (0);

#define NF_ASSERT_NO_EFFECT(exp_)      \
    do                                  \
    {                                   \
        if (exp_) break;                \
        assert(exp_);                   \
    } while(0);

#define NF_CHECK(EXPRESSION) \
  NF_ASSERT_MSG(EXPRESSION, "CHECK failed: " #EXPRESSION)

#define NF_CHECK_EQ(A, B) NF_CHECK((A) == (B))
#define NF_CHECK_NE(A, B) NF_CHECK((A) != (B))
#define NF_CHECK_LT(A, B) NF_CHECK((A) <  (B))
#define NF_CHECK_LE(A, B) NF_CHECK((A) <= (B))
#define NF_CHECK_GT(A, B) NF_CHECK((A) >  (B))
#define NF_CHECK_GE(A, B) NF_CHECK((A) >= (B)

//#define GOOGLE_GLOG_DLL_DECL=

///////////////////////////////////////////////////////////////
#include <string>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <sstream>
#include <stdio.h>

#ifndef _MSC_VER
#include <sys/time.h>
#include <unistd.h>
#define EPOCHFILETIME 11644473600000000ULL
#else
#include <windows.h>
#include <time.h>
#include <process.h>
#define EPOCHFILETIME 11644473600000000Ui64
#endif

#if NF_PLATFORM == NF_PLATFORM_WIN
#define __WORDSIZE 64
#define NFSPRINTF sprintf_s
#define NFSTRICMP stricmp
#define NFGetPID() getpid()
typedef unsigned int NF_THREAD_ID;

inline NF_THREAD_ID ThreadId()
{
	return GetCurrentThreadId();
}

inline struct tm* localtime_r(const time_t* timep, struct tm* result)
{
	localtime_s(result, timep);
	return result;
}

#define strcasecmp   _stricmp
#define strncasecmp  _strnicmp
#else
#define NFSPRINTF snprintf
#define NFSTRICMP strcasecmp

#define NFGetPID() getpid()
typedef unsigned long int NF_THREAD_ID;
inline NF_THREAD_ID ThreadId()
{
	return pthread_self();
}
#endif

#define NFSLEEP(us) std::this_thread::sleep_for(std::chrono::microseconds(us));

//use actor mode--begin
#define NF_ACTOR_THREAD_COUNT 3
#define NF_DEFAULT_MYSQL_DB_NAME "proto_ff"

#ifndef NF_USE_ACTOR
#define NF_USE_ACTOR
#endif

#ifdef NF_USE_ACTOR

#ifdef NF_DEBUG_MODE
#define THERON_DEBUG 1
#else
#define THERON_DEBUG 0
#endif

#ifndef THERON_CPP11
#define THERON_CPP11 1
#endif

#ifndef NF_ENABLE_SSL
#define NF_ENABLE_SSL 1
#endif

#ifndef USE_NET_EVPP
#define USE_NET_EVPP
#endif

#endif
//use actor mode--end

#define GET_CLASS_NAME(className) (#className)

#define NF_SHARE_PTR std::shared_ptr

#define NF_NEW new

#define  NF_SAFE_DELETE(pData) { try { delete pData; } catch (...) { NF_ASSERT_MSG(false, "NFSafeDelete error"); } pData=NULL; }

inline int64_t NFGetTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

inline int64_t NFGetSecondTime()
{
	return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

inline int64_t NFGetMicroSecondTime()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

inline int64_t NFGetNanoSeccondTime()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

//
#ifndef NF_CASE_STRING_BIGIN
#define NF_CASE_STRING_BIGIN(state) switch(state){
#define NF_CASE_STRING(state) case state:return #state;break;
#define NF_CASE_STRING_END()  default:return "Unknown";break;}
#endif

#ifndef NF_FUNCTION_LINE
#define NF_FUNCTION_LINE __FUNCTION__, __LINE__
#endif

#ifndef NF_FILE_FUNCTION_LINE
#define NF_FILE_FUNCTION_LINE __FILE__, __FUNCTION__, __LINE__
#endif
#define NF_FORMAT(my_fmt, ...)             fmt::format(my_fmt, ##__VA_ARGS__);
#define NF_FORMAT_FUNCTION(my_fmt, ...)    fmt::format(std::string("[{}:{}]") + my_fmt, NF_FUNCTION_LINE, ##__VA_ARGS__);

#define MAKE_UINT32(low, high)	((uint32_t)(((uint16_t)((uint32_t)(low) & 0xffff)) | ((uint32_t)((uint16_t)((uint32_t)(high) & 0xffff))) << 16))
#define HIGH_UINT16(l) ((uint16_t)((uint32_t)(l) >> 16))
#define LOW_UINT16(l) ((uint16_t)((uint32_t)(l) & 0xffff))

#define MAKE_UINT64(low, high)	((uint64_t)(((uint32_t)((uint64_t)(low) & 0xffffffff)) | ((uint64_t)((uint32_t)((uint64_t)(high) & 0xffffffff))) << 32))
#define HIGH_UINT32(l) ((uint32_t)((uint64_t)(l) >> 32))
#define LOW_UINT32(l) ((uint32_t)((uint64_t)(l) & 0xffffffff))

#define BIT_ENABLED(AWORD, BITS) (((AWORD) & (BITS)) == (BITS))
#define BIT_DISABLED(AWORD, BITS) (((AWORD) & (BITS)) == 0)
#define SET_BITS(AWORD, BITS) ((AWORD) |= (BITS))
#define CLR_BITS(AWORD, BITS) ((AWORD) &= ~(BITS))

template <typename T, size_t N>
char (&ArraySizeHelper(T (&array)[N]))[N];


#ifndef _MSC_VER
template <typename T, size_t N>
char (&ArraySizeHelper(const T (&array)[N]))[N];
#endif


#ifndef _MSC_VER
#define ARRAYSIZE(array) (sizeof(ArraySizeHelper(array)))
#endif

#define ARRAYSIZE_UNSAFE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
     static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

#ifndef NF_DEBUG_MODE
#define TEST_SERVER
#endif

#ifndef NF_MACRO_FUNCTION
#if NF_PLATFORM == NF_PLATFORM_WIN
//#define NF_MACRO_FUNCTION __FUNCSIG__
#define NF_MACRO_FUNCTION __FUNCTION__
#else
//#define NF_MACRO_FUNCTION __PRETTY_FUNCTION__
#define NF_MACRO_FUNCTION __FUNCTION__
#endif
#endif