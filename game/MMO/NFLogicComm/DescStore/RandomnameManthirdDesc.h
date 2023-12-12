#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Randomname_s.h"

#define MAX_RANDOMNAME_MANTHIRD_NUM 1024

class RandomnameManthirdDesc : public NFIDescTemplate<RandomnameManthirdDesc, proto_ff_s::E_RandomnameManthird_s, EOT_CONST_RANDOMNAME_MANTHIRD_DESC_ID, MAX_RANDOMNAME_MANTHIRD_NUM>
{
public:
	RandomnameManthirdDesc();
	virtual ~RandomnameManthirdDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
