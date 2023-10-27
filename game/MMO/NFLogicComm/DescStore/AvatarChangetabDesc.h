#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_CHANGETAB_NUM 16

class AvatarChangetabDesc : public NFIDescTemplate<AvatarChangetabDesc, proto_ff_s::E_AvatarChangetab_s, EOT_CONST_AVATAR_CHANGETAB_DESC_ID, MAX_AVATAR_CHANGETAB_NUM>
{
public:
	AvatarChangetabDesc();
	virtual ~AvatarChangetabDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
