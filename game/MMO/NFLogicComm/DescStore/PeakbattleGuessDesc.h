#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Peakbattle_s.h"

#define MAX_PEAKBATTLE_GUESS_NUM 4

class PeakbattleGuessDesc : public NFIDescTemplate<PeakbattleGuessDesc, proto_ff_s::E_PeakbattleGuess_s, EOT_CONST_PEAKBATTLE_GUESS_DESC_ID, MAX_PEAKBATTLE_GUESS_NUM>
{
public:
	PeakbattleGuessDesc();
	virtual ~PeakbattleGuessDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
