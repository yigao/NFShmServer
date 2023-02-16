#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/avatar_s.h"

#define MAX_AVATAR_BATTLESLOT_NUM 20

class AvatarBattleslotDesc : public NFIDescStore
{
public:
	AvatarBattleslotDesc();
	virtual ~AvatarBattleslotDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AvatarBattleslot_s* GetDesc(int id) const;
	proto_ff_s::E_AvatarBattleslot_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_AvatarBattleslot_s, E_AvatarBattleslot, MAX_AVATAR_BATTLESLOT_NUM);
DECLARE_IDCREATE(AvatarBattleslotDesc);
};
