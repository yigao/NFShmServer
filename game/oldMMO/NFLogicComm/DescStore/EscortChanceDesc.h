#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/escort_s.h"

#define MAX_ESCORT_CHANCE_NUM 20

class EscortChanceDesc : public NFIDescStore
{
public:
	EscortChanceDesc(NFIPluginManager* pPluginManager);
	virtual ~EscortChanceDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::escortchance_s* GetDesc(int id) const;
	proto_ff_s::escortchance_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::escortchance_s, MAX_ESCORT_CHANCE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::escortchance_s, MAX_ESCORT_CHANCE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::escortchance_s, escortchance, MAX_ESCORT_CHANCE_NUM);
DECLARE_IDCREATE(EscortChanceDesc);
};
