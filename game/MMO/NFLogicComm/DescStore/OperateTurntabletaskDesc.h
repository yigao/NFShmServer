#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_TURNTABLETASK_NUM 20

class OperateTurntabletaskDesc : public NFIDescStore
{
public:
	OperateTurntabletaskDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateTurntabletaskDesc();
	const proto_ff_s::operateturntableTask_s* GetDesc(int id) const;
	proto_ff_s::operateturntableTask_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operateturntableTask_s, MAX_OPERATE_TURNTABLETASK_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operateturntableTask_s, MAX_OPERATE_TURNTABLETASK_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operateturntableTask_s, operateturntableTask, MAX_OPERATE_TURNTABLETASK_NUM);
DECLARE_IDCREATE(OperateTurntabletaskDesc);
};
