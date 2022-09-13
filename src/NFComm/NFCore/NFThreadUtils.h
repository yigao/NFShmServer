// -------------------------------------------------------------------------
//    @FileName         :    NFThreadUtils.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"

#include <thread>

/**
Static thread utility function interface.
*/
class _NFExport NFThreadUtils
{
public:

	/**
	Waste some cycles to avoid busy-waiting on a shared memory resource.
	\note This function is intentionally not force-inlined.
	*/
	inline static void Backoff(uint32_t &backoff);

	/**
	Yield execution of the calling thread to another hyperthread on the same core.
	*/
	inline static void YieldToHyperthread();

	/**
	Yield execution of the calling thread to any available thread on the same core.
	*/
	inline static void YieldToLocalThread();

	/**
	Yield execution of the calling thread to any other available thread.
	*/
	inline static void YieldToAnyThread();

	/**
	Put the calling thread to sleep for a given number of milliseconds.
	*/
	inline static void SleepThread(const uint32_t milliseconds);
private:

	NFThreadUtils(const NFThreadUtils &other);
	NFThreadUtils &operator=(const NFThreadUtils &other);
};


inline void NFThreadUtils::Backoff(uint32_t &backoff)
{
	// The backoff scales from a simple 'nop' to putting the calling thread to sleep.
	// This implementation is based roughly on http://www.1024cores.net/home/lock-free-algorithms/tricks/spinning
	if (++backoff < 10)
	{
		YieldToHyperthread();
	}
	else if (backoff < 20)
	{
		for (uint32_t i = 0; i < 50; ++i)
		{
			YieldToHyperthread();
		}
	}
	else if (backoff < 22)
	{
		YieldToLocalThread();
	}
	else
	{
		YieldToAnyThread();
	}
}


NF_FORCEINLINE void NFThreadUtils::YieldToHyperthread()
{

	// The intention of this code is to indicate to the scheduler
	// that the thread is not doing useful work, so another thread
	// able to run on the same core should be given priority.
	// It's intended to evaluate to a lightweight NOP instruction
	// rather than a heavyweight system call. On Windows the
	// YieldProcessor() function can be called to this effect;
	// on other systems we try to issue an explicit NOP or pause
	// instruction - but only some architectures are implemented.

#if NF_COMPILER == NF_COMPILER_MSVC

	YieldProcessor();

#elif NF_GCC

#ifdef __arm__
	__asm__ __volatile__("NOP");
#elif __X86_64__
	__asm__ __volatile__("pause");
#endif

#endif

}


NF_FORCEINLINE void NFThreadUtils::YieldToLocalThread()
{
	std::this_thread::yield();
}


NF_FORCEINLINE void NFThreadUtils::YieldToAnyThread()
{
	std::this_thread::yield();
}


NF_FORCEINLINE void NFThreadUtils::SleepThread(const uint32_t milliseconds)
{
	NF_ASSERT(milliseconds < 1000);

	std::this_thread::sleep_for(std::chrono::microseconds(milliseconds * 1000));
}