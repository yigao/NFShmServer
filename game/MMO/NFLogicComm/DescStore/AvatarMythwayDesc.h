#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_MYTHWAY_NUM 64

class AvatarMythwayDesc : public NFIDescTemplate<AvatarMythwayDesc, proto_ff_s::E_AvatarMythway_s, EOT_CONST_AVATAR_MYTHWAY_DESC_ID, MAX_AVATAR_MYTHWAY_NUM>
{
public:
	AvatarMythwayDesc();
	virtual ~AvatarMythwayDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
