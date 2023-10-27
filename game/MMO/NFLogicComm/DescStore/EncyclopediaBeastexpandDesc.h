#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_BEASTEXPAND_NUM 8

class EncyclopediaBeastexpandDesc : public NFIDescTemplate<EncyclopediaBeastexpandDesc, proto_ff_s::E_EncyclopediaBeastexpand_s, EOT_CONST_ENCYCLOPEDIA_BEASTEXPAND_DESC_ID, MAX_ENCYCLOPEDIA_BEASTEXPAND_NUM>
{
public:
	EncyclopediaBeastexpandDesc();
	virtual ~EncyclopediaBeastexpandDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
