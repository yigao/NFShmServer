// -------------------------------------------------------------------------
//    @FileName         :    NFMonitorModule.cpp
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFMonitorPlugin
//
// -------------------------------------------------------------------------

#include "NFMonitorModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFEventDefine.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFCore/NFStringUtility.h"

enum MonitorTimerEnum
{
	MonitorTimer_SYSTEMINFO = 1,
};

#define MONITOR_TIMER_SYSTEIMINFO_INTERNAL_TIME 100000		//10s

NFCMonitorModule::NFCMonitorModule(NFIPluginManager* p):NFIMonitorModule(p)
{
	m_pPluginManager = p;
}

NFCMonitorModule::~NFCMonitorModule()
{

}

bool NFCMonitorModule::Init()
{
	this->SetTimer(MonitorTimer_SYSTEMINFO, MONITOR_TIMER_SYSTEIMINFO_INTERNAL_TIME, INFINITY_CALL);
	mSystemInfo.Init();
	return true;
}

bool NFCMonitorModule::Execute()
{
	return true;
}

bool NFCMonitorModule::Finalize()
{
	return true;
}

/**
* @brief 处理定时器功能
*
* @return void
*/
void NFCMonitorModule::OnTimer(uint32_t nTimerID)
{
	if (nTimerID == MonitorTimer_SYSTEMINFO)
	{
		mSystemInfo.CountSystemInfo();
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "cpu:%{}, mem:{}M ----------------------{}bytes", mSystemInfo.GetProcessInfo().mCpuUsed, mSystemInfo.GetProcessInfo().mMemUsed /(double)1024 / (double)1024, mSystemInfo.GetProcessInfo().mMemUsed);
	}
}

void NFCMonitorModule::CountAndPrint()
{
    mSystemInfo.CountSystemInfo();
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "cpu:%{}, mem:{}M ----------------------{}bytes", mSystemInfo.GetProcessInfo().mCpuUsed, mSystemInfo.GetProcessInfo().mMemUsed /(double)1024 / (double)1024, mSystemInfo.GetProcessInfo().mMemUsed);
}

/**
* @brief 处理事件
*
* @return void
*/
int NFCMonitorModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    return 0;
}

const NFSystemInfo& NFCMonitorModule::GetSystemInfo() const
{
	return mSystemInfo;
}

uint32_t NFCMonitorModule::GetUserCount() const
{
	return mSystemInfo.GetUserCount();
}

void NFCMonitorModule::SetUserCount(uint32_t count)
{
	mSystemInfo.SetUserCount(count);
}

double NFCMonitorModule::GetCpuUsed()
{
    return mSystemInfo.GetProcessInfo().mCpuUsed;
}

uint64_t NFCMonitorModule::GetMemUsed()
{
    return mSystemInfo.GetProcessInfo().mMemUsed;
}
