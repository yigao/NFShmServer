// -------------------------------------------------------------------------
//    @FileName         :    NFOnlineModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFOnlineModule
//
// -------------------------------------------------------------------------

#pragma once


#include "NFLogicCommon/NFFishDynamicModule.h"

class NFCSnsPlayerModule : public NFFishDynamicModule
{
public:
    explicit NFCSnsPlayerModule(NFIPluginManager *p);

    virtual ~NFCSnsPlayerModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    virtual int OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;
public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2) override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2) override;

public:
    /**
     * @brief 玩家登录
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServicePlayerLogin(proto_ff::Proto_WTSLoginReq& request, proto_ff::Proto_STWLoginRsp& respone);

    /**
     * @brief 玩家重连
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServicePlayerReconnect(proto_ff::WTSPlayerReconnectReq& request, proto_ff::STWPlayerReconnectRsp& respone);

    /**
     * @brief
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServiceQueryPlayerSimpleData(proto_ff::Proto_TS_QueryPlayerSimpleDataReq& request, proto_ff::Proto_ST_QueryPlayerSimpleDataRsp& respone);

    /**
     * @brief 玩家掉线
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandlePlayerDisconnectMsg(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);

    /**
     * @brief 玩家登出
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandlePlayerLogoutNotify(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);

    /**
     * @brief
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleQueryUserSimpleDataReq(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);
};
