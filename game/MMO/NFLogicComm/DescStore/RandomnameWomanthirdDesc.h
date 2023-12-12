#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Randomname_s.h"

#define MAX_RANDOMNAME_WOMANTHIRD_NUM 512

class RandomnameWomanthirdDesc : public NFIDescTemplate<RandomnameWomanthirdDesc, proto_ff_s::E_RandomnameWomanthird_s, EOT_CONST_RANDOMNAME_WOMANTHIRD_DESC_ID, MAX_RANDOMNAME_WOMANTHIRD_NUM>
{
public:
	RandomnameWomanthirdDesc();
	virtual ~RandomnameWomanthirdDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
