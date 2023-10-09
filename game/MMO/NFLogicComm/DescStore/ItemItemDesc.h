#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Item_s.h"

#define MAX_ITEM_ITEM_NUM 4096

class ItemItemDesc : public NFIDescStore
{
public:
	ItemItemDesc();
	virtual ~ItemItemDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ItemItem_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ItemItem_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ItemItem_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ItemItem_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ItemItemDesc, proto_ff_s::E_ItemItem_s, E_ItemItem, MAX_ITEM_ITEM_NUM);
DECLARE_IDCREATE(ItemItemDesc);
};
