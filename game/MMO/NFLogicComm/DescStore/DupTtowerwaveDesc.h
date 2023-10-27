#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_TTOWERWAVE_NUM 1024

class DupTtowerwaveDesc : public NFIDescTemplate<DupTtowerwaveDesc, proto_ff_s::E_DupTtowerwave_s, EOT_CONST_DUP_TTOWERWAVE_DESC_ID, MAX_DUP_TTOWERWAVE_NUM>
{
public:
	DupTtowerwaveDesc();
	virtual ~DupTtowerwaveDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
