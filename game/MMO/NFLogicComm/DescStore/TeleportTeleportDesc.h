#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Teleport_s.h"

#define MAX_TELEPORT_TELEPORT_NUM 16

class TeleportTeleportDesc : public NFIDescStore
{
public:
	TeleportTeleportDesc();
	virtual ~TeleportTeleportDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_TeleportTeleport_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TeleportTeleport_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TeleportTeleport_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TeleportTeleport_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(TeleportTeleportDesc, proto_ff_s::E_TeleportTeleport_s, E_TeleportTeleport, MAX_TELEPORT_TELEPORT_NUM);
DECLARE_IDCREATE_GLOBAL(TeleportTeleportDesc);
};
