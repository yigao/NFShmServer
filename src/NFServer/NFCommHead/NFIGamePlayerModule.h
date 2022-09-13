// -------------------------------------------------------------------------
//    @FileName         :    NFIGameUserModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIGameUserModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFIGamePlayerModule : public NFIDynamicModule
{
public:
	NFIGamePlayerModule(NFIPluginManager* p) : NFIDynamicModule(p)
	{

	}

	virtual ~NFIGamePlayerModule()
	{

	}

	virtual int SendMsgToClientByPlayerId(uint64_t playerId, uint32_t nMsgId, const google::protobuf::Message& xData) = 0;
	virtual int SendMsgToClientByPlayerId(uint64_t playerId, uint16_t nMainMsgId, uint16_t nSubMsgId, const google::protobuf::Message& xData) = 0;
};
