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
private:
    NFMapEx<uint64_t, NFProxySession> mClientLinkInfo; //unlink -- NFProxySession
    NFMapEx<uint64_t, NFProxyPlayerInfo> mPlayerLinkInfo; //playerId -- NFProxyPlayerInfo
    NFPackageConfig m_packetConfig;

};
