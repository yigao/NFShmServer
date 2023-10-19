// -------------------------------------------------------------------------
//    @FileName         :    NFLogicRoomModule.h
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicRoomModule
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFFishDynamicModule.h"

class NFLogicRoomModule : public NFFishDynamicModule
{
public:
    explicit NFLogicRoomModule(NFIPluginManager* p);

    virtual ~NFLogicRoomModule();

    virtual bool Awake() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage) override;
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