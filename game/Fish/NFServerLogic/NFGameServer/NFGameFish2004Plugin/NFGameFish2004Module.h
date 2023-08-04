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

class NFGameFish2004Module : public NFFishDynamicModule
{
public:
    explicit NFGameFish2004Module(NFIPluginManager *p);

    virtual ~NFGameFish2004Module();

    virtual bool Awake() override;
};