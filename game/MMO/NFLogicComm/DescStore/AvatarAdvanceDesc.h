#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_ADVANCE_NUM 32

class AvatarAdvanceDesc : public NFIDescTemplate<AvatarAdvanceDesc, proto_ff_s::E_AvatarAdvance_s, EOT_CONST_AVATAR_ADVANCE_DESC_ID, MAX_AVATAR_ADVANCE_NUM>
{
public:
	AvatarAdvanceDesc();
	virtual ~AvatarAdvanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
