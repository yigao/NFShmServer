// -------------------------------------------------------------------------
//    @FileName         :    NFCTimerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFITimerModule.h"
#include "NFComm/NFPluginModule/NFTimerAxis.h"

class NFCTimerModule : public NFITimerModule
{
public:
	explicit NFCTimerModule(NFIPluginManager* p);

	virtual ~NFCTimerModule();

public:
	virtual bool Init() override;

	virtual bool Execute() override;

	virtual bool BeforeShut() override;

	virtual bool Shut() override;
public:
	//设置定时器
	virtual bool SetTimer(uint32_t nTimerID, uint64_t nInterVal, NFTimerObj* handler, uint32_t nCallCount = INFINITY_CALL) override;

	//关闭定时器
	virtual bool KillTimer(uint32_t nTimerID, NFTimerObj* handler) override;

	//关闭所有定时器
	virtual bool KillAllTimer(NFTimerObj* handler) override;

	//设置固定时间的定时器
	virtual bool SetClocker(uint32_t nTimerID, uint64_t nStartTime, uint32_t nInterDays, NFTimerObj* handler, uint32_t nCallCount = INFINITY_CALL) override;

	//设置固定时间的定时器
	virtual bool SetCalender(uint32_t nTimerID, const std::string& timeStr, NFTimerObj* handler, uint32_t nCallCount = INFINITY_CALL) override;
protected:
	NFTimerAxis mTimerAxis;
};

