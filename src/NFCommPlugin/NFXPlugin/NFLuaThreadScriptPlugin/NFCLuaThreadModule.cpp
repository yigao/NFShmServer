// -------------------------------------------------------------------------
//    @FileName         :    NFCLuaThreadModule.cpp
//    @Author           :    GaoYi
//    @Date             :    2018/08/26
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFCLuaThreadModule.h"
#include "NFCLuaScriptComponent.h"
#include "NFMessageDefine/server_msg.pb.h"
#include "NFComm/NFPluginModule/NFEventMgr.h"
#include "NFComm/NFPluginModule/NFEventDefine.h"
#include "NFComm/NFCore/NFMMOMD5.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFMessageDefine/server_to_server_msg.pb.h"
#include "NFServerLogic/NFServerLogicCommon/NFServerLogicCommon.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"

void NFLuaThreadTimer::OnTimer(uint32_t nTimerID)
{
	mCurCallCount++;
	if (mMsgType == NFTimerMessage::ACTOR_TIMER_MSG_PROCESS_TIMER)
	{
		m_pLuaScriptModule->AddProcessTimerTask(new NFProcessTimerActorTask(m_pLuaScriptModule, mLuaFunc, mDataStr));
	}
	else if (mMsgType == NFTimerMessage::ACTOR_TIMER_MSG_PROCESS_LOOP_TIMER)
	{
		m_pLuaScriptModule->AddProcessLoopTask(new NFProcessLoopTimerActorTask(m_pLuaScriptModule, mLuaFunc, mDataStr));
	}
	else if (mMsgType == NFTimerMessage::ACTOR_TIMER_MSG_PROCESS_REAL_TIMER)
	{
		m_pLuaScriptModule->AddWorkTask(new NFProcessRealTimerActorTask(m_pLuaScriptModule, mLuaFunc, mDataStr));
	}
}

bool NFCLuaThreadModule::Init()
{
	//初始化主循环Actor系统
	m_pServerLoopTaskModule = m_pPluginManager->CreateAloneModule<NFITaskModule>();
	m_pServerLoopTaskModule->InitActorThread(1);
	m_pServerLoopTaskModule->Init();
	m_pServerLoopTaskModule->AfterInit();

	m_pWorkTaskModule = m_pPluginManager->CreateAloneModule<NFITaskModule>();
	m_pTcpMsgTaskModule = m_pPluginManager->CreateAloneModule<NFITaskModule>();

	//初始化work Actor系统
#if NF_PLATFORM == NF_PLATFORM_WIN
	uint32_t threadNum = std::thread::hardware_concurrency();
#else
	uint32_t threadNum = std::thread::hardware_concurrency() * 2;
	if (threadNum < 10)
	{
		threadNum = 10;
	}
#endif

	uint32_t workThreadNum = 1;
	uint32_t tcpThreadNum = 1;

	if (m_pPluginManager->IsLoadAllServer())
	{
		workThreadNum = 2;
		tcpThreadNum = threadNum;
	}
	else
	{
		auto pServerConfig = NFConfigMgr::Instance()->GetServerConfig(m_pPluginManager->GetAppID());
		if (pServerConfig)
		{
			if (pServerConfig->mLuaTcpThreadNum > 0)
			{
				tcpThreadNum = pServerConfig->mLuaTcpThreadNum;
			}
			else
			{
				tcpThreadNum = threadNum;
			}

			if (pServerConfig->mLuaWorkThreadNum > 0)
			{
				workThreadNum = pServerConfig->mLuaWorkThreadNum;
			}
			else
			{
				workThreadNum = threadNum;
			}
		}
	}

	m_pWorkTaskModule->InitActorThread(workThreadNum);
	m_pTcpMsgTaskModule->InitActorThread(tcpThreadNum);

	m_pTcpMsgTaskModule->Init();
	m_pTcpMsgTaskModule->AfterInit();

	m_pWorkTaskModule->Init();
	m_pWorkTaskModule->AfterInit();
	//初始化work Actor系统

	m_pNetServerModule = FindModule<NFINetServerModule>();
	m_pNetClientModule = FindModule<NFINetClientModule>();
	m_pHttpServerModule = FindModule<NFIHttpServerModule>();

	if (m_pPluginManager->IsLoadAllServer())
	{
		FindModule<NFIServerNetEventModule>()->AddAccountEventCallBack(NF_ST_GAME, this, &NFCLuaThreadModule::OnAccountEventCallBack);
	}
	else
	{
		FindModule<NFIServerNetEventModule>()->AddAccountEventCallBack(NF_ST_GAME, this, &NFCLuaThreadModule::OnAccountEventCallBack);
		FindModule<NFIServerNetEventModule>()->AddAccountEventCallBack(NF_ST_WORLD, this, &NFCLuaThreadModule::OnAccountEventCallBack);
		FindModule<NFIServerNetEventModule>()->AddAccountEventCallBack(NF_ST_LOGIN, this, &NFCLuaThreadModule::OnAccountEventCallBack);
	}

	StartActorPool(workThreadNum, tcpThreadNum);
	SetTimer(EnumLuaThreadModule_LOAD, 1000, 1);
	return true;
}

bool NFCLuaThreadModule::AfterInit()
{
	return true;
}

bool NFCLuaThreadModule::ReadyExecute()
{
	return true;
}

bool NFCLuaThreadModule::Execute()
{
	m_pPluginManager->BeginProfiler("HandleLuaTimer");
	HandleLuaTimer();
	m_pPluginManager->EndProfiler();

	HandleLuaTcpMsg();
	return true;
}

bool NFCLuaThreadModule::BeforeShut()
{
	return true;
}

bool NFCLuaThreadModule::Shut()
{
	return true;
}

bool NFCLuaThreadModule::Finalize()
{
	return true;
}

void NFCLuaThreadModule::OnTimer(uint32_t nTimerID)
{
	if (nTimerID == EnumLuaThreadModule_LOAD)
	{
		m_pServerLoopTaskModule->AddTaskToEveryActor(NFServerLoopLoadTask(this));
		m_pWorkTaskModule->AddTaskToEveryActor(NFWorkActorLoadTask(this));
		m_pTcpMsgTaskModule->AddTaskToEveryActor(NFTcpMsgActorLoadTask(this));
		SetTimer(EnumLuaThreadModule_Init, 100, INFINITY_CALL);
	}
	else if (nTimerID == EnumLuaThreadModule_Init)
	{
		if (IsFinishAllLoad())
		{
			KillTimer(EnumLuaThreadModule_Init);
			AddProcessLoopTask(new NFServerLoopInitTask(this));
			SetTimer(EnumLuaThreadModule_WaitFinishInit, 100, INFINITY_CALL);
		}
	}
	else if (nTimerID == EnumLuaThreadModule_WaitFinishInit)
	{
		if (IsFinishAllInitServerLoop())
		{
			KillTimer(EnumLuaThreadModule_WaitFinishInit);
			SetFixTimer(EnumLuaThreadModule_Loop, 0, 1, INFINITY_CALL);
			SetFixTimer(EnumLuaThreadModule_MIN, 0, 60, INFINITY_CALL);
			SetFixTimer(EnumLuaThreadModule_5MIN, 0, 5*60, INFINITY_CALL);
			SetFixTimer(EnumLuaThreadModule_10MIN, 0, 10*60, INFINITY_CALL);
			SetFixTimer(EnumLuaThreadModule_30MIN, 0, 30*60, INFINITY_CALL);
			SetFixTimer(EnumLuaThreadModule_HOUR, 0, 3600, INFINITY_CALL);
			SetFixTimer(EnumLuaThreadModule_DAY, 0, 24*3600, INFINITY_CALL);
			//一周定时器
			SetTimer(EnumLuaThreadModule_WEEK, NFTime::GetNextWeekRemainingTime()*1000, 1);

			//一月定时器，多加了一秒，避免定时器32ms的误差
			uint64_t monthtime = NFTime::GetNextMonthRemainingTime() + 1;
			SetTimer(EnumLuaThreadModule_MONTH, monthtime * 1000, 1);

			NFMsg::ServerErrorLogMsg msg;
			NFEventMgr::GetSingletonPtr()->FireExecute(NFEVENT_LUA_FINISH_LOAD, 0, 0, msg);
		}
	}
	else if (nTimerID == EnumLuaThreadModule_Loop)
	{
		AddProcessLoopTask(new NFServerLoopTask(this));
	}
	else if (nTimerID == EnumLuaThreadModule_MIN)
	{
		UpdateMin();
	}
	else if (nTimerID == EnumLuaThreadModule_5MIN)
	{
		Update5Min();
	}
	else if (nTimerID == EnumLuaThreadModule_10MIN)
	{
		Update10Min();
	}
	else if (nTimerID == EnumLuaThreadModule_30MIN)
	{
		Update30Min();
	}
	else if (nTimerID == EnumLuaThreadModule_HOUR)
	{
		UpdateHour();
	}
	else if (nTimerID == EnumLuaThreadModule_DAY)
	{
		UpdateDay();
	}
	else if (nTimerID == EnumLuaThreadModule_WEEK)
	{
		UpdateWeek();
	}
	else if (nTimerID == EnumLuaThreadModule_MONTH)
	{
		UpdateMonth();
	}
}

void NFCLuaThreadModule::RunHttpRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint32_t requestId, const std::string& firstPath, const std::string& secondPath, const std::string& strMsg)
{
	AddTcpMsgTask(new NFHttpMsgActorTask(this, luaFunc, unLinkId, requestId, firstPath, secondPath, strMsg));
}

void NFCLuaThreadModule::RunNetRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t operateId, const uint32_t nMsgId, const std::string& strMsg)
{
	AddTcpMsgTask(new NFTcpMsgActorTask(this, luaFunc, unLinkId, valueId, operateId, nMsgId, strMsg));
}

void NFCLuaThreadModule::RunNetRecvLuaFuncWithMainSub(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t operateId, const uint16_t nMainMsgId, const uint16_t nSubMsgId, const std::string& strMsg)
{
	AddTcpMsgTask(new NFTcpMainSubMsgActorTask(this, luaFunc, unLinkId, valueId, operateId, nMainMsgId, nSubMsgId, strMsg));
}

void NFCLuaThreadModule::SessionReport(uint64_t playerId, const std::string& report)
{
	AddTcpMsgTask(new NFTcpSessionReportActorTask(this, playerId, report));
}

void NFCLuaThreadModule::SessionClose(uint64_t playerId)
{
	AddTcpMsgTask(new NFTcpSessionCloseActorTask(this, playerId));
}

bool NFCLuaThreadModule::StartActorPool(uint32_t workThreadNum, uint32_t tcpThreadNum)
{
	for (uint32_t i = 0; i < tcpThreadNum; i++)
	{
		NFCLuaScriptComponent* pComonnet = NF_NEW NFCLuaScriptComponent(this, m_pPluginManager);
		AddTcpMsgActorComponent(pComonnet);
	}
	
	for (uint32_t i = 0; i < workThreadNum; i++)
	{
		NFCLuaScriptComponent* pComonnet = NF_NEW NFCLuaScriptComponent(this, m_pPluginManager);
		AddWorkActorComponent(pComonnet);
	}

	NFCLuaScriptComponent* pLoopComonnet = NF_NEW NFCLuaScriptComponent(this, m_pPluginManager);
	AddServerLoopActorComponent(pLoopComonnet);
	return true;
}

bool NFCLuaThreadModule::CloseActorPool()
{
	return true;
}

uint32_t NFCLuaThreadModule::AddTimer(uint32_t msgType, const std::string& luaFunc, uint64_t nInterVal, const std::string& dataStr, uint32_t callCount)
{
	NFLuaThreadTimer* luaTimer = nullptr;
	if (m_luaTimerList.empty())
	{
		luaTimer = NF_NEW NFLuaThreadTimer(this);
	}
	else
	{
		luaTimer = m_luaTimerList.front();
		m_luaTimerList.pop_front();
		luaTimer->m_pLuaScriptModule = this;
	}

	luaTimer->mMsgType = msgType;
	luaTimer->mLuaFunc = luaFunc;
	luaTimer->mInterVal = nInterVal;
	luaTimer->mDataStr = dataStr;
	if (callCount == 0)
	{
		luaTimer->mCallCount = INFINITY_CALL;
	}
	else
	{
		luaTimer->mCallCount = callCount;
	}

	luaTimer->mCurCallCount = 0;
	luaTimer->mTimerId = ++m_luaTimerIndex;

	luaTimer->SetTimer(luaTimer->mTimerId, luaTimer->mInterVal, luaTimer->mCallCount);
	m_luaTimerMap.emplace(luaTimer->mTimerId, luaTimer);

	return luaTimer->mTimerId;
}

/*
处理多线程LUA发过来的消息
*/
void NFCLuaThreadModule::HandleLuaTcpMsg()
{
	std::vector<NFTcpMessage> listTask;
	const bool ret = m_mTcpMsgQueue.Pop(listTask);
	if (ret)
	{
		if (!listTask.empty())
		{
			m_pPluginManager->BeginProfiler("HandleLuaTcpMsg");
			for (size_t i = 0; i < listTask.size(); ++i)
			{
				NFTcpMessage* pMsg = &listTask[i];
				if (pMsg->m_nMsgType == NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ONE_PLAYER_PROXY_MSG)
				{
					SendMsgToPlayer(pMsg->m_usLinkId, pMsg->m_nPlayerID, pMsg->m_nMsgID, pMsg->m_nLen, pMsg->m_strData);
				}
				else if (pMsg->m_nMsgType == NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ONE_PLAYER_MASTER_MSG)
				{
					SendMsgToMaster(pMsg->m_usLinkId, pMsg->m_nPlayerID, pMsg->m_nMsgID, pMsg->m_nLen, pMsg->m_strData);
				}
				else if (pMsg->m_nMsgType == NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_MANY_PLAYER_PROXY_MSG)
				{
					SendMsgToManyPlayer(pMsg->m_nVecPlayerID, pMsg->m_nMsgID, pMsg->m_nLen, pMsg->m_strData);
				}
				else if (pMsg->m_nMsgType == NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ALL_PLAYER_PROXY_MSG)
				{
					SendMsgToAllPlayer(pMsg->m_nMsgID, pMsg->m_nLen, pMsg->m_strData);
				}
				else if (pMsg->m_nMsgType == NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ADD_ERROR_LOG_MSG)
				{
					SendErrorLog(pMsg->m_nPlayerID, pMsg->m_funcLog, pMsg->m_errorLog, pMsg->m_nLen);
				}
				else if (pMsg->m_nMsgType == NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ADD_HTTP_LOG_MSG)
				{
					SendHttpServerMsg(pMsg->m_usLinkId, pMsg->m_nPlayerID, pMsg->m_strData);
				}
			}
			uint32_t count = listTask.size();
			uint64_t useTime = m_pPluginManager->EndProfiler();
			if (useTime >= 30000) //>= 10毫秒
			{
				NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "HandleLuaTcpMsg: send tcp msg:{} use time:{} ms", listTask.size(), useTime / 1000);
			}
		}
	}
}

void NFCLuaThreadModule::HandleLuaTimer()
{
	std::vector<NFTimerMessage> listTask;
	const bool ret = m_mQueue.Pop(listTask);
	if (ret)
	{
		const uint64_t start = NFTime::Tick();
		for (size_t i = 0; i < listTask.size(); i++)
		{
			NFTimerMessage* xMsg = &listTask[i];
			AddTimer(xMsg->nMsgType, xMsg->m_luaFunc, xMsg->m_delayTime, xMsg->m_tmpParam, xMsg->m_callCount);
		}
	}

	for (auto iter = m_luaTimerMap.begin(); iter != m_luaTimerMap.end();)
	{
		NFLuaThreadTimer* pTimer = iter->second;
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
}

void NFCLuaThreadModule::SendMsgToPlayer(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
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

void NFCLuaThreadModule::SendMsgToManyPlayer(const std::vector<uint64_t>& nVecPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
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

void NFCLuaThreadModule::SendMsgToAllPlayer(const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetServerModule)
	{
		NFMsg::NotifyProxyPacketMsg packetMsg;
		auto pPlayerInfo = mPlayerProxyInfoMap.First();
		while (pPlayerInfo)
		{
			m_pNetServerModule->SendByServerID(pPlayerInfo->GetProxyUnlinkId(), nMsgID, strData, pPlayerInfo->GetPlayerId(), 0);
			pPlayerInfo = mPlayerProxyInfoMap.Next();
		}
	}
}

void NFCLuaThreadModule::SendMsgToMaster(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetClientModule)
	{
		if (usLinkId != 0)
		{
			m_pNetClientModule->SendByServerID(usLinkId, nMsgID, strData, nPlayerID, 0);
		}
	}
}

void NFCLuaThreadModule::SendMsgToPlayer(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
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

void NFCLuaThreadModule::SendMsgToManyPlayer(const std::vector<uint64_t>& nVecPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
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

void NFCLuaThreadModule::SendMsgToAllPlayer(const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetServerModule)
	{
		NFMsg::NotifyProxyPacketMsg packetMsg;
		auto pPlayerInfo = mPlayerProxyInfoMap.First();
		while (pPlayerInfo)
		{
			m_pNetServerModule->SendByServerID(pPlayerInfo->GetProxyUnlinkId(), nMainMsgID, nSubMsgID, strData, pPlayerInfo->GetPlayerId(), 0);
			pPlayerInfo = mPlayerProxyInfoMap.Next();
		}
	}
}

void NFCLuaThreadModule::SendMsgToMaster(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	if (m_pNetClientModule)
	{
		if (usLinkId != 0)
		{
			m_pNetClientModule->SendByServerID(usLinkId, nMainMsgID, nSubMsgID, strData, nPlayerID, 0);
		}
	}
}

void NFCLuaThreadModule::SendErrorLog(uint64_t playerId, const std::string& func_log, const std::string& errorLog, uint32_t count)
{
	NFMsg::ServerErrorLogMsg msg;
	msg.set_error_log(errorLog);
	msg.set_func_log(func_log);
	msg.set_player_id(playerId);
	msg.set_server_name(m_pPluginManager->GetAppName());
	msg.set_count(count);

	NFEventMgr::Instance()->FireExecute(NFEVENT_LUA_ERROR_LOG, playerId, 0, msg);
}

void NFCLuaThreadModule::SendHttpServerMsg(uint32_t servertype, const uint32_t requestId, const std::string& strMsg)
{
	if (m_pHttpServerModule)
	{
		m_pHttpServerModule->ResponseMsg((NF_SERVER_TYPES)servertype, requestId, strMsg, NFWebStatus::WEB_OK, "OK");
	}
}

void NFCLuaThreadModule::OnAccountEventCallBack(uint32_t nEvent, uint32_t unLinkId, NF_SHARE_PTR<PlayerGameServerInfo> pServerData)
{
	if (nEvent == eAccountEventType_CONNECTED)
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

	NFIMonitorModule* pMonitorModule = FindModule<NFIMonitorModule>();
	if (pMonitorModule)
	{
		pMonitorModule->SetUserCount(mPlayerProxyInfoMap.Count());
	}
}

NF_SHARE_PTR<PlayerGameServerInfo> NFCLuaThreadModule::GetPlayerInfo(uint64_t playerId)
{
	return mPlayerProxyInfoMap.GetElement(playerId);
}

void NFCLuaThreadModule::AddMsgToPlayer(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	NFTcpMessage msg;
	msg.m_nMsgType = NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ONE_PLAYER_PROXY_MSG;
	msg.m_usLinkId = usLinkId;
	msg.m_nPlayerID = nPlayerID;
	msg.m_nMsgID = nMsgID;
	msg.m_nLen = nLen;
	msg.m_strData = strData;

	m_mTcpMsgQueue.Push(msg);
}

void NFCLuaThreadModule::AddMsgToManyPlayer(const std::vector<uint64_t>& nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	NFTcpMessage msg;
	msg.m_nMsgType = NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_MANY_PLAYER_PROXY_MSG;
	msg.m_usLinkId = 0;
	msg.m_nPlayerID = 0;
	msg.m_nVecPlayerID = nPlayerID;
	msg.m_nMsgID = nMsgID;
	msg.m_nLen = nLen;
	msg.m_strData = strData;

	m_mTcpMsgQueue.Push(msg);
}

void NFCLuaThreadModule::AddMsgToAllPlayer(const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{

	NFTcpMessage msg;
	msg.m_nMsgType = NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ALL_PLAYER_PROXY_MSG;
	msg.m_usLinkId = 0;
	msg.m_nPlayerID = 0;
	msg.m_nMsgID = nMsgID;
	msg.m_nLen = nLen;
	msg.m_strData = strData;

	m_mTcpMsgQueue.Push(msg);
}

void NFCLuaThreadModule::AddMsgToMaster(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData)
{
	NFTcpMessage msg;
	msg.m_nMsgType = NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ONE_PLAYER_MASTER_MSG;
	msg.m_usLinkId = usLinkId;
	msg.m_nPlayerID = nPlayerID;
	msg.m_nMsgID = nMsgID;
	msg.m_nLen = nLen;
	msg.m_strData = strData;

	m_mTcpMsgQueue.Push(msg);
}

void NFCLuaThreadModule::AddMsgToPlayer(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	NFTcpMessage msg;
	msg.m_nMsgType = NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ONE_PLAYER_PROXY_MAIN_SUB_MSG;
	msg.m_usLinkId = usLinkId;
	msg.m_nPlayerID = nPlayerID;
	msg.m_nMainMsgID = nMainMsgID;
	msg.m_nSubMsgID = nSubMsgID;
	msg.m_nLen = nLen;
	msg.m_strData = strData;

	m_mTcpMsgQueue.Push(msg);
}

void NFCLuaThreadModule::AddMsgToManyPlayer(const std::vector<uint64_t>& nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	NFTcpMessage msg;
	msg.m_nMsgType = NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_MANY_PLAYER_PROXY_MAIN_SUB_MSG;
	msg.m_usLinkId = 0;
	msg.m_nPlayerID = 0;
	msg.m_nVecPlayerID = nPlayerID;
	msg.m_nMainMsgID = nMainMsgID;
	msg.m_nSubMsgID = nSubMsgID;
	msg.m_nLen = nLen;
	msg.m_strData = strData;

	m_mTcpMsgQueue.Push(msg);
}

void NFCLuaThreadModule::AddMsgToAllPlayer(const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	NFTcpMessage msg;
	msg.m_nMsgType = NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ALL_PLAYER_PROXY_MAIN_SUB_MSG;
	msg.m_usLinkId = 0;
	msg.m_nPlayerID = 0;
	msg.m_nMainMsgID = nMainMsgID;
	msg.m_nSubMsgID = nSubMsgID;
	msg.m_nLen = nLen;
	msg.m_strData = strData;

	m_mTcpMsgQueue.Push(msg);
}

void NFCLuaThreadModule::AddMsgToMaster(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData)
{
	NFTcpMessage msg;
	msg.m_nMsgType = NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ONE_PLAYER_MASTER_MAIN_SUB_MSG;
	msg.m_usLinkId = usLinkId;
	msg.m_nPlayerID = nPlayerID;
	msg.m_nMainMsgID = nMainMsgID;
	msg.m_nSubMsgID = nSubMsgID;
	msg.m_nLen = nLen;
	msg.m_strData = strData;

	m_mTcpMsgQueue.Push(msg);
}

void NFCLuaThreadModule::AddErrorLog(uint64_t playerId, const std::string& func_log, const std::string& errorLog, uint32_t count)
{
	NFTcpMessage msg;
	msg.m_nMsgType = NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ADD_ERROR_LOG_MSG;
	msg.m_nPlayerID = playerId;
	msg.m_errorLog = errorLog;
	msg.m_funcLog = func_log;
	msg.m_nLen = count;

	m_mTcpMsgQueue.Push(msg);
}

void NFCLuaThreadModule::AddHttpServerMsg(uint32_t servertype, const uint32_t requestId, const std::string& strMsg)
{
	NFTcpMessage msg;
	msg.m_nMsgType = NFTcpMessage::ACTOR_TCP_MESSAGE_TYPE_ADD_HTTP_LOG_MSG;
	msg.m_usLinkId = servertype,
	msg.m_nPlayerID = requestId;
	msg.m_strData = strMsg;

	m_mTcpMsgQueue.Push(msg);
}

/**
* @brief 添加一个Actor组件
*
* @return
*/
bool NFCLuaThreadModule::AddWorkActorComponent(NFITaskComponent* pComonnet)
{
	int actorId = m_pWorkTaskModule->RequireActor();
	if (actorId <= 0)
	{
		return false;
	}

	pComonnet->SetComponentName(std::string("WorkActor"));
	m_pWorkTaskModule->AddActorComponent(actorId, pComonnet);

	m_vecWorkActorPool.push_back(actorId);
	return true;
}

/**
* @brief 添加一个tcp msg Actor组件
*
* @return
*/
bool NFCLuaThreadModule::AddTcpMsgActorComponent(NFITaskComponent* pComonnet)
{
	int actorId = m_pTcpMsgTaskModule->RequireActor();
	if (actorId <= 0)
	{
		return false;
	}

	pComonnet->SetComponentName(std::string("TcpMsgActor"));
	m_pTcpMsgTaskModule->AddActorComponent(actorId, pComonnet);

	m_vecTcpMsgActorPool.push_back(actorId);
	return true;
}

/**
* @brief 添加一个server loop Actor组件
*
* @return
*/
bool NFCLuaThreadModule::AddServerLoopActorComponent(NFITaskComponent* pComonnet)
{
	m_processLoopActorId = m_pServerLoopTaskModule->RequireActor();
	if (m_processLoopActorId <= 0)
	{
		return false;
	}

	pComonnet->SetComponentName(std::string("ServerLoopActor"));
	m_pServerLoopTaskModule->AddActorComponent(m_processLoopActorId, pComonnet);
	return true;
}

/**
* @brief 通过平衡ID添加要异步处理的task
*
* @param pTask 要异步处理的task
* @return
*/
bool NFCLuaThreadModule::AddWorkTask(NFTask* pTask)
{
	if (pTask)
	{
		return m_pWorkTaskModule->AddTask(pTask);
	}

	return false;
}

/**
* @brief 通过平衡ID添加要异步处理的task
*
* @param pTask 要异步处理的task
* @return
*/
bool NFCLuaThreadModule::AddTcpMsgTask(NFTask* pTask)
{
	if (pTask)
	{
		return m_pTcpMsgTaskModule->AddTask(pTask);
	}

	return false;
}

/**
* @brief 循环异步处理的task
*
* @param pTask 要异步处理的task
* @return
*/
bool NFCLuaThreadModule::AddProcessLoopTask(NFTask* pTask)
{
	if (pTask)
	{
		return m_pServerLoopTaskModule->AddTask(m_processLoopActorId, pTask);
	}

	return false;
}

/**
* @brief 循环异步处理的task
*
* @param pTask 要异步处理的task
* @return
*/
bool NFCLuaThreadModule::AddProcessTimerTask(NFTask* pTask)
{
	if (pTask)
	{
		return m_pWorkTaskModule->AddTask(pTask);
	}

	return false;
}

/**
* @brief 循环异步处理的task
*
* @param pTask 要异步处理的task
* @return
*/
bool NFCLuaThreadModule::AddProcessWorkTask(NFTask* pTask)
{
	if (pTask)
	{
		return m_pWorkTaskModule->AddTask(pTask);
	}

	return false;
}

void NFCLuaThreadModule::AddProcessWork(const std::string& luaFunc, const std::string& tmpParam)
{
	AddProcessWorkTask(new NFWorkActorTask(this, luaFunc, tmpParam));
}

void NFCLuaThreadModule::AddRealTimer(uint32_t internal, uint32_t callcount, const std::string& luaFunc, const std::string& tmpParam)
{
	NFTimerMessage msg;
	msg.nMsgType = NFTimerMessage::ACTOR_TIMER_MSG_PROCESS_REAL_TIMER;
	msg.m_delayTime = internal;
	msg.m_luaFunc = luaFunc;
	msg.m_tmpParam = tmpParam;
	msg.m_callCount = callcount;

	m_mQueue.Push(msg);
}

void NFCLuaThreadModule::AddProcessTimer(uint32_t delayTimer, const std::string& luaFunc, const std::string& tmpParam)
{
	NFTimerMessage msg;
	msg.nMsgType = NFTimerMessage::ACTOR_TIMER_MSG_PROCESS_TIMER;
	msg.m_delayTime = delayTimer;
	msg.m_luaFunc = luaFunc;
	msg.m_tmpParam = tmpParam;
	msg.m_callCount = 1;

	m_mQueue.Push(msg);
}

void NFCLuaThreadModule::AddProcessLoopTimer(uint32_t delayTimer, const std::string& luaFunc, const std::string& tmpParam)
{
	NFTimerMessage msg;
	msg.nMsgType = NFTimerMessage::ACTOR_TIMER_MSG_PROCESS_LOOP_TIMER;
	msg.m_delayTime = delayTimer;
	msg.m_luaFunc = luaFunc;
	msg.m_tmpParam = tmpParam;
	msg.m_callCount = 1;

	m_mQueue.Push(msg);
}

void NFCLuaThreadModule::ReloadAllLuaFiles()
{
	AddTcpMsgTask(new NFHotfixAllLuaActorTask(this));
}

void NFCLuaThreadModule::ReloadLuaFiles()
{
	m_pServerLoopTaskModule->AddTaskToEveryActor(NFHotfixLuaFilesActorTask(this));
	m_pWorkTaskModule->AddTaskToEveryActor(NFHotfixLuaFilesActorTask(this));
	m_pTcpMsgTaskModule->AddTaskToEveryActor(NFHotfixLuaFilesActorTask(this));
}

void NFCLuaThreadModule::ReloadLuaFiles(const std::vector<std::string>& vecStr)
{
	m_pServerLoopTaskModule->AddTaskToEveryActor(NFHotfixLuaFilesActorTask(this, vecStr));
	m_pWorkTaskModule->AddTaskToEveryActor(NFHotfixLuaFilesActorTask(this, vecStr));
	m_pTcpMsgTaskModule->AddTaskToEveryActor(NFHotfixLuaFilesActorTask(this, vecStr));
}

void NFCLuaThreadModule::GcStep()
{
	m_pServerLoopTaskModule->AddTaskToEveryActor(NFLuaGcActorTask(this));
	m_pWorkTaskModule->AddTaskToEveryActor(NFLuaGcActorTask(this));
	m_pTcpMsgTaskModule->AddTaskToEveryActor(NFLuaGcActorTask(this));
}

void NFCLuaThreadModule::UpdateMin()
{
	AddProcessLoopTask(new NFLuaMinActorTask(this));
}

void NFCLuaThreadModule::Update5Min()
{
	AddProcessLoopTask(new NFLua5MinActorTask(this));
}

void NFCLuaThreadModule::Update10Min()
{
	AddProcessLoopTask(new NFLua10MinActorTask(this));
}

void NFCLuaThreadModule::Update30Min()
{
	AddProcessLoopTask(new NFLua30MinActorTask(this));
}

void NFCLuaThreadModule::UpdateHour()
{
	AddProcessLoopTask(new NFLuaHourActorTask(this));
}

void NFCLuaThreadModule::UpdateDay()
{
	AddProcessLoopTask(new NFLuaDayActorTask(this));
}

void NFCLuaThreadModule::UpdateWeek()
{
	AddProcessLoopTask(new NFLuaWeekActorTask(this));
	SetTimer(EnumLuaThreadModule_WEEK, 7 * 24 * 3600 * 1000, 1);
}

void NFCLuaThreadModule::UpdateMonth()
{
	AddProcessLoopTask(new NFLuaMonthActorTask(this));
	//一月定时器，多加了一秒，避免定时器32ms的误差
	uint64_t monthtime = NFTime::GetNextMonthRemainingTime() + 1;
	SetTimer(EnumLuaThreadModule_MONTH, monthtime * 1000, 1);
}

void NFCLuaThreadModule::RunGmFunction(const std::string& luaFunc, const std::vector<std::string>& vecStr)
{
	m_pWorkTaskModule->AddTask(new NFRunGmFunctionActorTask(this, luaFunc, vecStr));
}

void  NFCLuaThreadModule::AddFinishLoad() 
{ 
	m_finishLuaLoad++; 
}

void  NFCLuaThreadModule::AddFinishInitServerLoop() 
{ 
	m_finishInitServerLoop++; 
}

bool  NFCLuaThreadModule::IsFinishAllLoad() 
{ 
	return m_finishLuaLoad == 1 + m_vecWorkActorPool.size() + m_vecTcpMsgActorPool.size(); 
}

bool  NFCLuaThreadModule::IsFinishAllInitServerLoop() 
{ 
	return m_finishInitServerLoop == 1; 
}
