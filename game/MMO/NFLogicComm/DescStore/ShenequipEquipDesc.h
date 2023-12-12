#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_EQUIP_NUM 64

class ShenequipEquipDesc : public NFIDescTemplate<ShenequipEquipDesc, proto_ff_s::E_ShenequipEquip_s, EOT_CONST_SHENEQUIP_EQUIP_DESC_ID, MAX_SHENEQUIP_EQUIP_NUM>
{
public:
	ShenequipEquipDesc();
	virtual ~ShenequipEquipDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
