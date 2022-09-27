#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/getTreasure_s.h"

#define MAX_GETTREASURE_VIPBOSSCONTROL_NUM 20

class GettreasureVipbosscontrolDesc : public NFIDescStore
{
public:
	GettreasureVipbosscontrolDesc(NFIPluginManager* pPluginManager);
	virtual ~GettreasureVipbosscontrolDesc();
	const proto_ff_s::getTreasurevipBossControl_s* GetDesc(int id) const;
	proto_ff_s::getTreasurevipBossControl_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::getTreasurevipBossControl_s, MAX_GETTREASURE_VIPBOSSCONTROL_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::getTreasurevipBossControl_s, MAX_GETTREASURE_VIPBOSSCONTROL_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::getTreasurevipBossControl_s, getTreasurevipBossControl, MAX_GETTREASURE_VIPBOSSCONTROL_NUM);
DECLARE_IDCREATE(GettreasureVipbosscontrolDesc);
};
