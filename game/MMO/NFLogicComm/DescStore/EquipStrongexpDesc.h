#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_STRONGEXP_NUM 512

class EquipStrongexpDesc : public NFIDescTemplate<EquipStrongexpDesc, proto_ff_s::E_EquipStrongexp_s, EOT_CONST_EQUIP_STRONGEXP_DESC_ID, MAX_EQUIP_STRONGEXP_NUM>
{
public:
	EquipStrongexpDesc();
	virtual ~EquipStrongexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
