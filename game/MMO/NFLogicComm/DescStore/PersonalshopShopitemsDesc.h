#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Personalshop_s.h"

#define MAX_PERSONALSHOP_SHOPITEMS_NUM 1024

class PersonalshopShopitemsDesc : public NFIDescStore
{
public:
	PersonalshopShopitemsDesc();
	virtual ~PersonalshopShopitemsDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PersonalshopShopitems_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PersonalshopShopitems_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PersonalshopShopitems_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PersonalshopShopitems_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PersonalshopShopitemsDesc, proto_ff_s::E_PersonalshopShopitems_s, E_PersonalshopShopitems, MAX_PERSONALSHOP_SHOPITEMS_NUM);
DECLARE_IDCREATE(PersonalshopShopitemsDesc);
};
