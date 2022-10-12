#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/teleport_s.h"

#define MAX_TELEPORT_TELEPORT_NUM 40

class TeleportTeleportDesc : public NFIDescStore
{
public:
	TeleportTeleportDesc(NFIPluginManager* pPluginManager);
	virtual ~TeleportTeleportDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::teleportteleport_s* GetDesc(int id) const;
	proto_ff_s::teleportteleport_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::teleportteleport_s, MAX_TELEPORT_TELEPORT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::teleportteleport_s, MAX_TELEPORT_TELEPORT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::teleportteleport_s, teleportteleport, MAX_TELEPORT_TELEPORT_NUM);
DECLARE_IDCREATE(TeleportTeleportDesc);
};
