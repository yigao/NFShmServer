// -------------------------------------------------------------------------
//    @FileName         :    NFSpinLock.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFAtomic.h"

#if defined(_MSC_VER)

#include <Windows.h> // YieldProcessor

#include <Processthreadsapi.h>
#include <Synchapi.h> // Windows server
#include <intrin.h>

#endif

/**
 * ==============================================
 * ======            asm pause             ======
 * ==============================================
 */
#if defined(_MSC_VER)

 /*
  * See: http://msdn.microsoft.com/en-us/library/windows/desktop/ms687419(v=vs.85).aspx
  * Not for intel c++ compiler, so ignore http://software.intel.com/en-us/forums/topic/296168
  */

#ifdef YieldProcessor
#define __UTIL_LOCK_SPIN_LOCK_PAUSE() YieldProcessor()
#endif

#elif defined(__GNUC__) || defined(__clang__)
#if defined(__i386__) || defined(__x86_64__)
 /**
  * See: Intel(R) 64 and IA-32 Architectures Software Developer's Manual V2
  * PAUSE-Spin Loop Hint, 4-57
  * http://www.intel.com/content/www/us/en/architecture-and-technology/64-ia-32-architectures-software-developer-instruction-set-reference-manual-325383.html?wapkw=instruction+set+reference
  */
#define __UTIL_LOCK_SPIN_LOCK_PAUSE() __asm__ __volatile__("pause")
#elif defined(__ia64__) || defined(__ia64)
 /**
  * See: Intel(R) Itanium(R) Architecture Developer's Manual, Vol.3
  * hint - Performance Hint, 3:145
  * http://www.intel.com/content/www/us/en/processors/itanium/itanium-architecture-vol-3-manual.html
  */
#define __UTIL_LOCK_SPIN_LOCK_PAUSE() __asm__ __volatile__("hint @pause")
#elif defined(__arm__) && !defined(__ANDROID__)
 /**
  * See: ARM Architecture Reference Manuals (YIELD)
  * http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.subset.architecture.reference/index.html
  */
#define __UTIL_LOCK_SPIN_LOCK_PAUSE() __asm__ __volatile__("yield")
#endif

#endif /*compilers*/

  // set pause do nothing
#if !defined(__UTIL_LOCK_SPIN_LOCK_PAUSE)
#define __UTIL_LOCK_SPIN_LOCK_PAUSE()
#endif /*!defined(CAPO_SPIN_LOCK_PAUSE)*/


/**
 * ==============================================
 * ======            cpu yield             ======
 * ==============================================
 */
#if 0 && defined(_MSC_VER)

 // SwitchToThread only can be used in desktop system

#define __UTIL_LOCK_SPIN_LOCK_CPU_YIELD() SwitchToThread()

#elif defined(__linux__) || defined(__unix__)
#include <sched.h>
#define __UTIL_LOCK_SPIN_LOCK_CPU_YIELD() sched_yield()
#endif

#ifndef __UTIL_LOCK_SPIN_LOCK_CPU_YIELD
#define __UTIL_LOCK_SPIN_LOCK_CPU_YIELD() __UTIL_LOCK_SPIN_LOCK_PAUSE()
#endif

 /**
  * ==============================================
  * ======           thread yield           ======
  * ==============================================
  */
#if defined(__UTIL_LOCK_ATOMIC_INT_TYPE_ATOMIC_STD)
#include <chrono>
#include <thread>
#define __UTIL_LOCK_SPIN_LOCK_THREAD_YIELD() ::std::this_thread::yield()
#define __UTIL_LOCK_SPIN_LOCK_THREAD_SLEEP() ::std::this_thread::sleep_for(::std::chrono::milliseconds(1))
#elif defined(_MSC_VER)
#define __UTIL_LOCK_SPIN_LOCK_THREAD_YIELD() Sleep(0)
#define __UTIL_LOCK_SPIN_LOCK_THREAD_SLEEP() Sleep(1)
#endif

#ifndef __UTIL_LOCK_SPIN_LOCK_THREAD_YIELD
#define __UTIL_LOCK_SPIN_LOCK_THREAD_YIELD()
#define __UTIL_LOCK_SPIN_LOCK_THREAD_SLEEP() __UTIL_LOCK_SPIN_LOCK_CPU_YIELD()
#endif

  /**
   * ==============================================
   * ======           spin lock wait         ======
   * ==============================================
   * @note
   *   1. busy-wait
   *   2. asm pause
   *   3. thread give up cpu time slice but will not switch to another process
   *   4. thread give up cpu time slice (may switch to another process)
   *   5. sleep (will switch to another process when necessary)
   */

#define __UTIL_LOCK_SPIN_LOCK_WAIT(x)                                 \
    {                                                                 \
        unsigned char try_lock_times = static_cast<unsigned char>(x); \
        if (try_lock_times < 4) {                                     \
        } else if (try_lock_times < 16) {                             \
            __UTIL_LOCK_SPIN_LOCK_PAUSE();                            \
        } else if (try_lock_times < 32) {                             \
            __UTIL_LOCK_SPIN_LOCK_THREAD_YIELD();                     \
        } else if (try_lock_times < 64) {                             \
            __UTIL_LOCK_SPIN_LOCK_CPU_YIELD();                        \
        } else {                                                      \
            __UTIL_LOCK_SPIN_LOCK_THREAD_SLEEP();                     \
        }                                                             \
    }

/**
* @brief 自旋锁
* @see
*/
class NFSpinLock {
private:
	typedef enum { UNLOCKED = 0, LOCKED = 1 } LockStateType;
	std::atomic<unsigned int> mLockState;
public:
	NFSpinLock() { mLockState.store(UNLOCKED); }

	void Lock() 
	{
		unsigned char try_times = 0;
		while (mLockState.exchange(static_cast<unsigned int>(LOCKED), std::memory_order_acq_rel) == LOCKED)
			__UTIL_LOCK_SPIN_LOCK_WAIT(try_times++); /* busy-wait */
	}

	void UnLock() 
	{ 
		mLockState.store(static_cast<unsigned int>(UNLOCKED), std::memory_order_release); 
	}

	bool IsLocked() 
	{ 
		return mLockState.load(std::memory_order_acquire) == LOCKED;
	}

	bool TryLock() 
	{
		return mLockState.exchange(static_cast<unsigned int>(LOCKED), std::memory_order_acq_rel) == UNLOCKED;
	}

	bool TryUnLock() {
		return mLockState.exchange(static_cast<unsigned int>(UNLOCKED), std::memory_order_acq_rel) == LOCKED;
	}
};

class NFSpinLockHolder
{
public:
	NFSpinLockHolder(NFSpinLock& lock) :mLockFlag(&lock)
	{
		mLockFlag->Lock();
	}

	~NFSpinLockHolder()
	{
		mLockFlag->UnLock();
	}

	bool IsAvailable() const { return mLockFlag != NULL; }
private:
	NFSpinLock* mLockFlag;
};