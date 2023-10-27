#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_EQUIPEXPVALUE_NUM 64

class EncyclopediaEquipexpvalueDesc : public NFIDescTemplate<EncyclopediaEquipexpvalueDesc, proto_ff_s::E_EncyclopediaEquipexpvalue_s, EOT_CONST_ENCYCLOPEDIA_EQUIPEXPVALUE_DESC_ID, MAX_ENCYCLOPEDIA_EQUIPEXPVALUE_NUM>
{
public:
	EncyclopediaEquipexpvalueDesc();
	virtual ~EncyclopediaEquipexpvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
