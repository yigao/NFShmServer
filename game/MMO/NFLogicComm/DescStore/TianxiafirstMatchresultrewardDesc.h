#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_MATCHRESULTREWARD_NUM 8

class TianxiafirstMatchresultrewardDesc : public NFIDescTemplate<TianxiafirstMatchresultrewardDesc, proto_ff_s::E_TianxiafirstMatchresultreward_s, EOT_CONST_TIANXIAFIRST_MATCHRESULTREWARD_DESC_ID, MAX_TIANXIAFIRST_MATCHRESULTREWARD_NUM>
{
public:
	TianxiafirstMatchresultrewardDesc();
	virtual ~TianxiafirstMatchresultrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
