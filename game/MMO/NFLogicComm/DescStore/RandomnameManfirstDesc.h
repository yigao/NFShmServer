#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Randomname_s.h"

#define MAX_RANDOMNAME_MANFIRST_NUM 64

class RandomnameManfirstDesc : public NFIDescTemplate<RandomnameManfirstDesc, proto_ff_s::E_RandomnameManfirst_s, EOT_CONST_RANDOMNAME_MANFIRST_DESC_ID, MAX_RANDOMNAME_MANFIRST_NUM>
{
public:
	RandomnameManfirstDesc();
	virtual ~RandomnameManfirstDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
