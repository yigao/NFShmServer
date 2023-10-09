#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/avatar_s.h"

#define MAX_AVATAR_FRAGMENT_NUM 20

class AvatarFragmentDesc : public NFIDescStore
{
public:
	AvatarFragmentDesc();
	virtual ~AvatarFragmentDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AvatarFragment_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AvatarFragment_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AvatarFragment_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AvatarFragment_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(AvatarFragmentDesc, proto_ff_s::E_AvatarFragment_s, E_AvatarFragment, MAX_AVATAR_FRAGMENT_NUM);
DECLARE_IDCREATE(AvatarFragmentDesc);
};
