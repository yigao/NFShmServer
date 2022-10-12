#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_TURNTABLE_NUM 20

class OperateTurntableDesc : public NFIDescStore
{
public:
	OperateTurntableDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateTurntableDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::operateturntable_s* GetDesc(int id) const;
	proto_ff_s::operateturntable_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operateturntable_s, MAX_OPERATE_TURNTABLE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operateturntable_s, MAX_OPERATE_TURNTABLE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operateturntable_s, operateturntable, MAX_OPERATE_TURNTABLE_NUM);
DECLARE_IDCREATE(OperateTurntableDesc);
};
