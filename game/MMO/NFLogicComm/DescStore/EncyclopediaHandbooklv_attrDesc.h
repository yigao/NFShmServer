#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_HANDBOOKLV_ATTR_NUM 256

class EncyclopediaHandbooklv_attrDesc : public NFIDescTemplate<EncyclopediaHandbooklv_attrDesc, proto_ff_s::E_EncyclopediaHandbooklv_attr_s, EOT_CONST_ENCYCLOPEDIA_HANDBOOKLV_ATTR_DESC_ID, MAX_ENCYCLOPEDIA_HANDBOOKLV_ATTR_NUM>
{
public:
	EncyclopediaHandbooklv_attrDesc();
	virtual ~EncyclopediaHandbooklv_attrDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
