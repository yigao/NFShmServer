// -------------------------------------------------------------------------
//    @FileName         :    NFCoroutine.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFPluginModule/NFError.h"

#include <functional>
#include <list>
#include <set>
#include <string.h>
#include <stdint.h>

#if NF_PLATFORM == NF_PLATFORM_LINUX
#include <sys/poll.h>
#include <ucontext.h>
#else
#include <WinSock2.h>
#include <Windows.h>
#endif

#define NF_COROUTINE_DEAD 0
#define NF_COROUTINE_READY 1
#define NF_COROUTINE_RUNNING 2
#define NF_COROUTINE_SUSPEND 3

#define MAX_FREE_CO_NUM     1024
#define INVALID_CO_ID       -1

class NFSchedule;

typedef void (*NFCoroutineFunc)(struct NFSchedule *, void *ud);

class NFCoroutine {
public:
	NFCoroutine(uint32_t statckSize) {
		func = NULL;
		ud = NULL;
		sch = NULL;
		status = NF_COROUTINE_DEAD;
		enable_hook = false;
		stack = new char[statckSize];
		result = 0;
#if NF_PLATFORM == NF_PLATFORM_LINUX
		memset(&ctx, 0, sizeof(ucontext_t));
#else
		ctx = NULL;
#endif
	}

	virtual ~NFCoroutine()
	{
		delete [] stack;
	}


public:
	NFCoroutineFunc func;
	std::function<void()> std_func;
	void *ud;
#if NF_PLATFORM == NF_PLATFORM_LINUX
	ucontext_t ctx;
#else
	void* ctx;
#endif
	NFSchedule * sch;
	int status;
	bool enable_hook;
	char* stack;                // 协程栈的内容
	int32_t result;             // 携带resume结果
};
