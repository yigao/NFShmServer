#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk1v1_s.h"

#define MAX_PK1V1_RANK_NUM 64

class Pk1v1RankDesc : public NFIDescTemplate<Pk1v1RankDesc, proto_ff_s::E_Pk1v1Rank_s, EOT_CONST_PK1V1_RANK_DESC_ID, MAX_PK1V1_RANK_NUM>
{
public:
	Pk1v1RankDesc();
	virtual ~Pk1v1RankDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
