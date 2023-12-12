#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equipimprove_s.h"

#define MAX_EQUIPIMPROVE_SOARING_NUM 32

class EquipimproveSoaringDesc : public NFIDescTemplate<EquipimproveSoaringDesc, proto_ff_s::E_EquipimproveSoaring_s, EOT_CONST_EQUIPIMPROVE_SOARING_DESC_ID, MAX_EQUIPIMPROVE_SOARING_NUM>
{
public:
	EquipimproveSoaringDesc();
	virtual ~EquipimproveSoaringDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
