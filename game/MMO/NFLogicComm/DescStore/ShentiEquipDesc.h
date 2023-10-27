#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_EQUIP_NUM 1024

class ShentiEquipDesc : public NFIDescTemplate<ShentiEquipDesc, proto_ff_s::E_ShentiEquip_s, EOT_CONST_SHENTI_EQUIP_DESC_ID, MAX_SHENTI_EQUIP_NUM>
{
public:
	ShentiEquipDesc();
	virtual ~ShentiEquipDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
