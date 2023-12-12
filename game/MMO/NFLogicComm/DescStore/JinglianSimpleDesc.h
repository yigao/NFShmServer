#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Jinglian_s.h"

#define MAX_JINGLIAN_SIMPLE_NUM 16

class JinglianSimpleDesc : public NFIDescTemplate<JinglianSimpleDesc, proto_ff_s::E_JinglianSimple_s, EOT_CONST_JINGLIAN_SIMPLE_DESC_ID, MAX_JINGLIAN_SIMPLE_NUM>
{
public:
	JinglianSimpleDesc();
	virtual ~JinglianSimpleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
