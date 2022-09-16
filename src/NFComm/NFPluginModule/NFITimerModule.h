// -------------------------------------------------------------------------
//    @FileName         :    NFITimerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFIModule.h"
#include "NFComm/NFPluginModule/NFTimerAxis.h"

class NFITimerModule : public NFIModule
{
public:
	NFITimerModule(NFIPluginManager* p) :NFIModule(p)
	{

	}

	virtual ~NFITimerModule()
	{

	}
	//设置定时器
	virtual bool SetTimer(uint32_t nTimerID, uint64_t nInterVal, NFTimerObj* handler, uint32_t nCallCount = INFINITY_CALL) = 0;

	//关闭定时器
	virtual bool KillTimer(uint32_t nTimerID, NFTimerObj* handler) = 0;

	//关闭所有定时器
	virtual bool KillAllTimer(NFTimerObj* handler) = 0;

	//设置固定时间的定时器
	virtual bool SetClocker(uint32_t nTimerID, uint64_t nStartTime, uint32_t nInterDays, NFTimerObj* handler, uint32_t nCallCount = INFINITY_CALL) = 0;

	virtual bool SetCalender(uint32_t nTimerID, const std::string& timeStr, NFTimerObj* handler, uint32_t nCallCount = INFINITY_CALL) = 0;
};

