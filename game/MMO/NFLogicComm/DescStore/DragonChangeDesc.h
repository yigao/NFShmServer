#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragon_s.h"

#define MAX_DRAGON_CHANGE_NUM 8

class DragonChangeDesc : public NFIDescTemplate<DragonChangeDesc, proto_ff_s::E_DragonChange_s, EOT_CONST_DRAGON_CHANGE_DESC_ID, MAX_DRAGON_CHANGE_NUM>
{
public:
	DragonChangeDesc();
	virtual ~DragonChangeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
