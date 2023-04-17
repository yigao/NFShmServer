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
#include "NFServerComm/NFServerCommon/NFIProxyPlayerModule.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFProxySession.h"
#include "NFProxyPlayerInfo.h"
#include <ComDefine.pb.h>

#define NF_PROXY_CLIENT_TIMER_ID 1
#define NF_PROXY_CLIENT_INTERVAL_TIME 100

class NFCProxyPlayerModule : public NFIProxyPlayerModule
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

    /*
     * 处理客户端连接超时
     * */
    int HandleProxyClientTick();
    int HandlePlayerTick();



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

    /**
     * @brief 通知玩家断开连接，离开游戏
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleLeaveGame(uint64_t unLinkId, NFDataPackage &packet);
public:
    /**
     * @brief 处理登录协议
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleClientLogin(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief 处理登录协议
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleClientLoginRep(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleChangeServerBusId(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleEnterGameRsp(uint64_t unLinkId, NFDataPackage &packet);
public:
    /**
     * @brief handle world server return msg
     */

    /**
     * @brief 处理世界服务器返回的排队协议
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleClientQueueResult(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief
     * @param clientId
     * @param force
     * @param flag
     * @return
     */
    int LeaveGame(NF_SHARE_PTR<NFProxySession> pLinkInfo, proto_ff::LOGOUT_TYPE flag);

    /**
     * @brief 强制玩家掉线，先通知别的服务器玩家掉线，在关闭网络链接(关闭网络链接时异步的)
     * @param clientId
     * @param flag
     * @return
     */
    int ForceDisconnect(NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo, NF_SHARE_PTR<NFProxySession> pLinkInfo, proto_ff::LOGOUT_TYPE flag);

    /*
     * 踢掉玩家
     * */
    int KickPlayer(NF_SHARE_PTR<NFProxySession> pLinkInfo, uint32_t flag);

    /**
     * @brief 通知中心服玩家掉线
     * @param unLinkId
     * @param pPlayerInfo
     * @return
     */
    int NotifyPlayerDisconnect(uint64_t unLinkId, NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo) const;
private:
    NFMapEx<uint64_t, NFProxySession> mClientLinkInfo; //unlink -- NFProxySession
    NFMapEx<uint64_t, NFProxyPlayerInfo> mPlayerLinkInfo; //playerId -- NFProxyPlayerInfo
    NFPackageConfig m_packetConfig;

};
