#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_DISPLAY_NUM 2

class AvatarDisplayDesc : public NFIDescTemplate<AvatarDisplayDesc, proto_ff_s::E_AvatarDisplay_s, EOT_CONST_AVATAR_DISPLAY_DESC_ID, MAX_AVATAR_DISPLAY_NUM>
{
public:
	AvatarDisplayDesc();
	virtual ~AvatarDisplayDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
