#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Randomname_s.h"

#define MAX_RANDOMNAME_WOMANSECOND_NUM 128

class RandomnameWomansecondDesc : public NFIDescTemplate<RandomnameWomansecondDesc, proto_ff_s::E_RandomnameWomansecond_s, EOT_CONST_RANDOMNAME_WOMANSECOND_DESC_ID, MAX_RANDOMNAME_WOMANSECOND_NUM>
{
public:
	RandomnameWomansecondDesc();
	virtual ~RandomnameWomansecondDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
