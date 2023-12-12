#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Peakbattle_s.h"

#define MAX_PEAKBATTLE_CONSTANT_NUM 2

class PeakbattleConstantDesc : public NFIDescTemplate<PeakbattleConstantDesc, proto_ff_s::E_PeakbattleConstant_s, EOT_CONST_PEAKBATTLE_CONSTANT_DESC_ID, MAX_PEAKBATTLE_CONSTANT_NUM>
{
public:
	PeakbattleConstantDesc();
	virtual ~PeakbattleConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
