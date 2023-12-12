#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragon_s.h"

#define MAX_DRAGON_STARVALUE_NUM 2048

class DragonStarvalueDesc : public NFIDescTemplate<DragonStarvalueDesc, proto_ff_s::E_DragonStarvalue_s, EOT_CONST_DRAGON_STARVALUE_DESC_ID, MAX_DRAGON_STARVALUE_NUM>
{
public:
	DragonStarvalueDesc();
	virtual ~DragonStarvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
