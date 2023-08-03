// -------------------------------------------------------------------------
//    @FileName         :    NFCAccountLoginModule.h
//    @Author           :    gaoyi
//    @Date             :    23-7-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFCAccountLoginModule
//
// -------------------------------------------------------------------------

#pragma once


#include "NFLogicCommon/NFFishDynamicModule.h"

class NFCAccountLoginModule : public NFFishDynamicModule
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
    /**
     * @brief 处理账号登录
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServiceAccountLogin(proto_ff::Proto_CSAccountLoginReq& request, proto_ff::Proto_SCAccountLoginRsp& respone);

    /**
     * @brief 处理账号注册账号
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServiceRegisterAccount(proto_ff::Proto_CSRegisterAccountReq& request, proto_ff::Proto_SCRegisterAccountRsp& respone);
};
