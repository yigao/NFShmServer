#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_STOVEEXP_NUM 128

class EquipStoveexpDesc : public NFIDescTemplate<EquipStoveexpDesc, proto_ff_s::E_EquipStoveexp_s, EOT_CONST_EQUIP_STOVEEXP_DESC_ID, MAX_EQUIP_STOVEEXP_NUM>
{
public:
	EquipStoveexpDesc();
	virtual ~EquipStoveexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
