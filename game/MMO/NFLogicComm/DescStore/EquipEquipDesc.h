#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_EQUIP_NUM 16384

class EquipEquipDesc : public NFIDescTemplate<EquipEquipDesc, proto_ff_s::E_EquipEquip_s, EOT_CONST_EQUIP_EQUIP_DESC_ID, MAX_EQUIP_EQUIP_NUM>
{
public:
	EquipEquipDesc();
	virtual ~EquipEquipDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
