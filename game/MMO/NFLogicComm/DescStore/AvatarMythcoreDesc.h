#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_MYTHCORE_NUM 64

class AvatarMythcoreDesc : public NFIDescTemplate<AvatarMythcoreDesc, proto_ff_s::E_AvatarMythcore_s, EOT_CONST_AVATAR_MYTHCORE_DESC_ID, MAX_AVATAR_MYTHCORE_NUM>
{
public:
	AvatarMythcoreDesc();
	virtual ~AvatarMythcoreDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
