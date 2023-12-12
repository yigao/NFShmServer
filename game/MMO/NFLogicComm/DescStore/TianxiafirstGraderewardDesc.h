#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_GRADEREWARD_NUM 8

class TianxiafirstGraderewardDesc : public NFIDescTemplate<TianxiafirstGraderewardDesc, proto_ff_s::E_TianxiafirstGradereward_s, EOT_CONST_TIANXIAFIRST_GRADEREWARD_DESC_ID, MAX_TIANXIAFIRST_GRADEREWARD_NUM>
{
public:
	TianxiafirstGraderewardDesc();
	virtual ~TianxiafirstGraderewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
