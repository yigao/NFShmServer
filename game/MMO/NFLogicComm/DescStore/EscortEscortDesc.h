#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/escort_s.h"

#define MAX_ESCORT_ESCORT_NUM 20

class EscortEscortDesc : public NFIDescStore
{
public:
	EscortEscortDesc(NFIPluginManager* pPluginManager);
	virtual ~EscortEscortDesc();
	const proto_ff_s::escortescort_s* GetDesc(int id) const;
	proto_ff_s::escortescort_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::escortescort_s, MAX_ESCORT_ESCORT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::escortescort_s, MAX_ESCORT_ESCORT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::escortescort_s, escortescort, MAX_ESCORT_ESCORT_NUM);
DECLARE_IDCREATE(EscortEscortDesc);
};
