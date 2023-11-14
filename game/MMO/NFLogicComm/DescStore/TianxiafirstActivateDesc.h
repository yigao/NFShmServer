#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_ACTIVATE_NUM 16

class TianxiafirstActivateDesc : public NFIDescTemplate<TianxiafirstActivateDesc, proto_ff_s::E_TianxiafirstActivate_s, EOT_CONST_TIANXIAFIRST_ACTIVATE_DESC_ID, MAX_TIANXIAFIRST_ACTIVATE_NUM>
{
public:
	TianxiafirstActivateDesc();
	virtual ~TianxiafirstActivateDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
