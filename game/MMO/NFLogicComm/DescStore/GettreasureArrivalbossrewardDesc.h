#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/getTreasure_s.h"

#define MAX_GETTREASURE_ARRIVALBOSSREWARD_NUM 20

class GettreasureArrivalbossrewardDesc : public NFIDescStore
{
public:
	GettreasureArrivalbossrewardDesc(NFIPluginManager* pPluginManager);
	virtual ~GettreasureArrivalbossrewardDesc();
	const proto_ff_s::getTreasureArrivalBossReward_s* GetDesc(int id) const;
	proto_ff_s::getTreasureArrivalBossReward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::getTreasureArrivalBossReward_s, MAX_GETTREASURE_ARRIVALBOSSREWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::getTreasureArrivalBossReward_s, MAX_GETTREASURE_ARRIVALBOSSREWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::getTreasureArrivalBossReward_s, getTreasureArrivalBossReward, MAX_GETTREASURE_ARRIVALBOSSREWARD_NUM);
DECLARE_IDCREATE(GettreasureArrivalbossrewardDesc);
};
