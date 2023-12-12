#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Achievement_s.h"

#define MAX_ACHIEVEMENT_TOTALACHIEVEMENTS_NUM 64

class AchievementTotalachievementsDesc : public NFIDescTemplate<AchievementTotalachievementsDesc, proto_ff_s::E_AchievementTotalachievements_s, EOT_CONST_ACHIEVEMENT_TOTALACHIEVEMENTS_DESC_ID, MAX_ACHIEVEMENT_TOTALACHIEVEMENTS_NUM>
{
public:
	AchievementTotalachievementsDesc();
	virtual ~AchievementTotalachievementsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
