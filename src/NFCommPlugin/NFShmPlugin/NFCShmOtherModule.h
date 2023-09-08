// -------------------------------------------------------------------------
//    @FileName         :    NFCShmOtherModule.h
//    @Author           :    gaoyi
//    @Date             :    23-9-8
//    @Email			:    445267987@qq.com
//    @Module           :    NFCShmOtherModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFCShmOtherModule : public NFIDynamicModule
{
public:
    NFCShmOtherModule(NFIPluginManager *p);

    virtual ~NFCShmOtherModule();
public:
    virtual bool Awake() override;

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage) override;
};