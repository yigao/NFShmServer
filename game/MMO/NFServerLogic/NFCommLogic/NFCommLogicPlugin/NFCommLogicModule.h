// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFLogicCommon/NFICommLogicModule.h"

class NFCommLogicModule : public NFICommLogicModule
{
public:
	NFCommLogicModule(NFIPluginManager* p) :NFICommLogicModule(p)
	{

	}

	virtual ~NFCommLogicModule()
	{

	}

	virtual bool Awake() override;

    virtual int OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;
};