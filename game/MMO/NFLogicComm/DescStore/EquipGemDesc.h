#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_GEM_NUM 16

class EquipGemDesc : public NFIDescTemplate<EquipGemDesc, proto_ff_s::E_EquipGem_s, EOT_CONST_EQUIP_GEM_DESC_ID, MAX_EQUIP_GEM_NUM>
{
public:
	EquipGemDesc();
	virtual ~EquipGemDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
