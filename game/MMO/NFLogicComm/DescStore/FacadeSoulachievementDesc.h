#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_SOULACHIEVEMENT_NUM 128

class FacadeSoulachievementDesc : public NFIDescTemplate<FacadeSoulachievementDesc, proto_ff_s::E_FacadeSoulachievement_s, EOT_CONST_FACADE_SOULACHIEVEMENT_DESC_ID, MAX_FACADE_SOULACHIEVEMENT_NUM>
{
public:
	FacadeSoulachievementDesc();
	virtual ~FacadeSoulachievementDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
