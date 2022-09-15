// -------------------------------------------------------------------------
//    @FileName         :    NFCConfigModule.cpp
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFKernelPlugin
//    @Desc             :
// -------------------------------------------------------------------------

#include "NFCConfigModule.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFCore/NFDateTime.hpp"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/proto_common.pb.h"

NFCConfigModule::NFCConfigModule(NFIPluginManager* p):NFIConfigModule(p)
{
    m_appConfig = NULL;
    mServerConfig.resize(NF_ST_MAX);
    for(int i = 0; i < (int)mServerConfig.size(); i++)
    {
        mServerConfig[i] = NULL;
    }
	NFConfigMgr::Instance()->Init(this);
}

NFCConfigModule::~NFCConfigModule()
{

}

bool NFCConfigModule::LoadConfig()
{
	TryAddPackagePath(m_pPluginManager->GetPluginPath()); //Add Search Path to Lua

    {
        std::list<std::string> fileList;
        NFFileUtility::GetFiles(m_pPluginManager->GetPluginPath(), fileList, true, "*.lua");

        for (auto it = fileList.begin(); it != fileList.end(); ++it) {
            if (TryLoadScriptFile(*it) == false) {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Load {} Failed!", *it);
                assert(0);
            }
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
		NFLuaRef serverPluginListRef;
		if (!GetLuaTableValue(serverPluginRef, DEFINE_LUA_STRING_SERVER_PLUGINS, serverPluginListRef))
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "{} can't find int server:{} int the table {}  in the plugin.lua",
			           DEFINE_LUA_STRING_SERVER_PLUGINS, serverPluginName, DEFINE_LUA_STRING_LOAD_PLUGIN);
			assert(0);
		}

		NFPluginConfig* pConfig = NF_NEW NFPluginConfig();
		if (serverPluginListRef.isTable())
		{
			for (int i = 1; i <= serverPluginListRef.len(); i++)
			{
				std::string plugin;
				if (GetLuaTableValue(serverPluginListRef, i, plugin))
				{
					pConfig->mVecPlugins.push_back(plugin);
				}
			}
		}

		if (!GetLuaTableValue(serverPluginRef, DEFINE_LUA_STRING_SERVER_TYPE, pConfig->mServerType))
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "{} can't find int server:{} int the table {}  in the plugin.lua",
			           DEFINE_LUA_STRING_SERVER_PLUGINS, serverPluginName, DEFINE_LUA_STRING_LOAD_PLUGIN);
			assert(0);
		}

		if (pConfig->mServerType >= NF_ST_MAX)
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

	if (m_pPluginManager->IsLoadAllServer())
    {
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_MASTER_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_MASTER_SERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_LOGIN_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_LOGIN_SERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_GAME_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_GAME_SERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_PROXY_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_PROXY_SERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_WORLD_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_WORLD_SERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_ROUTE_AGENT_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_ROUTE_AGENT_SERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_ROUTESERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_ROUTESERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_STOREERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_STOREERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_SNSSERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_SNSSERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_LOGICSERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_LOGICSERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_WEBSERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_WEBSERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_MONITORSERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_MONITORSERVER, serverRef);
            }
        }

        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_PROXYAGENTSERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_PROXYAGENTSERVER, serverRef);
            }
        }
    }
	else
    {
	    if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_MASTER_SERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_MASTER_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_MASTER_SERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_LOGIN_SERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_LOGIN_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_LOGIN_SERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_GAME_SERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_GAME_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_GAME_SERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_PROXY_SERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_PROXY_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_PROXY_SERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_WORLD_SERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_WORLD_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_WORLD_SERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_ROUTE_AGENT_SERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_ROUTE_AGENT_SERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_ROUTE_AGENT_SERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_ROUTESERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_ROUTESERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_ROUTESERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_STOREERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_STOREERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_STOREERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_SNSSERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_SNSSERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_SNSSERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_LOGICSERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_LOGICSERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_LOGICSERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_WEBSERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_WEBSERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_WEBSERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_MONITORSERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_MONITORSERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_MONITORSERVER, serverRef);
            }
        }
        else if (m_pPluginManager->GetAppName() == DEFINE_LUA_STRING_PROXYAGENTSERVER)
        {
            NFLuaRef serverRef = GetGlobal(DEFINE_LUA_STRING_PROXYAGENTSERVER);
            if (serverRef.isValid())
            {
                vecLuaRef.emplace(DEFINE_LUA_STRING_PROXYAGENTSERVER, serverRef);
            }
        }
    }


	for (auto vec_iter = vecLuaRef.begin(); vec_iter != vecLuaRef.end(); vec_iter++)
	{
	    std::string serverTypeName = vec_iter->first;
        NFLuaRef serverRef = vec_iter->second;

        proto_ff::pbNFServerConfigList tmpConfig;
        NFProtobufCommon::LuaToProtoMessage(serverRef, &tmpConfig);

        for (int i = 0; i < tmpConfig.list_size(); i++)
        {
            proto_ff::pbNFServerConfig* pPbConfig = tmpConfig.mutable_list(i);
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load config:{}", pPbConfig->DebugString());

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

            if (pPbConfig->has_servertype())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "must be config the ServerType........");
                assert(0);
            }

            NF_ASSERT(pPbConfig->servertype() >= 0 && pPbConfig->servertype() < NF_ST_MAX);
            NF_ASSERT(GetServerName((NF_SERVER_TYPES)pPbConfig->servertype()) == serverTypeName);

            if (pPbConfig->buslength() == 0)
            {
                pPbConfig->set_buslength(20971520);  //20M
            }

            std::string linkMode = pPbConfig->linkmode();
            NFStringUtility::Trim(linkMode);
            NFStringUtility::ToLower(linkMode);
            pPbConfig->set_linkmode(linkMode);
            if (linkMode.empty())
            {
                pPbConfig->set_linkmode("tcp");
                std::string url = NF_FORMAT("tcp://{}:{}", pConfig->ServerIp, pConfig->ServerPort);
                pPbConfig->set_url(url);
            }
            else if (linkMode != "tcp" && linkMode != "udp" && linkMode != "http" && linkMode != "bus")
            {
                pPbConfig->set_linkmode("tcp");
                std::string url = NF_FORMAT("tcp://{}:{}", pConfig->ServerIp, pConfig->ServerPort);
                pPbConfig->set_url(url);
            }
            else if (pConfig->LinkMode == "bus")
            {
                std::string url = NF_FORMAT("bus://{}:{}", pConfig->ServerId, pConfig->BusLength);
                pPbConfig->set_url(url);
            }
            else
            {
                std::string url = NF_FORMAT("{}://{}:{}", pConfig->LinkMode, pConfig->ServerIp, pConfig->ServerPort);
                pPbConfig->set_url(url);
            }

            if (m_pPluginManager->IsLoadAllServer())
            {
                if (mServerConfig[pConfig->ServerType])
                {
                    int index = NFServerIDUtil::GetInstID(mServerConfig[pPbConfig->servertype()]->BusId);
                    int curIndex = NFServerIDUtil::GetInstID(pConfig->BusId);
                    if (curIndex < index)
                    {
                        mServerConfig[pPbConfig->servertype()] = pConfig;
                    }
                }
                else
                {
                    mServerConfig[pPbConfig->servertype()] = pConfig;
                }
            }
            else
            {
                if (pPbConfig->busid() == (uint32_t)m_pPluginManager->GetAppID())
                {
                    mServerConfig[pPbConfig->servertype()] = pConfig;
                }
            }

            if (pPbConfig->busid() == (uint32_t)m_pPluginManager->GetAppID())
            {
                m_appConfig = pConfig;
            }
        }
	}

    if (!m_pPluginManager->IsLoadAllServer())
    {
        NF_ASSERT(m_appConfig);
    }

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
    NFConfigMgr::Instance()->UnInit();
    for (auto it = mPluginConfig.begin(); it != mPluginConfig.end(); ++it)
    {
        NFPluginConfig* pConfig = it->second;
        if (pConfig)
        {
            NF_SAFE_DELETE(pConfig);
        }
    }
    mPluginConfig.clear();

    for (auto it = mServerConfig.begin(); it != mServerConfig.end(); ++it)
    {
        NFServerConfig* pConfig = *it;
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

bool NFCConfigModule::OnReloadPlugin()
{
	return true;
}

NFLogConfig* NFCConfigModule::GetLogConfig()
{
	return &mLogConfig;
}

NFPluginConfig* NFCConfigModule::GetPluginConfig(const std::string& pluginName)
{
	auto it = mPluginConfig.find(pluginName);
	if (it != mPluginConfig.end())
	{
		return it->second;
	}
	return nullptr;
}

NFServerConfig* NFCConfigModule::GetServerConfig(NF_SERVER_TYPES eServerType)
{
    return mServerConfig[eServerType];
}

NFServerConfig* NFCConfigModule::GetAppConfig(NF_SERVER_TYPES eServerType)
{
    if (m_pPluginManager->IsLoadAllServer())
    {
        if (eServerType == NF_ST_NONE)
        {
            for(int i = 0; i < (int)mServerConfig.size(); i++)
            {
                if (mServerConfig[i] && mServerConfig[i]->ServerType != NF_ST_MASTER_SERVER
                    && mServerConfig[i]->ServerType != NF_ST_ROUTE_AGENT_SERVER && mServerConfig[i]->ServerType != NF_ST_ROUTE_SERVER)
                {
					const NFServerData* pServerData = NFMessageMgr::Instance()->GetRouteData((NF_SERVER_TYPES)mServerConfig[i]->ServerType);
					if (pServerData && pServerData->mUnlinkId > 0)
					{
						return mServerConfig[i];
					}
                }
            }
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

std::string NFCConfigModule::GetGameDbName(NF_SERVER_TYPES nfServerTypes)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(nfServerTypes);
    if (pConfig)
    {
		return pConfig->mGameDbName;
    }
    return std::string();
}

std::string NFCConfigModule::GetDefaultDBName(NF_SERVER_TYPES nfServerTypes)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(nfServerTypes);
    if (pConfig)
    {
        return pConfig->DefaultDBName;
    }
    return std::string();
}

std::string NFCConfigModule::GetRedisIp(NF_SERVER_TYPES nfServerTypes)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(nfServerTypes);
    if (pConfig)
    {
        return pConfig->RedisIp;
    }
    return std::string();
}

uint32_t NFCConfigModule::GetRedisPort(NF_SERVER_TYPES nfServerTypes)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(nfServerTypes);
    if (pConfig)
    {
        return pConfig->RedisPort;
    }
    return 0;
}

std::string NFCConfigModule::GetRedisPass(NF_SERVER_TYPES nfServerTypes)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(nfServerTypes);
    if (pConfig)
    {
        return pConfig->RedisPass;
    }
    return std::string();
}

uint32_t NFCConfigModule::GetGameId(NF_SERVER_TYPES nfServerTypes)
{
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(nfServerTypes);
	if (pConfig)
	{
		return pConfig->mGameId;
	}
	return 0;
}

std::vector<uint32_t> NFCConfigModule::GetRoomIdList(NF_SERVER_TYPES nfServerTypes)
{
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(nfServerTypes);
	if (pConfig)
	{
		return pConfig->mRoomIdList;
	}
	return std::vector<uint32_t>();
}

bool NFCConfigModule::CheckConfig()
{
    if (!m_pPluginManager->IsLoadAllServer())
    {
        NF_ASSERT(m_appConfig);
        NF_ASSERT(GetServerName((NF_SERVER_TYPES)m_appConfig->ServerType) == m_pPluginManager->GetAppName());
    }
    return true;
}
