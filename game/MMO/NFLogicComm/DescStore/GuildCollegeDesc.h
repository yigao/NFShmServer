#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_COLLEGE_NUM 16384

class GuildCollegeDesc : public NFIDescStore
{
public:
	GuildCollegeDesc();
	virtual ~GuildCollegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildCollege_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildCollege_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildCollege_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildCollege_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildCollegeDesc, proto_ff_s::E_GuildCollege_s, E_GuildCollege, MAX_GUILD_COLLEGE_NUM);
DECLARE_IDCREATE(GuildCollegeDesc);
};
