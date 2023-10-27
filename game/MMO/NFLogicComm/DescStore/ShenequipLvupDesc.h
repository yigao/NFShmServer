#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_LVUP_NUM 4096

class ShenequipLvupDesc : public NFIDescTemplate<ShenequipLvupDesc, proto_ff_s::E_ShenequipLvup_s, EOT_CONST_SHENEQUIP_LVUP_DESC_ID, MAX_SHENEQUIP_LVUP_NUM>
{
public:
	ShenequipLvupDesc();
	virtual ~ShenequipLvupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
