#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equipimprove_s.h"

#define MAX_EQUIPIMPROVE_SEALSLOT_NUM 64

class EquipimproveSealslotDesc : public NFIDescTemplate<EquipimproveSealslotDesc, proto_ff_s::E_EquipimproveSealslot_s, EOT_CONST_EQUIPIMPROVE_SEALSLOT_DESC_ID, MAX_EQUIPIMPROVE_SEALSLOT_NUM>
{
public:
	EquipimproveSealslotDesc();
	virtual ~EquipimproveSealslotDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
