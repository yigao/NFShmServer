#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Meditation_s.h"

#define MAX_MEDITATION_MEDITATION_NUM 16

class MeditationMeditationDesc : public NFIDescTemplate<MeditationMeditationDesc, proto_ff_s::E_MeditationMeditation_s, EOT_CONST_MEDITATION_MEDITATION_DESC_ID, MAX_MEDITATION_MEDITATION_NUM>
{
public:
	MeditationMeditationDesc();
	virtual ~MeditationMeditationDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
