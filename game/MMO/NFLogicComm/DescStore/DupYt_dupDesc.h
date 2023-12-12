#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_YT_DUP_NUM 1024

class DupYt_dupDesc : public NFIDescTemplate<DupYt_dupDesc, proto_ff_s::E_DupYt_dup_s, EOT_CONST_DUP_YT_DUP_DESC_ID, MAX_DUP_YT_DUP_NUM>
{
public:
	DupYt_dupDesc();
	virtual ~DupYt_dupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
