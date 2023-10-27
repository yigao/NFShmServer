#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Washparty_s.h"

#define MAX_WASHPARTY_EXP_NUM 512

class WashpartyExpDesc : public NFIDescTemplate<WashpartyExpDesc, proto_ff_s::E_WashpartyExp_s, EOT_CONST_WASHPARTY_EXP_DESC_ID, MAX_WASHPARTY_EXP_NUM>
{
public:
	WashpartyExpDesc();
	virtual ~WashpartyExpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
