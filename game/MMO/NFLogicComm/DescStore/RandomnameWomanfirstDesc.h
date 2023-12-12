#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Randomname_s.h"

#define MAX_RANDOMNAME_WOMANFIRST_NUM 256

class RandomnameWomanfirstDesc : public NFIDescTemplate<RandomnameWomanfirstDesc, proto_ff_s::E_RandomnameWomanfirst_s, EOT_CONST_RANDOMNAME_WOMANFIRST_DESC_ID, MAX_RANDOMNAME_WOMANFIRST_NUM>
{
public:
	RandomnameWomanfirstDesc();
	virtual ~RandomnameWomanfirstDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
