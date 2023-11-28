#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_BONESTRONG_NUM 1024

class SoulBonestrongDesc : public NFIDescTemplate<SoulBonestrongDesc, proto_ff_s::E_SoulBonestrong_s, EOT_CONST_SOUL_BONESTRONG_DESC_ID, MAX_SOUL_BONESTRONG_NUM>
{
public:
	SoulBonestrongDesc();
	virtual ~SoulBonestrongDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
