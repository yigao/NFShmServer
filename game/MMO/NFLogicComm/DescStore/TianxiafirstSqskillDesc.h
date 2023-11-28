#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_SQSKILL_NUM 64

class TianxiafirstSqskillDesc : public NFIDescTemplate<TianxiafirstSqskillDesc, proto_ff_s::E_TianxiafirstSqskill_s, EOT_CONST_TIANXIAFIRST_SQSKILL_DESC_ID, MAX_TIANXIAFIRST_SQSKILL_NUM>
{
public:
	TianxiafirstSqskillDesc();
	virtual ~TianxiafirstSqskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
