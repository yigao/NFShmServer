#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_ARTIFACT_ENCHANT_NUM 1024

class AvatarArtifact_enchantDesc : public NFIDescTemplate<AvatarArtifact_enchantDesc, proto_ff_s::E_AvatarArtifact_enchant_s, EOT_CONST_AVATAR_ARTIFACT_ENCHANT_DESC_ID, MAX_AVATAR_ARTIFACT_ENCHANT_NUM>
{
public:
	AvatarArtifact_enchantDesc();
	virtual ~AvatarArtifact_enchantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
