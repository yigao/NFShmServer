#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk3v3_s.h"

#define MAX_PK3V3_BADGE_NUM 16

class Pk3v3BadgeDesc : public NFIDescTemplate<Pk3v3BadgeDesc, proto_ff_s::E_Pk3v3Badge_s, EOT_CONST_PK3V3_BADGE_DESC_ID, MAX_PK3V3_BADGE_NUM>
{
public:
	Pk3v3BadgeDesc();
	virtual ~Pk3v3BadgeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
