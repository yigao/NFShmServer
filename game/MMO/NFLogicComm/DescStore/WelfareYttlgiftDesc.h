#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_YTTLGIFT_NUM 4

class WelfareYttlgiftDesc : public NFIDescTemplate<WelfareYttlgiftDesc, proto_ff_s::E_WelfareYttlgift_s, EOT_CONST_WELFARE_YTTLGIFT_DESC_ID, MAX_WELFARE_YTTLGIFT_NUM>
{
public:
	WelfareYttlgiftDesc();
	virtual ~WelfareYttlgiftDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
