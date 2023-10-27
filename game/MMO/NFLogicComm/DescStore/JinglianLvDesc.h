#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Jinglian_s.h"

#define MAX_JINGLIAN_LV_NUM 1024

class JinglianLvDesc : public NFIDescTemplate<JinglianLvDesc, proto_ff_s::E_JinglianLv_s, EOT_CONST_JINGLIAN_LV_DESC_ID, MAX_JINGLIAN_LV_NUM>
{
public:
	JinglianLvDesc();
	virtual ~JinglianLvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
