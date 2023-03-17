#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/chat_s.h"

#define MAX_CHAT_CHAT_NUM 40

class ChatChatDesc : public NFIDescStore
{
public:
	ChatChatDesc();
	virtual ~ChatChatDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ChatChat_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ChatChat_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ChatChat_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ChatChat_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(ChatChatDesc, proto_ff_s::E_ChatChat_s, E_ChatChat, MAX_CHAT_CHAT_NUM);
DECLARE_IDCREATE(ChatChatDesc);
};
