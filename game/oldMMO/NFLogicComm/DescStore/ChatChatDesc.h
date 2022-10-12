#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/chat_s.h"

#define MAX_CHAT_CHAT_NUM 200

class ChatChatDesc : public NFIDescStore
{
public:
	ChatChatDesc(NFIPluginManager* pPluginManager);
	virtual ~ChatChatDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::chatchat_s* GetDesc(int id) const;
	proto_ff_s::chatchat_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::chatchat_s, MAX_CHAT_CHAT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::chatchat_s, MAX_CHAT_CHAT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::chatchat_s, chatchat, MAX_CHAT_CHAT_NUM);
DECLARE_IDCREATE(ChatChatDesc);
};
