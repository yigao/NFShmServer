#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_CLEAR_NUM 16

class EquipClearDesc : public NFIDescTemplate<EquipClearDesc, proto_ff_s::E_EquipClear_s, EOT_CONST_EQUIP_CLEAR_DESC_ID, MAX_EQUIP_CLEAR_NUM>
{
public:
	EquipClearDesc();
	virtual ~EquipClearDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
