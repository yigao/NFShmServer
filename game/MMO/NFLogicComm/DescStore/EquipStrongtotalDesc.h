#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_STRONGTOTAL_NUM 256

class EquipStrongtotalDesc : public NFIDescTemplate<EquipStrongtotalDesc, proto_ff_s::E_EquipStrongtotal_s, EOT_CONST_EQUIP_STRONGTOTAL_DESC_ID, MAX_EQUIP_STRONGTOTAL_NUM>
{
public:
	EquipStrongtotalDesc();
	virtual ~EquipStrongtotalDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
