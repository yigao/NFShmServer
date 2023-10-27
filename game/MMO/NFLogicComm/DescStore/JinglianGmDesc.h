#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Jinglian_s.h"

#define MAX_JINGLIAN_GM_NUM 16

class JinglianGmDesc : public NFIDescTemplate<JinglianGmDesc, proto_ff_s::E_JinglianGm_s, EOT_CONST_JINGLIAN_GM_DESC_ID, MAX_JINGLIAN_GM_NUM>
{
public:
	JinglianGmDesc();
	virtual ~JinglianGmDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
