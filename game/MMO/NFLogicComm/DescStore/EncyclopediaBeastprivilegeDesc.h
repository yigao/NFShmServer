#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_BEASTPRIVILEGE_NUM 4

class EncyclopediaBeastprivilegeDesc : public NFIDescTemplate<EncyclopediaBeastprivilegeDesc, proto_ff_s::E_EncyclopediaBeastprivilege_s, EOT_CONST_ENCYCLOPEDIA_BEASTPRIVILEGE_DESC_ID, MAX_ENCYCLOPEDIA_BEASTPRIVILEGE_NUM>
{
public:
	EncyclopediaBeastprivilegeDesc();
	virtual ~EncyclopediaBeastprivilegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
