#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_BREAK_NUM 32

class EquipBreakDesc : public NFIDescTemplate<EquipBreakDesc, proto_ff_s::E_EquipBreak_s, EOT_CONST_EQUIP_BREAK_DESC_ID, MAX_EQUIP_BREAK_NUM>
{
public:
	EquipBreakDesc();
	virtual ~EquipBreakDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
