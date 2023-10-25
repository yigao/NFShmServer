#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk3v3_s.h"

#define MAX_PK3V3_BADGE_NUM 16

class Pk3v3BadgeDesc : public NFIDescStore
{
public:
	Pk3v3BadgeDesc();
	virtual ~Pk3v3BadgeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_Pk3v3Badge_s* GetDesc(int64_t id) const;
	proto_ff_s::E_Pk3v3Badge_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_Pk3v3Badge_s* GetDescByIndex(int index) const;
	proto_ff_s::E_Pk3v3Badge_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(Pk3v3BadgeDesc, proto_ff_s::E_Pk3v3Badge_s, E_Pk3v3Badge, MAX_PK3V3_BADGE_NUM);
DECLARE_IDCREATE_GLOBAL(Pk3v3BadgeDesc);
};
