#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_DOMINANCE_NUM 8

class ShenequipDominanceDesc : public NFIDescTemplate<ShenequipDominanceDesc, proto_ff_s::E_ShenequipDominance_s, EOT_CONST_SHENEQUIP_DOMINANCE_DESC_ID, MAX_SHENEQUIP_DOMINANCE_NUM>
{
public:
	ShenequipDominanceDesc();
	virtual ~ShenequipDominanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
