#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_EQUIPSUIT_NUM 16

class AvatarEquipsuitDesc : public NFIDescTemplate<AvatarEquipsuitDesc, proto_ff_s::E_AvatarEquipsuit_s, EOT_CONST_AVATAR_EQUIPSUIT_DESC_ID, MAX_AVATAR_EQUIPSUIT_NUM>
{
public:
	AvatarEquipsuitDesc();
	virtual ~AvatarEquipsuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
