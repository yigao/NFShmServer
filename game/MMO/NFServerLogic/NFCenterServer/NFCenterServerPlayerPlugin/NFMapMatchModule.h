// -------------------------------------------------------------------------
//    @FileName         :    NFMapMatchModule.h
//    @Author           :    gaoyi
//    @Date             :    23-10-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapMatchModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFMMODynamicModule.h"

class NFMapMatchModule : public NFMMODynamicModule
{
public:
    explicit NFMapMatchModule(NFIPluginManager* p);
    virtual ~NFMapMatchModule();
    
    virtual bool Awake() override;
    
    virtual bool Execute() override;
    
    virtual bool OnDynamicPlugin() override;
    
    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;
public:
    /**
     * Ω¯»Î”Œœ∑
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServiceEnterScene(proto_ff::EnterSceneReq& request, proto_ff::EnterSceneRsp& respone);
};