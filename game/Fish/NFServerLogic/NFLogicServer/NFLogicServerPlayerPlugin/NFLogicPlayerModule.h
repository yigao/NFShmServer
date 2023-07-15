// -------------------------------------------------------------------------
//    @FileName         :    NFIWorldPlayerModule.h
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFIWorldPlayerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFLogicServer/NFLogicServerPlayerPlugin/Player/NFPlayerMgr.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "ServerInternal.pb.h"

class NFCLogicPlayerModule : public NFIDynamicModule
{
public:
	explicit NFCLogicPlayerModule(NFIPluginManager* p);
	virtual ~NFCLogicPlayerModule();

	virtual bool Awake() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;
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
    int OnRpcServicePlayerLogin(proto_ff::Proto_WorldToLogicLoginReq& request, proto_ff::Proto_LogicToWorldLoginRsp& respone);

    /**
     * @brief 玩家重连
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServicePlayerReconnect(proto_ff::WTLPlayerReconnectReq& request, proto_ff::LTWPlayerReconnectRsp& respone);

    /**
     * @brief 玩家掉线
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandlePlayerDisconnectMsg(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);
};
