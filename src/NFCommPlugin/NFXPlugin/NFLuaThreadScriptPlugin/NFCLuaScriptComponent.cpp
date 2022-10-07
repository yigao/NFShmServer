// -------------------------------------------------------------------------
//    @FileName         :    NFCLuaScriptComponent.cpp
//    @Author           :    GaoYi
//    @Date             :    2018/08/26
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFCLuaScriptComponent.h"
#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFCLuaThreadModule.h"
#include "NFComm/NFCore/NFMMOMD5.h"
#include "NFComm/NFCore/NFCRC32.h"
#include "NFComm/NFCore/NFCRC16.h"
#include "NFComm/NFCore/NFBase64.h"
#include "NFComm/NFCore/NFSha256.h"
#include "NFComm/NFPluginModule/NFCurlHttpClient.h"

bool NFProcessRealTimerActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->Do_ProcessRealTimer(m_luaFunc, m_param);
	}
	return true;
}

bool NFProcessTimerActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->Do_ProcessTimer(m_luaFunc, m_param);
	}
	return true;
}

bool NFProcessLoopTimerActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->Do_ProcessLoopTimer(m_luaFunc, m_param);
	}
	return true;
}

bool NFWorkActorLoadTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->Register();
		m_pComponent->LoadScript();
	}
	return true;
}

bool NFWorkActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->Do_ProcessWork(m_luaFunc, m_param);
	}
	return true;
}

bool NFServerLoopLoadTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->Register();
		m_pComponent->LoadScript();
	}
	return true;
}

NFServerLoopLoadTask::TPTaskState NFServerLoopLoadTask::MainThreadProcess()
{
	m_pLuaThreadModule->AddFinishLoad();
	return TPTASK_STATE_COMPLETED;
}

bool NFServerLoopInitTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->ProcessInit(m_param);
	}
	return true;
}

NFServerLoopTask::TPTaskState NFServerLoopInitTask::MainThreadProcess()
{
	m_pLuaThreadModule->AddFinishInitServerLoop();
	return TPTASK_STATE_COMPLETED;
}

bool NFServerLoopTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->ProcessLoop(m_param);
	}
	return true;
}

NFServerLoopTask::TPTaskState NFServerLoopTask::MainThreadProcess()
{
	return TPTASK_STATE_COMPLETED;
}

bool NFTcpMsgActorLoadTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->Register();
		m_pComponent->LoadScript();
	}
	return true;
}

bool NFTcpMsgActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TryRunGlobalScriptFunc(m_luaFunc, m_unLinkId, m_valueId, m_operateId, m_msgId, m_strMsg);
	}
	return true;
}

bool NFTcpMainSubMsgActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TryRunGlobalScriptFunc(m_luaFunc, m_unLinkId, m_valueId, m_operateId, m_mainMsgId, m_subMsgId, m_strMsg);
	}
	return true;
}

bool NFHttpMsgActorTask::ThreadProcess()
{
	m_pComponent->TryRunGlobalScriptFunc(m_luaFunc, m_unLinkId, m_requestId, m_firstPath, m_secondPath, m_strMsg);
	return true;
}

/**
**  异步线程处理函数，将在另一个线程里运行
*/
bool NFHotfixAllLuaActorTask::ThreadProcess()
{
	try
	{
		LuaIntf::LuaRef func(*m_pComponent->GetLuaContext(), "NFLuaReload.ReloadAll");
		LuaIntf::LuaRef retRef = func.call<LuaIntf::LuaRef>();
		if (retRef.isTable())
		{
			int len = retRef.len();
			for (int i = 1; i <= len; i++)
			{
				LuaIntf::LuaTableRef ref = retRef[i];
				std::string luapath = ref.value<std::string>();
				m_vecLuaFile.push_back(luapath);
			}
		}
		
		return true;
	}
	catch (LuaIntf::LuaException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return false;
}

/**
** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
	返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
*/
NFHotfixAllLuaActorTask::TPTaskState NFHotfixAllLuaActorTask::MainThreadProcess()
{
	if (m_vecLuaFile.empty() == false)
	{
		m_pLuaThreadModule->ReloadLuaFiles(m_vecLuaFile);
	}

	return TPTASK_STATE_COMPLETED;
}

/**
**  异步线程处理函数，将在另一个线程里运行
*/
bool NFHotfixLuaFilesActorTask::ThreadProcess()
{
	if (m_vecLuaFile.empty())
	{
		m_pComponent->TryRunGlobalScriptFunc("NFLuaReload.ReloadFile");
	}
	else
	{
		m_pComponent->TryRunGlobalScriptFunc("NFLuaReload.ReloadFile", m_vecLuaFile);
	}
	return true;
}

bool NFLuaGcActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->GcStep();
	}
	return true;
}

bool NFLuaMinActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TryRunGlobalScriptFunc("LuaNFrame.UpdateMin");
	}
	return true;
}

bool NFLua5MinActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TryRunGlobalScriptFunc("LuaNFrame.Update5Min");
	}
	return true;
}

bool NFLua10MinActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TryRunGlobalScriptFunc("LuaNFrame.Update10Min");
	}
	return true;
}

bool NFLua30MinActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TryRunGlobalScriptFunc("LuaNFrame.Update30Min");
	}
	return true;
}

bool NFLuaHourActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TryRunGlobalScriptFunc("LuaNFrame.UpdateHour");
	}
	return true;
}

bool NFLuaDayActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TryRunGlobalScriptFunc("LuaNFrame.UpdateDay");
	}
	return true;
}

bool NFLuaWeekActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TryRunGlobalScriptFunc("LuaNFrame.UpdateWeek");
	}
	return true;
}

bool NFLuaMonthActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TryRunGlobalScriptFunc("LuaNFrame.UpdateMonth");
	}
	return true;
}

/**
**  异步线程处理函数，将在另一个线程里运行
*/
bool NFTcpSessionCloseActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TcpSessionClose(m_playerId);
	}
	return true;
}

/**
**  异步线程处理函数，将在另一个线程里运行
*/
bool NFTcpSessionReportActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		m_pComponent->TcpSessionReport(m_playerId, m_ip);
	}
	return true;
}

bool NFRunGmFunctionActorTask::ThreadProcess()
{
	if (m_pComponent)
	{
		auto size = m_vecParams.size();
		if (size == 0)
		{
			m_pComponent->TryRunGlobalScriptFunc(m_luaFunction);
		}
		if (size == 1)
		{
			m_pComponent->TryRunGlobalScriptFunc(m_luaFunction, m_vecParams[0]);
		}
		else if (size == 2)
		{
			m_pComponent->TryRunGlobalScriptFunc(m_luaFunction, m_vecParams[0], m_vecParams[1]);
		}
		else if (size == 3)
		{
			m_pComponent->TryRunGlobalScriptFunc(m_luaFunction, m_vecParams[0], m_vecParams[1], m_vecParams[2]);
		}
		else if (size == 4)
		{
			m_pComponent->TryRunGlobalScriptFunc(m_luaFunction, m_vecParams[0], m_vecParams[1], m_vecParams[2], m_vecParams[3]);
		}
		else if (size == 5)
		{
			m_pComponent->TryRunGlobalScriptFunc(m_luaFunction, m_vecParams[0], m_vecParams[1], m_vecParams[2], m_vecParams[3], m_vecParams[4]);
		}
	}
	return true;
}


NFCLuaScriptComponent::NFCLuaScriptComponent(NFCLuaThreadModule* pLuaThreadModule, NFIPluginManager* p)
{
	m_pLuaThreadModule = pLuaThreadModule;
	m_pPluginManager = p;
	m_pLogModule = m_pPluginManager->FindModule<NFILogModule>();
	NFCurlHttpClient::GetSingletonPtr();
	ClearDeadCycle();
}

NFCLuaScriptComponent::~NFCLuaScriptComponent()
{
	NFCurlHttpClient::ReleaseInstance();
}

uint32_t NFCLuaScriptComponent::AddTimer(const std::string& luaFunc, uint64_t nInterVal, uint32_t nCallCount, const NFLuaRef& dataStr)
{
	std::string tmpStr;
	if (dataStr != nullptr)
	{
		try
		{
			tmpStr = dataStr.toValue<std::string>();
		}
		catch (LuaIntf::LuaException& e)
		{
			if (m_pLogModule)
			{
				m_pLogModule->LuaError(0, 0, "AddTimer, luaFunc:" + luaFunc + " err:" + std::string(e.what()));
			}
		}
	}
	m_pLuaThreadModule->AddRealTimer(nInterVal, nCallCount, luaFunc, tmpStr);
	return 0;
}

uint32_t NFCLuaScriptComponent::AddClocker(const std::string& luaFunc, uint64_t nStartTime, uint32_t nInterDays, uint32_t nCallCount, const NFLuaRef& dataStr)
{
	return 0;
}

void NFCLuaScriptComponent::StopTimer(uint32_t nTimerID)
{

}

void NFCLuaScriptComponent::StopClocker(uint32_t nTimerID)
{

}

uint64_t NFCLuaScriptComponent::GetMsecTime() const
{
	return NFTime::Now().UnixMSec();
}

uint64_t NFCLuaScriptComponent::GetSecTime() const
{
	return NFTime::Now().UnixSec();
}

void NFCLuaScriptComponent::SendErrorLog(uint64_t playerId, const std::string& func_log, const std::string& errorLog, uint32_t count)
{
	m_pLuaThreadModule->AddErrorLog(playerId, func_log, errorLog, count);
}

bool NFCLuaScriptComponent::Register()
{
	LuaIntf::LuaBinding(*m_pLuaContext).beginClass<NFCLuaScriptComponent>("NFCLuaScriptComponent")
		.addFunction("GetInitTime", &NFCLuaScriptComponent::GetInitTime)
		.addFunction("GetNowTime", &NFCLuaScriptComponent::GetNowTime)
		.addFunction("GetMsecTime", &NFCLuaScriptComponent::GetMsecTime)
		.addFunction("GetSecTime", &NFCLuaScriptComponent::GetSecTime)
		.addFunction("AddTimer", &NFCLuaScriptComponent::AddTimer)
		.addFunction("StopTimer", &NFCLuaScriptComponent::StopTimer)
		.addFunction("AddClocker", &NFCLuaScriptComponent::AddClocker)
		.addFunction("StopClocker", &NFCLuaScriptComponent::StopClocker)
		.addFunction("GetAppName", &NFCLuaScriptComponent::GetAppName)
		.addFunction("GetAppID", &NFCLuaScriptComponent::GetAppID)
		.addFunction("GetMD5", &NFCLuaScriptComponent::GetMD5)
		.addFunction("GetCRC32", &NFCLuaScriptComponent::GetCRC32)
		.addFunction("GetCRC16", &NFCLuaScriptComponent::GetCRC16)
		.addFunction("Base64Encode", &NFCLuaScriptComponent::Base64Encode)
		.addFunction("Base64Decode", &NFCLuaScriptComponent::Base64Decode)
		.addFunction("SetDefaultLevel", &NFCLuaScriptComponent::SetDefaultLevel)
		.addFunction("SetDefaultFlush", &NFCLuaScriptComponent::SetDefaultFlush)
		.addFunction("LuaDebug", &NFCLuaScriptComponent::LuaDebug)
		.addFunction("LuaInfo", &NFCLuaScriptComponent::LuaInfo)
		.addFunction("LuaWarn", &NFCLuaScriptComponent::LuaWarn)
		.addFunction("LuaError", &NFCLuaScriptComponent::LuaError)
		.addFunction("SendMsgToPlayer", &NFCLuaScriptComponent::SendMsgToPlayer)
		.addFunction("SendMsgToManyPlayer", &NFCLuaScriptComponent::SendMsgToManyPlayer)
		.addFunction("SendMsgToAllPlayer", &NFCLuaScriptComponent::SendMsgToAllPlayer)
		.addFunction("SendMsgToMaster", &NFCLuaScriptComponent::SendMsgToMaster)
		.addFunction("SendMsgToPlayer_MainSub", &NFCLuaScriptComponent::SendMsgToPlayer_MainSub)
		.addFunction("SendMsgToManyPlayer_MainSub", &NFCLuaScriptComponent::SendMsgToManyPlayer_MainSub)
		.addFunction("SendMsgToAllPlayer_MainSub", &NFCLuaScriptComponent::SendMsgToAllPlayer_MainSub)
		.addFunction("SendMsgToMaster_MainSub", &NFCLuaScriptComponent::SendMsgToMaster_MainSub)
		.addFunction("ProcessWork", &NFCLuaScriptComponent::ProcessWork)
		.addFunction("ProcessTimer", &NFCLuaScriptComponent::ProcessTimer)
		.addFunction("ProcessLoopTimer", &NFCLuaScriptComponent::ProcessLoopTimer)
		.addFunction("BeginProfiler", &NFCLuaScriptComponent::BeginProfiler)
		.addFunction("EndProfiler", &NFCLuaScriptComponent::EndProfiler)
		.addFunction("Sha256", &NFCLuaScriptComponent::Sha256)
		.addFunction("Platfrom", &NFCLuaScriptComponent::Platfrom)
		.addFunction("IsThreadModule", &NFCLuaScriptComponent::IsThreadModule)
		.addFunction("SendErrorLog", &NFCLuaScriptComponent::SendErrorLog)
		.addFunction("SendMsgToHttpServer", &NFCLuaScriptComponent::SendMsgToHttpServer)
		.addFunction("HttpGet", &NFCLuaScriptComponent::HttpGet)
		.addFunction("HttpGetWithHead", &NFCLuaScriptComponent::HttpGetWithHead)
		.addFunction("HttpPost", &NFCLuaScriptComponent::HttpPost)
		.addFunction("HttpPostWithHead", &NFCLuaScriptComponent::HttpPostWithHead)
		.endClass();
	return true;
}

void NFCLuaScriptComponent::LoadScript()
{
	TryAddPackagePath(m_pPluginManager->GetLuaScriptPath());
	TryLoadScriptFile("init.lua");
	TryRunGlobalScriptFunc("LuaNFrame.InitScript", this);
}

const std::string& NFCLuaScriptComponent::GetAppName() const
{
	return m_pPluginManager->GetAppName();
}

int NFCLuaScriptComponent::GetAppID() const
{
	return m_pPluginManager->GetAppID();
}

uint64_t NFCLuaScriptComponent::GetInitTime() const
{
	return m_pPluginManager->GetInitTime();
}

uint64_t NFCLuaScriptComponent::GetNowTime() const
{
	return m_pPluginManager->GetNowTime();
}

std::string NFCLuaScriptComponent::GetMD5(const std::string& str)
{
	return NFMMOMD5(str).toStr();
}

uint32_t NFCLuaScriptComponent::GetCRC32(const std::string& s)
{
	return NFCRC32::Sum(s);
}

uint16_t NFCLuaScriptComponent::GetCRC16(const std::string& s)
{
	return NFCRC16::Sum(s);
}

std::string NFCLuaScriptComponent::Base64Encode(const std::string& s)
{
	return NFBase64::Encode(s);
}

std::string NFCLuaScriptComponent::Base64Decode(const std::string& s)
{
	return NFBase64::Decode(s);
}

std::string NFCLuaScriptComponent::Sha256(const std::string& s)
{
	std::string ret;
	NFSha256::hash256_hex_string(s, ret);
	return ret;
}

std::string NFCLuaScriptComponent::Platfrom()
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	return "win32";
#else
	return "linux";
#endif
}

bool NFCLuaScriptComponent::IsThreadModule()
{
	return true;
}

void NFCLuaScriptComponent::SendMsgToPlayer(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	m_pLuaThreadModule->AddMsgToPlayer(usLinkId, nPlayerID, nMsgID, nLen, strData);
}

void NFCLuaScriptComponent::SendMsgToManyPlayer(const std::vector<uint64_t>& nVecPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	m_pLuaThreadModule->AddMsgToManyPlayer(nVecPlayerID, nMsgID, nLen, strData);
}

void NFCLuaScriptComponent::SendMsgToAllPlayer(const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	m_pLuaThreadModule->AddMsgToAllPlayer(nMsgID, nLen, strData);
}

void NFCLuaScriptComponent::SendMsgToMaster(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	m_pLuaThreadModule->AddMsgToMaster(usLinkId, nPlayerID, nMsgID, nLen, strData);
}

void NFCLuaScriptComponent::SendMsgToPlayer_MainSub(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	m_pLuaThreadModule->AddMsgToPlayer(usLinkId, nPlayerID, nMainMsgID, nSubMsgID, nLen, strData);
}

void NFCLuaScriptComponent::SendMsgToManyPlayer_MainSub(const std::vector<uint64_t>& nVecPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	m_pLuaThreadModule->AddMsgToManyPlayer(nVecPlayerID, nMainMsgID, nSubMsgID, nLen, strData);
}

void NFCLuaScriptComponent::SendMsgToAllPlayer_MainSub(const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	m_pLuaThreadModule->AddMsgToAllPlayer(nMainMsgID, nSubMsgID, nLen, strData);
}

void NFCLuaScriptComponent::SendMsgToMaster_MainSub(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	m_pLuaThreadModule->AddMsgToMaster(usLinkId, nPlayerID, nMainMsgID, nSubMsgID, nLen, strData);
}

void NFCLuaScriptComponent::SendMsgToHttpServer(uint32_t servertype, const uint32_t requestId, const std::string& strMsg)
{
	m_pLuaThreadModule->AddHttpServerMsg(servertype, requestId, strMsg);
}

void NFCLuaScriptComponent::SetDefaultLevel(uint32_t log_level)
{
	if (m_pLogModule)
	{
		m_pLogModule->SetDefaultLevel((NF_LOG_LEVEL)log_level);
	}
}

void NFCLuaScriptComponent::SetDefaultFlush(uint32_t log_level)
{
	if (m_pLogModule)
	{
		m_pLogModule->SetDefaultFlush((NF_LOG_LEVEL)log_level);
	}
}

void NFCLuaScriptComponent::LuaDebug(uint32_t logId, uint64_t guid, const std::string& str)
{
	if (m_pLogModule)
	{
		m_pLogModule->LuaDebug(logId, guid, str);
	}
}

void NFCLuaScriptComponent::LuaInfo(uint32_t logId, uint64_t guid, const std::string& str)
{
	if (m_pLogModule)
	{
		m_pLogModule->LuaInfo(logId, guid, str);
	}
}

void NFCLuaScriptComponent::LuaWarn(uint32_t logId, uint64_t guid, const std::string& str)
{
	if (m_pLogModule)
	{
		m_pLogModule->LuaWarn(logId, guid, str);
	}
}

void NFCLuaScriptComponent::LuaError(uint32_t logId, uint64_t guid, const std::string& str)
{
	if (m_pLogModule)
	{
		m_pLogModule->LuaError(logId, guid, str);
	}
}

void NFCLuaScriptComponent::ProcessLoop(const std::string& dataStr)
{
	TryRunGlobalScriptFunc("LuaNFrame.UpdateSec", dataStr);
}

void NFCLuaScriptComponent::ProcessInit(const std::string& dataStr)
{
	TryRunGlobalScriptFunc("LuaNFrame.TimerInit", dataStr);
}

void NFCLuaScriptComponent::ProcessWork(const std::string& luaFunc, const NFLuaRef& dataStr)
{
	std::string tmpStr;
	if (dataStr != nullptr)
	{
		try
		{
			tmpStr = dataStr.toValue<std::string>();
		}
		catch (LuaIntf::LuaException& e)
		{
			if (m_pLogModule)
			{
				m_pLogModule->LuaError(0, 0, "ProcessWork, luaFunc:"+luaFunc+" err:"+std::string(e.what()));
			}
		}
	}
	m_pLuaThreadModule->AddProcessWork(luaFunc, tmpStr);
}

void NFCLuaScriptComponent::Do_ProcessWork(const std::string& luaFunc, const std::string& dataStr)
{
	TryRunGlobalScriptFunc("LuaNFrame.DispatchWorker", luaFunc, dataStr);
}

void NFCLuaScriptComponent::ProcessTimer(uint32_t timeSec, const std::string& luaFunc, const NFLuaRef& dataStr)
{
	std::string tmpStr;
	if (dataStr != nullptr)
	{
		try
		{
			tmpStr = dataStr.toValue<std::string>();
		}
		catch (LuaIntf::LuaException& e)
		{
			if (m_pLogModule)
			{
				m_pLogModule->LuaError(0, 0, "ProcessTimer, luaFunc:" + luaFunc + " err:" + std::string(e.what()));
			}
		}
	}
	m_pLuaThreadModule->AddProcessTimer(timeSec, luaFunc, tmpStr);
}

void NFCLuaScriptComponent::ProcessLoopTimer(uint32_t timeSec, const std::string& luaFunc, const NFLuaRef& dataStr)
{
	std::string tmpStr;
	if (dataStr != nullptr)
	{
		try
		{
			tmpStr = dataStr.toValue<std::string>();
		}
		catch (LuaIntf::LuaException& e)
		{
			if (m_pLogModule)
			{
				m_pLogModule->LuaError(0, 0, "ProcessLoopTimer, luaFunc:" + luaFunc + " err:" + std::string(e.what()));
			}
		}
	}
	m_pLuaThreadModule->AddProcessLoopTimer(timeSec, luaFunc, tmpStr);
}

void NFCLuaScriptComponent::Do_ProcessRealTimer(const std::string& luaFunc, const std::string& dataStr)
{
	TryRunGlobalScriptFunc("LuaNFrame.DispatchTimer", luaFunc, dataStr);
}

void NFCLuaScriptComponent::Do_ProcessTimer(const std::string& luaFunc, const std::string& dataStr)
{
	TryRunGlobalScriptFunc("LuaNFrame.DispatchTimerOnce", luaFunc, dataStr);
}

void NFCLuaScriptComponent::Do_ProcessLoopTimer(const std::string& luaFunc, const std::string& dataStr)
{
	TryRunGlobalScriptFunc("LuaNFrame.DispatchTimerOnce", luaFunc, dataStr);
}

void NFCLuaScriptComponent::BeginProfiler(const std::string& funcName)
{

}

uint64_t NFCLuaScriptComponent::EndProfiler()
{
	return 0;
}

void NFCLuaScriptComponent::RunHttpRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint32_t requestId, const std::string& firstPath, const std::string& secondPath, const std::string& strMsg)
{
	TryRunGlobalScriptFunc(luaFunc, unLinkId, requestId, firstPath, secondPath, strMsg);
}

void NFCLuaScriptComponent::RunNetRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t nMsgId, const std::string& strMsg)
{
	TryRunGlobalScriptFunc(luaFunc, unLinkId, valueId, nMsgId, strMsg);
}

void NFCLuaScriptComponent::GcStep()
{
	lua_gc(GetLuaState(), LUA_GCSTEP, 0);
	//lua_gc(GetLuaState(), LUA_GCCOLLECT, 0);
}

void NFCLuaScriptComponent::TcpSessionClose(uint64_t playerId)
{
	TryRunGlobalScriptFunc("TcpSessionClose", playerId);
}

void NFCLuaScriptComponent::TcpSessionReport(uint64_t playerId, const std::string& ip)
{
	TryRunGlobalScriptFunc("TcpSessionReport", playerId, ip);
}

std::string NFCLuaScriptComponent::HttpGet(const std::string& url)
{
	std::string strResp;
	int ret = NFCurlHttpClient::GetSingletonPtr()->Gets(url, strResp);
	if (ret != 0)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "HttpGet url:{}, return error code:{}", url, ret);
	}
	return strResp;
}

std::string NFCLuaScriptComponent::HttpGetWithHead(const std::string& url, const std::map<std::string, std::string>& xHeaders)
{
	std::string strResp;
	int ret = NFCurlHttpClient::GetSingletonPtr()->Gets(url, strResp);
	if (ret != 0)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "HttpGet url:{}, return error code:{}", url, ret);
	}
	return strResp;
}

std::string NFCLuaScriptComponent::HttpPost(const std::string& url, const std::string& postContent)
{
	std::string strResp;
	int ret = NFCurlHttpClient::GetSingletonPtr()->Posts(url, postContent, strResp);
	if (ret != 0)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "HttpPost url:{}, return error code:{}", url, ret);
	}
	return strResp;
}

std::string NFCLuaScriptComponent::HttpPostWithHead(const std::string& url, const std::string& postContent, const std::map<std::string, std::string>& xHeaders)
{
	std::string strResp;
	int ret = NFCurlHttpClient::GetSingletonPtr()->Posts(url, postContent, strResp);
	if (ret != 0)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "HttpPost url:{}, return error code:{}", url, ret);
	}
	return strResp;
}