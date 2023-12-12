#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_MATCHTIMESREWARD_NUM 8

class TianxiafirstMatchtimesrewardDesc : public NFIDescTemplate<TianxiafirstMatchtimesrewardDesc, proto_ff_s::E_TianxiafirstMatchtimesreward_s, EOT_CONST_TIANXIAFIRST_MATCHTIMESREWARD_DESC_ID, MAX_TIANXIAFIRST_MATCHTIMESREWARD_NUM>
{
public:
	TianxiafirstMatchtimesrewardDesc();
	virtual ~TianxiafirstMatchtimesrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
