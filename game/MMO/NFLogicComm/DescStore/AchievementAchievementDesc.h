#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Achievement_s.h"

#define MAX_ACHIEVEMENT_ACHIEVEMENT_NUM 256

class AchievementAchievementDesc : public NFIDescTemplate<AchievementAchievementDesc, proto_ff_s::E_AchievementAchievement_s, EOT_CONST_ACHIEVEMENT_ACHIEVEMENT_DESC_ID, MAX_ACHIEVEMENT_ACHIEVEMENT_NUM>
{
public:
	AchievementAchievementDesc();
	virtual ~AchievementAchievementDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
