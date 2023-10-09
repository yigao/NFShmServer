#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_FLYATT_NUM 128

class DragonsoulFlyattDesc : public NFIDescStore
{
public:
	DragonsoulFlyattDesc();
	virtual ~DragonsoulFlyattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonsoulFlyatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonsoulFlyatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonsoulFlyatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonsoulFlyatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonsoulFlyattDesc, proto_ff_s::E_DragonsoulFlyatt_s, E_DragonsoulFlyatt, MAX_DRAGONSOUL_FLYATT_NUM);
DECLARE_IDCREATE(DragonsoulFlyattDesc);
};
