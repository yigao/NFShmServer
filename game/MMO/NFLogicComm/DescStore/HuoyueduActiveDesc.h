#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/huoyuedu_s.h"

#define MAX_HUOYUEDU_ACTIVE_NUM 80

class HuoyueduActiveDesc : public NFIDescStore
{
public:
	HuoyueduActiveDesc(NFIPluginManager* pPluginManager);
	virtual ~HuoyueduActiveDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::huoyueduactive_s* GetDesc(int id) const;
	proto_ff_s::huoyueduactive_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::huoyueduactive_s, MAX_HUOYUEDU_ACTIVE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::huoyueduactive_s, MAX_HUOYUEDU_ACTIVE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::huoyueduactive_s, huoyueduactive, MAX_HUOYUEDU_ACTIVE_NUM);
DECLARE_IDCREATE(HuoyueduActiveDesc);
};
