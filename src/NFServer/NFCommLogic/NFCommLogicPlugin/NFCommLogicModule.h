// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"


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

	virtual std::string GetConstValue(proto_ff::enConstType type) const;

    virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message);

    virtual std::string GetRandomName() const override;
};