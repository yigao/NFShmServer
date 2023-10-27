#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_BPLEVEL_NUM 1024

class DupBplevelDesc : public NFIDescTemplate<DupBplevelDesc, proto_ff_s::E_DupBplevel_s, EOT_CONST_DUP_BPLEVEL_DESC_ID, MAX_DUP_BPLEVEL_NUM>
{
public:
	DupBplevelDesc();
	virtual ~DupBplevelDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
