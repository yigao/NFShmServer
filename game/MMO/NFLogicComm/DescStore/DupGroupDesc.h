#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_GROUP_NUM 64

class DupGroupDesc : public NFIDescTemplate<DupGroupDesc, proto_ff_s::E_DupGroup_s, EOT_CONST_DUP_GROUP_DESC_ID, MAX_DUP_GROUP_NUM>
{
public:
	DupGroupDesc();
	virtual ~DupGroupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
