#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/teleport_s.h"

#define MAX_TELEPORT_BORN_NUM 300

class TeleportBornDesc : public NFIDescStore
{
public:
	TeleportBornDesc(NFIPluginManager* pPluginManager);
	virtual ~TeleportBornDesc();
	const proto_ff_s::teleportborn_s* GetDesc(int id) const;
	proto_ff_s::teleportborn_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::teleportborn_s, MAX_TELEPORT_BORN_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::teleportborn_s, MAX_TELEPORT_BORN_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::teleportborn_s, teleportborn, MAX_TELEPORT_BORN_NUM);
DECLARE_IDCREATE(TeleportBornDesc);
};
