#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Sensitiveword_s.h"

#define MAX_SENSITIVEWORD_WORD2_NUM 32768

class SensitivewordWord2Desc : public NFIDescTemplate<SensitivewordWord2Desc, proto_ff_s::E_SensitivewordWord2_s, EOT_CONST_SENSITIVEWORD_WORD2_DESC_ID, MAX_SENSITIVEWORD_WORD2_NUM>
{
public:
	SensitivewordWord2Desc();
	virtual ~SensitivewordWord2Desc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
