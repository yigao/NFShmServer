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

NFCLuaScriptModule::NFCLuaScriptModule(NFIPluginManager *p) : NFILuaScriptModule(p)
{
    m_luaTimerIndex = 10000;
    mnTime = 0;
    mxLuaCallBack.resize(NF_ST_MAX);
}

NFCLuaScriptModule::~NFCLuaScriptModule()
{

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
        m_luaTimerList.push_back(luaTimer);
    }
}

void NFCLuaScriptModule::StopClocker(uint32_t nTimerID)
{
    StopTimer(nTimerID);
}

uint32_t NFCLuaScriptModule::AddTimer(const LuaIntf::LuaRef &luaFunc, uint64_t nInterVal, uint32_t nCallCount, const NFLuaRef &dataStr)
{
    NFLuaTimer *luaTimer = nullptr;
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

uint32_t
NFCLuaScriptModule::AddClocker(const LuaIntf::LuaRef &luaFunc, uint64_t nStartTime, uint32_t nInterDays, uint32_t nCallCount, const NFLuaRef &dataStr)
{
    NFLuaTimer *luaTimer = nullptr;
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

NFServerConfig* NFCLuaScriptModule::GetAppConfig(uint32_t serverType)
{
    return FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
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

bool NFCLuaScriptModule::RegisterClientMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, const LuaIntf::LuaRef &luaFunc)
{
    CHECK_EXPR(luaFunc.isFunction(), false, "RegisterClientMessage Lua Func Fail, is not a function");

    if (NFIDynamicModule::RegisterClientMessage(eType, nMsgID))
    {
        if (eType < mxLuaCallBack.size())
        {
            CHECK_EXPR_ASSERT(nMsgID < NF_NET_MAX_MSG_ID, false, "nMsgID:{} >= NF_NET_MAX_MSG_ID", nMsgID);
            mxLuaCallBack[eType].mxReceiveCallBack[NF_MODULE_CLIENT][nMsgID] = NetLuaReceiveFunctor(luaFunc);
            return NFIDynamicModule::RegisterClientMessage(eType, nMsgID);
        }
    }

    return false;
}

bool NFCLuaScriptModule::RegisterServerMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, const LuaIntf::LuaRef &luaFunc)
{
    CHECK_EXPR(luaFunc.isFunction(), false, "RegisterServerMessage Lua Func Fail, is not a function");

    if (NFIDynamicModule::RegisterServerMessage(eType, nMsgID))
    {
        if (eType < mxLuaCallBack.size())
        {
            CHECK_EXPR_ASSERT(nMsgID < NF_NET_MAX_MSG_ID, false, "nMsgID:{} >= NF_NET_MAX_MSG_ID", nMsgID);
            mxLuaCallBack[eType].mxReceiveCallBack[NF_MODULE_SERVER][nMsgID] = NetLuaReceiveFunctor(luaFunc);
            return NFIDynamicModule::RegisterClientMessage(eType, nMsgID);
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
        bool ret = TryRunGlobalScriptFunc("LuaNFrame.DispatchMessage", mxLuaCallBack[eServerType].mxReceiveCallBack[NF_MODULE_CLIENT][msgId].m_luaFunc, msgId, packet, param1,
                                          param2);
        if (ret == false)
        {
            return -1;
        }
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
        bool ret = TryRunGlobalScriptFunc("LuaNFrame.DispatchMessage", mxLuaCallBack[eServerType].mxReceiveCallBack[NF_MODULE_SERVER][msgId].m_luaFunc, msgId, packet, param1,
                                          param2);
        if (ret == false)
        {
            return -1;
        }
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
    NFLogMgr::Instance()->SetDefaultLevel((NF_LOG_LEVEL)level);
}

void NFCLuaScriptModule::SetFlushOn(uint32_t level)
{
    NFLogMgr::Instance()->SetDefaultFlush((NF_LOG_LEVEL)level);
}

void NFCLuaScriptModule::LuaTrace(uint32_t logId, uint64_t guid, const std::string& file, int line, const std::string& func, const std::string& log)
{
#ifdef _WIN32
    std::string tempFile = "\\" + file;
        const char* pFile = strrchr(tempFile.c_str(), '\\') + 1;
#else
    std::string tempFile = "/" + file;
    const char* pFile = strrchr(tempFile.c_str(), '/') + 1;
#endif

    NFLogMgr::Instance()->LogDefault(NLL_TRACE_NORMAL, NFSourceLoc{pFile, line, func.c_str()}, logId, guid, log);
}

void NFCLuaScriptModule::LuaDebug(uint32_t logId, uint64_t guid, const std::string& file, int line, const std::string& func, const std::string& log)
{
#ifdef _WIN32
    std::string tempFile = "\\" + file;
        const char* pFile = strrchr(tempFile.c_str(), '\\') + 1;
#else
    std::string tempFile = "/" + file;
    const char* pFile = strrchr(tempFile.c_str(), '/') + 1;
#endif
    NFLogMgr::Instance()->LogDefault(NLL_DEBUG_NORMAL, NFSourceLoc{pFile, line, func.c_str()}, logId, guid, log);
}

void NFCLuaScriptModule::LuaInfo(uint32_t logId, uint64_t guid, const std::string& file, int line, const std::string& func, const std::string& log)
{
#ifdef _WIN32
    std::string tempFile = "\\" + file;
        const char* pFile = strrchr(tempFile.c_str(), '\\') + 1;
#else
    std::string tempFile = "/" + file;
    const char* pFile = strrchr(tempFile.c_str(), '/') + 1;
#endif
    NFLogMgr::Instance()->LogDefault(NLL_INFO_NORMAL, NFSourceLoc{pFile, line, func.c_str()}, logId, guid, log);
}

void NFCLuaScriptModule::LuaWarn(uint32_t logId, uint64_t guid, const std::string& file, int line, const std::string& func, const std::string& log)
{
#ifdef _WIN32
    std::string tempFile = "\\" + file;
        const char* pFile = strrchr(tempFile.c_str(), '\\') + 1;
#else
    std::string tempFile = "/" + file;
    const char* pFile = strrchr(tempFile.c_str(), '/') + 1;
#endif
    NFLogMgr::Instance()->LogDefault(NLL_WARING_NORMAL, NFSourceLoc{pFile, line, func.c_str()}, logId, guid, log);
}

void NFCLuaScriptModule::LuaError(uint32_t logId, uint64_t guid, const std::string& file, int line, const std::string& func, const std::string& log)
{
#ifdef _WIN32
    std::string tempFile = "\\" + file;
        const char* pFile = strrchr(tempFile.c_str(), '\\') + 1;
#else
    std::string tempFile = "/" + file;
    const char* pFile = strrchr(tempFile.c_str(), '/') + 1;
#endif
    NFLogMgr::Instance()->LogDefault(NLL_ERROR_NORMAL, NFSourceLoc{pFile, line, func.c_str()}, logId, guid, log);
}