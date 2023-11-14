#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_STRONGITEM_NUM 2

class TianxiafirstStrongitemDesc : public NFIDescTemplate<TianxiafirstStrongitemDesc, proto_ff_s::E_TianxiafirstStrongitem_s, EOT_CONST_TIANXIAFIRST_STRONGITEM_DESC_ID, MAX_TIANXIAFIRST_STRONGITEM_NUM>
{
public:
	TianxiafirstStrongitemDesc();
	virtual ~TianxiafirstStrongitemDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
