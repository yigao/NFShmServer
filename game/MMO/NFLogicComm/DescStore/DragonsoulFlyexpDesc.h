#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_FLYEXP_NUM 64

class DragonsoulFlyexpDesc : public NFIDescStore
{
public:
	DragonsoulFlyexpDesc();
	virtual ~DragonsoulFlyexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonsoulFlyexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonsoulFlyexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonsoulFlyexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonsoulFlyexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonsoulFlyexpDesc, proto_ff_s::E_DragonsoulFlyexp_s, E_DragonsoulFlyexp, MAX_DRAGONSOUL_FLYEXP_NUM);
DECLARE_IDCREATE(DragonsoulFlyexpDesc);
};
