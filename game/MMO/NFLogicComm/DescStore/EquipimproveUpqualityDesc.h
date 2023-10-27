#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equipimprove_s.h"

#define MAX_EQUIPIMPROVE_UPQUALITY_NUM 128

class EquipimproveUpqualityDesc : public NFIDescTemplate<EquipimproveUpqualityDesc, proto_ff_s::E_EquipimproveUpquality_s, EOT_CONST_EQUIPIMPROVE_UPQUALITY_DESC_ID, MAX_EQUIPIMPROVE_UPQUALITY_NUM>
{
public:
	EquipimproveUpqualityDesc();
	virtual ~EquipimproveUpqualityDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
