#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_MYTH_NUM 4

class AvatarMythDesc : public NFIDescTemplate<AvatarMythDesc, proto_ff_s::E_AvatarMyth_s, EOT_CONST_AVATAR_MYTH_DESC_ID, MAX_AVATAR_MYTH_NUM>
{
public:
	AvatarMythDesc();
	virtual ~AvatarMythDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
