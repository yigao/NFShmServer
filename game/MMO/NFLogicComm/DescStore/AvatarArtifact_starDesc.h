#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_ARTIFACT_STAR_NUM 256

class AvatarArtifact_starDesc : public NFIDescTemplate<AvatarArtifact_starDesc, proto_ff_s::E_AvatarArtifact_star_s, EOT_CONST_AVATAR_ARTIFACT_STAR_DESC_ID, MAX_AVATAR_ARTIFACT_STAR_NUM>
{
public:
	AvatarArtifact_starDesc();
	virtual ~AvatarArtifact_starDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
