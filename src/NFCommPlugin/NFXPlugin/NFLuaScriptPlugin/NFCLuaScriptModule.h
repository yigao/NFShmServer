// -------------------------------------------------------------------------
//    @FileName         :    NFCLuaScriptModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-07-08
//    @Module           :    NFCLuaScriptModule
//    @Desc             :
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFILuaScriptModule.h"
#include "NFComm/NFPluginModule/NFTimerObj.h"
#include "NFComm/NFPluginModule/NFILuaLoader.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFCore/NFCommon.h"

#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFCommPlugin/NFKernelPlugin/NFServerLinkData.h"

#include <unordered_set>

enum EnumLuaModule
{
	EnumLuaModule_NULL = 0,
	EnumLuaModule_INIT = 1,
	EnumLuaModule_SEC = 6,
	EnumLuaModule_MIN = 7,
	EnumLuaModule_5MIN = 8,
	EnumLuaModule_10MIN = 9,
	EnumLuaModule_30MIN = 10,
	EnumLuaModule_HOUR = 11,
	EnumLuaModule_DAY = 12,
	EnumLuaModule_WEEK = 13,
	EnumLuaModule_MONTH = 14,
};

class NFCLuaScriptModule;

class NFLuaTimer : public NFTimerObj
{
public:
	NFLuaTimer(NFCLuaScriptModule* p, NFIPluginManager* pPluginManager): NFTimerObj(pPluginManager)
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
	}

	uint32_t mTimerId;
    LuaIntf::LuaRef mLuaFunc;
	uint64_t mInterVal;
	uint32_t mCallCount;
	uint32_t mCurCallCount;
	NFLuaRef mDataStr;
	NFCLuaScriptModule* m_pLuaScriptModule;

	virtual int OnTimer(uint32_t nTimerID) override;
};

struct NetLuaReceiveFunctor
{
    NetLuaReceiveFunctor()
    {
    }

    NetLuaReceiveFunctor(const LuaIntf::LuaRef& luaFunc): m_luaFunc(luaFunc)
    {
    }

    NetLuaReceiveFunctor(const NetLuaReceiveFunctor& functor)
    {
        if (this != &functor)
        {
            m_luaFunc = functor.m_luaFunc;
        }
    }

    NetLuaReceiveFunctor& operator=(const NetLuaReceiveFunctor& functor)
    {
        if (this != &functor)
        {
            m_luaFunc = functor.m_luaFunc;
        }

        return *this;
    }

    LuaIntf::LuaRef m_luaFunc;
};

struct LuaCallBack {
    //call back
    LuaCallBack()
    {
        mxReceiveCallBack.resize(NF_MODULE_MAX);
        for(int i = 0; i < (int)mxReceiveCallBack.size(); i++)
        {
            mxReceiveCallBack[i].resize(NF_NET_MAX_MSG_ID);
        }

        mxRpcCallBack.resize(NF_NET_MAX_MSG_ID);
    }

    virtual ~LuaCallBack()
    {

    }

    std::vector<std::vector<NetLuaReceiveFunctor>> mxReceiveCallBack;
    std::unordered_map<uint64_t, NetEventFunctor> mxEventCallBack;
    std::unordered_map<uint64_t, NetReceiveFunctor> mxOtherMsgCallBackList;
    NetReceiveFunctor mxAllMsgCallBackList;
    std::unordered_map<uint32_t, std::unordered_map<std::string, HTTP_RECEIVE_FUNCTOR>> mxHttpMsgCBMap; //uint32_t => NFHttpType
    std::unordered_map<uint32_t, std::vector<HTTP_RECEIVE_FUNCTOR>> mxHttpOtherMsgCBMap; //uint32_t => NFHttpType
    std::unordered_map<std::string, HTTP_FILTER_FUNCTOR> mxHttpMsgFliterMap;
    std::vector<NetRpcService> mxRpcCallBack;
};

class NFCLuaScriptModule
	: public NFILuaScriptModule, public NFILuaLoader
{
public:
    NFCLuaScriptModule(NFIPluginManager* p);
    virtual ~NFCLuaScriptModule();
public:

    virtual bool Init() override;
    virtual bool AfterInit();
	virtual bool ReadyExecute() override;

    virtual bool Execute() override;

    virtual bool BeforeShut() override;
    virtual bool Shut() override;
    virtual bool Finalize() override;

	virtual int OnTimer(uint32_t nTimerID) override;

public:
	virtual void SessionReport(uint64_t playerId, const std::string& report) override;
	virtual void SessionClose(uint64_t playerId) override;
	virtual void RunGmFunction(const std::string& luaFunc, const std::vector<std::string>& vecStr) override;
public:
	virtual uint32_t AddTimer(const LuaIntf::LuaRef& luaFunc, uint64_t nInterVal, uint32_t nCallCount, const NFLuaRef& dataStr);
	virtual uint32_t AddClocker(const LuaIntf::LuaRef& luaFunc, uint64_t nStartTime, uint32_t nInterDays, uint32_t nCallCount, const NFLuaRef& dataStr);
	virtual void StopTimer(uint32_t nTimerID);
	virtual void StopClocker(uint32_t nTimerID);
public:
    virtual void SendErrorLog(uint64_t id, const std::string& funcLog, const std::string& errorLog, uint32_t count);
public:
    /**
     * @brief 注册客户端信息处理函数
     * @param eType
     * @param nMsgID
     * @return
     */
    virtual bool RegisterClientMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, const LuaIntf::LuaRef& luaFunc);

    /**
     * @brief 注册服务器信息处理函数
     * @param eType
     * @param nMsgID
     * @return
     */
    virtual bool RegisterServerMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, const LuaIntf::LuaRef& luaFunc);

    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);
public:
public:
    virtual int SendMsgToMasterServer(NF_SERVER_TYPES eSendTyp, uint32_t nMsgId, const std::string &xData, uint64_t nParam1 = 0,
                                      uint64_t nParam2 = 0);

public:
    ////////////////////////////send proxy msg to other serer//////////////////////////////////
    virtual int
    SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const std::string &xData,
                        uint64_t nParam1 = 0, uint64_t nParam2 = 0);

public:
    ///////////////////////////other server send msg to proxy msg/////////////////////////////
    virtual int SendRedirectMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, const std::unordered_set<uint64_t> &ids, uint32_t nMsgId,
                                             const string &xData);

    virtual int
    SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const std::string &xData,
                         uint64_t nParam1 = 0, uint64_t nParam2 = 0);

    ///////////////////////////other server send msg to world msg/////////////////////////////
    virtual int
    SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgId, const std::string &xData, uint64_t nParam1 = 0,
                         uint64_t nParam2 = 0);

    virtual int SendTransToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const std::string &xData, uint32_t req_trans_id = 0,
                                       uint32_t rsp_trans_id = 0);

    ///////////////////////////other server send msg to game msg/////////////////////////////
    virtual int
    SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const std::string &xData,
                        uint64_t nParam1 = 0, uint64_t nParam2 = 0);

    virtual int
    SendTransToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const std::string &xData, uint32_t req_trans_id = 0,
                          uint32_t rsp_trans_id = 0);

    ///////////////////////////other server send msg to logic server/////////////////////////////
    virtual int
    SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const std::string &xData,
                         uint64_t nParam1 = 0, uint64_t nParam2 = 0);

    virtual int
    SendTransToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const std::string &xData, uint32_t req_trans_id = 0,
                           uint32_t rsp_trans_id = 0);

    ///////////////////////////other server send msg to sns server/////////////////////////////
    virtual int
    SendMsgToSnsServer(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgId, const std::string &xData, uint64_t nParam1 = 0,
                       uint64_t nParam2 = 0);

    virtual int SendTransToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const std::string &xData, uint32_t req_trans_id = 0,
                                     uint32_t rsp_trans_id = 0);
public:
	virtual const std::string& GetAppName() const;
	virtual int GetAppID() const;
	virtual uint64_t GetInitTime() const;
	virtual uint64_t GetNowTime() const;
	virtual std::string GetMD5(const std::string& str);
	virtual uint32_t GetCRC32(const std::string& s);
	virtual uint16_t GetCRC16(const std::string& s);
	virtual std::string Base64Encode(const std::string& s);
	virtual std::string Base64Decode(const std::string& s);
	virtual uint64_t GetMsecTime() const;
	virtual uint64_t GetSecTime() const;

	virtual void LuaDebug(uint32_t logId, uint64_t guid, const std::string& str);

	virtual void LuaInfo(uint32_t logId, uint64_t guid, const std::string& str);

	virtual void LuaWarn(uint32_t logId, uint64_t guid, const std::string& str);

	virtual void LuaError(uint32_t logId, uint64_t guid, const std::string& str);

	virtual void BeginProfiler(const std::string& luaFunc);
	virtual uint64_t EndProfiler();//return this time cost time(us) 微妙

	virtual void ReloadAllLuaFiles() override;
	virtual void ReloadLuaFiles() override;
	virtual void ReloadLuaFiles(const std::vector<std::string>& vecStr) override;

	virtual std::string Sha256(const std::string& s);
	virtual std::string Platform();
	virtual bool IsThreadModule();
    virtual bool IsDebug();
public:
    bool Register();
	void LoadScript();

	virtual void UpdateSec();
	virtual void UpdateMin();
	virtual void Update5Min();
	virtual void Update10Min();
	virtual void Update30Min();
	virtual void UpdateHour();
	virtual void UpdateDay();
	virtual void UpdateWeek();
	virtual void UpdateMonth();
protected:
    int64_t mnTime;
protected:
	std::map<uint64_t, NFLuaTimer*> m_luaTimerMap;
	std::list<NFLuaTimer*> m_luaTimerList;
	uint32_t m_luaTimerIndex;
protected:
    std::vector<LuaCallBack> mxLuaCallBack;
};

