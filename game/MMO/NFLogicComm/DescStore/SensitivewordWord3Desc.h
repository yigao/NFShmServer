#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Sensitiveword_s.h"

#define MAX_SENSITIVEWORD_WORD3_NUM 32768

class SensitivewordWord3Desc : public NFIDescTemplate<SensitivewordWord3Desc, proto_ff_s::E_SensitivewordWord3_s, EOT_CONST_SENSITIVEWORD_WORD3_DESC_ID, MAX_SENSITIVEWORD_WORD3_NUM>
{
public:
	SensitivewordWord3Desc();
	virtual ~SensitivewordWord3Desc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
