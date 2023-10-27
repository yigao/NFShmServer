#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Sensitiveword_s.h"

#define MAX_SENSITIVEWORD_WORD1_NUM 32768

class SensitivewordWord1Desc : public NFIDescTemplate<SensitivewordWord1Desc, proto_ff_s::E_SensitivewordWord1_s, EOT_CONST_SENSITIVEWORD_WORD1_DESC_ID, MAX_SENSITIVEWORD_WORD1_NUM>
{
public:
	SensitivewordWord1Desc();
	virtual ~SensitivewordWord1Desc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
