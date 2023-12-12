#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_ARTIFACT_DECOMPOSE_NUM 32

class AvatarArtifact_decomposeDesc : public NFIDescTemplate<AvatarArtifact_decomposeDesc, proto_ff_s::E_AvatarArtifact_decompose_s, EOT_CONST_AVATAR_ARTIFACT_DECOMPOSE_DESC_ID, MAX_AVATAR_ARTIFACT_DECOMPOSE_NUM>
{
public:
	AvatarArtifact_decomposeDesc();
	virtual ~AvatarArtifact_decomposeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
