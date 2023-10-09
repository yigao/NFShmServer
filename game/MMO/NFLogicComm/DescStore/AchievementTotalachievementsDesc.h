#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Achievement_s.h"

#define MAX_ACHIEVEMENT_TOTALACHIEVEMENTS_NUM 16

class AchievementTotalachievementsDesc : public NFIDescStore
{
public:
	AchievementTotalachievementsDesc();
	virtual ~AchievementTotalachievementsDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AchievementTotalachievements_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AchievementTotalachievements_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AchievementTotalachievements_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AchievementTotalachievements_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AchievementTotalachievementsDesc, proto_ff_s::E_AchievementTotalachievements_s, E_AchievementTotalachievements, MAX_ACHIEVEMENT_TOTALACHIEVEMENTS_NUM);
DECLARE_IDCREATE(AchievementTotalachievementsDesc);
};
