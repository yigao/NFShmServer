// -------------------------------------------------------------------------
//    @FileName         :    NFCConfigModule.cpp
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFKernelPlugin
//    @Desc             :
// -------------------------------------------------------------------------

#include "NFCConfigModule.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFKernelMessage/proto_common.pb.h"
#include "NFComm/NFKernelMessage/proto_common_s.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"

#include <set>
#include <map>

NFCConfigModule::NFCConfigModule(NFIPluginManager *p) : NFIConfigModule(p)
{
    m_appConfig = NULL;
    mServerConfig.resize(NF_ST_MAX);
    for (int i = 0; i < (int) mServerConfig.size(); i++)
    {
        mServerConfig[i] = NULL;
    }
}

NFCConfigModule::~NFCConfigModule()
{

}

bool NFCConfigModule::LoadConfig()
{
    TryAddPackagePath(m_pObjPluginManager->GetPluginPath()); //Add Search Path to Lua

    std::list<std::string> fileList;
    NFFileUtility::GetFiles(m_pObjPluginManager->GetPluginPath(), fileList, true, "*.lua");

    for (auto it = fileList.begin(); it != fileList.end(); ++it)
    {
        if (TryLoadScriptFile(*it) == false)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Load {} Failed!", *it);
            assert(0);
        }
    }

    LoadPluginConfig();
    LoadServerConfig();
    LoadLogConfig();
    CheckConfig();
    return true;
}

bool NFCConfigModule::LoadLogConfig()
{
    mLogConfig.Clear();

    GetValue(DEFINE_LUA_STRING_LOG_LEVEL, mLogConfig.mLogLevel);
    GetValue(DEFINE_LUA_STRING_LOG_FLUSH_LEVEL, mLogConfig.mLogFlushLevel);

    NFLuaRef logInfoRef = GetGlobal(DEFINE_LUA_STRING_LOG_INFO);
    if (!logInfoRef.isValid())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "log.lua can't find ({})", DEFINE_LUA_STRING_LOG_INFO);
        assert(0);
    }

    if (!logInfoRef.isTable())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "{} is not table in the log.lua", DEFINE_LUA_STRING_LOG_INFO);
        assert(0);
    }

    /* lua 是从1开始的 */
    for (int i = 1; i <= logInfoRef.len(); i++)
    {
        NFLuaRef logRef = logInfoRef[i];
        if (!logRef.isTable())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "logInfo some wrong in the log.lua");
            assert(0);
        }

        LogInfoConfig lineConfig;

        GetLuaTableValue(logRef, "logid", lineConfig.mLogId);
        GetLuaTableValue(logRef, "display", lineConfig.mDisplay);
        GetLuaTableValue(logRef, "level", lineConfig.mLevel);
        GetLuaTableValue(logRef, "logname", lineConfig.mLogName);

        NFLuaRef guidRef;
        GetLuaTableValue(logRef, "guid", guidRef);
        if (guidRef.isTable())
        {
            for (int j = 1; j <= guidRef.len(); j++)
            {
                NFLuaRef guidLuaRef = guidRef[j];
                if (guidLuaRef.isValid())
                {
                    uint64_t guid = guidLuaRef.toValue<uint64_t>();
                    if (guid != 0)
                    {
                        lineConfig.mVecGuid.push_back(guid);
                    }
                }
            }
        }
        else
        {
            uint64_t guid = guidRef.toValue<uint64_t>();
            if (guid != 0)
            {
                lineConfig.mVecGuid.push_back(guid);
            }
        }

        mLogConfig.mLineConfigList.push_back(lineConfig);
    }

    return true;
}

bool NFCConfigModule::LoadPluginConfig()
{
    NFLuaRef pluginRef = GetGlobal(DEFINE_LUA_STRING_LOAD_PLUGIN);
    if (!pluginRef.isValid())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Plugin.lua can't find ({})", DEFINE_LUA_STRING_LOAD_PLUGIN);
        assert(0);
    }

    if (!pluginRef.isTable())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "{} is not table in the plugin.lua", DEFINE_LUA_STRING_LOAD_PLUGIN);
        assert(0);
    }

    for (auto it = pluginRef.begin(); it != pluginRef.end(); ++it)
    {
        std::string serverPluginName = it.key<std::string>();
        NFLuaRef serverPluginRef = it.value();

        proto_ff::pbPluginConfig pbPluginConfig;
        NFProtobufCommon::LuaToProtoMessage(serverPluginRef, &pbPluginConfig);
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load server:{} plugin config:\n{}", serverPluginName, pbPluginConfig.DebugString());

        if (pbPluginConfig.frameplugins_size() <= 0 && pbPluginConfig.serverplugins_size() <= 0 && pbPluginConfig.workplugins_size() <= 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "{} can't find int server:{} int the table {}  in the plugin.lua",
                       DEFINE_LUA_STRING_SERVER_PLUGINS, serverPluginName, DEFINE_LUA_STRING_LOAD_PLUGIN);
            assert(0);
        }

        if (!pbPluginConfig.has_servertype())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "{} can't find int server:{} int the table {}  in the plugin.lua",
                       DEFINE_LUA_STRING_SERVER_PLUGINS, serverPluginName, DEFINE_LUA_STRING_LOAD_PLUGIN);
            assert(0);
        }

        NFPluginConfig *pConfig = NF_NEW NFPluginConfig();
        pConfig->read_from_pbmsg(pbPluginConfig);

        if (pConfig->ServerType >= NF_ST_MAX)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "{} can't find int server:{} int the table {}  in the plugin.lua",
                       DEFINE_LUA_STRING_SERVER_PLUGINS, serverPluginName, DEFINE_LUA_STRING_LOAD_PLUGIN);
            assert(0);
        }
        mPluginConfig.emplace(serverPluginName, pConfig);
    }

    return true;
}

bool NFCConfigModule::LoadServerConfig()
{
    std::map<std::string, NFLuaRef> vecLuaRef;
    std::set<std::string> vecServerIDMap;
    std::set<uint32_t> vecServerTypeMap;

    if (m_pObjPluginManager->IsLoadAllServer())
    {
        NFPluginConfig *pAllServer = GetPluginConfig(ALL_SERVER);
        if (pAllServer)
        {
            for (int i = 0; i < (int) pAllServer->ServerList.size(); i++)
            {
                proto_ff_s::pbAllServerConfig_s &serverInfo = pAllServer->ServerList[i];
                NFLuaRef serverRef = GetGlobal(serverInfo.Server);
                if (serverRef.isValid() && serverRef.isTable())
                {
                    CHECK_EXPR_ASSERT(vecLuaRef.find(serverInfo.Server) == vecLuaRef.end(), false, "all server config error, the server:{} exist",
                                      serverInfo.Server);
                    CHECK_EXPR_ASSERT(vecServerIDMap.find(serverInfo.ID) == vecServerIDMap.end(), false,
                                      "all server config error, the server id:{} exist", serverInfo.ID);
                    CHECK_EXPR_ASSERT(vecServerTypeMap.find(serverInfo.ServerType) == vecServerTypeMap.end(), false,
                                      "all server config error, the server type:{} exist", serverInfo.ServerType);

                    vecLuaRef.emplace(serverInfo.Server, serverRef);
                    vecServerIDMap.insert(serverInfo.ID);
                    vecServerTypeMap.insert(serverInfo.ServerType);
                }
            }
        }
    }
    else
    {
        NFLuaRef serverRef = GetGlobal(m_pObjPluginManager->GetAppName());
        if (serverRef.isValid() && serverRef.isTable())
        {
            vecLuaRef.emplace(m_pObjPluginManager->GetAppName(), serverRef);
        }
    }

    for (auto vec_iter = vecLuaRef.begin(); vec_iter != vecLuaRef.end(); vec_iter++)
    {
        std::string serverTypeName = vec_iter->first;
        NFLuaRef serverRef = vec_iter->second;
        if (!serverRef.isValid() || !serverRef.isTable()) continue;

        for (auto iter = serverRef.begin(); iter != serverRef.end(); ++iter)
        {
            std::string serverName = iter.key<std::string>();
            NFLuaRef serverConfigRef = iter.value();

            proto_ff::pbNFServerConfig tmpConfig;
            NFProtobufCommon::LuaToProtoMessage(serverConfigRef, &tmpConfig);

            proto_ff::pbNFServerConfig *pPbConfig = &tmpConfig;
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load server:{} config:\n{}", serverName, pPbConfig->DebugString());

            if (!pPbConfig->has_serverid())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "must be config the ServerId........");
                assert(0);
            }

            pPbConfig->set_busid(NFServerIDUtil::GetBusID(pPbConfig->serverid()));
            if (pPbConfig->busid() <= 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "serverid can't BusAddrAton to busid:{}", pPbConfig->serverid());
                assert(0);
            }

            if (!pPbConfig->has_servertype())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "must be config the ServerType........");
                assert(0);
            }

            NF_ASSERT(pPbConfig->servertype() < NF_ST_MAX);
            NF_ASSERT(GetServerName((NF_SERVER_TYPES) pPbConfig->servertype()) == serverTypeName);

            if (pPbConfig->buslength() == 0)
            {
                pPbConfig->set_buslength(20971520);  //20M
            }

            if (pPbConfig->idlesleepus() == 0)
            {
                pPbConfig->set_idlesleepus(1000);
            }

            if (pPbConfig->handlemsgnumperframe() == 0)
            {
                pPbConfig->set_handlemsgnumperframe(NF_NO_FIX_FAME_HANDLE_MAX_MSG_COUNT);
            }

            std::string linkMode = pPbConfig->linkmode();
            NFStringUtility::Trim(linkMode);
            NFStringUtility::ToLower(linkMode);
            pPbConfig->set_linkmode(linkMode);
            if (linkMode.empty())
            {
                pPbConfig->set_linkmode("tcp");
                std::string url = NF_FORMAT("tcp://{}:{}", pPbConfig->serverip(), pPbConfig->serverport());
                pPbConfig->set_url(url);
            }
            else if (linkMode != "tcp" && linkMode != "udp" && linkMode != "http" && linkMode != "bus")
            {
                pPbConfig->set_linkmode("tcp");
                std::string url = NF_FORMAT("tcp://{}:{}", pPbConfig->serverip(), pPbConfig->serverport());
                pPbConfig->set_url(url);
            }
            else if (linkMode == "bus")
            {
                std::string url = NF_FORMAT("bus://{}:{}", pPbConfig->serverid(), pPbConfig->buslength());
                pPbConfig->set_url(url);
            }
            else
            {
                std::string url = NF_FORMAT("{}://{}:{}", pPbConfig->linkmode(), pPbConfig->serverip(), pPbConfig->serverport());
                pPbConfig->set_url(url);
            }

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load config:{}", pPbConfig->DebugString());
            NFServerConfig *pConfig = NF_NEW NFServerConfig();
            pConfig->read_from_pbmsg(*pPbConfig);

            if (m_pObjPluginManager->IsLoadAllServer())
            {
                if (vecServerIDMap.find(pPbConfig->serverid()) != vecServerIDMap.end())
                {
                    mServerConfig[pPbConfig->servertype()] = pConfig;
                    if (pPbConfig->busid() == (uint32_t) m_pObjPluginManager->GetAppID())
                    {
                        m_appConfig = pConfig;
                    }
                }
                else
                {
                    NF_SAFE_DELETE(pConfig);
                }
            }
            else
            {
                if (pPbConfig->busid() == (uint32_t) m_pObjPluginManager->GetAppID())
                {
                    mServerConfig[pPbConfig->servertype()] = pConfig;
                    m_appConfig = pConfig;
                }
                else
                {
                    NF_SAFE_DELETE(pConfig);
                }
            }
        }
    }

    //check all server
    if (m_pObjPluginManager->IsLoadAllServer())
    {
        NFPluginConfig *pAllServer = GetPluginConfig(ALL_SERVER);
        if (pAllServer)
        {
            bool flag = true;
            for (int i = 0; i < (int) pAllServer->ServerList.size(); i++)
            {
                proto_ff_s::pbAllServerConfig_s &serverInfo = pAllServer->ServerList[i];
                if (mServerConfig[serverInfo.ServerType] == NULL)
                {
                    flag = false;
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "the server:{},{} match error, can't find the config", serverInfo.Server, serverInfo.ID);
                }
            }
            CHECK_EXPR_ASSERT(flag, false, "all server config error..........");
        }
    }

    CHECK_EXPR_ASSERT(m_appConfig != NULL, false, "m_appConfig is NULL, maybe ServerID:{} error, not match the config",
                      m_pObjPluginManager->GetAppName());

    return true;
}

bool NFCConfigModule::BeforeShut()
{
    return true;
}

bool NFCConfigModule::Shut()
{
    return true;
}

bool NFCConfigModule::Finalize()
{
    for (auto it = mPluginConfig.begin(); it != mPluginConfig.end(); ++it)
    {
        NFPluginConfig *pConfig = it->second;
        if (pConfig)
        {
            NF_SAFE_DELETE(pConfig);
        }
    }
    mPluginConfig.clear();

    for (auto it = mServerConfig.begin(); it != mServerConfig.end(); ++it)
    {
        NFServerConfig *pConfig = *it;
        if (pConfig)
        {
            NF_SAFE_DELETE(pConfig);
        }
    }
    mServerConfig.clear();
    return true;
}

bool NFCConfigModule::Execute()
{
    return true;
}

bool NFCConfigModule::OnReloadConfig()
{
    return true;
}

NFLogConfig *NFCConfigModule::GetLogConfig()
{
    return &mLogConfig;
}

NFPluginConfig *NFCConfigModule::GetPluginConfig(const std::string &pluginName)
{
    auto it = mPluginConfig.find(pluginName);
    if (it != mPluginConfig.end())
    {
        return it->second;
    }
    return nullptr;
}

NFServerConfig *NFCConfigModule::GetServerConfig(NF_SERVER_TYPES eServerType)
{
    return mServerConfig[eServerType];
}

NFServerConfig *NFCConfigModule::GetAppConfig(NF_SERVER_TYPES eServerType)
{
    if (m_pObjPluginManager->IsLoadAllServer())
    {
        if (eServerType == NF_ST_NONE)
        {
            for (int i = 0; i < (int) mServerConfig.size(); i++)
            {
                if (mServerConfig[i] && mServerConfig[i]->ServerType != NF_ST_MASTER_SERVER
                    && mServerConfig[i]->ServerType != NF_ST_ROUTE_AGENT_SERVER && mServerConfig[i]->ServerType != NF_ST_ROUTE_SERVER
                    && mServerConfig[i]->ServerType != NF_ST_PROXY_SERVER && mServerConfig[i]->ServerType != NF_ST_PROXY_AGENT_SERVER
                    && mServerConfig[i]->ServerType != NF_ST_STORE_SERVER && mServerConfig[i]->ServerType != NF_ST_MONITOR_SERVER)
                {
                    const NFServerData *pServerData = FindModule<NFIMessageModule>()->GetRouteData((NF_SERVER_TYPES) mServerConfig[i]->ServerType);
                    if (pServerData && pServerData->mUnlinkId > 0)
                    {
                        return mServerConfig[i];
                    }
                }
            }
            return m_appConfig;
        }
        return GetServerConfig(eServerType);
    }
    else
    {
        if (eServerType != NF_ST_NONE)
        {
            NF_ASSERT(m_appConfig && m_appConfig->ServerType == eServerType);
        }
        return m_appConfig;
    }
    return NULL;
}

std::string NFCConfigModule::GetDefaultDBName(NF_SERVER_TYPES nfServerTypes)
{
    NFServerConfig *pConfig = GetAppConfig(nfServerTypes);
    if (pConfig)
    {
        return pConfig->DefaultDBName;
    }
    return std::string();
}

std::string NFCConfigModule::GetCrossDBName(NF_SERVER_TYPES nfServerTypes)
{
    NFServerConfig *pConfig = GetAppConfig(nfServerTypes);
    if (pConfig)
    {
        return pConfig->CrossDBName;
    }
    return std::string();
}

std::string NFCConfigModule::GetRedisIp(NF_SERVER_TYPES nfServerTypes)
{
    NFServerConfig *pConfig = GetAppConfig(nfServerTypes);
    if (pConfig)
    {
        return pConfig->RedisConfig.RedisIp;
    }
    return std::string();
}

uint32_t NFCConfigModule::GetRedisPort(NF_SERVER_TYPES nfServerTypes)
{
    NFServerConfig *pConfig = GetAppConfig(nfServerTypes);
    if (pConfig)
    {
        return pConfig->RedisConfig.RedisPort;
    }
    return 0;
}

std::string NFCConfigModule::GetRedisPass(NF_SERVER_TYPES nfServerTypes)
{
    NFServerConfig *pConfig = GetAppConfig(nfServerTypes);
    if (pConfig)
    {
        return pConfig->RedisConfig.RedisPass;
    }
    return std::string();
}

bool NFCConfigModule::CheckConfig()
{
    if (!m_pObjPluginManager->IsLoadAllServer())
    {
        NF_ASSERT(m_appConfig);
        NF_ASSERT(GetServerName((NF_SERVER_TYPES) m_appConfig->ServerType) == m_pObjPluginManager->GetAppName());
    }
    return true;
}
