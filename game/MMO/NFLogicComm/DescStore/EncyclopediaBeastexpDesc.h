#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_BEASTEXP_NUM 256

class EncyclopediaBeastexpDesc : public NFIDescTemplate<EncyclopediaBeastexpDesc, proto_ff_s::E_EncyclopediaBeastexp_s, EOT_CONST_ENCYCLOPEDIA_BEASTEXP_DESC_ID, MAX_ENCYCLOPEDIA_BEASTEXP_NUM>
{
public:
	EncyclopediaBeastexpDesc();
	virtual ~EncyclopediaBeastexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
