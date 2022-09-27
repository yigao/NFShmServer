#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/occupation_s.h"

#define MAX_OCCUPATION_CONDITIONLIST_NUM 100

class OccupationConditionlistDesc : public NFIDescStore
{
public:
	OccupationConditionlistDesc(NFIPluginManager* pPluginManager);
	virtual ~OccupationConditionlistDesc();
	const proto_ff_s::occupationconditionList_s* GetDesc(int id) const;
	proto_ff_s::occupationconditionList_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::occupationconditionList_s, MAX_OCCUPATION_CONDITIONLIST_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::occupationconditionList_s, MAX_OCCUPATION_CONDITIONLIST_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::occupationconditionList_s, occupationconditionList, MAX_OCCUPATION_CONDITIONLIST_NUM);
DECLARE_IDCREATE(OccupationConditionlistDesc);
};
