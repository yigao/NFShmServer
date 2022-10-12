#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/marry_s.h"

#define MAX_MARRY_WARM_NUM 20

class MarryWarmDesc : public NFIDescStore
{
public:
	MarryWarmDesc(NFIPluginManager* pPluginManager);
	virtual ~MarryWarmDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::marrywarm_s* GetDesc(int id) const;
	proto_ff_s::marrywarm_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::marrywarm_s, MAX_MARRY_WARM_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::marrywarm_s, MAX_MARRY_WARM_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::marrywarm_s, marrywarm, MAX_MARRY_WARM_NUM);
DECLARE_IDCREATE(MarryWarmDesc);
};
