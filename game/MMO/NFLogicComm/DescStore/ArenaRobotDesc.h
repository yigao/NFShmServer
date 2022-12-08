#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/arena_s.h"

#define MAX_ARENA_ROBOT_NUM 6000

class ArenaRobotDesc : public NFIDescStore
{
public:
	ArenaRobotDesc();
	virtual ~ArenaRobotDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::arenarobot_s* GetDesc(int id) const;
	proto_ff_s::arenarobot_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::arenarobot_s, arenarobot, MAX_ARENA_ROBOT_NUM);
DECLARE_IDCREATE(ArenaRobotDesc);
};
