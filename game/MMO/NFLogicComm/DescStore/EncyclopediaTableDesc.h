#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_TABLE_NUM 16

class EncyclopediaTableDesc : public NFIDescTemplate<EncyclopediaTableDesc, proto_ff_s::E_EncyclopediaTable_s, EOT_CONST_ENCYCLOPEDIA_TABLE_DESC_ID, MAX_ENCYCLOPEDIA_TABLE_NUM>
{
public:
	EncyclopediaTableDesc();
	virtual ~EncyclopediaTableDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
