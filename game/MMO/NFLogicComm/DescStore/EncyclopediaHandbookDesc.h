#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_HANDBOOK_NUM 512

class EncyclopediaHandbookDesc : public NFIDescTemplate<EncyclopediaHandbookDesc, proto_ff_s::E_EncyclopediaHandbook_s, EOT_CONST_ENCYCLOPEDIA_HANDBOOK_DESC_ID, MAX_ENCYCLOPEDIA_HANDBOOK_NUM>
{
public:
	EncyclopediaHandbookDesc();
	virtual ~EncyclopediaHandbookDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
