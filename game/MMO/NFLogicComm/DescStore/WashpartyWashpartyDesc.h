#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Washparty_s.h"

#define MAX_WASHPARTY_WASHPARTY_NUM 16

class WashpartyWashpartyDesc : public NFIDescTemplate<WashpartyWashpartyDesc, proto_ff_s::E_WashpartyWashparty_s, EOT_CONST_WASHPARTY_WASHPARTY_DESC_ID, MAX_WASHPARTY_WASHPARTY_NUM>
{
public:
	WashpartyWashpartyDesc();
	virtual ~WashpartyWashpartyDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
