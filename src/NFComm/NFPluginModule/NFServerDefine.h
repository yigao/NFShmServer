// -------------------------------------------------------------------------
//    @FileName         :    NFServerDefine.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include <stdint.h>
#include <functional>
#include <string>
#include <vector>

#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"

#define WG_INT_MAX32 0x7FFFFFFFL

enum NF_SERVER_TYPES
{
	NF_ST_NONE = 0, // NONE
	NF_ST_MASTER_SERVER = 1, //
	NF_ST_LOGIN_SERVER = 2, //
	NF_ST_WORLD_SERVER = 3, //
	NF_ST_GAME_SERVER = 4, //
	NF_ST_PROXY_SERVER = 5, //
	NF_ST_ROUTE_AGENT_SERVER = 6, //路由代理服务器  负责同一台机子服务器数据之间的转发
	NF_ST_ROUTE_SERVER = 7, //路由集群服务器 负责不同机子服务器数据之间的转发
	NF_ST_STORE_SERVER = 8, //DB服务器
	NF_ST_SNS_SERVER = 9, //SNS服务器
	NF_ST_LOGIC_SERVER = 10, //Logic服务器
	NF_ST_WEB_SERVER = 11, //Web服务器
	NF_ST_MONITOR_SERVER = 12, //Monitor服务器
    NF_ST_PROXY_AGENT_SERVER = 13, //Proxy 路由代理服务器 负责同一台机子客户端与服务器数据之间的转发
    NF_ST_PROXY_SERVER_FOR_CLIENT = 14, //网关服务器对客户端的端口
	NF_ST_MAX = 20, //
};

enum PacketParseType
{
	PACKET_PARSE_TYPE_INTERNAL = 0,		//内网协议
	PACKET_PARSE_TYPE_EXTERNAL = 1,		//默认外部协议
	PACKET_PARSE_TYPE_OLD_EXTERNAL = 2,		//老的外部协议
};

enum {
    APP_INIT_STATUS_SERVER_CONNECT = 0,
    APP_INIT_STATUS_SERVER_LOAD_DESC_STORE = 1,
    APP_INIT_STATUS_SERVER_LOAD_OBJ_FROM_DB = 2,
};

enum {
    APP_INIT_NONE,
    //
    APP_INIT_CONNECT_MASTER,
    APP_INIT_CONNECT_ROUTE_AGENT_SERVER,
    APP_INIT_CONNECT_ROUTE_SERVER,
    APP_INIT_NEED_STORE_SERVER,

    //
    APP_INIT_DESC_STORE_LOAD,
    //

    APP_INIT_LOAD_RANK_FROM_DB,
    APP_INIT_LOAD_GAME_ROBOT_FROM_DB,
    APP_INIT_LOAD_SYSTEM_STAT_DB,

    APP_INIT_MAX,
};

#define NF_JSON_MSG_ID 0
#define NF_SERVER_TO_SERVER_HEART_BEAT 1 //心跳协议
#define NF_SERVER_TO_SERVER_HEART_BEAT_RSP 2 //心跳协议

#define NF_SERVER_TO_SERVER_BUS_CONNECT_REQ 3 //BUS Connect 协议
#define NF_SERVER_TO_SERVER_BUS_CONNECT_RSP 4 //BUS CONNECT RSP 协议

const std::string gArrayServer[NF_ST_MAX] = {
	"NoneServer",
	"MasterServer",
	"LoginServer",
	"WorldServer",
	"GameServer",
	"ProxyServer",
	"RouteAgentServer",
	"RouteServer",
	"StoreServer",
	"SnsServer",
	"LogicServer",
	"WebServer",
	"MonitorServer",
	"ProxyAgentServer",
	"NoneServer",
	"NoneServer",
	"NoneServer",
	"NoneServer",
	"NoneServer",
	"NoneServer",
};

std::string GetServerName(NF_SERVER_TYPES serverId);

enum eMsgType
{
	eMsgType_Num = 0,
	eMsgType_CONNECTED = 1,
	eMsgType_DISCONNECTED = 2,
	eMsgType_RECIVEDATA = 3,
};

enum eAccountEventType
{
	eAccountEventType_Num = 0,
	eAccountEventType_CONNECTED = 1,
	eAccountEventType_DISCONNECTED = 2,
	eAccountEventType_RECONNECTED = 3,
};

typedef std::function<int(uint64_t conntionLinkId, uint64_t objectLinkId, uint64_t nSendValue, uint64_t nSendId, uint32_t nMsgId, const char* msg, uint32_t nLen)> NET_CALLBACK_RECEIVE_FUNCTOR;

typedef std::function<int(uint64_t unLinkId, uint64_t sendValueId, uint64_t otherValue, uint32_t nMsgId, const char* msg, uint32_t nLen)> NET_RECEIVE_FUNCTOR;

typedef std::function<int(eMsgType nEvent, uint64_t unLinkId)> NET_EVENT_FUNCTOR;

typedef std::function<int(eMsgType nEvent, uint64_t conntionLinkId, uint64_t objectLinkId)> NET_CALLBACK_EVENT_FUNCTOR;

typedef std::function<void(int iRet, google::protobuf::Message &message)> RPC_TRANS_DESC_STORE_CB;

typedef std::function<int(uint64_t userId, const google::protobuf::Message* message)> LOG_BEHAVIOR_CALLBAK_FUNCTOR;

/**
* @brief log打印配置
*
* @param  mLogId log配置ID
* @param  mDisplay 是否打印这个LOG
* @param  mLevel 输出等级
* @param  mLogName 显示名字
* @param  mGuid 0表示打印所有玩家LOG，玩家ID表示只打印这个玩家的LOG
*/
class LogInfoConfig
{
public:
	LogInfoConfig()
	{
		mLogId = 0;
		mDisplay = false;
		mLevel = 0;
	}

	bool Exist(uint64_t guid)
	{
		for (size_t i = 0; i < mVecGuid.size(); i++)
		{
			if (mVecGuid[i] == guid)
			{
				return true;
			}
		}
		return false;
	}

	uint32_t mLogId;
	bool mDisplay;
	uint32_t mLevel;
	std::string mLogName;
	std::vector<uint64_t> mVecGuid;
};

//////////////////////////////////////////////////////////////////////////
class NFServerData
{
public:
    NFServerData()
    {
        mUnlinkId = 0;
        mRouteAgentBusId = 0;
    }

    ~NFServerData()
    {
        mUnlinkId = 0;
        mRouteAgentBusId = 0;
    }

    uint64_t mUnlinkId;
    uint32_t mRouteAgentBusId;
    proto_ff::ServerInfoReport mServerInfo;
};

typedef struct tagUidAndIndex
{
    uint64_t m_ullUid;
    int32_t m_iIdx;
}TUidAndIndex;

int UidCompare( const TUidAndIndex *pstLeft, const TUidAndIndex *pstRight );
int UidHash( const TUidAndIndex *pstKey );

struct TUid2Uid
{
    uint64_t m_ullUid;
    uint64_t m_ullTargetUid;
};

int Uid2Compare( const TUid2Uid *pstLeft, const TUid2Uid *pstRight );
int Uid2Hash( const TUid2Uid *pstKey );

const int MAX_NAME_STR_LEN = 32;
typedef struct tagStrAndID
{
    char m_szName[MAX_NAME_STR_LEN];
    int m_iID;
}TStrAndID;

int StrCompare( const TStrAndID *pstLeft, const TStrAndID *pstRight );
int StrHash( const TStrAndID *pstKey );


