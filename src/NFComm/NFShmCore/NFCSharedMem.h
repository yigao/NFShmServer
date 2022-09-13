// -------------------------------------------------------------------------
//    @FileName         :    NFCSharedMem.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmDefine.h"

#if NF_PLATFORM == NF_PLATFORM_WIN
#include <Windows.h>
typedef long key_t;
#else
#include <sys/ipc.h>
#include <sys/shm.h>
#endif

/////////////////////////////////////////////////
/**
* @file  NFCSharedMem.h
* @brief  共享内存封装类.
*
*/
/////////////////////////////////////////////////


/**
* @brief  共享内存连接类，说明:
* 1 用于连接共享内存, 共享内存的权限是 0666
*/

class NFCSharedMemModule;

class NFCSharedMem
{
public:
	friend NFCSharedMemModule;

	/**
	* @brief 构造函数.
	*/
#if NF_PLATFORM == NF_PLATFORM_WIN
	NFCSharedMem(key_t nKey, size_t siSize, EN_OBJ_MODE enInitFlag, HANDLE shemID);
#else
	NFCSharedMem(key_t nKey, size_t siSize, EN_OBJ_MODE enInitFlag, int shemID);
#endif


	/**
	* @brief 析构函数.
	*/
	virtual ~NFCSharedMem();

	/**
	* @brief 初始化.
	*/
	int  Initialize(key_t nKey, size_t siSize);

	/**
	* @brief 初始化.
	*/
	void SetStamp();

	/**
	* @brief new一块内存
	*/
	void *operator new(size_t siSize) throw();

	/**
	* @brief 释放一块内存
	*/
	void operator delete(void *pMem);

	/**
	* @brief 获得状态
	*/
	EN_OBJ_MODE  GetInitMode();

	/**
	* @brief 获得状态
	*/
	void  SetInitMode(EN_OBJ_MODE mode);

	/**
	* @brief
	*/
	void*	CreateSegment(size_t siSize);

	/**
	* @brief  获得剩余可用空间大小
	*/
	size_t   GetFreeSize()
	{
		return m_siShmSize - (size_t)(m_pbCurrentSegMent - (char*)this);
	}

	/**
	* @brief  获得已经使用空间大小
	*/
	size_t   GetUsedSize()
	{
		return (size_t)(m_pbCurrentSegMent - (char*)this);
	}

	/**
	* @brief  获得全部空间大小
	*/
	size_t   GetTotalSize()
	{
		return m_siShmSize;
	}

	/**
	* @brief  获得偏移地址
	*/
	size_t   GetAddrOffset()
	{
		return m_siAddrOffset;
	}

	/**
	* @brief  对象seq自增
	*/
	int		IncreaseObjSeqNum()
	{
		return m_iObjSeqNum++;
	}

	/**
	* @brief  设置共享内存能够被安全摧毁
	*/
	void	SetShmCanbeDestroySafe();

	/**
	* @brief  设置功能内存初始化成功
	*/
	void	SetShmInitSuccessFlag();

	/**
	* @brief  清理初始化成功标识
	*
	*/
	void	ClearShmInitSuccessFlag();
protected:
	/**
	* 共享内存key
	*/
	key_t           m_nShmKey;

	/**
	* 共享内存大小
	*/
	size_t          m_siShmSize;

	/**
	* 共享内存创建时间
	*/
	uint64_t		m_iCreateTime;

	/**
	* 共享内存创建时间
	*/
	uint64_t		m_iLastStamp;

	/**
	* 共享内存创建时间
	*/
	size_t			m_siCRC;

	/**
	* 共享内存创建时间
	*/
	char			*m_pbCurrentSegMent;

	/**
	* 共享内存起始地址
	*/
	char            *m_pShmAddr;

	/**
	* 相对于上次共享内存地址recover之后的偏移量,用来恢复指针对象
	*/
	size_t			m_siAddrOffset;

	/**
	* 对象序列号,出去安全考虑,用来区别同一个内存地址的不同对象
	*/
	int				m_iObjSeqNum;

	/**
	* 当前共享内存运行状态
	*/
	EN_OBJ_MODE		m_enRunMode;

	/**
	* 能否被安全删除的标记，如果是的话表示内存中没有需要保存的数据了
	*/
	int				m_iCanBeDestroySafe;

	/**
	* 初始化成功的标记，没有初始化成功的内存recover是没有意义的
	*/
	int				m_iInitSuccessFlag;

	/**
	* 版本校验，如果版本不对，recover不起来，防止外网误操作，引起悲剧
	*/
	int				m_iServerCheckVersion;

	/**
	* 共享内存id
	*/
#if NF_PLATFORM == NF_PLATFORM_WIN
	HANDLE			m_shemID;
#else
	int             m_shemID;
#endif
public:
	/**
	* 当前共享内存块，放在共享内存块开头
	*/
	static char*	pbCurrentShm;

	/**
	* 共享内存初始标志
	*/
	static bool		s_bCheckInitSuccessFlag;
};
