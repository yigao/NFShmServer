#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_STRONG_NUM 8

class TianxiafirstStrongDesc : public NFIDescTemplate<TianxiafirstStrongDesc, proto_ff_s::E_TianxiafirstStrong_s, EOT_CONST_TIANXIAFIRST_STRONG_DESC_ID, MAX_TIANXIAFIRST_STRONG_NUM>
{
public:
	TianxiafirstStrongDesc();
	virtual ~TianxiafirstStrongDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
