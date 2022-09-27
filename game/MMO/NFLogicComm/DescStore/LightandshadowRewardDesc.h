#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/lightAndShadow_s.h"

#define MAX_LIGHTANDSHADOW_REWARD_NUM 20

class LightandshadowRewardDesc : public NFIDescStore
{
public:
	LightandshadowRewardDesc(NFIPluginManager* pPluginManager);
	virtual ~LightandshadowRewardDesc();
	const proto_ff_s::lightAndShadowreward_s* GetDesc(int id) const;
	proto_ff_s::lightAndShadowreward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::lightAndShadowreward_s, MAX_LIGHTANDSHADOW_REWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::lightAndShadowreward_s, MAX_LIGHTANDSHADOW_REWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::lightAndShadowreward_s, lightAndShadowreward, MAX_LIGHTANDSHADOW_REWARD_NUM);
DECLARE_IDCREATE(LightandshadowRewardDesc);
};
