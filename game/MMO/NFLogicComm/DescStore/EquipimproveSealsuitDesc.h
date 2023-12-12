#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equipimprove_s.h"

#define MAX_EQUIPIMPROVE_SEALSUIT_NUM 1024

class EquipimproveSealsuitDesc : public NFIDescTemplate<EquipimproveSealsuitDesc, proto_ff_s::E_EquipimproveSealsuit_s, EOT_CONST_EQUIPIMPROVE_SEALSUIT_DESC_ID, MAX_EQUIPIMPROVE_SEALSUIT_NUM>
{
public:
	EquipimproveSealsuitDesc();
	virtual ~EquipimproveSealsuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
