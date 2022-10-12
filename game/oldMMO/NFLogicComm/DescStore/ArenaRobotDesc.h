#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/arena_s.h"

#define MAX_ARENA_ROBOT_NUM 6000

class ArenaRobotDesc : public NFIDescStore
{
public:
	ArenaRobotDesc(NFIPluginManager* pPluginManager);
	virtual ~ArenaRobotDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::arenarobot_s* GetDesc(int id) const;
	proto_ff_s::arenarobot_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::arenarobot_s, MAX_ARENA_ROBOT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::arenarobot_s, MAX_ARENA_ROBOT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::arenarobot_s, arenarobot, MAX_ARENA_ROBOT_NUM);
DECLARE_IDCREATE(ArenaRobotDesc);
};
