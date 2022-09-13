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

#define DEFINE_LUA_STRING_SERVER_NAME			"ServerName"
#define DEFINE_LUA_STRING_SERVER_ID				"ServerId"
#define DEFINE_LUA_STRING_IDLESLEEPUS			"IdleSleepUS"
#define DEFINE_LUA_STRING_SERVER_IP				"ServerIp"
#define DEFINE_LUA_STRING_SERVER_PORT			"ServerPort"
#define DEFINE_LUA_STRING_MAX_CONNECT_NUM		"MaxConnectNum"
#define DEFINE_LUA_STRING_WORK_THREAD_NUM		"WorkThreadNum"
#define DEFINE_LUA_STRING_SECURITY				"Security"
#define DEFINE_LUA_STRING_LOG_LEVEL				"LogLevel"					//log等级配置
#define DEFINE_LUA_STRING_LOG_FLUSH_LEVEL		"LogFlushLevel"				//log刷新等级配置
#define DEFINE_LUA_STRING_WebSocket				"WebSocket"
#define DEFINE_LUA_STRING_HttpPort				"HttpPort"

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

struct NFServerConfig
{
public:
	NFServerConfig()
	{
		mServerType = NF_ST_NONE;
		mBusId = 0;
		mIdleSleepUs = 0;
		mServerPort = 0;
		mMaxConnectNum = 100;
		mWorkThreadNum = 1;
		mSecurity = false;
		mWebSocket = false;
        mBusLength = 0;
		mHttpPort = 0;
		mMysqlPort = 0;
		mNosqlPort = 0;
		mParseType = 0;
		mMasterPort = 0;
		mExternalServerPort = 0;
		mGameId = 0;
		mRobotOn = 0;
		mRobotNumPerDesk = 1;
		mRobotShootInterval = 200;
		mIsRobotNeedRealPlayer = 1;
		
        mMaxOnlinePlayerNum = 100;
        mNetThreadNum = 1;

        mHeartBeatTimeout = 20;
        mClientKeepAliveTimeout = 60;

        mMaxDeskCount = 5;

        mDefaultDBName = "proto_ff";

        mRedisIp = "127.0.0.1";
        mRedisPort = 6379;
        mRedisPass = "";
	}

	uint32_t GetMaxRoomNum()
    {
	    return (uint32_t)mRoomIdList.size();
    }

    uint32_t GetMaxDeskNum()
    {
	    return (uint32_t)GetMaxRoomNum() * mMaxDeskCount;
    }
public:
	uint32_t mBusId;
    uint32_t mBusLength;  //NFBUS/TBUS共享内存通信大小
	std::string mBusName;		//服务器唯一ID like:1.1.1.1
	std::string mServerName;	//服务器名字
	uint32_t mServerType;	//服务器类型

	std::string mLinkMode;
    std::string mUrl;
	uint32_t mIdleSleepUs; //
	std::string mMysqlIp;
	uint32_t	mMysqlPort;
	std::string mMysqlDbName;
	std::vector<std::string> mVecMysqlDbName;
	std::string mMysqlUser;
	std::string mMysqlPassword;
	std::string mNosqlIp;
	uint32_t	mNosqlPort;
	std::string mServerIp;  //服务器监听IP
	uint32_t mServerPort;	//服务器监听端口
	std::string mExternalServerIp;  //服务器对外监听IP
	uint32_t mExternalServerPort;	//服务器对外监听端口
	uint32_t mHttpPort;		//服务器http监听ip
	uint32_t mMaxConnectNum;	//最大连接数目
	uint32_t mWorkThreadNum;	//work线程数目
	uint32_t mNetThreadNum;     //tcp/bus线程数目
	bool mSecurity;				//是否加密
	bool mWebSocket;			//是否开启websocket功能
	uint32_t mParseType;  //协议解析方式, 默认值0，是标准内网协议
	std::string mMasterIp;
	uint32_t mMasterPort;
	std::string mRouteAgent;

    uint32_t mGameId;
    std::vector<uint32_t> mRoomIdList;
    std::string mGameDbName;
    std::string mDefaultDBName;
    uint32_t mMaxDeskCount;
	uint32_t mRobotOn;
	uint32_t mRobotNumPerDesk;
	uint32_t mRobotShootInterval;
	uint32_t mIsRobotNeedRealPlayer;

    uint32_t mMaxOnlinePlayerNum;
    std::string mNamingHost;
    std::string mNamingPath;

    std::string mWwwUrl;
    std::string mEmail;

    uint32_t mHeartBeatTimeout;
    uint32_t mClientKeepAliveTimeout;
    std::unordered_map<std::string, uint32_t> mTBConfMap;

    std::string mRedisIp;
    uint32_t mRedisPort;
    std::string mRedisPass;
};
