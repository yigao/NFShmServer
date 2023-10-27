#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_ANSWER_NUM 64

class GuildAnswerDesc : public NFIDescTemplate<GuildAnswerDesc, proto_ff_s::E_GuildAnswer_s, EOT_CONST_GUILD_ANSWER_DESC_ID, MAX_GUILD_ANSWER_NUM>
{
public:
	GuildAnswerDesc();
	virtual ~GuildAnswerDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
