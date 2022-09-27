#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/getTreasure_s.h"

#define MAX_GETTREASURE_BOSS_NUM 800

class GettreasureBossDesc : public NFIDescStore
{
public:
	GettreasureBossDesc(NFIPluginManager* pPluginManager);
	virtual ~GettreasureBossDesc();
	const proto_ff_s::getTreasureboss_s* GetDesc(int id) const;
	proto_ff_s::getTreasureboss_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::getTreasureboss_s, MAX_GETTREASURE_BOSS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::getTreasureboss_s, MAX_GETTREASURE_BOSS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::getTreasureboss_s, getTreasureboss, MAX_GETTREASURE_BOSS_NUM);
DECLARE_IDCREATE(GettreasureBossDesc);
};
