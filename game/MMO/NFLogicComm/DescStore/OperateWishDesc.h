#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_WISH_NUM 2000

class OperateWishDesc : public NFIDescStore
{
public:
	OperateWishDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateWishDesc();
	const proto_ff_s::operatewish_s* GetDesc(int id) const;
	proto_ff_s::operatewish_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operatewish_s, MAX_OPERATE_WISH_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operatewish_s, MAX_OPERATE_WISH_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operatewish_s, operatewish, MAX_OPERATE_WISH_NUM);
DECLARE_IDCREATE(OperateWishDesc);
};
