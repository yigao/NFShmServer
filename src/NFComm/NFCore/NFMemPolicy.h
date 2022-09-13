// -------------------------------------------------------------------------
//    @FileName         :    NFMemPolicy.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"
#include "NFShm.h"

//////////////////////////////////////////////////////////////////////
// 存储策略: 内存, 共享内存, mmap(文件)

/**
* 内存存储
*/
template<typename T>
class NFMemStorePolicy
{
public:
	/**
	* 初始化
	* @param pAddr: 指令队列空间的指针
	* @param iSize: 空间的指针
	*/
	void create(void *pAddr, size_t iSize)
	{
		_t.create(pAddr, iSize);
	}

	/**
	* 连接上队列
	* @param pAddr: 指令队列空间的指针
	* @param iSize: 空间的指针
	*/
	void connect(void *pAddr, size_t iSize)
	{
		_t.connect(pAddr, iSize);
	}

protected:
	T   _t;
};

/**
* 共享内存存储
*/
template<typename T>
class ShmStorePolicy
{
public:
	/**
	* 初始化共享存储
	* @param iShmKey
	* @param iSize
	*/
	void initStore(key_t iShmKey, size_t iSize)
	{
		_shm.init(iSize, iShmKey);
		if (_shm.iscreate())
		{
			_t.create(_shm.getPointer(), iSize);
		}
		else
		{
			_t.connect(_shm.getPointer(), iSize);
		}
	}

	/**
	* 释放共享内存
	*/
	void release()
	{
		_shm.del();
	}
protected:
	NFShm  _shm;
	T       _t;
};


