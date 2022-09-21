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

	virtual std::string GetConstValue(proto_ff::enConstType type) const override;;

    virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message) override;

    virtual std::string GetRandomName() const override;
};