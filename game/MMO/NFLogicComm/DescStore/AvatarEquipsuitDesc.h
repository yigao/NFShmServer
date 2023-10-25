#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_EQUIPSUIT_NUM 16

class AvatarEquipsuitDesc : public NFIDescStore
{
public:
	AvatarEquipsuitDesc();
	virtual ~AvatarEquipsuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AvatarEquipsuit_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AvatarEquipsuit_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AvatarEquipsuit_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AvatarEquipsuit_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AvatarEquipsuitDesc, proto_ff_s::E_AvatarEquipsuit_s, E_AvatarEquipsuit, MAX_AVATAR_EQUIPSUIT_NUM);
DECLARE_IDCREATE_GLOBAL(AvatarEquipsuitDesc);
};
