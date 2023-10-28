#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_CRYSTALLV_NUM 1024

class SoulCrystallvDesc : public NFIDescTemplate<SoulCrystallvDesc, proto_ff_s::E_SoulCrystallv_s, EOT_CONST_SOUL_CRYSTALLV_DESC_ID, MAX_SOUL_CRYSTALLV_NUM>
{
public:
	SoulCrystallvDesc();
	virtual ~SoulCrystallvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
