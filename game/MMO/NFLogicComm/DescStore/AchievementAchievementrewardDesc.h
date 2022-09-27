#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/achievement_s.h"

#define MAX_ACHIEVEMENT_ACHIEVEMENTREWARD_NUM 20

class AchievementAchievementrewardDesc : public NFIDescStore
{
public:
	AchievementAchievementrewardDesc(NFIPluginManager* pPluginManager);
	virtual ~AchievementAchievementrewardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::achievementachievementreward_s* GetDesc(int id) const;
	proto_ff_s::achievementachievementreward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::achievementachievementreward_s, MAX_ACHIEVEMENT_ACHIEVEMENTREWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::achievementachievementreward_s, MAX_ACHIEVEMENT_ACHIEVEMENTREWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::achievementachievementreward_s, achievementachievementreward, MAX_ACHIEVEMENT_ACHIEVEMENTREWARD_NUM);
DECLARE_IDCREATE(AchievementAchievementrewardDesc);
};
