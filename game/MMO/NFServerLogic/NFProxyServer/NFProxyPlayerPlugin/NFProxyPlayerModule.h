// -------------------------------------------------------------------------
//    @FileName         :    NFProxyClientModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyClientModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPackageConfig.h"
#include "NFProxySession.h"
#include "NFProxyAccount.h"
#include "NFLogicCommon/NFMMODynamicModule.h"

#define NF_PROXY_CLIENT_TIMER_ID 1
#define NF_PROXY_CLIENT_INTERVAL_TIME 100

class NFCProxyPlayerModule : public NFMMODynamicModule
{
public:
    explicit NFCProxyPlayerModule(NFIPluginManager *p);

    virtual ~NFCProxyPlayerModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    virtual int OnTimer(uint32_t nTimerID) override;

    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet) override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet) override;
public:
    /*
        处理客户端链接事件和未注册消息
    */
    int OnProxyClientSocketEvent(eMsgType nEvent, uint64_t unLinkId);

    int OnHandleProxyClientOtherMessage(uint64_t unLinkId, NFDataPackage &packet);

    int OnHandleClientDisconnect(uint64_t unLinkId);

    /**
     * @brief 通知中心服玩家掉线
     * @param unLinkId
     * @param pPlayerInfo
     * @return
     */
    int NotifyPlayerDisconnect(uint64_t unLinkId, NF_SHARE_PTR<NFProxyAccount> pPlayerInfo);
public:
    /*
     * 处理客户端连接超时
     * */
    int HandleProxyClientTick();
    int HandlePlayerTick();

    int KickPlayer(uint64_t unLinkId, int reason = 0);
public:

    /**
     * @brief 处理其他服务器发给客户的 信息
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleOtherServerToClientMsg(uint64_t unLinkId, NFDataPackage &packet);
public:
    int OnHandleRedirectMsg(uint64_t unLinkId, NFDataPackage &packet);
public:
    /*
     * 处理心跳包
     */
    int OnHandleClientHeartBeat(uint64_t unLinkId, NFDataPackage &packet);
public:
    /**
     * @brief 玩家登录
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandlePlayerLoginFromClient(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief 创建角色
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleCreateRoleFromClient(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief 进入游戏请求
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleEnterGameReq(uint64_t unLinkId, NFDataPackage &packet);
public:
    /**
     * @brief 断线重连
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandlePlayerReconnectFromClient(uint64_t unLinkId, NFDataPackage &packet);
public:
    /**
     * @brief 世界服通知网管，玩家掉线
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServicePlayerLeaveGame(proto_ff::NotifyGateLeaveGame2 &request, proto_ff::EmptyMessage &respone);

private:
    NFMapEx<uint64_t, NFProxySession> mSessionMap; //unlink -- NFProxySession
    NFMapEx<uint64_t, NFProxyAccount> mAccountMap; //uid -- NFProxyPlayerInfo
    NFPackageConfig m_packetConfig;
};
