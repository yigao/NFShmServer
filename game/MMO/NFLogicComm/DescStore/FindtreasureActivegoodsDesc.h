#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_ACTIVEGOODS_NUM 4

class FindtreasureActivegoodsDesc : public NFIDescTemplate<FindtreasureActivegoodsDesc, proto_ff_s::E_FindtreasureActivegoods_s, EOT_CONST_FINDTREASURE_ACTIVEGOODS_DESC_ID, MAX_FINDTREASURE_ACTIVEGOODS_NUM>
{
public:
	FindtreasureActivegoodsDesc();
	virtual ~FindtreasureActivegoodsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
