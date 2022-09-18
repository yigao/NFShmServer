// -------------------------------------------------------------------------
//    @FileName         :    NFTimerObj.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once
#include <stdint.h>
#include "NFComm/NFCore/NFPlatform.h"

class NFIPluginManager;
struct NFTimerObj
{
public:
	NFTimerObj(NFIPluginManager* pPluginManager);
	virtual ~NFTimerObj();
public:
	virtual void OnTimer(uint32_t nTimerID) = 0;

	virtual bool SetTimer(uint32_t nTimerID, uint64_t nInterVal, uint32_t nCallCount = 0);

	virtual bool KillTimer(uint32_t nTimerID);

	virtual bool KillAllTimer();

	virtual bool SetFixTimer(uint32_t nTimerID, uint64_t nStartTime, uint32_t nInterSec, uint32_t nCallCount = 0);
public:
	virtual void** GetTimerInfoPtr()
	{
		return &m_pTimerInfoPtr;
	}

	virtual void** GetFixTimerInfoPtr()
	{
		return &m_pFixTimerInfoPtr;
	}

public:
    NFIPluginManager* m_pTimerPluginManager;
private:
	void* m_pTimerInfoPtr;
	void* m_pFixTimerInfoPtr;
};

