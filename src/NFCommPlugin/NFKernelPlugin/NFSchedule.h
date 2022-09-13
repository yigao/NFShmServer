// -------------------------------------------------------------------------
//    @FileName         :    NFCoroutine.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFPlatform.h"

#include <functional>
#include <list>
#include <set>
#include <string.h>
#include <stdint.h>
#include <unordered_map>

#if NF_PLATFORM == NF_PLATFORM_LINUX
#include <sys/poll.h>
#include <ucontext.h>
#else

#endif

#include "NFCoroutine.h"

#ifdef Yield
#undef Yield
#endif

/// @brief struct schedule 协程调度器的数据结构
class NFSchedule {
public:
	NFSchedule(uint32_t stackSize)
	{
	    nco = 1;
	    running = -1;
	    co_free_num = 0;
	    stack_size = stackSize;
#if NF_PLATFORM == NF_PLATFORM_LINUX
        memset(&main, 0, sizeof(ucontext_t));
#else
		main = ConvertThreadToFiber(nullptr);
#endif
	}

	~NFSchedule()
	{
        for(auto iter = co_hash_map.begin(); iter != co_hash_map.end(); iter++)
        {
            if (iter->second)
            {
                NF_SAFE_DELETE(iter->second);
            }
        }

        for(auto iter = co_free_list.begin(); iter != co_free_list.end(); iter++)
        {
           NF_SAFE_DELETE(*iter);
        }
#if NF_PLATFORM == NF_PLATFORM_LINUX
        memset(&main, 0, sizeof(ucontext_t));
#else
        ConvertFiberToThread();
		main = NULL;
#endif
	}

	/// @brief 创建一个协程
	/// @param 协程执行体的函数指针
	/// @note 只能够在主线程调用
	NFCoroutine *NewCoroutine(const std::function<void()>& std_func);

	/// @brief 创建一个协程
	/// @param 协程执行体的函数指针
	/// @note 只能够在主线程调用
	NFCoroutine *NewCoroutine(NFCoroutineFunc func, void *ud);

	/// @brief 创建一个协程
	/// @param 协程执行体的函数指针
	/// @return 协程ID
	/// @note 只能够在主线程调用
	int64_t CreateCoroutine(const std::function<void()>& func);

	/// @brief 创建一个协程
	/// @param 协程执行体的函数指针
	/// @param 该协程执行函数的参数
	/// @return 协程ID
	/// @note 只能够在主线程调用
	int64_t CreateCoroutine(NFCoroutineFunc func, void *ud);

	/// @brief 继续一个协程的运行
	/// @param[in] 协程ID
	/// @param[in] resume时可传递结果，默认为0
	/// @return 处理结果 @see CoroutineErrorCode
	/// @note 只能够在主线程调用
	int32_t CoroutineResume(int64_t id, int32_t result = 0);

	/// @brief 获取协程当前状态
	/// @param 协程ID
	/// @return 返回协程运行状态
	int CoroutineStatus(int64_t id);

	/// @brief 获取当前正在运行的协程ID
	/// @return 返回正在运行的协程ID
	int64_t CoroutineRunning();

	/// @brief 暂停一个协程的运行
	/// @return 处理结果，@see CoroutineErrorCode
	/// @note 只能够在协程内调用
	int32_t CoroutineYield();
public:
#if NF_PLATFORM == NF_PLATFORM_LINUX
    ucontext_t main;
#else
	void *main;
#endif
    int64_t nco;                // 下一个要创建的协程ID
    int64_t running;            // 当前正在运行的协程ID
    std::unordered_map<int64_t, NFCoroutine*> co_hash_map;
    std::list<NFCoroutine*> co_free_list;
    int32_t co_free_num;
    uint32_t stack_size;
};
