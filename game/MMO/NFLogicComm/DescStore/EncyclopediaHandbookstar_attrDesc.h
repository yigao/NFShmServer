#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_HANDBOOKSTAR_ATTR_NUM 256

class EncyclopediaHandbookstar_attrDesc : public NFIDescTemplate<EncyclopediaHandbookstar_attrDesc, proto_ff_s::E_EncyclopediaHandbookstar_attr_s, EOT_CONST_ENCYCLOPEDIA_HANDBOOKSTAR_ATTR_DESC_ID, MAX_ENCYCLOPEDIA_HANDBOOKSTAR_ATTR_NUM>
{
public:
	EncyclopediaHandbookstar_attrDesc();
	virtual ~EncyclopediaHandbookstar_attrDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
