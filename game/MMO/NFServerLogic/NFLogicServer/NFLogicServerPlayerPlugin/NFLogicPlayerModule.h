// -------------------------------------------------------------------------
//    @FileName         :    NFIWorldPlayerModule.h
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFIWorldPlayerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "Player/NFPlayerMgr.h"
#include "NFLogicCommon/NFMMODynamicModule.h"

class NFCLogicPlayerModule : public NFMMODynamicModule
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
     * @brief 进入游戏
     * @param request
     * @param respone
     * @param proxyId
     * @param param2
     * @return
     */
    int OnRpcServiceEnterGame(proto_ff::ClientEnterGameReq& request, proto_ff::ClientEnterGameInternalRsp& respone, uint64_t proxyId, uint64_t param2);
};
