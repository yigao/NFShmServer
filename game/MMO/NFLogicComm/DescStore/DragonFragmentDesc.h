#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragon_s.h"

#define MAX_DRAGON_FRAGMENT_NUM 16

class DragonFragmentDesc : public NFIDescStore
{
public:
	DragonFragmentDesc();
	virtual ~DragonFragmentDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonFragment_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonFragment_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonFragment_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonFragment_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonFragmentDesc, proto_ff_s::E_DragonFragment_s, E_DragonFragment, MAX_DRAGON_FRAGMENT_NUM);
DECLARE_IDCREATE(DragonFragmentDesc);
};
