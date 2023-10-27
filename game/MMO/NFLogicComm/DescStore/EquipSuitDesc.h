#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_SUIT_NUM 64

class EquipSuitDesc : public NFIDescTemplate<EquipSuitDesc, proto_ff_s::E_EquipSuit_s, EOT_CONST_EQUIP_SUIT_DESC_ID, MAX_EQUIP_SUIT_NUM>
{
public:
	EquipSuitDesc();
	virtual ~EquipSuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
