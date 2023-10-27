#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_ATTRIBUTE_NUM 16384

class EquipAttributeDesc : public NFIDescTemplate<EquipAttributeDesc, proto_ff_s::E_EquipAttribute_s, EOT_CONST_EQUIP_ATTRIBUTE_DESC_ID, MAX_EQUIP_ATTRIBUTE_NUM>
{
public:
	EquipAttributeDesc();
	virtual ~EquipAttributeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
