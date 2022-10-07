// -------------------------------------------------------------------------
//    @FileName         :    NFCLuaScriptModule.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-01-02
//    @Module           :    NFCLuaScriptModule
//    @Desc             :
// -------------------------------------------------------------------------

#include <assert.h>
#include <set>
#include "NFCLuaScriptModule.h"

#include "NFComm/NFCore/NFMMOMD5.h"
#include "NFComm/NFCore/NFCRC32.h"
#include "NFComm/NFCore/NFCRC16.h"
#include "NFComm/NFCore/NFBase64.h"
#include "NFComm/NFCore/NFSha256.h"
#include "NFComm/NFPluginModule/NFEventMgr.h"
#include "NFComm/NFPluginModule/NFEventDefine.h"
#include "NFMessageDefine/server_to_server_msg.pb.h"
#include "NFServerLogic/NFServerLogicCommon/NFServerLogicCommon.h"
#include "NFComm/NFPluginModule/NFCurlHttpClient.h"

enum EnumLuaScriptTimer
{
	EnumLuaScriptTimer_ServerLoop = 0,
};

void NFLuaTimer::OnTimer(uint32_t nTimerID)
{
	mCurCallCount++;
	if (mGlobalLuaFunc == "LuaNFrame.DispatchTimerLoop")
	{
		m_pLuaScriptModule->BeginProfiler("LuaNFrame.DispatchTimerLoop--"+ mTmpStr);
		m_pLuaScriptModule->TryRunGlobalScriptFunc("LuaNFrame.DispatchTimerLoop", mTmpStr);
		m_pLuaScriptModule->EndProfiler();
	}
	else if (mGlobalLuaFunc == "LuaNFrame.DispatchTimerOnce")
	{
		m_pLuaScriptModule->BeginProfiler("LuaNFrame.DispatchTimerOnce--"+mLuaFunc);
		m_pLuaScriptModule->TryRunGlobalScriptFunc("LuaNFrame.DispatchTimerOnce", mLuaFunc, mDataStr);
		m_pLuaScriptModule->EndProfiler();
	}
	else if (mGlobalLuaFunc == "LuaNFrame.DispatchWorker")
	{
		m_pLuaScriptModule->BeginProfiler("LuaNFrame.DispatchWorker--"+ mLuaFunc);
		m_pLuaScriptModule->TryRunGlobalScriptFunc("LuaNFrame.DispatchWorker", mLuaFunc, mDataStr);
		m_pLuaScriptModule->EndProfiler();
	}
	else
	{
		m_pLuaScriptModule->BeginProfiler("LuaNFrame.DispatchTimer--"+ mLuaFunc);
		m_pLuaScriptModule->TryRunGlobalScriptFunc("LuaNFrame.DispatchTimer", mLuaFunc, mDataStr);
		m_pLuaScriptModule->EndProfiler();
	}
}

bool NFCLuaScriptModule::Init()
{
//#if NF_PLATFORM == NF_PLATFORM_WIN
//	SetConsoleOutputCP(CP_UTF8);
//#endif
	m_pNetServerModule = m_pPluginManager->FindModule<NFINetServerModule>();
	m_pNetClientModule = m_pPluginManager->FindModule<NFINetClientModule>();
	m_pLogModule = m_pPluginManager->FindModule<NFILogModule>();
	m_pHttpServerModule = m_pPluginManager->FindModule<NFIHttpServerModule>();

	if (m_pPluginManager->IsLoadAllServer())
	{
		FindModule<NFIServerNetEventModule>()->AddAccountEventCallBack(NF_ST_GAME, this, &NFCLuaScriptModule::OnAccountEventCallBack);
	}
	else
	{
		FindModule<NFIServerNetEventModule>()->AddAccountEventCallBack(NF_ST_GAME, this, &NFCLuaScriptModule::OnAccountEventCallBack);
		FindModule<NFIServerNetEventModule>()->AddAccountEventCallBack(NF_ST_WORLD, this, &NFCLuaScriptModule::OnAccountEventCallBack);
		FindModule<NFIServerNetEventModule>()->AddAccountEventCallBack(NF_ST_LOGIN, this, &NFCLuaScriptModule::OnAccountEventCallBack);
	}
	SetTimer(EnumLuaModule_INIT, 1000, 1);
    return true;
}

void NFCLuaScriptModule::OnTimer(uint32_t nTimerID)
{
	if (nTimerID == EnumLuaModule_INIT)
	{
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

		NFMsg::ServerErrorLogMsg msg;
		NFEventMgr::GetSingletonPtr()->FireExecute(NFEVENT_LUA_FINISH_LOAD, 0, 0, msg);
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
	TryAddPackagePath(m_pPluginManager->GetLuaScriptPath());
	TryLoadScriptFile("init.lua");
	TryRunGlobalScriptFunc("LuaNFrame.InitScript", this);

	TryRunGlobalScriptFunc("LuaNFrame.TimerInit");
}

const std::string& NFCLuaScriptModule::GetAppName() const
{
	return m_pPluginManager->GetAppName();
}

int NFCLuaScriptModule::GetAppID() const
{
	return m_pPluginManager->GetAppID();
}

uint64_t NFCLuaScriptModule::GetInitTime() const
{
	return m_pPluginManager->GetInitTime();
}

uint64_t NFCLuaScriptModule::GetNowTime() const
{
	return m_pPluginManager->GetNowTime();
}

std::string NFCLuaScriptModule::GetMD5(const std::string& str)
{
	return NFMMOMD5(str).toStr();
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

void NFCLuaScriptModule::SendMsgToPlayer(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetServerModule)
	{
		if (usLinkId != 0)
		{
			m_pNetServerModule->SendByServerID(usLinkId, nMsgID, strData, nPlayerID, 0);
		}
		else
		{
			if (nPlayerID != 0)
			{
				auto pPlayerInfo = GetPlayerInfo(nPlayerID);
				if (pPlayerInfo)
				{
					m_pNetServerModule->SendByServerID(pPlayerInfo->GetProxyUnlinkId(), nMsgID, strData, nPlayerID, 0);
				}
			}
		}
	}
}

void NFCLuaScriptModule::SendMsgToManyPlayer(const std::vector<uint64_t>& nVecPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetServerModule)
	{
		for (size_t i = 0; i < nVecPlayerID.size(); i++)
		{
			uint64_t nPlayerID = nVecPlayerID[i];
			if (nPlayerID != 0)
			{
				auto pPlayerInfo = GetPlayerInfo(nPlayerID);
				if (pPlayerInfo)
				{
					m_pNetServerModule->SendByServerID(pPlayerInfo->GetProxyUnlinkId(), nMsgID, strData, nPlayerID, 0);
				}
			}
		}
	}
}

void NFCLuaScriptModule::SendMsgToAllPlayer(const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetServerModule)
	{
		auto pPlayerInfo = mPlayerProxyInfoMap.First();
		while (pPlayerInfo)
		{	
			m_pNetServerModule->SendByServerID(pPlayerInfo->GetProxyUnlinkId(), nMsgID, strData, pPlayerInfo->GetPlayerId(), 0);
			pPlayerInfo = mPlayerProxyInfoMap.Next();
		}
	}
}

void NFCLuaScriptModule::SendMsgToMaster(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetClientModule)
	{
		if (usLinkId != 0)
		{
			m_pNetClientModule->SendByServerID(usLinkId, nMsgID, strData, nPlayerID, 0);
		}
	}
}

void NFCLuaScriptModule::SendMsgToPlayer_MainSub(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetServerModule)
	{
		if (usLinkId != 0)
		{
			m_pNetServerModule->SendByServerID(usLinkId, nMainMsgID, nSubMsgID, strData, nPlayerID, 0);
		}
		else
		{
			if (nPlayerID != 0)
			{
				auto pPlayerInfo = GetPlayerInfo(nPlayerID);
				if (pPlayerInfo)
				{
					m_pNetServerModule->SendByServerID(pPlayerInfo->GetProxyUnlinkId(), nMainMsgID, nSubMsgID, strData, nPlayerID, 0);
				}
			}
		}
	}
}

void NFCLuaScriptModule::SendMsgToManyPlayer_MainSub(const std::vector<uint64_t>& nVecPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetServerModule)
	{
		for (size_t i = 0; i < nVecPlayerID.size(); i++)
		{
			uint64_t nPlayerID = nVecPlayerID[i];
			if (nPlayerID != 0)
			{
				auto pPlayerInfo = GetPlayerInfo(nPlayerID);
				if (pPlayerInfo)
				{
					m_pNetServerModule->SendByServerID(pPlayerInfo->GetProxyUnlinkId(), nMainMsgID, nSubMsgID, strData, nPlayerID, 0);
				}
			}
		}
	}
}

void NFCLuaScriptModule::SendMsgToAllPlayer_MainSub(const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetServerModule)
	{
		auto pPlayerInfo = mPlayerProxyInfoMap.First();
		while (pPlayerInfo)
		{
			m_pNetServerModule->SendByServerID(pPlayerInfo->GetProxyUnlinkId(), nMainMsgID, nSubMsgID, strData, pPlayerInfo->GetPlayerId(), 0);
			pPlayerInfo = mPlayerProxyInfoMap.Next();
		}
	}
}

void NFCLuaScriptModule::SendMsgToMaster_MainSub(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetClientModule)
	{
		if (usLinkId != 0)
		{
			m_pNetClientModule->SendByServerID(usLinkId, nMainMsgID, nSubMsgID, strData, nPlayerID, 0);
		}
	}
}

void NFCLuaScriptModule::SendMsgToHttpServer(uint32_t servertype, const uint32_t requestId, const std::string& strMsg)
{
	if (m_pHttpServerModule)
	{
		m_pHttpServerModule->ResponseMsg((NF_SERVER_TYPES)servertype, requestId, strMsg, NFWebStatus::WEB_OK, "OK");
	}
}

void NFCLuaScriptModule::SetDefaultLevel(uint32_t log_level)
{
	if (m_pLogModule)
	{
		m_pLogModule->SetDefaultLevel((NF_LOG_LEVEL)log_level);
	}
}

void NFCLuaScriptModule::SetDefaultFlush(uint32_t log_level)
{
	if (m_pLogModule)
	{
		m_pLogModule->SetDefaultFlush((NF_LOG_LEVEL)log_level);
	}
}

void NFCLuaScriptModule::LuaDebug(uint32_t logId, uint64_t guid, const std::string& str)
{
	if (m_pLogModule)
	{
		m_pLogModule->LuaDebug(logId, guid, str);
	}
}

void NFCLuaScriptModule::LuaInfo(uint32_t logId, uint64_t guid, const std::string& str)
{
	if (m_pLogModule)
	{
		m_pLogModule->LuaInfo(logId, guid, str);
	}
}

void NFCLuaScriptModule::LuaWarn(uint32_t logId, uint64_t guid, const std::string& str)
{
	if (m_pLogModule)
	{
		m_pLogModule->LuaWarn(logId, guid, str);
	}
}

void NFCLuaScriptModule::LuaError(uint32_t logId, uint64_t guid, const std::string& str)
{
	if (m_pLogModule)
	{
		m_pLogModule->LuaError(logId, guid, str);
	}
}


void NFCLuaScriptModule::ProcessWork(const std::string& luaFunc, const NFLuaRef& dataStr)
{
	NFLuaTimer* luaTimer = nullptr;
	if (m_luaTimerList.empty())
	{
		luaTimer = NF_NEW NFLuaTimer(this);
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

void NFCLuaScriptModule::ProcessTimer(uint32_t timeSec, const std::string& luaFunc, const NFLuaRef& dataStr)
{
	if (timeSec <= 0)
	{
		timeSec = 1;
	}

	NFLuaTimer* luaTimer = nullptr;
	if (m_luaTimerList.empty())
	{
		luaTimer = NF_NEW NFLuaTimer(this);
	}
	else
	{
		luaTimer = m_luaTimerList.front();
		m_luaTimerList.pop_front();
		luaTimer->m_pLuaScriptModule = this;
	}

	luaTimer->mGlobalLuaFunc = "LuaNFrame.DispatchTimerOnce";
	luaTimer->mLuaFunc = luaFunc;
	luaTimer->mInterVal = timeSec;
	luaTimer->mDataStr = dataStr;
	luaTimer->mCallCount = 1;


	luaTimer->mCurCallCount = 0;
	luaTimer->mTimerId = ++m_luaTimerIndex;

	luaTimer->SetTimer(luaTimer->mTimerId, luaTimer->mInterVal, luaTimer->mCallCount);
	m_luaTimerMap.emplace(luaTimer->mTimerId, luaTimer);
}

void NFCLuaScriptModule::ProcessLoopTimer(uint32_t timeSec, const std::string& luaFunc, const NFLuaRef& dataStr)
{
	ProcessTimer(timeSec, luaFunc, dataStr);
}

void NFCLuaScriptModule::BeginProfiler(const std::string& funcName)
{
	m_pPluginManager->BeginProfiler(funcName);
}

uint64_t NFCLuaScriptModule::EndProfiler()
{
	return m_pPluginManager->EndProfiler();
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
		.addFunction("SetDefaultLevel", &NFCLuaScriptModule::SetDefaultLevel)
		.addFunction("SetDefaultFlush", &NFCLuaScriptModule::SetDefaultFlush)
		.addFunction("LuaDebug", &NFCLuaScriptModule::LuaDebug)
		.addFunction("LuaInfo", &NFCLuaScriptModule::LuaInfo)
		.addFunction("LuaWarn", &NFCLuaScriptModule::LuaWarn)
		.addFunction("LuaError", &NFCLuaScriptModule::LuaError)
		.addFunction("SendMsgToPlayer", &NFCLuaScriptModule::SendMsgToPlayer)
		.addFunction("SendMsgToManyPlayer", &NFCLuaScriptModule::SendMsgToManyPlayer)
		.addFunction("SendMsgToAllPlayer", &NFCLuaScriptModule::SendMsgToAllPlayer)
		.addFunction("SendMsgToMaster", &NFCLuaScriptModule::SendMsgToMaster)
		.addFunction("SendMsgToPlayer_MainSub", &NFCLuaScriptModule::SendMsgToPlayer_MainSub)
		.addFunction("SendMsgToManyPlayer_MainSub", &NFCLuaScriptModule::SendMsgToManyPlayer_MainSub)
		.addFunction("SendMsgToAllPlayer_MainSub", &NFCLuaScriptModule::SendMsgToAllPlayer_MainSub)
		.addFunction("SendMsgToMaster_MainSub", &NFCLuaScriptModule::SendMsgToMaster_MainSub)
		.addFunction("ProcessWork", &NFCLuaScriptModule::ProcessWork)
		.addFunction("ProcessTimer", &NFCLuaScriptModule::ProcessTimer)
		.addFunction("ProcessLoopTimer", &NFCLuaScriptModule::ProcessLoopTimer)
		.addFunction("BeginProfiler", &NFCLuaScriptModule::BeginProfiler)
		.addFunction("EndProfiler", &NFCLuaScriptModule::EndProfiler)
		.addFunction("Sha256", &NFCLuaScriptModule::Sha256)
		.addFunction("Platfrom", &NFCLuaScriptModule::Platfrom)
		.addFunction("IsThreadModule", &NFCLuaScriptModule::IsThreadModule)
		.addFunction("SendErrorLog", &NFCLuaScriptModule::SendErrorLog)
		.addFunction("SendMsgToHttpServer", &NFCLuaScriptModule::SendMsgToHttpServer)
		.addFunction("HttpGet", &NFCLuaScriptModule::HttpGet)
		.addFunction("HttpGetWithHead", &NFCLuaScriptModule::HttpGetWithHead)
		.addFunction("HttpPost", &NFCLuaScriptModule::HttpPost)
		.addFunction("HttpPostWithHead", &NFCLuaScriptModule::HttpPostWithHead)
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
		luaTimer = NF_NEW NFLuaTimer(this);
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
		luaTimer = NF_NEW NFLuaTimer(this);
	}
	else
	{
		NFLuaTimer* luaTimer = m_luaTimerList.front();
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

void NFCLuaScriptModule::OnAccountEventCallBack(uint32_t nEvent, uint32_t unLinkId, NF_SHARE_PTR<PlayerGameServerInfo> pServerData)
{
	if(nEvent == eAccountEventType_CONNECTED)
	{
		if (mPlayerProxyInfoMap.ExistElement(pServerData->GetPlayerId()))
		{
			mPlayerProxyInfoMap.RemoveElement(pServerData->GetPlayerId());
		}
		mPlayerProxyInfoMap.AddElement(pServerData->GetPlayerId(), pServerData);
	}
	else if (nEvent == eAccountEventType_DISCONNECTED)
	{
		if (mPlayerProxyInfoMap.ExistElement(pServerData->GetPlayerId()))
		{
			mPlayerProxyInfoMap.RemoveElement(pServerData->GetPlayerId());
		}
	}
	else if (nEvent == eAccountEventType_RECONNECTED)
	{
		if (mPlayerProxyInfoMap.ExistElement(pServerData->GetPlayerId()))
		{
			mPlayerProxyInfoMap.RemoveElement(pServerData->GetPlayerId());
		}
		mPlayerProxyInfoMap.AddElement(pServerData->GetPlayerId(), pServerData);
	}
}

NF_SHARE_PTR<PlayerGameServerInfo> NFCLuaScriptModule::GetPlayerInfo(uint64_t playerId)
{
	return mPlayerProxyInfoMap.GetElement(playerId);
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

std::string NFCLuaScriptModule::Platfrom()
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

void NFCLuaScriptModule::SendErrorLog(uint64_t playerId, const std::string& func_log, const std::string& errorLog)
{
	NFMsg::ServerErrorLogMsg msg;
	msg.set_error_log(errorLog);
	msg.set_func_log(func_log);
	msg.set_player_id(playerId);
	msg.set_server_name(m_pPluginManager->GetAppName());

	NFEventMgr::Instance()->FireExecute(NFEVENT_LUA_ERROR_LOG, playerId, 0, msg);
}

std::string NFCLuaScriptModule::HttpGet(const std::string& url)
{
	std::string strResp;
	int ret = NFCurlHttpClient::GetSingletonPtr()->Gets(url, strResp);
	if (ret != 0)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "HttpPost url:{}, return error code:{}, strError:{}", url, ret, NFCurlHttpClient::GetSingletonPtr()->GetStrError(ret));
	}
	return strResp;
}

std::string NFCLuaScriptModule::HttpGetWithHead(const std::string& url, const std::map<std::string, std::string>& xHeaders)
{
	std::string strResp;
	int ret = NFCurlHttpClient::GetSingletonPtr()->Gets(url, strResp);
	if (ret != 0)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "HttpPost url:{}, return error code:{}, strError:{}", url, ret, NFCurlHttpClient::GetSingletonPtr()->GetStrError(ret));
	}
	return strResp;
}

std::string NFCLuaScriptModule::HttpPost(const std::string& url, const std::string& postContent)
{
	std::string strResp;
	int ret = NFCurlHttpClient::GetSingletonPtr()->Posts(url, postContent, strResp);
	if (ret != 0)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "HttpPost url:{}, return error code:{}, strError:{}, strError:{}", url, ret, NFCurlHttpClient::GetSingletonPtr()->GetStrError(ret));
	}
	return strResp;
}

std::string NFCLuaScriptModule::HttpPostWithHead(const std::string& url, const std::string& postContent, const std::map<std::string, std::string>& xHeaders)
{
	std::string strResp;
	int ret = NFCurlHttpClient::GetSingletonPtr()->Posts(url, postContent, strResp);
	if (ret != 0)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "HttpPost url:{}, return error code:{}, strError:{}", url, ret, NFCurlHttpClient::GetSingletonPtr()->GetStrError(ret));
	}
	return strResp;
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