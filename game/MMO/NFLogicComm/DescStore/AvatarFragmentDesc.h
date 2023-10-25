#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_FRAGMENT_NUM 16

class AvatarFragmentDesc : public NFIDescStore
{
public:
	AvatarFragmentDesc();
	virtual ~AvatarFragmentDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AvatarFragment_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AvatarFragment_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AvatarFragment_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AvatarFragment_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AvatarFragmentDesc, proto_ff_s::E_AvatarFragment_s, E_AvatarFragment, MAX_AVATAR_FRAGMENT_NUM);
DECLARE_IDCREATE_GLOBAL(AvatarFragmentDesc);
};
