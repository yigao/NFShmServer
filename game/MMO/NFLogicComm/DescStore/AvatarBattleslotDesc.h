#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_BATTLESLOT_NUM 8

class AvatarBattleslotDesc : public NFIDescStore
{
public:
	AvatarBattleslotDesc();
	virtual ~AvatarBattleslotDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AvatarBattleslot_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AvatarBattleslot_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AvatarBattleslot_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AvatarBattleslot_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AvatarBattleslotDesc, proto_ff_s::E_AvatarBattleslot_s, E_AvatarBattleslot, MAX_AVATAR_BATTLESLOT_NUM);
DECLARE_IDCREATE_GLOBAL(AvatarBattleslotDesc);
};
