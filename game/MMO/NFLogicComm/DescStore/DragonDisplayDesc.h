#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragon_s.h"

#define MAX_DRAGON_DISPLAY_NUM 32

class DragonDisplayDesc : public NFIDescTemplate<DragonDisplayDesc, proto_ff_s::E_DragonDisplay_s, EOT_CONST_DRAGON_DISPLAY_DESC_ID, MAX_DRAGON_DISPLAY_NUM>
{
public:
	DragonDisplayDesc();
	virtual ~DragonDisplayDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
