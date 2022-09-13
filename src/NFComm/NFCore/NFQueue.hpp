// -------------------------------------------------------------------------
//    @FileName         :    NFQueue.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :
//
// -------------------------------------------------------------------------

#ifndef NF_QUEUE_H
#define NF_QUEUE_H

#include <vector>
#include <list>
#include <thread>
#include <mutex>
#include <atomic>
#include "NFPlatform.h"
#include "NFMutex.h"
#include "NFLock.h"

template <typename T>
class NFQueueVector
{
public:
	NFQueueVector()
	{
	}

	virtual ~NFQueueVector()
	{
	}

	bool Push(const T& object)
	{
		NFLock lock(mMutex);
		mList.push_back(object);
		return true;
	}

	bool Pop(std::vector<T>& vecObj)
	{
		NFLock lock(mMutex);
		mList.swap(vecObj);
		return true;
	}

	bool Pop(T& object)
	{
		NFLock lock(mMutex);
		if (mList.empty())
		{
			return false;
		}
		object = mList.front();
		mList.pop_front();

		return true;
	}

	uint32_t Count()
	{
		NFLock lock(mMutex);
		return (uint32_t)mList.size();
	}
private:
	std::vector<T> mList;
	NFMutex mMutex;
};

template <typename T>
class NFQueue
{
public:
	NFQueue()
	{
	}

	virtual ~NFQueue()
	{
	}

	bool Push(const T& object)
	{
		NFLock lock(mMutex);
		mList.push_back(object);
		return true;
	}

	bool Pop(std::list<T>& vecObj)
	{
		NFLock lock(mMutex);
		mList.swap(vecObj);
		return true;
	}

	bool Pop(T& object)
	{
		NFLock lock(mMutex);
		if (mList.empty())
		{
			return false;
		}

		object = mList.front();
		mList.pop_front();

		return true;
	}

	uint32_t Count()
	{
		NFLock lock(mMutex);
		return (uint32_t)mList.size();
	}
private:
	std::list<T> mList;
	NFMutex mMutex;
};

#endif

