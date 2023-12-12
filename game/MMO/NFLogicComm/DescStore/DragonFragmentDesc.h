#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragon_s.h"

#define MAX_DRAGON_FRAGMENT_NUM 16

class DragonFragmentDesc : public NFIDescTemplate<DragonFragmentDesc, proto_ff_s::E_DragonFragment_s, EOT_CONST_DRAGON_FRAGMENT_DESC_ID, MAX_DRAGON_FRAGMENT_NUM>
{
public:
	DragonFragmentDesc();
	virtual ~DragonFragmentDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
