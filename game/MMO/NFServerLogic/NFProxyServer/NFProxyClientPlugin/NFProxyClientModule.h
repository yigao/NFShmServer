// -------------------------------------------------------------------------
//    @FileName         :    NFProxyClientModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyClientModule
//
// -------------------------------------------------------------------------

#pragma once

#include <NFLogicCommon/NFPackageConfig.h>
#include "NFServerComm/NFServerCommon/NFIProxyClientModule.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFProxySession.h"
#include "NFProxyPlayerInfo.h"

#define NF_PROXY_CLIENT_TIMER_ID 1
#define NF_PROXY_CLIENT_INTERVAL_TIME 100

class NFCProxyClientModule : public NFIProxyClientModule
{
public:
    explicit NFCProxyClientModule(NFIPluginManager *p);

    virtual ~NFCProxyClientModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnHandleOtherServerOtherMessage(uint64_t unLinkId, const NFDataPackage &packet) override;

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

    /*
     * 踢掉玩家
     * */
    int KickPlayer(uint64_t unLinkId, uint32_t flag);
public:
    /*
     * 处理心跳包
     */
    int OnHandleClientHeartBeat(uint64_t unLinkId, NFDataPackage &packet);

public:
    /*
     * 处理登录协议
     */
    int OnHandleClientCenterLogin(uint64_t unLinkId, NFDataPackage &packet);

private:
    /*
        对外部客户端监听唯一ID
    */
    uint64_t m_proxyClientLinkId;
    NFMapEx<uint64_t, NFProxySession> mClientLinkInfo; //unlink -- NFProxySession
    NFMapEx<uint64_t, NFProxyPlayerInfo> mPlayerLinkInfo; //playerId -- NFProxyPlayerInfo
    uint32_t m_loginInterPing;
    NFPackageConfig m_packetConfig;
};
