#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_ZYATT_NUM 32

class MofaZyattDesc : public NFIDescTemplate<MofaZyattDesc, proto_ff_s::E_MofaZyatt_s, EOT_CONST_MOFA_ZYATT_DESC_ID, MAX_MOFA_ZYATT_NUM>
{
public:
	MofaZyattDesc();
	virtual ~MofaZyattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
