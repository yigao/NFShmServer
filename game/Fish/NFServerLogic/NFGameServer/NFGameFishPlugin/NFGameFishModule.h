// -------------------------------------------------------------------------
//    @FileName         :    NFGameFish2004Module.h
//    @Author           :    gaoyi
//    @Date             :    23-8-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFish2004Module
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFFishDynamicModule.h"
#include "NFLogicCommon/NFISubGameModule.h"

class NFGameFishModule : public NFISubGameModule
{
public:
    explicit NFGameFishModule(NFIPluginManager *p);

    virtual ~NFGameFishModule();

    virtual bool Awake() override;

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;
public:
    void RegisterMsgToFishTypeHandler(uint32_t msgId, int fishTypeHandler);
    int GetFishTypeHandlerByMsgId(uint32_t msgId);
public:
    std::unordered_map<uint32_t, uint32_t> m_msgIdToFishTypeHandler;
};