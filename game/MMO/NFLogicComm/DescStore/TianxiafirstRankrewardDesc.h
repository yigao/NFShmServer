#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_RANKREWARD_NUM 32

class TianxiafirstRankrewardDesc : public NFIDescTemplate<TianxiafirstRankrewardDesc, proto_ff_s::E_TianxiafirstRankreward_s, EOT_CONST_TIANXIAFIRST_RANKREWARD_DESC_ID, MAX_TIANXIAFIRST_RANKREWARD_NUM>
{
public:
	TianxiafirstRankrewardDesc();
	virtual ~TianxiafirstRankrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
