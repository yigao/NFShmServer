#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/getTreasure_s.h"

#define MAX_GETTREASURE_TIMESCONTROL_NUM 20

class GettreasureTimescontrolDesc : public NFIDescStore
{
public:
	GettreasureTimescontrolDesc(NFIPluginManager* pPluginManager);
	virtual ~GettreasureTimescontrolDesc();
	const proto_ff_s::getTreasuretimesControl_s* GetDesc(int id) const;
	proto_ff_s::getTreasuretimesControl_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::getTreasuretimesControl_s, MAX_GETTREASURE_TIMESCONTROL_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::getTreasuretimesControl_s, MAX_GETTREASURE_TIMESCONTROL_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::getTreasuretimesControl_s, getTreasuretimesControl, MAX_GETTREASURE_TIMESCONTROL_NUM);
DECLARE_IDCREATE(GettreasureTimescontrolDesc);
};
