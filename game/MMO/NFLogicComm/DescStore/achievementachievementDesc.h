// -------------------------------------------------------------------------
//    @FileName         :    NFConstDesc.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFConstDesc.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/achievement_s.h"

#define MAX_achievementachievement_NUM 1000

class achievementachievementDesc : public NFIDescStore
{
public:
	achievementachievementDesc(NFIPluginManager* pPluginManager);
    virtual ~achievementachievementDesc();
    int CreateInit();
    int ResumeInit();
    const proto_ff_s::achievementachievement_s* GetDesc(int id) const;
    proto_ff_s::achievementachievement_s* GetDesc(int id);
public:
    IMPL_RES_HASH_DESC(proto_ff_s::achievementachievement_s, achievementachievement, MAX_achievementachievement_NUM);
	DECLARE_IDCREATE(achievementachievementDesc);
};
