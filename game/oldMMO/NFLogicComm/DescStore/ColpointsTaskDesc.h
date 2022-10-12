#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/colPoints_s.h"

#define MAX_COLPOINTS_TASK_NUM 20

class ColpointsTaskDesc : public NFIDescStore
{
public:
	ColpointsTaskDesc(NFIPluginManager* pPluginManager);
	virtual ~ColpointsTaskDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::colPointstask_s* GetDesc(int id) const;
	proto_ff_s::colPointstask_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::colPointstask_s, MAX_COLPOINTS_TASK_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::colPointstask_s, MAX_COLPOINTS_TASK_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::colPointstask_s, colPointstask, MAX_COLPOINTS_TASK_NUM);
DECLARE_IDCREATE(ColpointsTaskDesc);
};
