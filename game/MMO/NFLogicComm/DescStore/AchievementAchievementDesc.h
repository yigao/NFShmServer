#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/achievement_s.h"

#define MAX_ACHIEVEMENT_ACHIEVEMENT_NUM 400

class AchievementAchievementDesc : public NFIDescStore
{
public:
	AchievementAchievementDesc(NFIPluginManager* pPluginManager);
	virtual ~AchievementAchievementDesc();
	const proto_ff_s::achievementachievement_s* GetDesc(int id) const;
	proto_ff_s::achievementachievement_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::achievementachievement_s, MAX_ACHIEVEMENT_ACHIEVEMENT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::achievementachievement_s, MAX_ACHIEVEMENT_ACHIEVEMENT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::achievementachievement_s, achievementachievement, MAX_ACHIEVEMENT_ACHIEVEMENT_NUM);
DECLARE_IDCREATE(AchievementAchievementDesc);
};
