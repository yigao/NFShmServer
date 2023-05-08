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
#include "NFComm/NFPluginModule/NFProtobufCommon.h"

enum EnumLuaScriptTimer
{
    EnumLuaScriptTimer_ServerLoop = 0,
};

/**
* @brief 收到事件函数, 对收到的事件进行处理
*
* @param nEventID		事件ID
* @param nSrcID			事件源ID，一般都是玩家，生物唯一id
* @param bySrcType		事件源类型，玩家类型，怪物类型之类的
* @param pEventContext	发过来的事件数据
* @return
*/
/*
* 由Fire的问题，导致的问题:
* 问题1:如果在OnExecute函数里， 调用别的对象的UnSubscribe函数, 如果key一致(也就是nEventID,nSrcID,bySrcType都一样),
*		可能导致将要执行的事件被删除，这可能与你预想的设计不一样
* 问题2:如果在OnExecute函数里， Fire了别的事件，会导致迭代问题，事件系统已经了做了预付， 相同的事件，最多迭代5次，
*       所有的Fire事件最多迭代20次
*/
int NFLuaEventObj::OnExecuteImple(const SEventKey skey, const NFLuaRef &message)
{
    return OnExecute(skey.nServerType, skey.nEventID, skey.bySrcType, skey.nSrcID, message);
}

int NFLuaEventObj::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const NFLuaRef& message)
{
    LuaIntf::LuaRef luaFunc = m_pModule->GetGlobal(m_strLuaFunc);
    CHECK_EXPR(luaFunc.isFunction(), 0, "strLuaFunc:{} is not lua function", m_strLuaFunc);
    m_pModule->TryRunGlobalScriptFunc("LuaNFrame.DispatchEvent", luaFunc, m_strLuaFunc, serverType, nEventID, bySrcType, nSrcID, message);
    return 0;
}

int NFLuaEventObj::OnExecuteImple(const SEventKey skey, const std::string& msgType, const std::string& msgData)
{
    return OnExecute(skey.nServerType, skey.nEventID, skey.bySrcType, skey.nSrcID, msgType, msgData);
}

int NFLuaEventObj::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string& msgType, const std::string& msgData)
{
    LuaIntf::LuaRef luaFunc = m_pModule->GetGlobal(m_strLuaFunc);
    CHECK_EXPR(luaFunc.isFunction(), 0, "strLuaFunc:{} is not lua function", m_strLuaFunc);
    m_pModule->TryRunGlobalScriptFunc("LuaNFrame.DispatchEventStrMsg", luaFunc, m_strLuaFunc, serverType, nEventID, bySrcType, nSrcID, msgType, msgData);
    return 0;
}

NFCLuaScriptModule::NFCLuaScriptModule(NFIPluginManager *p) : NFILuaScriptModule(p)
{
    m_luaTimerIndex = 10000;
    mxLuaCallBack.resize(NF_ST_MAX);
    m_luaTimerPool = NF_NEW NFObjectPool<NFLuaTimer>(1000, false);
    m_luaEventPool = NF_NEW NFObjectPool<NFLuaEventObj>(1000, false);
}

NFCLuaScriptModule::~NFCLuaScriptModule()
{
    if (m_luaTimerPool)
    {
        NF_SAFE_DELETE(m_luaTimerPool);
    }

    if (m_luaEventPool)
    {
        NF_SAFE_DELETE(m_luaEventPool);
    }
}

int NFLuaTimer::OnTimer(uint32_t nTimerID)
{
    mCurCallCount++;
    m_pLuaScriptModule->TryRunGlobalScriptFunc("LuaNFrame.DispatchTimer", nTimerID, mLuaFunc, mDataStr);
    return 0;
}

bool NFCLuaScriptModule::Awake()
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
    return true;
}

bool NFCLuaScriptModule::Init()
{
    TryRunGlobalScriptFunc("LuaNFrame.Init");
    return true;
}

int NFCLuaScriptModule::OnTimer(uint32_t nTimerID)
{
    if (!m_pObjPluginManager->IsInited())
    {
        return 0;
    }

    if (nTimerID == EnumLuaModule_SEC)
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

bool NFCLuaScriptModule::OnReloadConfig()
{
    ReloadAllLuaFiles();
    return true;
}

bool NFCLuaScriptModule::Shut()
{
    TryRunGlobalScriptFunc("LuaNFrame.Shut");
    return true;
}

bool NFCLuaScriptModule::Finalize()
{
    for (auto iter = m_luaTimerMap.begin(); iter != m_luaTimerMap.end(); iter++)
    {
        m_luaTimerPool->FreeObj(iter->second);
    }

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
                    m_luaTimerPool->FreeObj(pTimer);
                    continue;
                }
            }
        }
        iter++;
    }
    return true;
}

void NFCLuaScriptModule::LoadScript()
{
    TryAddPackagePath(m_pObjPluginManager->GetLuaScriptPath());
    TryLoadScriptFile("init.lua");
    TryRunGlobalScriptFunc("LuaNFrame.InitScript", this);
}

const std::string &NFCLuaScriptModule::GetAppName() const
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

std::string NFCLuaScriptModule::GetMD5(const std::string &str)
{
    return NFMD5::md5str(str);
}

uint32_t NFCLuaScriptModule::GetCRC32(const std::string &s)
{
    return NFCRC32::Sum(s);
}

uint16_t NFCLuaScriptModule::GetCRC16(const std::string &s)
{
    return NFCRC16::Sum(s);
}

std::string NFCLuaScriptModule::Base64Encode(const std::string &s)
{
    return NFBase64::Encode(s);
}

std::string NFCLuaScriptModule::Base64Decode(const std::string &s)
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

void NFCLuaScriptModule::BeginProfiler(const std::string &funcName)
{
    m_pObjPluginManager->BeginProfiler(funcName);
}

uint64_t NFCLuaScriptModule::EndProfiler()
{
    return m_pObjPluginManager->EndProfiler();
}

std::string NFCLuaScriptModule::Sha256(const std::string &s)
{
    std::string ret;
    NFSha256::hash256_hex_string(s, ret);
    return ret;
}

bool NFCLuaScriptModule::Register()
{
    LuaIntf::LuaBinding(*m_pLuaContext).beginClass<NFServerConfig>("NFServerConfig")
            .addFunction("GetServerId", &NFServerConfig::GetServerId)
            .addFunction("GetServerName", &NFServerConfig::GetServerName)
            .addFunction("GetBusId", &NFServerConfig::GetBusId)
            .addFunction("GetServerOpenTime", &NFServerConfig::GetServerOpenTime)
            .addFunction("GetDefaultDBName", &NFServerConfig::GetDefaultDBName)
            .addFunction("GetCrossDBName", &NFServerConfig::GetCrossDBName)
            .addFunction("GetMaxOnlinePlayerNum", &NFServerConfig::GetMaxOnlinePlayerNum)
            .addFunction("GetHeartBeatTimeout", &NFServerConfig::GetHeartBeatTimeout)
            .addFunction("GetClientKeepAliveTimeout", &NFServerConfig::GetClientKeepAliveTimeout)
            .endClass();

    LuaIntf::LuaBinding(*m_pLuaContext).beginClass<NFDataPackage>("NFDataPackage")
            .addFunction("GetData", &NFDataPackage::GetData)
            .addFunction("GetSize", &NFDataPackage::GetSize)
            .addFunction("GetParam1", &NFDataPackage::GetParam1)
            .addFunction("GetParam2", &NFDataPackage::GetParam2)
            .addFunction("GetSrcId", &NFDataPackage::GetSrcId)
            .addFunction("GetDstId", &NFDataPackage::GetDstId)
            .addFunction("GetServerType", &NFDataPackage::GetServerType)
            .addFunction("GetObjectLinkId", &NFDataPackage::GetObjectLinkId)
            .addFunction("GetMsgId", &NFDataPackage::GetMsgId)
            .addFunction("ToString", &NFDataPackage::ToString)
            .endClass();

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
            .addFunction("SetLogLevel", &NFCLuaScriptModule::SetLogLevel)
            .addFunction("SetFlushOn", &NFCLuaScriptModule::SetFlushOn)
            .addFunction("LuaTrace", &NFCLuaScriptModule::LuaTrace)
            .addFunction("LuaDebug", &NFCLuaScriptModule::LuaDebug)
            .addFunction("LuaInfo", &NFCLuaScriptModule::LuaInfo)
            .addFunction("LuaWarn", &NFCLuaScriptModule::LuaWarn)
            .addFunction("LuaError", &NFCLuaScriptModule::LuaError)
            .addFunction("BeginProfiler", &NFCLuaScriptModule::BeginProfiler)
            .addFunction("EndProfiler", &NFCLuaScriptModule::EndProfiler)
            .addFunction("Sha256", &NFCLuaScriptModule::Sha256)
            .addFunction("Platform", &NFCLuaScriptModule::Platform)
            .addFunction("IsThreadModule", &NFCLuaScriptModule::IsThreadModule)
            .addFunction("IsDebug", &NFCLuaScriptModule::IsDebug)
            .addFunction("SendErrorLog", &NFCLuaScriptModule::SendErrorLog)
            .addFunction("RegisterClientMessage", &NFCLuaScriptModule::RegisterClientMessage)
            .addFunction("RegisterServerMessage", &NFCLuaScriptModule::RegisterServerMessage)
            .addFunction("AddEventCallBack", &NFCLuaScriptModule::AddEventCallBack)
            .addFunction("AddOtherCallBack", &NFCLuaScriptModule::AddOtherCallBack)
            .addFunction("AddAllMsgCallBack", &NFCLuaScriptModule::AddAllMsgCallBack)
            .addFunction("SendMsgToMasterServer", &NFCLuaScriptModule::SendMsgToMasterServer)
            .addFunction("SendProxyMsgByBusId", &NFCLuaScriptModule::SendProxyMsgByBusId)
            .addFunction("SendRedirectMsgToProxyServer", &NFCLuaScriptModule::SendRedirectMsgToProxyServer)
            .addFunction("SendMsgToProxyServer", &NFCLuaScriptModule::SendMsgToProxyServer)
            .addFunction("SendMsgToWorldServer", &NFCLuaScriptModule::SendMsgToWorldServer)
            .addFunction("SendTransToWorldServer", &NFCLuaScriptModule::SendTransToWorldServer)
            .addFunction("SendMsgToGameServer", &NFCLuaScriptModule::SendMsgToGameServer)
            .addFunction("SendTransToGameServer", &NFCLuaScriptModule::SendTransToGameServer)
            .addFunction("SendMsgToLogicServer", &NFCLuaScriptModule::SendMsgToLogicServer)
            .addFunction("SendTransToLogicServer", &NFCLuaScriptModule::SendTransToLogicServer)
            .addFunction("SendMsgToSnsServer", &NFCLuaScriptModule::SendMsgToSnsServer)
            .addFunction("SendTransToSnsServer", &NFCLuaScriptModule::SendTransToSnsServer)
            .addFunction("IsInited", &NFCLuaScriptModule::IsInited)
            .addFunction("IsServerStopping", &NFCLuaScriptModule::IsServerStopping)
            .addFunction("GetAppConfig", &NFCLuaScriptModule::GetAppConfig)
            .addFunction("GetClientLinkId", &NFCLuaScriptModule::GetClientLinkId)
            .addFunction("GetServerLinkId", &NFCLuaScriptModule::GetServerLinkId)
            .addFunction("AddRpcService", &NFCLuaScriptModule::AddRpcService)
            .addFunction("GetRpcService", &NFCLuaScriptModule::GetRpcService)
            .addFunction("FireCppExecute", &NFCLuaScriptModule::FireCppExecute)
            .addFunction("FireExecute", &NFCLuaScriptModule::FireExecute)
            .addFunction("Subscribe", &NFCLuaScriptModule::Subscribe)
            .addFunction("IsLuaFunction", &NFCLuaScriptModule::IsLuaFunction)
            .addFunction("GetLuaData", &NFCLuaScriptModule::GetLuaData)
            .endClass();

    return true;
}

void NFCLuaScriptModule::SessionReport(uint64_t playerId, const std::string &report)
{
    TryRunGlobalScriptFunc("TcpSessionReport", playerId, report);
}

void NFCLuaScriptModule::SessionClose(uint64_t playerId)
{
    TryRunGlobalScriptFunc("TcpSessionClose", playerId);
}

void NFCLuaScriptModule::RunGmFunction(const std::string &luaFunc, const std::vector<std::string> &vecStr)
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

void NFCLuaScriptModule::SendErrorLog(uint64_t id, const std::string &funcLog, const std::string &errorLog, uint32_t count)
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
        NFLuaTimer *luaTimer = iter->second;
        luaTimer->KillTimer(nTimerID);

        m_luaTimerMap.erase(iter);
        luaTimer->Clear();
        m_luaTimerPool->FreeObj(luaTimer);
    }
}

void NFCLuaScriptModule::StopClocker(uint32_t nTimerID)
{
    StopTimer(nTimerID);
}

uint32_t NFCLuaScriptModule::AddTimer(const LuaIntf::LuaRef &luaFunc, uint64_t nInterVal, uint32_t nCallCount, const NFLuaRef &dataStr)
{
    NFLuaTimer *luaTimer = m_luaTimerPool->MallocObjWithArgs(this, m_pObjPluginManager);

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

uint32_t
NFCLuaScriptModule::AddClocker(const LuaIntf::LuaRef &luaFunc, uint64_t nStartTime, uint32_t nInterDays, uint32_t nCallCount, const NFLuaRef &dataStr)
{
    NFLuaTimer *luaTimer = m_luaTimerPool->MallocObjWithArgs(this, m_pObjPluginManager);

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

void NFCLuaScriptModule::ReloadLuaFiles(const std::vector<std::string> &vecStr)
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

bool NFCLuaScriptModule::IsDebug()
{
#ifdef NF_DEBUG_MODE
    return true;
#else
    return false;
#endif
}

bool NFCLuaScriptModule::IsInited()
{
    return m_pObjPluginManager->IsInited();
}

bool NFCLuaScriptModule::IsServerStopping()
{
    return m_pObjPluginManager->IsServerStopping();
}

NFServerConfig *NFCLuaScriptModule::GetAppConfig(uint32_t serverType)
{
    return FindModule<NFIConfigModule>()->GetAppConfig((NF_SERVER_TYPES)serverType);
}

uint64_t NFCLuaScriptModule::GetClientLinkId(uint32_t serverType)
{
    return FindModule<NFIMessageModule>()->GetClientLinkId((NF_SERVER_TYPES)serverType);
}

uint64_t NFCLuaScriptModule::GetServerLinkId(uint32_t serverType)
{
    return FindModule<NFIMessageModule>()->GetServerLinkId((NF_SERVER_TYPES)serverType);
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

bool NFCLuaScriptModule::RegisterClientMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, const std::string &strLuaFunc, bool createCo)
{
    LuaIntf::LuaRef luaFunc = GetGlobal(strLuaFunc);
    CHECK_EXPR(luaFunc.isFunction(), false, "RegisterClientMessage Lua Func Fail, is not a function");

    if (NFIDynamicModule::RegisterClientMessage(eType, nMsgID, createCo))
    {
        if (eType < mxLuaCallBack.size())
        {
            CHECK_EXPR_ASSERT(nMsgID < NF_NET_MAX_MSG_ID, false, "nMsgID:{} >= NF_NET_MAX_MSG_ID", nMsgID);
            mxLuaCallBack[eType].mxReceiveCallBack[NF_MODULE_CLIENT][nMsgID] = NetLuaReceiveFunctor(strLuaFunc);
            return true;
        }
    }

    return false;
}

bool NFCLuaScriptModule::RegisterServerMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, const std::string &strLuaFunc, bool createCo)
{
    LuaIntf::LuaRef luaFunc = GetGlobal(strLuaFunc);
    CHECK_EXPR(luaFunc.isFunction(), false, "RegisterServerMessage Lua Func Fail, is not a function");

    if (NFIDynamicModule::RegisterServerMessage(eType, nMsgID, createCo))
    {
        if (eType < mxLuaCallBack.size())
        {
            CHECK_EXPR_ASSERT(nMsgID < NF_NET_MAX_MSG_ID, false, "nMsgID:{} >= NF_NET_MAX_MSG_ID", nMsgID);
            mxLuaCallBack[eType].mxReceiveCallBack[NF_MODULE_SERVER][nMsgID] = NetLuaReceiveFunctor(strLuaFunc);
            return true;
        }
    }

    return false;
}

int NFCLuaScriptModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Lua Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Lua Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    uint32_t eServerType = GetServerTypeFromUnlinkId(packet.nObjectLinkId);
    if (eServerType < mxLuaCallBack.size() && msgId < NF_NET_MAX_MSG_ID)
    {
        NetLuaReceiveFunctor &functor = mxLuaCallBack[eServerType].mxReceiveCallBack[NF_MODULE_CLIENT][msgId];
        LuaIntf::LuaRef luaFunc = GetGlobal(functor.m_strLuaFunc);
        TryRunGlobalScriptFunc("LuaNFrame.DispatchClientMessage", luaFunc, functor.m_strLuaFunc, msgId, packet, param1, param2);
    }
    return 0;
}

int NFCLuaScriptModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Lua Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Lua Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    uint32_t eServerType = GetServerTypeFromUnlinkId(packet.nObjectLinkId);
    if (eServerType < mxLuaCallBack.size() && msgId < NF_NET_MAX_MSG_ID)
    {
        NetLuaReceiveFunctor &functor = mxLuaCallBack[eServerType].mxReceiveCallBack[NF_MODULE_SERVER][msgId];
        LuaIntf::LuaRef luaFunc = GetGlobal(functor.m_strLuaFunc);
        TryRunGlobalScriptFunc("LuaNFrame.DispatchServerMessage", luaFunc, functor.m_strLuaFunc, msgId, packet, param1, param2);
    }
    return 0;
}

int NFCLuaScriptModule::SendMsgToMasterServer(NF_SERVER_TYPES eSendType, uint32_t nMsgId, const string &xData, uint64_t nParam1, uint64_t nParam2)
{
    auto pServerData = FindModule<NFIMessageModule>()->GetMasterData(eSendType);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, eType error:{}", (int) eSendType);

    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nMsgId, xData, nParam1, nParam2);
    return 0;
}

int NFCLuaScriptModule::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const string &xData,
                                            uint64_t nParam1, uint64_t nParam2)
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(eType, nDstId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", nDstId);

    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nModuleId, nMsgId, xData, nParam1, nParam2, pConfig->BusId, nDstId);
    return 0;
}

int NFCLuaScriptModule::SendRedirectMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, const unordered_set<uint64_t> &ids, uint32_t nMsgId,
                                                     const string &xData)
{
    proto_ff::Proto_SvrPkg svrPkg;
    svrPkg.set_msg_id(nMsgId);
    svrPkg.set_msg_data(xData);

    for (auto iter = ids.begin(); iter != ids.end(); iter++)
    {
        svrPkg.mutable_redirect_info()->add_id(*iter);
    }

    SendMsgToProxyServer(eType, nDstId, NF_MODULE_SERVER, proto_ff::NF_SERVER_REDIRECT_MSG_TO_PROXY_SERVER_CMD, svrPkg.SerializeAsString());
    return 0;
}

int NFCLuaScriptModule::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const string &xData,
                                             uint64_t nParam1, uint64_t nParam2)
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL");

    auto pServerData = FindModule<NFIMessageModule>()->GetRandomServerByServerType(eType, NF_ST_PROXY_AGENT_SERVER);
    if (pServerData)
    {
        FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nModuleId, nMsgId, xData, nParam1, nParam2, pConfig->BusId, nDstId);
        return 0;
    }

    pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(eType, nDstId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", nDstId);
    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nModuleId, nMsgId, xData, nParam1, nParam2, pConfig->BusId, nDstId);
    return 0;
}

int NFCLuaScriptModule::SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgId, const string &xData, uint64_t nParam1,
                                             uint64_t nParam2)
{
    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_WORLD_SERVER, 0, 0, nModuleId, nMsgId, xData, nParam1, nParam2);
}

int
NFCLuaScriptModule::SendTransToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const string &xData, uint32_t req_trans_id,
                                           uint32_t rsp_trans_id)
{
    return FindModule<NFIMessageModule>()->SendTrans(eType, NF_ST_WORLD_SERVER, 0, 0, nMsgId, xData, req_trans_id, rsp_trans_id);
}

int NFCLuaScriptModule::SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const string &xData,
                                            uint64_t nParam1, uint64_t nParam2)
{
    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_GAME_SERVER, 0, nDstId, nModuleId, nMsgId, xData, nParam1, nParam2);
}

int NFCLuaScriptModule::SendTransToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const string &xData,
                                              uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    return FindModule<NFIMessageModule>()->SendTrans(eType, NF_ST_GAME_SERVER, 0, nDstId, nMsgId, xData, req_trans_id, rsp_trans_id);
}

int NFCLuaScriptModule::SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const string &xData,
                                             uint64_t nParam1, uint64_t nParam2)
{
    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_LOGIC_SERVER, 0, nDstId, nModuleId, nMsgId, xData, nParam1, nParam2);
}

int NFCLuaScriptModule::SendTransToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const string &xData,
                                               uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    return FindModule<NFIMessageModule>()->SendTrans(eType, NF_ST_LOGIC_SERVER, 0, nDstId, nMsgId, xData, req_trans_id, rsp_trans_id);
}

int NFCLuaScriptModule::SendMsgToSnsServer(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgId, const string &xData, uint64_t nParam1,
                                           uint64_t nParam2)
{
    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_SNS_SERVER, 0, 0, nModuleId, nMsgId, xData, nParam1, nParam2);
}

int NFCLuaScriptModule::SendTransToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const string &xData, uint32_t req_trans_id,
                                             uint32_t rsp_trans_id)
{
    return FindModule<NFIMessageModule>()->SendTrans(eType, NF_ST_SNS_SERVER, 0, 0, nMsgId, xData, req_trans_id, rsp_trans_id);
}

void NFCLuaScriptModule::SetLogLevel(uint32_t level)
{
    NFLogMgr::Instance()->SetDefaultLevel((NF_LOG_LEVEL) level);
}

void NFCLuaScriptModule::SetFlushOn(uint32_t level)
{
    NFLogMgr::Instance()->SetDefaultFlush((NF_LOG_LEVEL) level);
}

void NFCLuaScriptModule::LuaTrace(uint32_t logId, uint64_t guid, const std::string &file, int line, const std::string &func, const std::string &log)
{
#ifdef _WIN32
    std::string tempFile = "\\" + file;
        const char* pFile = strrchr(tempFile.c_str(), '\\') + 1;
#else
    std::string tempFile = "/" + file;
    const char *pFile = strrchr(tempFile.c_str(), '/') + 1;
#endif

    NFLogMgr::Instance()->LogDefault(NLL_TRACE_NORMAL, NFSourceLoc{pFile, line, func.c_str()}, logId, guid, log);
}

void NFCLuaScriptModule::LuaDebug(uint32_t logId, uint64_t guid, const std::string &file, int line, const std::string &func, const std::string &log)
{
#ifdef _WIN32
    std::string tempFile = "\\" + file;
        const char* pFile = strrchr(tempFile.c_str(), '\\') + 1;
#else
    std::string tempFile = "/" + file;
    const char *pFile = strrchr(tempFile.c_str(), '/') + 1;
#endif
    NFLogMgr::Instance()->LogDefault(NLL_DEBUG_NORMAL, NFSourceLoc{pFile, line, func.c_str()}, logId, guid, log);
}

void NFCLuaScriptModule::LuaInfo(uint32_t logId, uint64_t guid, const std::string &file, int line, const std::string &func, const std::string &log)
{
#ifdef _WIN32
    std::string tempFile = "\\" + file;
        const char* pFile = strrchr(tempFile.c_str(), '\\') + 1;
#else
    std::string tempFile = "/" + file;
    const char *pFile = strrchr(tempFile.c_str(), '/') + 1;
#endif
    NFLogMgr::Instance()->LogDefault(NLL_INFO_NORMAL, NFSourceLoc{pFile, line, func.c_str()}, logId, guid, log);
}

void NFCLuaScriptModule::LuaWarn(uint32_t logId, uint64_t guid, const std::string &file, int line, const std::string &func, const std::string &log)
{
#ifdef _WIN32
    std::string tempFile = "\\" + file;
        const char* pFile = strrchr(tempFile.c_str(), '\\') + 1;
#else
    std::string tempFile = "/" + file;
    const char *pFile = strrchr(tempFile.c_str(), '/') + 1;
#endif
    NFLogMgr::Instance()->LogDefault(NLL_WARING_NORMAL, NFSourceLoc{pFile, line, func.c_str()}, logId, guid, log);
}

void NFCLuaScriptModule::LuaError(uint32_t logId, uint64_t guid, const std::string &file, int line, const std::string &func, const std::string &log)
{
#ifdef _WIN32
    std::string tempFile = "\\" + file;
        const char* pFile = strrchr(tempFile.c_str(), '\\') + 1;
#else
    std::string tempFile = "/" + file;
    const char *pFile = strrchr(tempFile.c_str(), '/') + 1;
#endif
    NFLogMgr::Instance()->LogDefault(NLL_ERROR_NORMAL, NFSourceLoc{pFile, line, func.c_str()}, logId, guid, log);
}

bool NFCLuaScriptModule::AddRpcService(NF_SERVER_TYPES serverType, uint32_t nMsgId, const std::string &reqType, const std::string &rspType,
                                       const std::string &strLuaFunc, bool createCo)
{
    bool ret = FindModule<NFIMessageModule>()->AddScriptRpcService(serverType, nMsgId, reqType, rspType, this,
                                                                   &NFCLuaScriptModule::OnHandleAddRpcService, createCo);
    if (ret)
    {
        LuaIntf::LuaRef luaFunc = GetGlobal(strLuaFunc);
        CHECK_EXPR(luaFunc.isFunction(), false, "AddRpcService Lua Func Fail, is not a function");

        if (serverType < mxLuaCallBack.size())
        {
            CHECK_EXPR_ASSERT(nMsgId < NF_NET_MAX_MSG_ID, false, "nMsgID:{} >= NF_NET_MAX_MSG_ID", nMsgId);
            mxLuaCallBack[serverType].mxRpcCallBack[nMsgId] = NetLuaRpcService(strLuaFunc);
            return true;
        }
    }
    return ret;
}

std::tuple<std::string, int>
NFCLuaScriptModule::GetRpcService(NF_SERVER_TYPES serverType, NF_SERVER_TYPES dstServerType, uint32_t dstBusId, uint32_t msgId,
                                  const std::string &reqType,
                                  const std::string &request, const std::string &rspType)
{
    std::string respone;
    int iRetCode = FindModule<NFIMessageModule>()->GetScriptRpcService(serverType, dstServerType, dstBusId, msgId, reqType, request, rspType,
                                                                       respone);
    return std::tuple<std::string, int>(respone, iRetCode);
}

int NFCLuaScriptModule::OnHandleAddRpcService(uint64_t unLinkId, uint32_t msgId, const std::string &reqType, const std::string &request,
                                              const std::string &rspType, std::string &respone)
{
    uint32_t eServerType = GetServerTypeFromUnlinkId(unLinkId);
    if (eServerType < mxLuaCallBack.size() && msgId < NF_NET_MAX_MSG_ID)
    {
        NetLuaRpcService &service = mxLuaCallBack[eServerType].mxRpcCallBack[msgId];
        LuaIntf::LuaRef luaFunc = GetGlobal(service.m_strLuaFunc);
        TryRunGlobalScriptFunc("LuaNFrame.DispatchRpcMessage", luaFunc, service.m_strLuaFunc, reqType, request, rspType, respone);
    }
    return 0;
}

int
NFCLuaScriptModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    CHECK_NULL(pMessage);

    SEventKey skey;
    skey.nServerType = serverType;
    skey.nEventID = nEventID;
    skey.bySrcType = bySrcType;
    skey.nSrcID = nSrcID;

    bool bRes = m_eventTemplate.Fire(skey, pMessage->GetTypeName(), pMessage->SerializeAsString());
    if (!bRes) {
        return -1;
    }

    return 0;
}

void NFCLuaScriptModule::FireCppExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string &msgTypeName,
                                        const std::string &msgData)
{
    ::google::protobuf::Message *pMessage = NFProtobufCommon::CreateMessageByName(msgTypeName);
    if (pMessage)
    {
        if (pMessage->ParseFromString(msgData))
        {
            NFIDynamicModule::FireExecute(serverType, nEventID, bySrcType, nSrcID, *pMessage);
        }
    }
}

void NFCLuaScriptModule::FireExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const NFLuaRef &luaData)
{
    SEventKey skey;
    skey.nServerType = serverType;
    skey.nEventID = nEventID;
    skey.bySrcType = bySrcType;
    skey.nSrcID = nSrcID;

    /**
    * @brief 先执行完全匹配的
    */
    if (skey.nSrcID != 0) {
        bool bRes = m_eventTemplate.Fire(skey, luaData);
        if (!bRes) {
            return;
        }
    }

    /**
    * @brief 再执行， 针对整个事件nEventID,类型为bySrcType
    * 比如订阅时，订阅了所有玩家类的事件，而不是对一个玩家的事件，
    * 订阅时将nSrcId=0，会受到所有玩家产生的该类事件
    */
    skey.nSrcID = 0;
    bool bRes = m_eventTemplate.Fire(skey, luaData);
    if (!bRes)
    {
        return;
    }
}

//取消订阅执行事件
bool NFCLuaScriptModule::UnSubscribe(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string &strLuaFunc)
{
    SEventKey skey;
    skey.nServerType = serverType;
    skey.nEventID = nEventID;
    skey.bySrcType = bySrcType;
    skey.nSrcID = nSrcID;

    auto iter = m_luaEventMap.find(strLuaFunc);
    if (iter != m_luaEventMap.end())
    {
        auto key_iter = iter->second.find(skey);
        if (key_iter != iter->second.end())
        {
            if (m_eventTemplate.UnSubscribe(key_iter->second, key_iter->first))
            {
                m_luaEventPool->FreeObj(key_iter->second);
                iter->second.erase(key_iter->first);
            }
            NFIDynamicModule::UnSubscribe(serverType, nEventID, bySrcType, nSrcID);
        }
    }

    return true;
}

bool  NFCLuaScriptModule::UnSubscribeAll(const std::string &strLuaFunc)
{
    auto iter = m_luaEventMap.find(strLuaFunc);
    if (iter != m_luaEventMap.end())
    {
        for(auto key_iter = iter->second.begin(); key_iter != iter->second.end(); key_iter++)
        {
            if (m_eventTemplate.UnSubscribeAll(key_iter->second))
            {
                m_luaEventPool->FreeObj(key_iter->second);
                NFIDynamicModule::UnSubscribe(key_iter->first.nServerType, key_iter->first.nEventID, key_iter->first.bySrcType, key_iter->first.nSrcID);
                iter->second.erase(key_iter->first);
            }
        }
    }
    return true;
}

bool NFCLuaScriptModule::Subscribe(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string &strLuaFunc)
{
    SEventKey skey;
    skey.nServerType = serverType;
    skey.nEventID = nEventID;
    skey.bySrcType = bySrcType;
    skey.nSrcID = nSrcID;

    LuaIntf::LuaRef ref = GetGlobal(strLuaFunc);
    CHECK_EXPR(ref.isFunction(), false, "strLuaFunc:{} is not lua function", strLuaFunc);

    auto pData = m_luaEventPool->MallocObjWithArgs(m_pObjPluginManager, this);
    CHECK_EXPR(pData, false, "m_luaEventPool->MallocObjWithArgs Failed");
    pData->m_strLuaFunc = strLuaFunc;

    if (m_eventTemplate.Subscribe(pData, skey, strLuaFunc))
    {
        m_luaEventMap[strLuaFunc].emplace(skey, pData);
        if (NFIDynamicModule::Subscribe(serverType, nEventID, bySrcType, nSrcID, strLuaFunc))
        {
            return true;
        }
        else {
            m_luaEventMap[strLuaFunc].erase(skey);
            m_eventTemplate.UnSubscribe(pData, skey);
            m_luaEventPool->FreeObj(pData);
        }
    }
    else {
        m_luaEventPool->FreeObj(pData);
    }

    return false;
}

bool NFCLuaScriptModule::AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, const std::string &strLuaFunc, bool createCo)
{
    LuaIntf::LuaRef luaFunc = GetGlobal(strLuaFunc);
    CHECK_EXPR(luaFunc.isFunction(), false, "AddEventCallBack Lua Func Fail, is not a function");

    NET_EVENT_FUNCTOR functor = std::bind(&NFCLuaScriptModule::OnHandleServerSocketEvent, this, std::placeholders::_1, std::placeholders::_2, linkId);

    if (FindModule<NFIMessageModule>()->AddEventCallBack(eType, linkId, this, functor, createCo))
    {
        if (eType < mxLuaCallBack.size())
        {
            mxLuaCallBack[eType].mxEventCallBack[linkId] = NetLuaEventFunctor(strLuaFunc);
            return true;
        }
    }

    return false;
}

bool NFCLuaScriptModule::AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, const std::string &strLuaFunc, bool createCo)
{
    LuaIntf::LuaRef luaFunc = GetGlobal(strLuaFunc);
    CHECK_EXPR(luaFunc.isFunction(), false, "AddOtherCallBack Lua Func Fail, is not a function");

    NET_RECEIVE_FUNCTOR functor = std::bind(&NFCLuaScriptModule::OnHandleServerOtherMessage, this, std::placeholders::_1, std::placeholders::_2, linkId);

    if (FindModule<NFIMessageModule>()->AddOtherCallBack(eType, linkId, this, functor, createCo))
    {
        if (eType < mxLuaCallBack.size())
        {
            mxLuaCallBack[eType].mxOtherMsgCallBackList[linkId] = NetLuaReceiveFunctor(strLuaFunc);
            return true;
        }
    }

    return false;
}

bool NFCLuaScriptModule::AddAllMsgCallBack(NF_SERVER_TYPES eType, const std::string &strLuaFunc, bool createCo)
{
    LuaIntf::LuaRef luaFunc = GetGlobal(strLuaFunc);
    CHECK_EXPR(luaFunc.isFunction(), false, "AddAllMsgCallBack Lua Func Fail, is not a function");

    if (FindModule<NFIMessageModule>()->AddAllMsgCallBack(eType, this, &NFCLuaScriptModule::OnHandleAllOtherMessage, createCo))
    {
        if (eType < mxLuaCallBack.size())
        {
            mxLuaCallBack[eType].mxAllMsgCallBackList = NetLuaReceiveFunctor(strLuaFunc);
            return true;
        }
    }

    return false;
}

int NFCLuaScriptModule::OnHandleServerSocketEvent(eMsgType nEvent, uint64_t unLinkId, uint64_t serverLinkId)
{
    uint32_t eServerType = GetServerTypeFromUnlinkId(unLinkId);
    if (eServerType < mxLuaCallBack.size())
    {
        auto iter = mxLuaCallBack[eServerType].mxEventCallBack.find(serverLinkId);
        if (iter != mxLuaCallBack[eServerType].mxEventCallBack.end())
        {
            NetLuaEventFunctor &service = iter->second;
            LuaIntf::LuaRef luaFunc = GetGlobal(service.m_strLuaFunc);
            TryRunGlobalScriptFunc("LuaNFrame.DispatchSocketEvent", luaFunc, service.m_strLuaFunc, nEvent, unLinkId);
        }
    }
    return 0;
}

int NFCLuaScriptModule::OnHandleServerOtherMessage(uint64_t unLinkId, NFDataPackage &packet, uint64_t serverLinkId)
{
    uint32_t eServerType = GetServerTypeFromUnlinkId(unLinkId);
    if (eServerType < mxLuaCallBack.size())
    {
        auto iter = mxLuaCallBack[eServerType].mxOtherMsgCallBackList.find(serverLinkId);
        if (iter != mxLuaCallBack[eServerType].mxOtherMsgCallBackList.end())
        {
            NetLuaReceiveFunctor &service = iter->second;
            LuaIntf::LuaRef luaFunc = GetGlobal(service.m_strLuaFunc);
            TryRunGlobalScriptFunc("LuaNFrame.DispatchOtherMessage", luaFunc, service.m_strLuaFunc, unLinkId, packet);
        }
    }
    return 0;
}

int NFCLuaScriptModule::OnHandleAllOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    uint32_t eServerType = GetServerTypeFromUnlinkId(unLinkId);
    if (eServerType < mxLuaCallBack.size())
    {
        NetLuaReceiveFunctor &service = mxLuaCallBack[eServerType].mxAllMsgCallBackList;
        LuaIntf::LuaRef luaFunc = GetGlobal(service.m_strLuaFunc);
        TryRunGlobalScriptFunc("LuaNFrame.DispatchAllOtherMessage", luaFunc, service.m_strLuaFunc, unLinkId, packet);
    }
    return 0;
}

bool NFCLuaScriptModule::IsLuaFunction(const std::string& strLuaFunc)
{
    LuaIntf::LuaRef ref = GetGlobal(strLuaFunc);
    return ref.isFunction();
}

LuaIntf::LuaRef NFCLuaScriptModule::GetLuaData(const std::string& strLuaFunc)
{
    LuaIntf::LuaRef ref = GetGlobal(strLuaFunc);
    return ref;
}