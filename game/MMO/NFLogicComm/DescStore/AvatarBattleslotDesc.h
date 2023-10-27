#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_BATTLESLOT_NUM 8

class AvatarBattleslotDesc : public NFIDescTemplate<AvatarBattleslotDesc, proto_ff_s::E_AvatarBattleslot_s, EOT_CONST_AVATAR_BATTLESLOT_DESC_ID, MAX_AVATAR_BATTLESLOT_NUM>
{
public:
	AvatarBattleslotDesc();
	virtual ~AvatarBattleslotDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
