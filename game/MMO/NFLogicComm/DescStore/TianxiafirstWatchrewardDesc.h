#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_WATCHREWARD_NUM 8

class TianxiafirstWatchrewardDesc : public NFIDescTemplate<TianxiafirstWatchrewardDesc, proto_ff_s::E_TianxiafirstWatchreward_s, EOT_CONST_TIANXIAFIRST_WATCHREWARD_DESC_ID, MAX_TIANXIAFIRST_WATCHREWARD_NUM>
{
public:
	TianxiafirstWatchrewardDesc();
	virtual ~TianxiafirstWatchrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
