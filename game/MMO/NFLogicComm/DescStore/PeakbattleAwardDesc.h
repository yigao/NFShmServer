#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Peakbattle_s.h"

#define MAX_PEAKBATTLE_AWARD_NUM 32

class PeakbattleAwardDesc : public NFIDescTemplate<PeakbattleAwardDesc, proto_ff_s::E_PeakbattleAward_s, EOT_CONST_PEAKBATTLE_AWARD_DESC_ID, MAX_PEAKBATTLE_AWARD_NUM>
{
public:
	PeakbattleAwardDesc();
	virtual ~PeakbattleAwardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
