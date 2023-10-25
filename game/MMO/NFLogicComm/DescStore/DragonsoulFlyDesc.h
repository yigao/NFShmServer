#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_FLY_NUM 32

class DragonsoulFlyDesc : public NFIDescStore
{
public:
	DragonsoulFlyDesc();
	virtual ~DragonsoulFlyDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonsoulFly_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonsoulFly_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonsoulFly_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonsoulFly_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonsoulFlyDesc, proto_ff_s::E_DragonsoulFly_s, E_DragonsoulFly, MAX_DRAGONSOUL_FLY_NUM);
DECLARE_IDCREATE_GLOBAL(DragonsoulFlyDesc);
};
