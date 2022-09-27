#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/item_s.h"

#define MAX_ITEM_ITEM_NUM 3000

class ItemItemDesc : public NFIDescStore
{
public:
	ItemItemDesc(NFIPluginManager* pPluginManager);
	virtual ~ItemItemDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::itemitem_s* GetDesc(int id) const;
	proto_ff_s::itemitem_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::itemitem_s, MAX_ITEM_ITEM_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::itemitem_s, MAX_ITEM_ITEM_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::itemitem_s, itemitem, MAX_ITEM_ITEM_NUM);
DECLARE_IDCREATE(ItemItemDesc);
};
