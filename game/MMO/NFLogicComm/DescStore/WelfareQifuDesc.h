#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_QIFU_NUM 16

class WelfareQifuDesc : public NFIDescTemplate<WelfareQifuDesc, proto_ff_s::E_WelfareQifu_s, EOT_CONST_WELFARE_QIFU_DESC_ID, MAX_WELFARE_QIFU_NUM>
{
public:
	WelfareQifuDesc();
	virtual ~WelfareQifuDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
