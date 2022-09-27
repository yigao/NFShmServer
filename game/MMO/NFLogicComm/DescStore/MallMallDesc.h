#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mall_s.h"

#define MAX_MALL_MALL_NUM 200

class MallMallDesc : public NFIDescStore
{
public:
	MallMallDesc(NFIPluginManager* pPluginManager);
	virtual ~MallMallDesc();
	const proto_ff_s::mallmall_s* GetDesc(int id) const;
	proto_ff_s::mallmall_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::mallmall_s, MAX_MALL_MALL_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::mallmall_s, MAX_MALL_MALL_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::mallmall_s, mallmall, MAX_MALL_MALL_NUM);
DECLARE_IDCREATE(MallMallDesc);
};
