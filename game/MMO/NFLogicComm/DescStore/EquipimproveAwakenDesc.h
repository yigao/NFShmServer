#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equipimprove_s.h"

#define MAX_EQUIPIMPROVE_AWAKEN_NUM 512

class EquipimproveAwakenDesc : public NFIDescTemplate<EquipimproveAwakenDesc, proto_ff_s::E_EquipimproveAwaken_s, EOT_CONST_EQUIPIMPROVE_AWAKEN_DESC_ID, MAX_EQUIPIMPROVE_AWAKEN_NUM>
{
public:
	EquipimproveAwakenDesc();
	virtual ~EquipimproveAwakenDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
