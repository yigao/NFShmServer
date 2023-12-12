#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_MYTHEQUIP_NUM 64

class AvatarMythequipDesc : public NFIDescTemplate<AvatarMythequipDesc, proto_ff_s::E_AvatarMythequip_s, EOT_CONST_AVATAR_MYTHEQUIP_DESC_ID, MAX_AVATAR_MYTHEQUIP_NUM>
{
public:
	AvatarMythequipDesc();
	virtual ~AvatarMythequipDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
