#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Back_s.h"

#define MAX_BACK_BACK_NUM 64

class BackBackDesc : public NFIDescTemplate<BackBackDesc, proto_ff_s::E_BackBack_s, EOT_CONST_BACK_BACK_DESC_ID, MAX_BACK_BACK_NUM>
{
public:
	BackBackDesc();
	virtual ~BackBackDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
