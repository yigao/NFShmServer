// -------------------------------------------------------------------------
//    @FileName         :    NFCTimerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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
	virtual bool SetTimer(uint32_t nTimerID, uint64_t nInterVal, NFTimerObjBase* handler, uint32_t nCallCount = INFINITY_CALL) override;

	//关闭定时器
	virtual bool KillTimer(uint32_t nTimerID, NFTimerObjBase* handler) override;

	//关闭所有定时器
	virtual bool KillAllTimer(NFTimerObjBase* handler) override;

	//设置固定时间的定时器
	virtual bool SetClocker(uint32_t nTimerID, uint64_t nStartTime, uint32_t nInterDays, NFTimerObjBase* handler, uint32_t nCallCount = INFINITY_CALL) override;

	//设置固定时间的定时器
	virtual bool SetCalender(uint32_t nTimerID, const std::string& timeStr, NFTimerObjBase* handler, uint32_t nCallCount = INFINITY_CALL) override;
protected:
	NFTimerAxis mTimerAxis;
};

