// -------------------------------------------------------------------------
//    @FileName         :    NFMutex.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"
#include <thread>
#include <mutex>


class _NFExport NFMutex
{
public:

	friend class NFCondition;
	friend class NFLock;

	NF_FORCEINLINE NFMutex()
	{
	}

	NF_FORCEINLINE ~NFMutex()
	{

	}

	NF_FORCEINLINE void Lock()
	{
		mMutex.lock();
	}

	NF_FORCEINLINE void Unlock()
	{
		mMutex.unlock();
	}

private:

	NFMutex(const NFMutex &other);
	NFMutex &operator=(const NFMutex &other);

	std::mutex mMutex;
};

class _NFExport NFMutexGuard
{
public:

	friend class NFCondition;
	friend class NFLock;

	NF_FORCEINLINE NFMutexGuard()
	{
		mMutex.Lock();
	}

	NF_FORCEINLINE ~NFMutexGuard()
	{
		mMutex.Unlock();
	}

private:

	NFMutexGuard(const NFMutexGuard &other);
	NFMutexGuard &operator=(const NFMutexGuard &other);

	NFMutex mMutex;
};

