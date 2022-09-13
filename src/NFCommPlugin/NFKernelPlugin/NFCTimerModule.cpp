// -------------------------------------------------------------------------
//    @FileName         :    NFCTimerModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#include "NFCTimerModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFTimerMgr.h"

NFCTimerModule::NFCTimerModule(NFIPluginManager* p):NFITimerModule(p)
{
	m_pPluginManager = p;
	mTimerAxis.Init();
	NFTimerMgr::Instance()->Init(this);
}

NFCTimerModule::~NFCTimerModule()
{
	NFTimerMgr::Instance()->UnInit();
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
bool NFCTimerModule::SetTimer(uint32_t nTimerID, uint64_t nInterVal, NFTimerObj* handler, uint32_t nCallCount /*= INFINITY_CALL*/)
{
	return mTimerAxis.SetTimer(nTimerID, nInterVal, handler, nCallCount);
}

//关闭定时器
bool NFCTimerModule::KillTimer(uint32_t nTimerID, NFTimerObj* handler)
{
	return mTimerAxis.KillTimer(nTimerID, handler);
}

//关闭所有定时器
bool NFCTimerModule::KillAllTimer(NFTimerObj* handler)
{
	return mTimerAxis.KillAllTimer(handler);
}

//设置固定时间的定时器
bool NFCTimerModule::SetClocker(uint32_t nTimerID, uint64_t nStartTime, uint32_t nInterDays, NFTimerObj* handler, uint32_t nCallCount/* = INFINITY_CALL */)
{
	return mTimerAxis.SetClocker(nTimerID, nStartTime, nInterDays, handler, nCallCount);
}

bool NFCTimerModule::SetCalender(uint32_t nTimerID, const std::string& timeStr, NFTimerObj* handler, uint32_t nCallCount/* = INFINITY_CALL */)
{
	return mTimerAxis.SetCalender(nTimerID, timeStr, handler, nCallCount);
}