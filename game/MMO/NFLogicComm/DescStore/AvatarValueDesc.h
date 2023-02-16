#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/avatar_s.h"

#define MAX_AVATAR_VALUE_NUM 400

class AvatarValueDesc : public NFIDescStore
{
public:
	AvatarValueDesc();
	virtual ~AvatarValueDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AvatarValue_s* GetDesc(int id) const;
	proto_ff_s::E_AvatarValue_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_AvatarValue_s, E_AvatarValue, MAX_AVATAR_VALUE_NUM);
DECLARE_IDCREATE(AvatarValueDesc);
};
