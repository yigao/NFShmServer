// -------------------------------------------------------------------------
//    @FileName         :    NFShmMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFTypeDefines.h"
#include "NFShmDefine.h"
#include "NFTypeDefines.h"

class NFShmObj;
class NFISharedMemModule;
class NFTransBase;
class NFShmTimerObj;

class NFShmMgr : public NFSingleton<NFShmMgr>
{
public:
	NFShmMgr();
	virtual ~NFShmMgr();
public:
    bool IsInited() const { return m_inited; }
	bool Init(NFISharedMemModule* pShmModule = nullptr);
	void UnInit();
public:
	/**
	* 共享内存模式
	*/
	virtual EN_OBJ_MODE	GetInitMode();

	/**
	* 共享内存模式
	*/
	virtual void SetInitMode(EN_OBJ_MODE mode);

	/**
	* 共享内存创建对象模式
	*/
	virtual EN_OBJ_MODE	GetCreateMode();

	/**
	* 共享内存创建对象模式
	*/
	virtual void	SetCreateMode(EN_OBJ_MODE mode);

protected:
	NFISharedMemModule* m_pShmModule;
	bool m_inited;
};

