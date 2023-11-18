#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Chat_s.h"

#define MAX_CHAT_CHAT_NUM 512

class ChatChatDesc : public NFIDescTemplate<ChatChatDesc, proto_ff_s::E_ChatChat_s, EOT_CONST_CHAT_CHAT_DESC_ID, MAX_CHAT_CHAT_NUM>
{
public:
	ChatChatDesc();
	virtual ~ChatChatDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
