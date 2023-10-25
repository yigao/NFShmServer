#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Personalshop_s.h"

#define MAX_PERSONALSHOP_SHOPS_NUM 2

class PersonalshopShopsDesc : public NFIDescStore
{
public:
	PersonalshopShopsDesc();
	virtual ~PersonalshopShopsDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PersonalshopShops_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PersonalshopShops_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PersonalshopShops_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PersonalshopShops_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PersonalshopShopsDesc, proto_ff_s::E_PersonalshopShops_s, E_PersonalshopShops, MAX_PERSONALSHOP_SHOPS_NUM);
DECLARE_IDCREATE_GLOBAL(PersonalshopShopsDesc);
};
