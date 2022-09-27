#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/taskreward_s.h"

#define MAX_TASKREWARD_TASKREWARD_NUM 4000

class TaskrewardTaskrewardDesc : public NFIDescStore
{
public:
	TaskrewardTaskrewardDesc(NFIPluginManager* pPluginManager);
	virtual ~TaskrewardTaskrewardDesc();
	const proto_ff_s::taskrewardtaskreward_s* GetDesc(int id) const;
	proto_ff_s::taskrewardtaskreward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::taskrewardtaskreward_s, MAX_TASKREWARD_TASKREWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::taskrewardtaskreward_s, MAX_TASKREWARD_TASKREWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::taskrewardtaskreward_s, taskrewardtaskreward, MAX_TASKREWARD_TASKREWARD_NUM);
DECLARE_IDCREATE(TaskrewardTaskrewardDesc);
};
