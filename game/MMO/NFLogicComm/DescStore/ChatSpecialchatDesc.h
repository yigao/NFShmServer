#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/chat_s.h"

#define MAX_CHAT_SPECIALCHAT_NUM 20

class ChatSpecialchatDesc : public NFIDescStore
{
public:
	ChatSpecialchatDesc(NFIPluginManager* pPluginManager);
	virtual ~ChatSpecialchatDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::chatspecialchat_s* GetDesc(int id) const;
	proto_ff_s::chatspecialchat_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::chatspecialchat_s, MAX_CHAT_SPECIALCHAT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::chatspecialchat_s, MAX_CHAT_SPECIALCHAT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::chatspecialchat_s, chatspecialchat, MAX_CHAT_SPECIALCHAT_NUM);
DECLARE_IDCREATE(ChatSpecialchatDesc);
};
