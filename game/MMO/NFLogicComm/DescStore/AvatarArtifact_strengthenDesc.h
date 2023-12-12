#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_ARTIFACT_STRENGTHEN_NUM 256

class AvatarArtifact_strengthenDesc : public NFIDescTemplate<AvatarArtifact_strengthenDesc, proto_ff_s::E_AvatarArtifact_strengthen_s, EOT_CONST_AVATAR_ARTIFACT_STRENGTHEN_DESC_ID, MAX_AVATAR_ARTIFACT_STRENGTHEN_NUM>
{
public:
	AvatarArtifact_strengthenDesc();
	virtual ~AvatarArtifact_strengthenDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
