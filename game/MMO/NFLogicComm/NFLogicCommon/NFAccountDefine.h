// -------------------------------------------------------------------------
//    @FileName         :    NFAccountDefine.h
//    @Author           :    gaoyi
//    @Date             :    22-10-29
//    @Email			:    445267987@qq.com
//    @Module           :    NFAccountDefine
//
// -------------------------------------------------------------------------

#pragma once

#include <string>
#include <unordered_map>

#include "NFComm/NFCore/NFPlatform.h"

#pragma pack (push)
#pragma pack(1)


enum OnlineAccountTokenState
{
    ONLINE_ACCOUNT_TOKEN_STATE_NONE = 0,		//无状态
    ONLINE_ACCOUNT_TOKEN_STATE_CHECK,			//等待验证状态
    ONLINE_ACCOUNT_TOKEN_STATE_ALREADY_CHECK,	//已经验证状态
};

enum OnlinAccountState
{
    ONLINE_ACCOUNT_STATE_NULL = 0,
    ONLINE_ACCOUNT_STATE_LOGIN,
    ONLINE_ACCOUNT_STATE_GAMING,
    ONLINE_ACCOUNT_STATE_KICKOUT,
    ONLINE_ACCOUNT_STATE_SWITCH_SERVER_SAVING,
    ONLINE_ACCOUNT_STATE_SWITCH_SERVER_SAVE_FINISH,
    ONLINE_ACCOUNT_STATE_END
};

enum LoginType
{
    LOGIN_TYPE_NULL = 0,
    LOGIN_TYPE_NORMAL,
    LOGIN_TYPE_RECONNECT,
    LOGIN_TYPE_SWITCH_SERVER			// 在逻辑服之间切换
};

enum AccountLoginState
{
    ACCOUNT_LOGIN_STATE_BEGIN = 0,
    ACCOUNT_LOGIN_STATE_VERIFY_CHANNEL,         // 渠道帐号接入验证
    ACCOUNT_LOGIN_STATE_CHECK_LOGIN,			// 校验登录
    ACCOUNT_LOGIN_STATE_GET_GAME_SERVER,        // 获取待登录游戏服务器的地址
    ACCOUNT_LOGIN_STATE_SUCCESS,				// 账户登录成功
    ACCOUNT_LOGIN_STATE_RETRY_GET_GAME_SERVER,  // 服务器人数已满，等待重新尝试获取
    ACCOUNT_LOGIN_STATE_END
};

enum AccountGameState
{
    ACCOUNT_GAME_STATE_NULL = 0,
    ACCOUNT_GAME_STATE_LOGIN,			// 登录游戏
    ACCOUNT_GAME_STATE_GAMING,			// 游戏状态
    ACCOUNT_GAME_STATE_DISCONNECT,		// 断线状态
    ACCOUNT_GAME_STATE_LOGOUT,			// 登出游戏
    ACCOUNT_GAME_STATE_SWITCH,			// 切换逻辑服
};

enum LeaveGameState
{
    LEAVE_GAME_STATE_NULL= 0,
    LEAVE_GAME_STATE_BEGIN,
    LEAVE_GAME_STATE_SAVE_DATA,         // 向DBProxy保存数据
    LEAVE_GAME_STATE_END
};


// login server
//这里的长度跟 accountinfo表存储的长度相关，不要随便改动
#define MAX_PLAT_USER_ID_LEN 32			//平台用户ID最大长度
#define MAX_PLAT_USER_NAME_LEN 32		//平台用户名最大长度
#define MAX_CHANNEL_ID_LEN 32			//渠道ID最大长度
#define MAX_CHANNEL_USER_ID_LEN 88		//渠道用户ID ,渠道ID + 平台用户ID 组合而成，用于唯一标示一个账户
#define DEFAULT_CHANNEL_ID "channel_cg"	//默认渠道ID
#define MAX_CHARACTER_NAME_LEN 32		//角色名最大长度

//逻辑服向中心服验证登录token的等待秒数
#define ONLINE_ACCOUNT_CHECK_LOGIC_TOKEN_WAIT_SEC 30






#define PLAYERCACHE_TIME	600000   //玩家数据缓存时间		10分钟
#define ACCOUNT_CACHE_TIME	600000   //帐号数据缓存时间		10分钟


//-------------------------------------------------------------------------------------------

//账号登出超时时间, 单位：毫秒
#define LOGOUT_TIMEOUT		60000
//登陆token时效,单位：毫秒
#define TOEKN_TIME			1800000
//断线重连时效,单位：毫秒
#define RECONNECT_TIME		600000
//一个账号下最大角色数量
#define MAX_ROLE_NUM  8

//账号状态
enum class EAccountState
{
    none,
    login,			// 登录游戏
    queue,			// 排队状态
    loading,		// 从DB加载角色数据
    enter,			// 进入游戏
    gaming,			// 游戏状态
    switch_scene,	// 切换场景
    logout,			// 登出游戏
    disconnect,     // 断线状态
};



//登录排队信息
class LoginQueue
{
public:
    uint32_t uid;		//排队玩家UID
    uint64_t lastReq;	//上一次请求排队名次的时间
    LoginQueue()
    {
        uid = 0;
        lastReq = 0;
    }

    bool operator==(const LoginQueue& obj2)
    {
        return  (uid == obj2.uid);
    }

};
using UID_QUEUE = std::vector<LoginQueue>;   //排队列表


//帐号下角色信息
struct AccountRoleInfo
{
    uint64_t cid = 0;			//角色cid
    string name;				//角色名字
    int32_t prof = 0;			//职业
    int32_t level = 0;			//等级
    uint64_t fight = 0;			//战力
    uint64_t createtime = 0;	//创建时间
    proto_ff::RoleFacadeProto facade;		//外观

    uint64_t sceneId = 0;
    uint64_t mapId = 0;
    NFPoint3<float> pos;

    uint64_t lastSceneId = 0;
    uint64_t lastMapId = 0;
    NFPoint3<float> lastpos;
};
//cid - AccountCharInfo
typedef unordered_map<uint64_t, AccountRoleInfo> AccountRoleMap;


//帐号信息
struct AccountInfo
{
    uint32_t uid = 0;								//帐号ID
    uint32_t chanId = 0;							//渠道ID
    EAccountState state = EAccountState::none;		//帐号状态
    uint64_t stateTick = 0;					//帐号状态开始时的tick
    uint64_t roleCid = 0;					//角色cid
    uint32_t logicId = 0;					//逻辑服ID
    uint32_t gateId = 0;					//网关ID
    uint32_t clientId = 0;					//客户端会话ID
    uint32_t bornzid = 0;					//登录的区服ID
    bool disconnect = false;				//是否断开会话了(网关通知中心服断开连接或者中心服主动通知网关断开连接成功的)
    AccountRoleMap mapRoleList;				//帐号下角色列表

    bool	isWhite = false;				//是否是白名单帐号
    //
    AccountInfo& operator =(const AccountInfo& other)
    {
        if (this != &other)
        {
            uid = other.uid;
            chanId = other.chanId;
            state = other.state;
            stateTick = other.stateTick;

            roleCid = other.roleCid;
            logicId = other.logicId;
            gateId = other.gateId;

            clientId = other.clientId;
            bornzid = other.bornzid;
            disconnect = other.disconnect;

            for (const auto& iter : other.mapRoleList)
            {
                mapRoleList[iter.first] = iter.second;
            }

            isWhite = other.isWhite;
        }

        return *this;
    }
};
using  AccountInfoMap = unordered_map<uint32_t, AccountInfo>;


#pragma pack(pop)
