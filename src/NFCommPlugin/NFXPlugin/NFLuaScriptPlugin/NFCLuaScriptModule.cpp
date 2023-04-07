// -------------------------------------------------------------------------
//    @FileName         :    NFCLuaScriptModule.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-01-02
//    @Module           :    NFCLuaScriptModule
//    @Desc             :
// -------------------------------------------------------------------------

#include <assert.h>
#include <set>
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFCLuaScriptModule.h"

#include "NFComm/NFCore/NFCRC32.h"
#include "NFComm/NFCore/NFCRC16.h"
#include "NFComm/NFCore/NFBase64.h"
#include "NFComm/NFCore/NFSha256.h"
#include "NFComm/NFPluginModule/NFEventDefine.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

enum EnumLuaScriptTimer
{
	EnumLuaScriptTimer_ServerLoop = 0,
};

NFCLuaScriptModule::NFCLuaScriptModule(NFIPluginManager* p): NFILuaScriptModule(p)
{
    m_luaTimerIndex = 10000;
    mnTime = 0;
}

NFCLuaScriptModule::~NFCLuaScriptModule()
{

}

int NFLuaTimer::OnTimer(uint32_t nTimerID)
{
	mCurCallCount++;
	if (mGlobalLuaFunc == "LuaNFrame.DispatchWorker")
	{
		m_pLuaScriptModule->BeginProfiler("LuaNFrame.DispatchWorker--"+ mLuaFunc);
		m_pLuaScriptModule->TryRunGlobalScriptFunc("LuaNFrame.DispatchWorker", mLuaFunc, mDataStr);
		m_pLuaScriptModule->EndProfiler();
	}
	else
	{
		m_pLuaScriptModule->BeginProfiler("LuaNFrame.DispatchTimer--"+ mLuaFunc);
		m_pLuaScriptModule->TryRunGlobalScriptFunc("LuaNFrame.DispatchTimer", nTimerID, mLuaFunc, mDataStr);
		m_pLuaScriptModule->EndProfiler();
	}
    return 0;
}

bool NFCLuaScriptModule::Init()
{
	SetTimer(EnumLuaModule_INIT, 1000, INFINITY_CALL);
    return true;
}

int NFCLuaScriptModule::OnTimer(uint32_t nTimerID)
{
    if (!m_pObjPluginManager->IsInited())
    {
        return 0;
    }

	if (nTimerID == EnumLuaModule_INIT)
	{
        KillTimer(nTimerID);
		Register();
		LoadScript();
		SetFixTimer(EnumLuaModule_SEC, 0, 1, INFINITY_CALL);
		SetFixTimer(EnumLuaModule_MIN, 0, 60, INFINITY_CALL);
		SetFixTimer(EnumLuaModule_5MIN, 0, 5 * 60, INFINITY_CALL);
		SetFixTimer(EnumLuaModule_10MIN, 0, 10 * 60, INFINITY_CALL);
		SetFixTimer(EnumLuaModule_30MIN, 0, 30 * 60, INFINITY_CALL);
		SetFixTimer(EnumLuaModule_HOUR, 0, 3600, INFINITY_CALL);
		SetFixTimer(EnumLuaModule_DAY, 0, 24 * 3600, INFINITY_CALL);
		//一周定时器
		SetTimer(EnumLuaModule_WEEK, NFTime::GetNextWeekRemainingTime() * 1000, 1);

		//一月定时器，多加了一秒，避免定时器32ms的误差
		uint64_t monthtime = NFTime::GetNextMonthRemainingTime() + 1;
		SetTimer(EnumLuaModule_MONTH, monthtime * 1000, 1);
	}
	else if (nTimerID == EnumLuaModule_SEC)
	{
		UpdateSec();
	}
	else if (nTimerID == EnumLuaModule_MIN)
	{
		UpdateMin();
	}
	else if (nTimerID == EnumLuaModule_5MIN)
	{
		Update5Min();
	}
	else if (nTimerID == EnumLuaModule_10MIN)
	{
		Update10Min();
	}
	else if (nTimerID == EnumLuaModule_30MIN)
	{
		Update30Min();
	}
	else if (nTimerID == EnumLuaModule_HOUR)
	{
		UpdateHour();
	}
	else if (nTimerID == EnumLuaModule_DAY)
	{
		UpdateDay();
	}
	else if (nTimerID == EnumLuaModule_WEEK)
	{
		UpdateWeek();
	}
	else if (nTimerID == EnumLuaModule_MONTH)
	{
		UpdateMonth();
	}
    return 0;
}

bool NFCLuaScriptModule::AfterInit()
{
    return true;
}

bool NFCLuaScriptModule::ReadyExecute()
{
	return true;
}

bool NFCLuaScriptModule::Shut()
{
    return true;
}

bool NFCLuaScriptModule::Finalize()
{
	for (auto iter = m_luaTimerMap.begin(); iter != m_luaTimerMap.end(); iter++)
	{
		NF_SAFE_DELETE(iter->second);
	}

	for (auto iter = m_luaTimerList.begin(); iter != m_luaTimerList.end(); iter++)
	{
		NF_SAFE_DELETE(*iter);
	}
	
	m_luaTimerList.clear();
	m_luaTimerMap.clear();
    return true;
}

bool NFCLuaScriptModule::Execute()
{
	for (auto iter = m_luaTimerMap.begin(); iter != m_luaTimerMap.end();)
	{
		auto pTimer = iter->second;
		if (pTimer)
		{
			if (pTimer->mCallCount != INFINITY_CALL)
			{
				if (pTimer->mCurCallCount >= pTimer->mCallCount)
				{
					iter = m_luaTimerMap.erase(iter);
					pTimer->Clear();
					m_luaTimerList.push_back(pTimer);
					continue;
				}
			}
		}
		iter++;
	}
    return true;
}

bool NFCLuaScriptModule::BeforeShut()
{
    return true;
}

void NFCLuaScriptModule::LoadScript()
{
	TryAddPackagePath(m_pObjPluginManager->GetLuaScriptPath());
	TryLoadScriptFile("init.lua");
	TryRunGlobalScriptFunc("LuaNFrame.InitScript", this);
}

const std::string& NFCLuaScriptModule::GetAppName() const
{
	return m_pObjPluginManager->GetAppName();
}

int NFCLuaScriptModule::GetAppID() const
{
	return m_pObjPluginManager->GetAppID();
}

uint64_t NFCLuaScriptModule::GetInitTime() const
{
	return m_pObjPluginManager->GetInitTime();
}

uint64_t NFCLuaScriptModule::GetNowTime() const
{
	return m_pObjPluginManager->GetNowTime();
}

std::string NFCLuaScriptModule::GetMD5(const std::string& str)
{
	return NFMD5::md5str(str);
}

uint32_t NFCLuaScriptModule::GetCRC32(const std::string& s)
{
	return NFCRC32::Sum(s);
}

uint16_t NFCLuaScriptModule::GetCRC16(const std::string& s)
{
	return NFCRC16::Sum(s);
}

std::string NFCLuaScriptModule::Base64Encode(const std::string& s)
{
	return NFBase64::Encode(s);
}

std::string NFCLuaScriptModule::Base64Decode(const std::string& s)
{
	return NFBase64::Decode(s);
}

uint64_t NFCLuaScriptModule::GetMsecTime() const
{
	return NFTime::Now().UnixMSec();
}

uint64_t NFCLuaScriptModule::GetSecTime() const
{
	return NFTime::Now().UnixSec();
}

void NFCLuaScriptModule::LuaDebug(uint32_t logId, uint64_t guid, const std::string& str)
{
    NFLogDebug(logId, guid, "{}", str);
}

void NFCLuaScriptModule::LuaInfo(uint32_t logId, uint64_t guid, const std::string& str)
{
    NFLogInfo(logId, guid, "{}", str);
}

void NFCLuaScriptModule::LuaWarn(uint32_t logId, uint64_t guid, const std::string& str)
{
    NFLogWarning(logId, guid, "{}", str);
}

void NFCLuaScriptModule::LuaError(uint32_t logId, uint64_t guid, const std::string& str)
{
    NFLogError(logId, guid, "{}", str);
}


void NFCLuaScriptModule::ProcessWork(const std::string& luaFunc, const NFLuaRef& dataStr)
{
	NFLuaTimer* luaTimer = nullptr;
	if (m_luaTimerList.empty())
	{
		luaTimer = NF_NEW NFLuaTimer(this, m_pObjPluginManager);
	}
	else
	{
		luaTimer = m_luaTimerList.front();
		m_luaTimerList.pop_front();
		luaTimer->m_pLuaScriptModule = this;
	}

	luaTimer->mGlobalLuaFunc = "LuaNFrame.DispatchWorker";
	luaTimer->mInterVal = 1;
	luaTimer->mLuaFunc = luaFunc;
	luaTimer->mDataStr = dataStr;
	luaTimer->mCallCount = 1;

	luaTimer->mCurCallCount = 0;
	luaTimer->mTimerId = ++m_luaTimerIndex;

	luaTimer->SetTimer(luaTimer->mTimerId, luaTimer->mInterVal, luaTimer->mCallCount);
	m_luaTimerMap.emplace(luaTimer->mTimerId, luaTimer);
}

void NFCLuaScriptModule::BeginProfiler(const std::string& funcName)
{
	m_pObjPluginManager->BeginProfiler(funcName);
}

uint64_t NFCLuaScriptModule::EndProfiler()
{
	return m_pObjPluginManager->EndProfiler();
}

std::string NFCLuaScriptModule::Sha256(const std::string& s)
{
	std::string ret;
	NFSha256::hash256_hex_string(s, ret);
	return ret;
}

bool NFCLuaScriptModule::Register()
{
	LuaIntf::LuaBinding(*m_pLuaContext).beginClass<NFCLuaScriptModule>("NFCLuaScriptModule")
		.addFunction("GetAppName", &NFCLuaScriptModule::GetAppName)
		.addFunction("GetAppID", &NFCLuaScriptModule::GetAppID)
		.addFunction("GetInitTime", &NFCLuaScriptModule::GetInitTime)
		.addFunction("GetNowTime", &NFCLuaScriptModule::GetNowTime)
		.addFunction("GetMsecTime", &NFCLuaScriptModule::GetMsecTime)
		.addFunction("GetSecTime", &NFCLuaScriptModule::GetSecTime)
		.addFunction("GetMD5", &NFCLuaScriptModule::GetMD5)
		.addFunction("GetCRC32", &NFCLuaScriptModule::GetCRC32)
		.addFunction("GetCRC16", &NFCLuaScriptModule::GetCRC16)
		.addFunction("Base64Encode", &NFCLuaScriptModule::Base64Encode)
		.addFunction("Base64Decode", &NFCLuaScriptModule::Base64Decode)
		.addFunction("AddTimer", &NFCLuaScriptModule::AddTimer)
		.addFunction("StopTimer", &NFCLuaScriptModule::StopTimer)
		.addFunction("AddClocker", &NFCLuaScriptModule::AddClocker)
		.addFunction("StopClocker", &NFCLuaScriptModule::StopClocker)
		.addFunction("LuaDebug", &NFCLuaScriptModule::LuaDebug)
		.addFunction("LuaInfo", &NFCLuaScriptModule::LuaInfo)
		.addFunction("LuaWarn", &NFCLuaScriptModule::LuaWarn)
		.addFunction("LuaError", &NFCLuaScriptModule::LuaError)
		.addFunction("ProcessWork", &NFCLuaScriptModule::ProcessWork)
		.addFunction("BeginProfiler", &NFCLuaScriptModule::BeginProfiler)
		.addFunction("EndProfiler", &NFCLuaScriptModule::EndProfiler)
		.addFunction("Sha256", &NFCLuaScriptModule::Sha256)
		.addFunction("Platform", &NFCLuaScriptModule::Platform)
		.addFunction("IsThreadModule", &NFCLuaScriptModule::IsThreadModule)
        .addFunction("SendErrorLog", &NFCLuaScriptModule::SendErrorLog)
		.endClass();
	return true;
}

void NFCLuaScriptModule::RunHttpRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint32_t requestId, const std::string& firstPath, const std::string& secondPath, const std::string& strMsg)
{
	TryRunGlobalScriptFunc(luaFunc, unLinkId, requestId, firstPath, secondPath, strMsg);
}

void NFCLuaScriptModule::RunNetRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t opreateId, const uint32_t nMsgId, const std::string& strMsg)
{
	TryRunGlobalScriptFunc(luaFunc, unLinkId, valueId, opreateId, nMsgId, strMsg);
}

void NFCLuaScriptModule::RunNetRecvLuaFuncWithMainSub(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t opreateId, const uint16_t nMainMsgId, const uint16_t nSubMsgId, const std::string& strMsg)
{
	TryRunGlobalScriptFunc(luaFunc, unLinkId, valueId, opreateId, nMainMsgId, nSubMsgId, strMsg);
}

void NFCLuaScriptModule::SessionReport(uint64_t playerId, const std::string& report)
{
	TryRunGlobalScriptFunc("TcpSessionReport", playerId, report);
}

void NFCLuaScriptModule::SessionClose(uint64_t playerId)
{
	TryRunGlobalScriptFunc("TcpSessionClose", playerId);
}

void NFCLuaScriptModule::RunGmFunction(const std::string& luaFunc, const std::vector<std::string>& vecStr)
{
	auto size = vecStr.size();
	if (size == 1)
	{
		TryRunGlobalScriptFunc(luaFunc, vecStr[0]);
	}
	else if (size == 2)
	{
		TryRunGlobalScriptFunc(luaFunc, vecStr[0], vecStr[1]);
	}
	else if (size == 3)
	{
		TryRunGlobalScriptFunc(luaFunc, vecStr[0], vecStr[1], vecStr[2]);
	}
	else if (size == 4)
	{
		TryRunGlobalScriptFunc(luaFunc, vecStr[0], vecStr[1], vecStr[2], vecStr[3]);
	}
	else if (size == 5)
	{
		TryRunGlobalScriptFunc(luaFunc, vecStr[0], vecStr[1], vecStr[2], vecStr[3], vecStr[4]);
	}
}

void NFCLuaScriptModule::SendErrorLog(uint64_t id, const std::string& funcLog, const std::string& errorLog, uint32_t count)
{
    std::string luaErrorLog;
    NF_FORMAT_EXPR(luaErrorLog, "id:{} luaFunc:{} errorLog:{} errorCount:{}", id, funcLog, errorLog, count);
    NFGlobalSystem::Instance()->GetGlobalPluginManager()->SendDumpInfo(luaErrorLog);
}

void NFCLuaScriptModule::StopTimer(uint32_t nTimerID)
{
	auto iter = m_luaTimerMap.find(nTimerID);
	if (iter != m_luaTimerMap.end())
	{
		NFLuaTimer* luaTimer = iter->second;
		luaTimer->KillTimer(nTimerID);

		m_luaTimerMap.erase(iter);
		luaTimer->Clear();
		m_luaTimerList.push_back(luaTimer);
	}
}

void NFCLuaScriptModule::StopClocker(uint32_t nTimerID)
{
	StopTimer(nTimerID);
}

uint32_t NFCLuaScriptModule::AddTimer(const std::string& luaFunc, uint64_t nInterVal, uint32_t nCallCount, const NFLuaRef& dataStr)
{
	NFLuaTimer* luaTimer = nullptr;
	if (m_luaTimerList.empty())
	{
		luaTimer = NF_NEW NFLuaTimer(this, m_pObjPluginManager);
	}
	else
	{
		luaTimer = m_luaTimerList.front();
		m_luaTimerList.pop_front();
		luaTimer->m_pLuaScriptModule = this;
	}

	luaTimer->mLuaFunc = luaFunc;
	luaTimer->mInterVal = nInterVal;
	luaTimer->mDataStr = dataStr;

	if (nCallCount == 0)
	{
		luaTimer->mCallCount = INFINITY_CALL;
	}
	else
	{
		luaTimer->mCallCount = nCallCount;
	}

	luaTimer->mCurCallCount = 0;
	luaTimer->mTimerId = ++m_luaTimerIndex;

	luaTimer->SetTimer(luaTimer->mTimerId, luaTimer->mInterVal, luaTimer->mCallCount);
	m_luaTimerMap.emplace(luaTimer->mTimerId, luaTimer);

	return luaTimer->mTimerId;
}

uint32_t NFCLuaScriptModule::AddClocker(const std::string& luaFunc, uint64_t nStartTime, uint32_t nInterDays, uint32_t nCallCount, const NFLuaRef& dataStr)
{
	NFLuaTimer* luaTimer = nullptr;
	if (m_luaTimerList.empty())
	{
		luaTimer = NF_NEW NFLuaTimer(this, m_pObjPluginManager);
	}
	else
	{
		luaTimer = m_luaTimerList.front();
		m_luaTimerList.pop_front();
		luaTimer->m_pLuaScriptModule = this;
	}

	luaTimer->mLuaFunc = luaFunc;
	luaTimer->mDataStr = dataStr;

	if (nCallCount == 0)
	{
		luaTimer->mCallCount = INFINITY_CALL;
	}
	else
	{
		luaTimer->mCallCount = nCallCount;
	}
	luaTimer->mCurCallCount = 0;
	luaTimer->mTimerId = ++m_luaTimerIndex;

	luaTimer->SetFixTimer(luaTimer->mTimerId, nStartTime, nInterDays, luaTimer->mCallCount);
	m_luaTimerMap.emplace(luaTimer->mTimerId, luaTimer);
	return luaTimer->mTimerId;
}

void NFCLuaScriptModule::ReloadAllLuaFiles()
{
	TryRunGlobalScriptFunc("NFLuaReload.ReloadAll");
}

void NFCLuaScriptModule::ReloadLuaFiles()
{
	TryRunGlobalScriptFunc("NFLuaReload.ReloadFile");
}

void NFCLuaScriptModule::ReloadLuaFiles(const std::vector<std::string>& vecStr)
{
	if (vecStr.empty())
	{
		TryRunGlobalScriptFunc("NFLuaReload.ReloadFile");
	}
	else
	{
		TryRunGlobalScriptFunc("NFLuaReload.ReloadFile", vecStr);
	}
	
}

std::string NFCLuaScriptModule::Platform()
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	return "win32";
#else
	return "linux";
#endif
}

bool NFCLuaScriptModule::IsThreadModule()
{
	return false;
}

void NFCLuaScriptModule::UpdateSec()
{
	TryRunGlobalScriptFunc("LuaNFrame.UpdateSec");
}

void NFCLuaScriptModule::UpdateMin()
{
	TryRunGlobalScriptFunc("LuaNFrame.UpdateMin");
}

void NFCLuaScriptModule::Update5Min()
{
	TryRunGlobalScriptFunc("LuaNFrame.Update5Min");
}

void NFCLuaScriptModule::Update10Min()
{
	TryRunGlobalScriptFunc("LuaNFrame.Update10Min");
}

void NFCLuaScriptModule::Update30Min()
{
	TryRunGlobalScriptFunc("LuaNFrame.Update30Min");
}

void NFCLuaScriptModule::UpdateHour()
{
	TryRunGlobalScriptFunc("LuaNFrame.UpdateHour");
}

void NFCLuaScriptModule::UpdateDay()
{
	TryRunGlobalScriptFunc("LuaNFrame.UpdateDay");
}

void NFCLuaScriptModule::UpdateWeek()
{
	TryRunGlobalScriptFunc("LuaNFrame.UpdateWeek");
	SetTimer(EnumLuaModule_WEEK, 7 * 24 * 3600 * 1000, 1);
}

void NFCLuaScriptModule::UpdateMonth()
{
	TryRunGlobalScriptFunc("LuaNFrame.UpdateMonth");
	//一月定时器，多加了一秒，避免定时器32ms的误差
	uint64_t monthtime = NFTime::GetNextMonthRemainingTime() + 1;
	SetTimer(EnumLuaModule_MONTH, monthtime * 1000, 1);
}