// -------------------------------------------------------------------------
//    @FileName         :    NFMatchPlayerModule.h
//    @Author           :    gaoyi
//    @Date             :    23-10-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFMatchPlayerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFLogicCommon/NFMMODynamicModule.h"

class NFCenterRegisterModule : public NFMMODynamicModule
{
public:
    explicit NFCenterRegisterModule(NFIPluginManager* p);
    virtual ~NFCenterRegisterModule();

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
     *
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServiceMapReg(proto_ff::RegisterMapInfoReq& request, proto_ff::ReigsterMapInfoRsp& respone);
public:
    /**
     * @brief 跨服地图注册
     * @return
     */
    int RegisterCrossMap();
};

