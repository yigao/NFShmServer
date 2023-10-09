#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Chat_s.h"

#define MAX_CHAT_CHAT_NUM 64

class ChatChatDesc : public NFIDescStore
{
public:
	ChatChatDesc();
	virtual ~ChatChatDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ChatChat_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ChatChat_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ChatChat_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ChatChat_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ChatChatDesc, proto_ff_s::E_ChatChat_s, E_ChatChat, MAX_CHAT_CHAT_NUM);
DECLARE_IDCREATE(ChatChatDesc);
};
