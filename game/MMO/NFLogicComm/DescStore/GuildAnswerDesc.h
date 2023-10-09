#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_ANSWER_NUM 64

class GuildAnswerDesc : public NFIDescStore
{
public:
	GuildAnswerDesc();
	virtual ~GuildAnswerDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildAnswer_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildAnswer_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildAnswer_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildAnswer_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildAnswerDesc, proto_ff_s::E_GuildAnswer_s, E_GuildAnswer, MAX_GUILD_ANSWER_NUM);
DECLARE_IDCREATE(GuildAnswerDesc);
};
