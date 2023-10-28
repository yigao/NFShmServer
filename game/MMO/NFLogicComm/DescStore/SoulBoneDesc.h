#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_BONE_NUM 8

class SoulBoneDesc : public NFIDescTemplate<SoulBoneDesc, proto_ff_s::E_SoulBone_s, EOT_CONST_SOUL_BONE_DESC_ID, MAX_SOUL_BONE_NUM>
{
public:
	SoulBoneDesc();
	virtual ~SoulBoneDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
