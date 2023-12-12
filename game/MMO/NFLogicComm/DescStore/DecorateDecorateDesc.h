#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Decorate_s.h"

#define MAX_DECORATE_DECORATE_NUM 64

class DecorateDecorateDesc : public NFIDescTemplate<DecorateDecorateDesc, proto_ff_s::E_DecorateDecorate_s, EOT_CONST_DECORATE_DECORATE_DESC_ID, MAX_DECORATE_DECORATE_NUM>
{
public:
	DecorateDecorateDesc();
	virtual ~DecorateDecorateDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
