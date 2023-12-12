#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_ARTIFACT_NUM 8

class AvatarArtifactDesc : public NFIDescTemplate<AvatarArtifactDesc, proto_ff_s::E_AvatarArtifact_s, EOT_CONST_AVATAR_ARTIFACT_DESC_ID, MAX_AVATAR_ARTIFACT_NUM>
{
public:
	AvatarArtifactDesc();
	virtual ~AvatarArtifactDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
