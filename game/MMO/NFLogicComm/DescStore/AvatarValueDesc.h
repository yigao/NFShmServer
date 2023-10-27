#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_VALUE_NUM 4096

class AvatarValueDesc : public NFIDescTemplate<AvatarValueDesc, proto_ff_s::E_AvatarValue_s, EOT_CONST_AVATAR_VALUE_DESC_ID, MAX_AVATAR_VALUE_NUM>
{
public:
	AvatarValueDesc();
	virtual ~AvatarValueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
