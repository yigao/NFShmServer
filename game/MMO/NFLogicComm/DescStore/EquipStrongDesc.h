#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_STRONG_NUM 2048

class EquipStrongDesc : public NFIDescTemplate<EquipStrongDesc, proto_ff_s::E_EquipStrong_s, EOT_CONST_EQUIP_STRONG_DESC_ID, MAX_EQUIP_STRONG_NUM>
{
public:
	EquipStrongDesc();
	virtual ~EquipStrongDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
