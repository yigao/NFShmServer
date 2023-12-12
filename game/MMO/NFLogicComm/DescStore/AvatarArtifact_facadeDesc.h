#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_ARTIFACT_FACADE_NUM 16

class AvatarArtifact_facadeDesc : public NFIDescTemplate<AvatarArtifact_facadeDesc, proto_ff_s::E_AvatarArtifact_facade_s, EOT_CONST_AVATAR_ARTIFACT_FACADE_DESC_ID, MAX_AVATAR_ARTIFACT_FACADE_NUM>
{
public:
	AvatarArtifact_facadeDesc();
	virtual ~AvatarArtifact_facadeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
