#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/taskdynamic_s.h"

#define MAX_TASKDYNAMIC_TASKDYNAMIC_NUM 40

class TaskdynamicTaskdynamicDesc : public NFIDescStore
{
public:
	TaskdynamicTaskdynamicDesc(NFIPluginManager* pPluginManager);
	virtual ~TaskdynamicTaskdynamicDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::taskdynamictaskdynamic_s* GetDesc(int id) const;
	proto_ff_s::taskdynamictaskdynamic_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::taskdynamictaskdynamic_s, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::taskdynamictaskdynamic_s, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::taskdynamictaskdynamic_s, taskdynamictaskdynamic, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM);
DECLARE_IDCREATE(TaskdynamicTaskdynamicDesc);
};
