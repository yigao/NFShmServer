#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_EQUIPVALUE_NUM 64

class AncientgodEquipvalueDesc : public NFIDescTemplate<AncientgodEquipvalueDesc, proto_ff_s::E_AncientgodEquipvalue_s, EOT_CONST_ANCIENTGOD_EQUIPVALUE_DESC_ID, MAX_ANCIENTGOD_EQUIPVALUE_NUM>
{
public:
	AncientgodEquipvalueDesc();
	virtual ~AncientgodEquipvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
