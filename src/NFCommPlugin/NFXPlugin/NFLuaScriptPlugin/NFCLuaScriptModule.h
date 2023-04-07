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
	std::string mGlobalLuaFunc;
	std::string mLuaFunc;
	uint64_t mInterVal;
	uint32_t mCallCount;
	uint32_t mCurCallCount;
	NFLuaRef mDataStr;
	std::string mTmpStr;
	NFCLuaScriptModule* m_pLuaScriptModule;

	virtual int OnTimer(uint32_t nTimerID) override;
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
	virtual void RunNetRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t opreateId, const uint32_t nMsgId, const std::string& strMsg) override;
	virtual void RunNetRecvLuaFuncWithMainSub(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t opreateId, const uint16_t nMainMsgId, const uint16_t nSubMsgId, const std::string& strMsg) override;
	virtual void RunHttpRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint32_t requestId, const std::string& firstPath, const std::string& secondPath, const std::string& strMsg) override;
	virtual void SessionReport(uint64_t playerId, const std::string& report) override;
	virtual void SessionClose(uint64_t playerId) override;
	virtual void RunGmFunction(const std::string& luaFunc, const std::vector<std::string>& vecStr) override;
public:
	virtual uint32_t AddTimer(const std::string& luaFunc, uint64_t nInterVal, uint32_t nCallCount, const NFLuaRef& dataStr);
	virtual uint32_t AddClocker(const std::string& luaFunc, uint64_t nStartTime, uint32_t nInterDays, uint32_t nCallCount, const NFLuaRef& dataStr);
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
    virtual bool RegisterClientMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, const std::string& luaFunc);

    /**
     * @brief 注册服务器信息处理函数
     * @param eType
     * @param nMsgID
     * @return
     */
    virtual bool RegisterServerMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, const std::string& luaFunc);
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

	virtual void ProcessWork(const std::string& luaFunc, const NFLuaRef& dataStr);

	virtual void BeginProfiler(const std::string& luaFunc);
	virtual uint64_t EndProfiler();//return this time cost time(us) 微妙

	virtual void ReloadAllLuaFiles() override;
	virtual void ReloadLuaFiles() override;
	virtual void ReloadLuaFiles(const std::vector<std::string>& vecStr) override;

	virtual std::string Sha256(const std::string& s);
	virtual std::string Platform();
	virtual bool IsThreadModule();
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
};

