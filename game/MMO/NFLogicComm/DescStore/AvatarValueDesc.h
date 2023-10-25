#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_VALUE_NUM 4096

class AvatarValueDesc : public NFIDescStore
{
public:
	AvatarValueDesc();
	virtual ~AvatarValueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AvatarValue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AvatarValue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AvatarValue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AvatarValue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AvatarValueDesc, proto_ff_s::E_AvatarValue_s, E_AvatarValue, MAX_AVATAR_VALUE_NUM);
DECLARE_IDCREATE_GLOBAL(AvatarValueDesc);
};
