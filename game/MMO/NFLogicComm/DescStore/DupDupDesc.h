#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_DUP_NUM 2048

class DupDupDesc : public NFIDescTemplate<DupDupDesc, proto_ff_s::E_DupDup_s, EOT_CONST_DUP_DUP_DESC_ID, MAX_DUP_DUP_NUM>
{
public:
	DupDupDesc();
	virtual ~DupDupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
