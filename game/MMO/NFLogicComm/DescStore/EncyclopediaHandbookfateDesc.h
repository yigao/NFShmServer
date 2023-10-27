#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_HANDBOOKFATE_NUM 128

class EncyclopediaHandbookfateDesc : public NFIDescTemplate<EncyclopediaHandbookfateDesc, proto_ff_s::E_EncyclopediaHandbookfate_s, EOT_CONST_ENCYCLOPEDIA_HANDBOOKFATE_DESC_ID, MAX_ENCYCLOPEDIA_HANDBOOKFATE_NUM>
{
public:
	EncyclopediaHandbookfateDesc();
	virtual ~EncyclopediaHandbookfateDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
