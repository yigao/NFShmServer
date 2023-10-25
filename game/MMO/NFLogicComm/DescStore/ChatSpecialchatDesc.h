#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Chat_s.h"

#define MAX_CHAT_SPECIALCHAT_NUM 8

class ChatSpecialchatDesc : public NFIDescStore
{
public:
	ChatSpecialchatDesc();
	virtual ~ChatSpecialchatDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ChatSpecialchat_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ChatSpecialchat_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ChatSpecialchat_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ChatSpecialchat_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ChatSpecialchatDesc, proto_ff_s::E_ChatSpecialchat_s, E_ChatSpecialchat, MAX_CHAT_SPECIALCHAT_NUM);
DECLARE_IDCREATE_GLOBAL(ChatSpecialchatDesc);
};
