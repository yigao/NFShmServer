#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Randomname_s.h"

#define MAX_RANDOMNAME_MANSECOND_NUM 64

class RandomnameMansecondDesc : public NFIDescTemplate<RandomnameMansecondDesc, proto_ff_s::E_RandomnameMansecond_s, EOT_CONST_RANDOMNAME_MANSECOND_DESC_ID, MAX_RANDOMNAME_MANSECOND_NUM>
{
public:
	RandomnameMansecondDesc();
	virtual ~RandomnameMansecondDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
