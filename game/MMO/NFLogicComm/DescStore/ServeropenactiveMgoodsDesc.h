#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/serveropenactive_s.h"

#define MAX_SERVEROPENACTIVE_MGOODS_NUM 160

class ServeropenactiveMgoodsDesc : public NFIDescStore
{
public:
	ServeropenactiveMgoodsDesc(NFIPluginManager* pPluginManager);
	virtual ~ServeropenactiveMgoodsDesc();
	const proto_ff_s::serveropenactivemGoods_s* GetDesc(int id) const;
	proto_ff_s::serveropenactivemGoods_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::serveropenactivemGoods_s, MAX_SERVEROPENACTIVE_MGOODS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::serveropenactivemGoods_s, MAX_SERVEROPENACTIVE_MGOODS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::serveropenactivemGoods_s, serveropenactivemGoods, MAX_SERVEROPENACTIVE_MGOODS_NUM);
DECLARE_IDCREATE(ServeropenactiveMgoodsDesc);
};
