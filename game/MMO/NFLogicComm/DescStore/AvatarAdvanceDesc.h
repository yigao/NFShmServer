#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/avatar_s.h"

#define MAX_AVATAR_ADVANCE_NUM 20

class AvatarAdvanceDesc : public NFIDescStore
{
public:
	AvatarAdvanceDesc();
	virtual ~AvatarAdvanceDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AvatarAdvance_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AvatarAdvance_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AvatarAdvance_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AvatarAdvance_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(AvatarAdvanceDesc, proto_ff_s::E_AvatarAdvance_s, E_AvatarAdvance, MAX_AVATAR_ADVANCE_NUM);
DECLARE_IDCREATE(AvatarAdvanceDesc);
};
