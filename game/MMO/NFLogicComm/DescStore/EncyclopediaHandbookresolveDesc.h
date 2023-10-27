#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_HANDBOOKRESOLVE_NUM 8

class EncyclopediaHandbookresolveDesc : public NFIDescTemplate<EncyclopediaHandbookresolveDesc, proto_ff_s::E_EncyclopediaHandbookresolve_s, EOT_CONST_ENCYCLOPEDIA_HANDBOOKRESOLVE_DESC_ID, MAX_ENCYCLOPEDIA_HANDBOOKRESOLVE_NUM>
{
public:
	EncyclopediaHandbookresolveDesc();
	virtual ~EncyclopediaHandbookresolveDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
