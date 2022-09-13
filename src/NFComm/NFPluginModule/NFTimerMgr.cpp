// -------------------------------------------------------------------------
//    @FileName         :    NFTimerMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#include "NFTimerMgr.h"
#include "NFComm/NFPluginModule/NFITimerModule.h"

NFTimerMgr::NFTimerMgr()
{
	m_pTimerModule = nullptr;
}

NFTimerMgr::~NFTimerMgr()
{
}

bool NFTimerMgr::Init(NFITimerModule* pTimerModule)
{
	m_pTimerModule = pTimerModule;
	return true;
}

void NFTimerMgr::UnInit()
{
	m_pTimerModule = nullptr;
}

//设置定时器
bool NFTimerMgr::SetTimer(uint32_t nTimerID, uint64_t nInterVal, NFTimerObj* handler, uint32_t nCallCount /*= INFINITY_CALL*/)
{
	if (m_pTimerModule)
	{
		return m_pTimerModule->SetTimer(nTimerID, nInterVal, handler, nCallCount);
	}
	return false;
}

//关闭定时器
bool NFTimerMgr::KillTimer(uint32_t nTimerID, NFTimerObj* handler)
{
	if (m_pTimerModule)
	{
		return m_pTimerModule->KillTimer(nTimerID, handler);
	}
	return false;
}

//关闭所有定时器
bool NFTimerMgr::KillAllTimer(NFTimerObj* handler)
{
	if (m_pTimerModule)
	{
		return m_pTimerModule->KillAllTimer(handler);
	}
	return false;
}

//设置固定时间的定时器
bool NFTimerMgr::SetFixTimer(uint32_t nTimerID, uint64_t nStartTime, uint32_t nInterSec, NFTimerObj* handler, uint32_t nCallCount/* = INFINITY_CALL */)
{
	if (m_pTimerModule)
	{
		return m_pTimerModule->SetClocker(nTimerID, nStartTime, nInterSec, handler, nCallCount);
	}
	return false;
}

