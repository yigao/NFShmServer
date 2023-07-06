// -------------------------------------------------------------------------
//    @FileName         :    NFCAccountLoginModule.h
//    @Author           :    gaoyi
//    @Date             :    23-7-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFCAccountLoginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "CSLogin.pb.h"

class NFCAccountLoginModule : public NFIDynamicModule
{
public:
	explicit NFCAccountLoginModule(NFIPluginManager* p);
	virtual ~NFCAccountLoginModule();

	virtual bool Awake() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

    virtual int OnTimer(uint32_t nTimerID) override;
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
    int OnRpcServiceAccountLogin(proto_ff::Proto_CSAccountLoginReq& request, proto_ff::Proto_SCAccountLoginRsp& respone);
};
