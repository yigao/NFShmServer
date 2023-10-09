#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragon_s.h"

#define MAX_DRAGON_DISPLAY_NUM 32

class DragonDisplayDesc : public NFIDescStore
{
public:
	DragonDisplayDesc();
	virtual ~DragonDisplayDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonDisplay_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonDisplay_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonDisplay_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonDisplay_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonDisplayDesc, proto_ff_s::E_DragonDisplay_s, E_DragonDisplay, MAX_DRAGON_DISPLAY_NUM);
DECLARE_IDCREATE(DragonDisplayDesc);
};
