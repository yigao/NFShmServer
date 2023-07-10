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
    int OnRpcServicePlayerLogin(proto_ff::Proto_WorldToLogicLoginReq& request, proto_ff::Proto_LogicToWorldLoginRsp& respone);
};
