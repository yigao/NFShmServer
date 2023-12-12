#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_GEMLV_NUM 512

class EquipGemlvDesc : public NFIDescTemplate<EquipGemlvDesc, proto_ff_s::E_EquipGemlv_s, EOT_CONST_EQUIP_GEMLV_DESC_ID, MAX_EQUIP_GEMLV_NUM>
{
public:
	EquipGemlvDesc();
	virtual ~EquipGemlvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
