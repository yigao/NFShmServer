// -------------------------------------------------------------------------
//    @FileName         :    NFLock.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"
#include "NFMutex.h"
#include <thread>

/**
Portable lock synchronization primitive.
This class is a helper which allows a mutex to be locked and automatically locked within a scope.
*/
class _NFExport NFLock
{
public:

	friend class NFCondition;

	/**
	Constructor. Locks the given mutex object.
	*/
	NF_FORCEINLINE explicit NFLock(NFMutex &mutex) :
		mLock(mutex.mMutex)
	{

	}

	/**
	Destructor. Automatically unlocks the locked mutex that was locked on construction.
	*/
	NF_FORCEINLINE ~NFLock()
	{

	}

	/**
	Explicitly and temporarily unlocks the locked mutex.
	\note The caller should always call \ref Relock after this call and before destruction.
	*/
	NF_FORCEINLINE void Unlock()
	{
		NF_ASSERT(mLock.owns_lock() == true);
		mLock.unlock();
	}

	/**
	Re-locks the associated mutex, which must have been previously unlocked with \ref Unlock.
	\note Relock can only be called after a preceding call to \ref Unlock.
	*/
	NF_FORCEINLINE void Relock()
	{
		NF_ASSERT(mLock.owns_lock() == false);
		mLock.lock();
	}

private:

	NFLock(const NFLock &other);
	NFLock &operator=(const NFLock &other);

	std::unique_lock<std::mutex> mLock;
};