#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_STOVEATT_NUM 2048

class EquipStoveattDesc : public NFIDescTemplate<EquipStoveattDesc, proto_ff_s::E_EquipStoveatt_s, EOT_CONST_EQUIP_STOVEATT_DESC_ID, MAX_EQUIP_STOVEATT_NUM>
{
public:
	EquipStoveattDesc();
	virtual ~EquipStoveattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
