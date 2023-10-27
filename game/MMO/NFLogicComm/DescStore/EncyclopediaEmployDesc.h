#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_EMPLOY_NUM 128

class EncyclopediaEmployDesc : public NFIDescTemplate<EncyclopediaEmployDesc, proto_ff_s::E_EncyclopediaEmploy_s, EOT_CONST_ENCYCLOPEDIA_EMPLOY_DESC_ID, MAX_ENCYCLOPEDIA_EMPLOY_NUM>
{
public:
	EncyclopediaEmployDesc();
	virtual ~EncyclopediaEmployDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
