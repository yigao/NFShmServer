#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Escort_s.h"

#define MAX_ESCORT_CHANCE_NUM 4

class EscortChanceDesc : public NFIDescTemplate<EscortChanceDesc, proto_ff_s::E_EscortChance_s, EOT_CONST_ESCORT_CHANCE_DESC_ID, MAX_ESCORT_CHANCE_NUM>
{
public:
	EscortChanceDesc();
	virtual ~EscortChanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
