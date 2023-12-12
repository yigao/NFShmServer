#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_CHANGE_NUM 32

class AvatarChangeDesc : public NFIDescTemplate<AvatarChangeDesc, proto_ff_s::E_AvatarChange_s, EOT_CONST_AVATAR_CHANGE_DESC_ID, MAX_AVATAR_CHANGE_NUM>
{
public:
	AvatarChangeDesc();
	virtual ~AvatarChangeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
