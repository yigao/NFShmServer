#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/solo_s.h"

#define MAX_SOLO_DUANWEI_NUM 40

class SoloDuanweiDesc : public NFIDescStore
{
public:
	SoloDuanweiDesc(NFIPluginManager* pPluginManager);
	virtual ~SoloDuanweiDesc();
	const proto_ff_s::soloduanwei_s* GetDesc(int id) const;
	proto_ff_s::soloduanwei_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::soloduanwei_s, MAX_SOLO_DUANWEI_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::soloduanwei_s, MAX_SOLO_DUANWEI_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::soloduanwei_s, soloduanwei, MAX_SOLO_DUANWEI_NUM);
DECLARE_IDCREATE(SoloDuanweiDesc);
};
