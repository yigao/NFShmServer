#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/getTreasure_s.h"

#define MAX_GETTREASURE_ARRIVALBOSSCONTROL_NUM 20

class GettreasureArrivalbosscontrolDesc : public NFIDescStore
{
public:
	GettreasureArrivalbosscontrolDesc(NFIPluginManager* pPluginManager);
	virtual ~GettreasureArrivalbosscontrolDesc();
	const proto_ff_s::getTreasureArrivalBossControl_s* GetDesc(int id) const;
	proto_ff_s::getTreasureArrivalBossControl_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::getTreasureArrivalBossControl_s, MAX_GETTREASURE_ARRIVALBOSSCONTROL_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::getTreasureArrivalBossControl_s, MAX_GETTREASURE_ARRIVALBOSSCONTROL_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::getTreasureArrivalBossControl_s, getTreasureArrivalBossControl, MAX_GETTREASURE_ARRIVALBOSSCONTROL_NUM);
DECLARE_IDCREATE(GettreasureArrivalbosscontrolDesc);
};
