// -------------------------------------------------------------------------
//    @FileName         :    NFLogicObServiceModule.h
//    @Author           :    gaoyi
//    @Date             :    23-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicObServiceModule
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFIDynServiceModule.h"

class NFLogicObServiceModule : public NFIDysServiceModule
{
public:
    NFLogicObServiceModule(NFIPluginManager *p);
    
    virtual ~NFLogicObServiceModule();

public:
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
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2) override;
    
    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2) override;
    
    /** 处理服务器之间的rpc，这里负责转发玩家part的rpc
     * @brief
     * @param msgId
     * @param pRequest
     * @param pRespone
     * @param param1
     * @param param2
     * @return
     */
    virtual int OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message& request, google::protobuf::Message& respone, uint64_t param1, uint64_t param2) override;
};