#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_BEAST_NUM 32

class EncyclopediaBeastDesc : public NFIDescTemplate<EncyclopediaBeastDesc, proto_ff_s::E_EncyclopediaBeast_s, EOT_CONST_ENCYCLOPEDIA_BEAST_DESC_ID, MAX_ENCYCLOPEDIA_BEAST_NUM>
{
public:
	EncyclopediaBeastDesc();
	virtual ~EncyclopediaBeastDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
