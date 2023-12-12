#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Arena_s.h"

#define MAX_ARENA_BUYCHALLENGE_NUM 8

class ArenaBuychallengeDesc : public NFIDescTemplate<ArenaBuychallengeDesc, proto_ff_s::E_ArenaBuychallenge_s, EOT_CONST_ARENA_BUYCHALLENGE_DESC_ID, MAX_ARENA_BUYCHALLENGE_NUM>
{
public:
	ArenaBuychallengeDesc();
	virtual ~ArenaBuychallengeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
