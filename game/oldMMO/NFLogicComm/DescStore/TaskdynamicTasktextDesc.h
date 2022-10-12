#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/taskdynamic_s.h"

#define MAX_TASKDYNAMIC_TASKTEXT_NUM 20

class TaskdynamicTasktextDesc : public NFIDescStore
{
public:
	TaskdynamicTasktextDesc(NFIPluginManager* pPluginManager);
	virtual ~TaskdynamicTasktextDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::taskdynamictasktext_s* GetDesc(int id) const;
	proto_ff_s::taskdynamictasktext_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::taskdynamictasktext_s, MAX_TASKDYNAMIC_TASKTEXT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::taskdynamictasktext_s, MAX_TASKDYNAMIC_TASKTEXT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::taskdynamictasktext_s, taskdynamictasktext, MAX_TASKDYNAMIC_TASKTEXT_NUM);
DECLARE_IDCREATE(TaskdynamicTasktextDesc);
};
