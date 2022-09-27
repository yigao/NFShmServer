#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/taskdynamic_s.h"

#define MAX_TASKDYNAMIC_TASKCOMCOND_NUM 140

class TaskdynamicTaskcomcondDesc : public NFIDescStore
{
public:
	TaskdynamicTaskcomcondDesc(NFIPluginManager* pPluginManager);
	virtual ~TaskdynamicTaskcomcondDesc();
	const proto_ff_s::taskdynamictaskcomcond_s* GetDesc(int id) const;
	proto_ff_s::taskdynamictaskcomcond_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::taskdynamictaskcomcond_s, MAX_TASKDYNAMIC_TASKCOMCOND_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::taskdynamictaskcomcond_s, MAX_TASKDYNAMIC_TASKCOMCOND_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::taskdynamictaskcomcond_s, taskdynamictaskcomcond, MAX_TASKDYNAMIC_TASKCOMCOND_NUM);
DECLARE_IDCREATE(TaskdynamicTaskcomcondDesc);
};
