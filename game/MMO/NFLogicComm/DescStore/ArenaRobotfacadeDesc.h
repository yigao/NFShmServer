#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Arena_s.h"

#define MAX_ARENA_ROBOTFACADE_NUM 2

class ArenaRobotfacadeDesc : public NFIDescStore
{
public:
	ArenaRobotfacadeDesc();
	virtual ~ArenaRobotfacadeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ArenaRobotfacade_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ArenaRobotfacade_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ArenaRobotfacade_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ArenaRobotfacade_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ArenaRobotfacadeDesc, proto_ff_s::E_ArenaRobotfacade_s, E_ArenaRobotfacade, MAX_ARENA_ROBOTFACADE_NUM);
DECLARE_IDCREATE(ArenaRobotfacadeDesc);
};
