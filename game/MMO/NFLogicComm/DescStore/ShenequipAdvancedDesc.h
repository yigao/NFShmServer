#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_ADVANCED_NUM 64

class ShenequipAdvancedDesc : public NFIDescTemplate<ShenequipAdvancedDesc, proto_ff_s::E_ShenequipAdvanced_s, EOT_CONST_SHENEQUIP_ADVANCED_DESC_ID, MAX_SHENEQUIP_ADVANCED_NUM>
{
public:
	ShenequipAdvancedDesc();
	virtual ~ShenequipAdvancedDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
