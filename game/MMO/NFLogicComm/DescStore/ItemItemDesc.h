#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Item_s.h"

#define MAX_ITEM_ITEM_NUM 4096

class ItemItemDesc : public NFIDescTemplate<ItemItemDesc, proto_ff_s::E_ItemItem_s, EOT_CONST_ITEM_ITEM_DESC_ID, MAX_ITEM_ITEM_NUM>
{
public:
	ItemItemDesc();
	virtual ~ItemItemDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
