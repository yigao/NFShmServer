// -------------------------------------------------------------------------
//    @FileName         :    NFConfigDefine.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFServerDefine.h"
#include <unordered_map>
#include "NFComm/NFKernelMessage/proto_common_s.h"

#define DEFINE_LUA_STRING_LOAD_PLUGIN			"LoadPlugin"
#define DEFINE_LUA_STRING_SERVER_PLUGINS		"ServerPlugins"
#define DEFINE_LUA_STRING_SERVER_TYPE			"ServerType"

#define DEFINE_LUA_STRING_MASTER_SERVER				"MasterServer"
#define DEFINE_LUA_STRING_LOGIN_SERVER				"LoginServer"
#define DEFINE_LUA_STRING_GAME_SERVER				"GameServer"
#define DEFINE_LUA_STRING_PROXY_SERVER				"ProxyServer"
#define DEFINE_LUA_STRING_WORLD_SERVER				"WorldServer"
#define DEFINE_LUA_STRING_ROUTE_AGENT_SERVER		"RouteAgentServer"
#define DEFINE_LUA_STRING_ROUTESERVER				"RouteServer"
#define DEFINE_LUA_STRING_STOREERVER				"StoreServer"
#define DEFINE_LUA_STRING_SNSSERVER				    "SnsServer"
#define DEFINE_LUA_STRING_LOGICSERVER				"LogicServer"
#define DEFINE_LUA_STRING_WEBSERVER				    "WebServer"
#define DEFINE_LUA_STRING_MONITORSERVER				"MonitorServer"
#define DEFINE_LUA_STRING_PROXYAGENTSERVER			"ProxyAgentServer"

#define DEFINE_LUA_STRING_LOG_LEVEL				"LogLevel"					//log等级配置
#define DEFINE_LUA_STRING_LOG_FLUSH_LEVEL		"LogFlushLevel"				//log刷新等级配置

#define DEFINE_LUA_STRING_LOG_INFO				"LogInfo"			//log配置

enum EnumLogInfoLuaString
{
	LOG_INFO_LOG_ID = 0,
	LOG_INFO_DISPLAY = 1,
	LOG_INFO_LEVEL = 2,
	LOG_INFO_LOG_NAME = 3,
	LOG_INFO_LOG_GUID = 4,
};

struct NFPluginConfig
{
	NFPluginConfig()
	{
		mServerType = NF_ST_NONE;
	}

public:
	std::vector<std::string> mVecPlugins;
	uint32_t mServerType;
};

struct NFLogConfig
{
	NFLogConfig()
	{
		Clear();
	}

	void Clear()
	{
		mLogLevel = 0;
		mLogFlushLevel = 0;
		mLineConfigList.clear();
	}

	uint32_t mLogLevel;
	uint32_t mLogFlushLevel;
	std::vector<LogInfoConfig> mLineConfigList;
};

struct NFServerRoomConfig
{
public:
    NFServerRoomConfig():mGameKind(0),mGameId(0),mRoomId(0)
    {

    }
    int mGameKind;
    int mGameId;
    int mRoomId;
};

typedef proto_ff_s::pbNFServerConfig_s NFServerConfig;
