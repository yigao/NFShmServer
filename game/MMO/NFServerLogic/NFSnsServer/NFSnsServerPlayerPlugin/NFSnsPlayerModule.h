// -------------------------------------------------------------------------
//    @FileName         :    NFOnlineModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFOnlineModule
//
// -------------------------------------------------------------------------

#pragma once


#include "NFLogicCommon/NFMMODynamicModule.h"

class NFCSnsPlayerModule : public NFMMODynamicModule
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
};
