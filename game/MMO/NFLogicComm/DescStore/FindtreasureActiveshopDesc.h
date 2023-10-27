#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_ACTIVESHOP_NUM 4

class FindtreasureActiveshopDesc : public NFIDescTemplate<FindtreasureActiveshopDesc, proto_ff_s::E_FindtreasureActiveshop_s, EOT_CONST_FINDTREASURE_ACTIVESHOP_DESC_ID, MAX_FINDTREASURE_ACTIVESHOP_NUM>
{
public:
	FindtreasureActiveshopDesc();
	virtual ~FindtreasureActiveshopDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
