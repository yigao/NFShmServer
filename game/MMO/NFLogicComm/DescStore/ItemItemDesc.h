#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/item_s.h"

#define MAX_ITEM_ITEM_NUM 2000

class ItemItemDesc : public NFIDescStore
{
public:
	ItemItemDesc();
	virtual ~ItemItemDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ItemItem_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ItemItem_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ItemItem_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ItemItem_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_ItemItem_s, E_ItemItem, MAX_ITEM_ITEM_NUM);
DECLARE_IDCREATE(ItemItemDesc);
};
