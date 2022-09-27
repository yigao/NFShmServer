#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/back_s.h"

#define MAX_BACK_BACK_NUM 160

class BackBackDesc : public NFIDescStore
{
public:
	BackBackDesc(NFIPluginManager* pPluginManager);
	virtual ~BackBackDesc();
	const proto_ff_s::backback_s* GetDesc(int id) const;
	proto_ff_s::backback_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::backback_s, MAX_BACK_BACK_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::backback_s, MAX_BACK_BACK_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::backback_s, backback, MAX_BACK_BACK_NUM);
DECLARE_IDCREATE(BackBackDesc);
};
