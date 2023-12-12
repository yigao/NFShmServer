#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_BEASTSTRONG_NUM 128

class EquipBeaststrongDesc : public NFIDescTemplate<EquipBeaststrongDesc, proto_ff_s::E_EquipBeaststrong_s, EOT_CONST_EQUIP_BEASTSTRONG_DESC_ID, MAX_EQUIP_BEASTSTRONG_NUM>
{
public:
	EquipBeaststrongDesc();
	virtual ~EquipBeaststrongDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
