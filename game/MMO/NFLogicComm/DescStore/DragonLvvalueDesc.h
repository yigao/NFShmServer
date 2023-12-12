#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragon_s.h"

#define MAX_DRAGON_LVVALUE_NUM 1024

class DragonLvvalueDesc : public NFIDescTemplate<DragonLvvalueDesc, proto_ff_s::E_DragonLvvalue_s, EOT_CONST_DRAGON_LVVALUE_DESC_ID, MAX_DRAGON_LVVALUE_NUM>
{
public:
	DragonLvvalueDesc();
	virtual ~DragonLvvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
