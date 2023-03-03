// -------------------------------------------------------------------------
//    @FileName         :    NFServerDefine.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include <functional>
#include <string>
#include <vector>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFSlice.hpp"
#include "NFComm/NFCore/NFBuffer.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"

// (uint16) 如果修改增加此处大小，需要修改接受缓冲区大小，与客户端 NetDefine.cs 中的定义一直
const uint16_t MAX_CLIENT_NET_PACK_LENGTH = 1024 * 48;
const uint32_t MAX_SERVER_NET_PACK_LENGTH = 1024 * 512;
const uint32_t INNER_SENDBUF_DEFAULT_SIZE = 1024 * 1024 * 2;
const uint32_t INNER_RECVBUF_DEFAULT_SIZE = 1024 * 1024 * 2;
const uint32_t MAX_WEB_NET_PACK_LENGTH	  = 1024 * 512;

#define WG_INT_MAX32 0x7FFFFFFFL

enum NF_SERVER_TYPES
{
    NF_ST_NONE = 0,            // NONE
    NF_ST_MASTER_SERVER = 1,
    NF_ST_ROUTE_SERVER = 2, //路由集群服务器 负责不同机子服务器数据之间的转发
    NF_ST_ROUTE_AGENT_SERVER = 3, //路由代理服务器  负责同一台机子服务器数据之间的转发
    NF_ST_PROXY_SERVER = 4,
    NF_ST_PROXY_AGENT_SERVER = 5, //Proxy 路由代理服务器 负责同一台机子客户端与服务器数据之间的转发
    NF_ST_STORE_SERVER = 6, //DB服务器
    NF_ST_LOGIN_SERVER = 7,
    NF_ST_WORLD_SERVER = 8,
    NF_ST_LOGIC_SERVER = 9, //Logic服务器
    NF_ST_GAME_SERVER = 10,
    NF_ST_SNS_SERVER = 11, //SNS服务器
    NF_ST_WEB_SERVER = 12, //Web服务器
    NF_ST_MONITOR_SERVER = 18, //Monitor服务器
    NF_ST_MAX = 50,
};

enum NF_MODULE_TYPE
{
    NF_MODULE_SERVER= 0, //服务器内网通讯
    NF_MODULE_CLIENT = 1, //客户端外部协议
    NF_MODULE_MAX = 2,
};

#define NF_NET_MAX_MSG_ID 10000

enum PacketParseType
{
    PACKET_PARSE_TYPE_INTERNAL = 0,        //内网协议
    PACKET_PARSE_TYPE_EXTERNAL = 1,        //默认外部协议
    PACKET_PARSE_TYPE_OLD_EXTERNAL = 2,        //老的外部协议
};

enum
{
    APP_INIT_STATUS_SERVER_CONNECT = 0,
    APP_INIT_STATUS_SERVER_LOAD_DESC_STORE = 1,
    APP_INIT_STATUS_SERVER_LOAD_OBJ_FROM_DB = 2,
};

enum
{
    APP_INIT_NONE,
    //
    APP_INIT_CONNECT_MASTER,
    APP_INIT_CONNECT_ROUTE_AGENT_SERVER,
    APP_INIT_CONNECT_ROUTE_SERVER,
    APP_INIT_NEED_STORE_SERVER,
    APP_INIT_NEED_WORLD_SERVER,
    APP_INIT_REGISTER_WORLD_SERVER,

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

#define NF_CLIENT_TO_SERVER_HEART_BEAT 10
#define NF_CLIENT_TO_SERVER_HEART_BEAT_RSP 11

#define NF_NO_FIX_FAME_HANDLE_MAX_MSG_COUNT 10000
#define NF_FIX_FRAME_HANDLE_MAX_MSG_COUNT 2000    //release test handle 2000 msg => cpu 20%

const std::string gArrayServer[NF_ST_MAX] = {
        "NoneServer",
        "MasterServer", //1
        "RouteServer", //2
        "RouteAgentServer", //3
        "ProxyServer", //4
        "ProxyAgentServer", //5
        "StoreServer", //6
        "LoginServer", //7
        "WorldServer", //8
        "LogicServer", //9
        "GameServer", //10
        "SnsServer", //11
        "WebServer", //12
        "NoneServer", //13
        "NoneServer", //14
        "NoneServer", //15
        "NoneServer", //16
        "NoneServer", //17
        "MonitorServer", //18
        "NoneServer", //19
};

std::string GetServerName(NF_SERVER_TYPES serverId);

enum eMsgType
{
    eMsgType_Num = 0,
    eMsgType_CONNECTED = 1,
    eMsgType_DISCONNECTED = 2,
    eMsgType_RECIVEDATA = 3,
    eMsgType_SENDBUFFER = 4,
};

enum eAccountEventType
{
    eAccountEventType_Num = 0,
    eAccountEventType_CONNECTED = 1,
    eAccountEventType_DISCONNECTED = 2,
    eAccountEventType_RECONNECTED = 3,
};

const uint32_t s_compressBitPos = 15;

struct NFDataPackage
{
    NFDataPackage()
    {
        Clear();
    }

    virtual ~NFDataPackage()
    {

    }

    std::string ToString() const
    {
        return NF_FORMAT("(mdouleId:{} msgId:{} param1:{} param2:{} nMsgLen:{})", mModuleId, nMsgId, nParam1, nParam2, nMsgLen);
    }

    virtual void Clear()
    {
        mModuleId = 0;
        nMsgId = 0;
        nParam1 = 0;
        nParam2 = 0;
        nSrcId = 0;
        nDstId = 0;
        nSendBusLinkId = 0;
        bCompress = false;
        nConnectLinkId = 0;
        nObjectLinkId = 0;
        nPacketParseType = 0;
        isSecurity = false;
        nBuffer = NULL;
        nMsgLen = 0;
    }

    const char* GetBuffer() const
    {
        return nBuffer;
    }

    uint32_t GetSize() const
    {
        return nMsgLen;
    }

    uint32_t mModuleId;
    uint32_t nMsgId;
    uint64_t nParam1;
    uint64_t nParam2;
    uint64_t nSrcId;
    uint64_t nDstId;
    uint64_t nSendBusLinkId;
    bool bCompress;
    uint64_t nConnectLinkId;
    uint64_t nObjectLinkId;
    uint32_t nPacketParseType;
    bool isSecurity;
    char* nBuffer;
    uint64_t nMsgLen;
};

typedef std::function<int(uint64_t conntionLinkId, uint64_t objectLinkId, NFDataPackage &packet)> NET_CALLBACK_RECEIVE_FUNCTOR;

typedef std::function<int(uint64_t unLinkId, NFDataPackage &packet)> NET_RECEIVE_FUNCTOR;

typedef std::function<int(eMsgType nEvent, uint64_t unLinkId)> NET_EVENT_FUNCTOR;

typedef std::function<int(eMsgType nEvent, uint64_t conntionLinkId, uint64_t objectLinkId)> NET_CALLBACK_EVENT_FUNCTOR;

typedef std::function<void(int iRet, google::protobuf::Message &message)> RPC_TRANS_DESC_STORE_CB;

typedef std::function<int(uint64_t userId, const google::protobuf::Message *message)> LOG_BEHAVIOR_CALLBAK_FUNCTOR;

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
} TUidAndIndex;

int UidCompare(const TUidAndIndex *pstLeft, const TUidAndIndex *pstRight);

int UidHash(const TUidAndIndex *pstKey);

struct TUid2Uid
{
    uint64_t m_ullUid;
    uint64_t m_ullTargetUid;
};

int Uid2Compare(const TUid2Uid *pstLeft, const TUid2Uid *pstRight);

int Uid2Hash(const TUid2Uid *pstKey);

const int MAX_NAME_STR_LEN = 32;
typedef struct tagStrAndID
{
    char m_szName[MAX_NAME_STR_LEN];
    int m_iID;
} TStrAndID;

int StrCompare(const TStrAndID *pstLeft, const TStrAndID *pstRight);

int StrHash(const TStrAndID *pstKey);


