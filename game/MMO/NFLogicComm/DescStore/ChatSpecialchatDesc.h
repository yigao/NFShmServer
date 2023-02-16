#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/chat_s.h"

#define MAX_CHAT_SPECIALCHAT_NUM 20

class ChatSpecialchatDesc : public NFIDescStore
{
public:
	ChatSpecialchatDesc();
	virtual ~ChatSpecialchatDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ChatSpecialchat_s* GetDesc(int id) const;
	proto_ff_s::E_ChatSpecialchat_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_ChatSpecialchat_s, chatspecialchat, MAX_CHAT_SPECIALCHAT_NUM);
DECLARE_IDCREATE(ChatSpecialchatDesc);
};
