#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/avatar_s.h"

#define MAX_AVATAR_CHANGE_NUM 20

class AvatarChangeDesc : public NFIDescStore
{
public:
	AvatarChangeDesc();
	virtual ~AvatarChangeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AvatarChange_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AvatarChange_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AvatarChange_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AvatarChange_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(AvatarChangeDesc, proto_ff_s::E_AvatarChange_s, E_AvatarChange, MAX_AVATAR_CHANGE_NUM);
DECLARE_IDCREATE(AvatarChangeDesc);
};
