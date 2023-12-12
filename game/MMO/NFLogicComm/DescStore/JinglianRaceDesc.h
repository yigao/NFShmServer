#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Jinglian_s.h"

#define MAX_JINGLIAN_RACE_NUM 8

class JinglianRaceDesc : public NFIDescTemplate<JinglianRaceDesc, proto_ff_s::E_JinglianRace_s, EOT_CONST_JINGLIAN_RACE_DESC_ID, MAX_JINGLIAN_RACE_NUM>
{
public:
	JinglianRaceDesc();
	virtual ~JinglianRaceDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
