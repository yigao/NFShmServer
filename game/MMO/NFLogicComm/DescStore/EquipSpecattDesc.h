#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_SPECATT_NUM 128

class EquipSpecattDesc : public NFIDescTemplate<EquipSpecattDesc, proto_ff_s::E_EquipSpecatt_s, EOT_CONST_EQUIP_SPECATT_DESC_ID, MAX_EQUIP_SPECATT_NUM>
{
public:
	EquipSpecattDesc();
	virtual ~EquipSpecattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
