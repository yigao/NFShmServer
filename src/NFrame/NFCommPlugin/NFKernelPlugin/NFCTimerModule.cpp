// -------------------------------------------------------------------------
//    @FileName         :    NFCTimerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#include "NFCTimerModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

NFCTimerModule::NFCTimerModule(NFIPluginManager* p):NFITimerModule(p)
{
    m_pObjPluginManager = p;
	mTimerAxis.Init();
}

NFCTimerModule::~NFCTimerModule()
{
}

bool NFCTimerModule::Init()
{
	return true;
}

bool NFCTimerModule::Execute()
{
	mTimerAxis.Update();
	return true;
}

bool NFCTimerModule::BeforeShut()
{
	return true;
}

bool NFCTimerModule::Shut()
{
	mTimerAxis.UnInit();
	return true;
}

//设置定时器
bool NFCTimerModule::SetTimer(uint32_t nTimerID, uint64_t nInterVal, NFTimerObjBase* handler, uint32_t nCallCount /*= INFINITY_CALL*/)
{
	return mTimerAxis.SetTimer(nTimerID, nInterVal, handler, nCallCount);
}

//关闭定时器
bool NFCTimerModule::KillTimer(uint32_t nTimerID, NFTimerObjBase* handler)
{
	return mTimerAxis.KillTimer(nTimerID, handler);
}

//关闭所有定时器
bool NFCTimerModule::KillAllTimer(NFTimerObjBase* handler)
{
	return mTimerAxis.KillAllTimer(handler);
}

//设置固定时间的定时器
bool NFCTimerModule::SetClocker(uint32_t nTimerID, uint64_t nStartTime, uint32_t nInterDays, NFTimerObjBase* handler, uint32_t nCallCount/* = INFINITY_CALL */)
{
	return mTimerAxis.SetClocker(nTimerID, nStartTime, nInterDays, handler, nCallCount);
}

bool NFCTimerModule::SetCalender(uint32_t nTimerID, const std::string& timeStr, NFTimerObjBase* handler, uint32_t nCallCount/* = INFINITY_CALL */)
{
	return mTimerAxis.SetCalender(nTimerID, timeStr, handler, nCallCount);
}