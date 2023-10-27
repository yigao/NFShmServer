#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_FRAGMENT_NUM 16

class AvatarFragmentDesc : public NFIDescTemplate<AvatarFragmentDesc, proto_ff_s::E_AvatarFragment_s, EOT_CONST_AVATAR_FRAGMENT_DESC_ID, MAX_AVATAR_FRAGMENT_NUM>
{
public:
	AvatarFragmentDesc();
	virtual ~AvatarFragmentDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
