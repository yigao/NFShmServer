#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_TTOWERDEVELOP_DATA_NUM 32

class GuildTtowerdevelop_dataDesc : public NFIDescTemplate<GuildTtowerdevelop_dataDesc, proto_ff_s::E_GuildTtowerdevelop_data_s, EOT_CONST_GUILD_TTOWERDEVELOP_DATA_DESC_ID, MAX_GUILD_TTOWERDEVELOP_DATA_NUM>
{
public:
	GuildTtowerdevelop_dataDesc();
	virtual ~GuildTtowerdevelop_dataDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
