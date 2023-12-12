#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_REFINE_NUM 128

class TianxiafirstRefineDesc : public NFIDescTemplate<TianxiafirstRefineDesc, proto_ff_s::E_TianxiafirstRefine_s, EOT_CONST_TIANXIAFIRST_REFINE_DESC_ID, MAX_TIANXIAFIRST_REFINE_NUM>
{
public:
	TianxiafirstRefineDesc();
	virtual ~TianxiafirstRefineDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
