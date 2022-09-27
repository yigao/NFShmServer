#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/tasktracker_s.h"

#define MAX_TASKTRACKER_TASKTRACKER_NUM 60

class TasktrackerTasktrackerDesc : public NFIDescStore
{
public:
	TasktrackerTasktrackerDesc(NFIPluginManager* pPluginManager);
	virtual ~TasktrackerTasktrackerDesc();
	const proto_ff_s::tasktrackertasktracker_s* GetDesc(int id) const;
	proto_ff_s::tasktrackertasktracker_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::tasktrackertasktracker_s, MAX_TASKTRACKER_TASKTRACKER_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::tasktrackertasktracker_s, MAX_TASKTRACKER_TASKTRACKER_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::tasktrackertasktracker_s, tasktrackertasktracker, MAX_TASKTRACKER_TASKTRACKER_NUM);
DECLARE_IDCREATE(TasktrackerTasktrackerDesc);
};
