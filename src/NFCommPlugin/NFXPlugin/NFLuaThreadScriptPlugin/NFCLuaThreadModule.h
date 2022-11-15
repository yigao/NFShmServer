// -------------------------------------------------------------------------
//    @FileName         :    NFCLuaThreadModule.h
//    @Author           :    GaoYi
//    @Date             :    2018/08/26
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFILuaThreadModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFILuaLoader.h"
#include "NFComm/NFPluginModule/NFILuaScriptModule.h"
#include "NFComm/NFCore/NFQueue.hpp"

#include "NFComm/NFPluginModule/NFITaskModule.h"
#include "NFComm/NFPluginModule/NFTask.h"

#include "NFComm/NFPluginModule/NFTimerMgr.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

#include "NFComm/NFPluginModule/NFINetServerModule.h"
#include "NFComm/NFPluginModule/NFINetClientModule.h"
#include "NFComm/NFPluginModule/NFIHttpServerModule.h"
#include "NFComm/NFCore/NFMapEx.hpp"

#include <vector>
#include <atomic>

class NFCLuaThreadModule;

/**
* @brief actor��ʱ����Ϣ����
*
*/
class NFTimerMessage
{
public:
	/**
	* @brief ��Ϣ����
	*
	*/
	enum MessageType
	{
		ACTOR_TIMER_MSG_PROCESS_NULL = 0,
		ACTOR_TIMER_MSG_PROCESS_TIMER = 1,
		ACTOR_TIMER_MSG_PROCESS_LOOP_TIMER = 2,
		ACTOR_TIMER_MSG_PROCESS_REAL_TIMER = 3,
	};

	/**
	* @brief ���캯��
	*
	*/
	NFTimerMessage()
	{
		m_delayTime = 0;
		nMsgType = ACTOR_TIMER_MSG_PROCESS_NULL;
		m_callCount = 1;
	}

	virtual ~NFTimerMessage()
	{

	}

public:
	/**
	* @brief ��Ϣ����
	*
	*/
	int nMsgType;

	/**
	* @brief ��ʱʱ��
	*
	*/
	int m_delayTime;

	/**
	* @brief Ҫ��ʱִ�е�LUA����
	*
	*/
	std::string m_luaFunc;

	/**
	* @brief Ҫ��ʱִ�е�LUA�����Ĳ���
	*
	*/
	std::string m_tmpParam;

	/**
	* @brief ���ô���
	*
	*/
	uint32_t m_callCount;
};

class NFTcpMessage
{
public:
	/**
	* @brief ��Ϣ����
	*
	*/
	enum MessageType
	{
		ACTOR_TCP_MESSAGE_TYPE_NULL = 0,
		ACTOR_TCP_MESSAGE_TYPE_ONE_PLAYER_PROXY_MSG = 1,
		ACTOR_TCP_MESSAGE_TYPE_MANY_PLAYER_PROXY_MSG = 2,
		ACTOR_TCP_MESSAGE_TYPE_ALL_PLAYER_PROXY_MSG = 3,
		ACTOR_TCP_MESSAGE_TYPE_ONE_PLAYER_MASTER_MSG = 4,
		ACTOR_TCP_MESSAGE_TYPE_ONE_PLAYER_PROXY_MAIN_SUB_MSG = 5,
		ACTOR_TCP_MESSAGE_TYPE_MANY_PLAYER_PROXY_MAIN_SUB_MSG = 6,
		ACTOR_TCP_MESSAGE_TYPE_ALL_PLAYER_PROXY_MAIN_SUB_MSG = 7,
		ACTOR_TCP_MESSAGE_TYPE_ONE_PLAYER_MASTER_MAIN_SUB_MSG = 8,
		ACTOR_TCP_MESSAGE_TYPE_ADD_ERROR_LOG_MSG = 10,
		ACTOR_TCP_MESSAGE_TYPE_ADD_HTTP_LOG_MSG = 11,
	};

	NFTcpMessage()
	{
		m_nMsgType = ACTOR_TCP_MESSAGE_TYPE_NULL;
		m_usLinkId = 0;
		m_nPlayerID = 0;
		m_nMsgID = 0;
		m_nLen = 0;
		m_nMainMsgID = 0;
		m_nSubMsgID = 0;
	}

	uint32_t m_nMsgType;
	uint32_t m_usLinkId;
	uint64_t m_nPlayerID;
	std::vector<uint64_t> m_nVecPlayerID;
	uint32_t m_nMsgID;
	uint16_t m_nMainMsgID;
	uint16_t m_nSubMsgID;
	uint32_t m_nLen;
	std::string m_strData;
	std::string m_errorLog;
	std::string m_funcLog;
};

class NFLuaThreadTimer : public NFTimerObj
{
public:
	NFLuaThreadTimer(NFCLuaThreadModule* p)
	{
		Clear();
		m_pLuaScriptModule = p;
	}

	void Clear()
	{
		mTimerId = 0;
		mInterVal = 0;
		mCallCount = 0;
		mCurCallCount = 0;
		mMsgType = 0;
	}

	uint32_t mTimerId;
	std::string mLuaFunc;
	uint32_t mMsgType;
	uint64_t mInterVal;
	uint32_t mCallCount;
	uint32_t mCurCallCount;
	std::string mDataStr;
	NFCLuaThreadModule* m_pLuaScriptModule;

	virtual void OnTimer(uint32_t nTimerID) override;
};

class NFCLuaThreadModule : public NFILuaScriptModule, public NFTimerObj
{
public:
	NFCLuaThreadModule(NFIPluginManager* p)
	{
		m_pPluginManager = p;
		m_processLoopActorId = 0;
		m_luaTimerIndex = 1000;
		m_pNetServerModule = nullptr;
		m_pNetClientModule = nullptr;
		m_pServerLoopTaskModule = nullptr;
		m_pWorkTaskModule = nullptr;
		m_finishLuaLoad = 0;
		m_finishInitServerLoop = 0;
	}

	virtual ~NFCLuaThreadModule()
	{

	}

public:
	virtual bool Init();
	virtual bool AfterInit();
	virtual bool ReadyExecute();

	virtual bool Execute();

	virtual bool BeforeShut();
	virtual bool Shut();
	virtual bool Finalize();

	virtual void OnTimer(uint32_t nTimerID);

	virtual bool StartActorPool(uint32_t workThreadNum, uint32_t tcpThreadNum);
	virtual bool CloseActorPool();

	virtual uint32_t AddTimer(uint32_t mMsgType, const std::string& luaFunc, uint64_t nInterVal, const std::string& dataStr, uint32_t callCount = 1);
public:
	virtual void RunNetRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t opreateId, const uint32_t nMsgId, const std::string& strMsg) override;
	virtual void RunNetRecvLuaFuncWithMainSub(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t opreateId, const uint16_t nMainMsgId, const uint16_t nSubMsgId, const std::string& strMsg) override;
	virtual void RunHttpRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint32_t requestId, const std::string& firstPath, const std::string& secondPath, const std::string& strMsg) override;
	virtual void SessionReport(uint64_t playerId, const std::string& report) override;
	virtual void SessionClose(uint64_t playerId) override;

	virtual void SendMsgToPlayer(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToManyPlayer(const std::vector<uint64_t>& nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToAllPlayer(const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToMaster(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);

	virtual void SendMsgToPlayer(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToManyPlayer(const std::vector<uint64_t>& nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToAllPlayer(const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToMaster(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);

	virtual void SendErrorLog(uint64_t playerId, const std::string& func_log, const std::string& errorLog, uint32_t count);
	virtual void SendHttpServerMsg(uint32_t servertype, const uint32_t requestId, const std::string& strMsg);

	virtual void AddMsgToPlayer(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);
	virtual void AddMsgToManyPlayer(const std::vector<uint64_t>& nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);
	virtual void AddMsgToAllPlayer(const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);
	virtual void AddMsgToMaster(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);

	virtual void AddMsgToPlayer(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);
	virtual void AddMsgToManyPlayer(const std::vector<uint64_t>& nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);
	virtual void AddMsgToAllPlayer(const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);
	virtual void AddMsgToMaster(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);


	virtual void AddErrorLog(uint64_t playerId, const std::string& func_log, const std::string& errorLog, uint32_t count);
	virtual void AddHttpServerMsg(uint32_t servertype, const uint32_t requestId, const std::string& strMsg);

	virtual void ReloadAllLuaFiles() override;
	virtual void ReloadLuaFiles() override;
	virtual void ReloadLuaFiles(const std::vector<std::string>& vecStr) override;
	virtual void GcStep();

	virtual void UpdateMin();
	virtual void Update5Min();
	virtual void Update10Min();
	virtual void Update30Min();
	virtual void UpdateHour();
	virtual void UpdateDay();
	virtual void UpdateWeek();
	virtual void UpdateMonth();

	virtual void RunGmFunction(const std::string& luaFunc, const std::vector<std::string>& vecStr) override;
public:
	/**
	* @brief ���һ��work Actor���
	*
	* @return
	*/
	virtual bool AddWorkActorComponent(NFITaskComponent* pComonnet);

	/**
	* @brief ���һ��tcp msg Actor���
	*
	* @return
	*/
	virtual bool AddTcpMsgActorComponent(NFITaskComponent* pComonnet);

	/**
	* @brief ���һ��server loop Actor���
	*
	* @return
	*/
	virtual bool AddServerLoopActorComponent(NFITaskComponent* pComonnet);

	/**
	* @brief ͨ��ƽ��ID���Ҫ�첽�����task
	*
	* @param pTask Ҫ�첽�����task
	* @return
	*/
	bool AddWorkTask(NFTask* pTask);

	/**
	* @brief ͨ��ƽ��ID���Ҫ�첽�����task
	*
	* @param pTask Ҫ�첽�����task
	* @return
	*/
	bool AddTcpMsgTask(NFTask* pTask);

	/**
	* @brief ѭ���첽�����task
	*
	* @param pTask Ҫ�첽�����task
	* @return
	*/
	bool AddProcessLoopTask(NFTask* pTask);

	/**
	* @brief ѭ���첽�����task
	*
	* @param pTask Ҫ�첽�����task
	* @return
	*/
	bool AddProcessTimerTask(NFTask* pTask);

	/**
	* @brief ѭ���첽�����task
	*
	* @param pTask Ҫ�첽�����task
	* @return
	*/
	bool AddProcessWorkTask(NFTask* pTask);

	void AddProcessTimer(uint32_t delayTimer, const std::string& luaFunc, const std::string& tmpParam);

	void AddProcessLoopTimer(uint32_t delayTimer, const std::string& luaFunc, const std::string& tmpParam);

	void AddRealTimer(uint32_t internal, uint32_t callount, const std::string& luaFunc, const std::string& tmpParam);

	void AddProcessWork(const std::string& luaFunc, const std::string& tmpParam);
	/*
	������߳�LUA�������Ķ�ʱ��
	*/
	void HandleLuaTimer();

	/*
	������߳�LUA����������Ϣ
	*/
	void HandleLuaTcpMsg();

	void AddFinishLoad();
	void AddFinishInitServerLoop();
	bool IsFinishAllLoad();
	bool IsFinishAllInitServerLoop();
public:
	void OnAccountEventCallBack(uint32_t nEvent, uint32_t unLinkId, NF_SHARE_PTR<PlayerGameServerInfo> pServerData);
	NF_SHARE_PTR<PlayerGameServerInfo> GetPlayerInfo(uint64_t playerId);
protected:
	/**
	* @brief ���صĶ�ʱ����Ϣ��,
	* actor�߳̽����ݷ�����У� ���̴߳Ӷ�����ȡ���ݴ���
	*/
	NFQueueVector<NFTimerMessage> m_mQueue;

	/*
		��ʱ��
	*/
	std::map<uint64_t, NFLuaThreadTimer*> m_luaTimerMap;
	std::list<NFLuaThreadTimer*> m_luaTimerList;
	uint32_t m_luaTimerIndex;

	NFMapEx<uint64_t, PlayerGameServerInfo> mPlayerProxyInfoMap;
protected:
	NFINetServerModule* m_pNetServerModule;
	NFINetClientModule* m_pNetClientModule;
	NFIHttpServerModule* m_pHttpServerModule;
protected:
	/**
	* @brief ���صĶ�ʱ����Ϣ��,
	* actor�߳̽����ݷ�����У� ���̴߳Ӷ�����ȡ���ݴ���
	*/
	NFQueueVector<NFTcpMessage> m_mTcpMsgQueue;

	/**
	* @brief server loop actor module ��ѭ�����߳�ϵͳ
	*/
	NFITaskModule* m_pServerLoopTaskModule;

	/**
	* @brief server loop actor  ��ѭ�����߳�Actor
	*/
	int m_processLoopActorId;

	/**
	* @brief process work/timer actor module ���߳�ϵͳ
	*/
	NFITaskModule* m_pWorkTaskModule;

	/**
	* @brief actor��������
	*/
	std::vector<int> m_vecWorkActorPool;

	/**
	* @brief tcp msg actor module ���߳�ϵͳ
	*/
	NFITaskModule* m_pTcpMsgTaskModule;

	/**
	* @brief tcp actor��������
	*/
	std::vector<int> m_vecTcpMsgActorPool;

	/**
	* @brief actor ��ɼ��ش���
	*/
	uint32_t m_finishLuaLoad;

	/**
	* @brief actor ��ɳ�ʼ��ѭ������
	*/
	uint32_t m_finishInitServerLoop;
};