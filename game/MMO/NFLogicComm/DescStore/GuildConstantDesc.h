#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_CONSTANT_NUM 128

class GuildConstantDesc : public NFIDescTemplate<GuildConstantDesc, proto_ff_s::E_GuildConstant_s, EOT_CONST_GUILD_CONSTANT_DESC_ID, MAX_GUILD_CONSTANT_NUM>
{
public:
	GuildConstantDesc();
	virtual ~GuildConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
