#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_LUCKYREWARD_NUM 8

class TianxiafirstLuckyrewardDesc : public NFIDescTemplate<TianxiafirstLuckyrewardDesc, proto_ff_s::E_TianxiafirstLuckyreward_s, EOT_CONST_TIANXIAFIRST_LUCKYREWARD_DESC_ID, MAX_TIANXIAFIRST_LUCKYREWARD_NUM>
{
public:
	TianxiafirstLuckyrewardDesc();
	virtual ~TianxiafirstLuckyrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
