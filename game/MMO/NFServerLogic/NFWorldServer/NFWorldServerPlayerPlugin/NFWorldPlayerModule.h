// -------------------------------------------------------------------------
//    @FileName         :    NFIWorldPlayerModule.h
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFIWorldPlayerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFLogicCommon/NFMMODynamicModule.h"

class NFCWorldPlayerModule : public NFMMODynamicModule
{
public:
	explicit NFCWorldPlayerModule(NFIPluginManager* p);
	virtual ~NFCWorldPlayerModule();

	virtual bool Awake() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;
public:
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
    /**
     * @brief 玩家登录
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServicePlayerLogin(proto_ff::ClientLoginReq& request, proto_ff::ClientLoginRsp& respone, uint64_t proxyId, uint64_t clientId);
public:
    /**
     * @brief
     * @param proxyId
     * @param clientId
     * @param leaveFlag
     * @return
     */
    int NotifyGateLeave(uint32_t proxyId, uint64_t clientId, proto_ff::LOGOUT_TYPE leaveFlag);
};
