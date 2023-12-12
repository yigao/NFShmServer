#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equipimprove_s.h"

#define MAX_EQUIPIMPROVE_SEAL_NUM 16

class EquipimproveSealDesc : public NFIDescTemplate<EquipimproveSealDesc, proto_ff_s::E_EquipimproveSeal_s, EOT_CONST_EQUIPIMPROVE_SEAL_DESC_ID, MAX_EQUIPIMPROVE_SEAL_NUM>
{
public:
	EquipimproveSealDesc();
	virtual ~EquipimproveSealDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
