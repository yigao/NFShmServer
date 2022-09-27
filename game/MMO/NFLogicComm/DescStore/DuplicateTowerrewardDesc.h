#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/duplicate_s.h"

#define MAX_DUPLICATE_TOWERREWARD_NUM 80

class DuplicateTowerrewardDesc : public NFIDescStore
{
public:
	DuplicateTowerrewardDesc(NFIPluginManager* pPluginManager);
	virtual ~DuplicateTowerrewardDesc();
	const proto_ff_s::duplicatetowerReward_s* GetDesc(int id) const;
	proto_ff_s::duplicatetowerReward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::duplicatetowerReward_s, MAX_DUPLICATE_TOWERREWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::duplicatetowerReward_s, MAX_DUPLICATE_TOWERREWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::duplicatetowerReward_s, duplicatetowerReward, MAX_DUPLICATE_TOWERREWARD_NUM);
DECLARE_IDCREATE(DuplicateTowerrewardDesc);
};
