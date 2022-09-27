#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/indultTask_s.h"

#define MAX_INDULTTASK_TASK_NUM 20

class IndulttaskTaskDesc : public NFIDescStore
{
public:
	IndulttaskTaskDesc(NFIPluginManager* pPluginManager);
	virtual ~IndulttaskTaskDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::indultTasktask_s* GetDesc(int id) const;
	proto_ff_s::indultTasktask_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::indultTasktask_s, MAX_INDULTTASK_TASK_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::indultTasktask_s, MAX_INDULTTASK_TASK_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::indultTasktask_s, indultTasktask, MAX_INDULTTASK_TASK_NUM);
DECLARE_IDCREATE(IndulttaskTaskDesc);
};
