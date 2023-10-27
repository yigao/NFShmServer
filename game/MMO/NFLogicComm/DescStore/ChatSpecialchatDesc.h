#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Chat_s.h"

#define MAX_CHAT_SPECIALCHAT_NUM 8

class ChatSpecialchatDesc : public NFIDescTemplate<ChatSpecialchatDesc, proto_ff_s::E_ChatSpecialchat_s, EOT_CONST_CHAT_SPECIALCHAT_DESC_ID, MAX_CHAT_SPECIALCHAT_NUM>
{
public:
	ChatSpecialchatDesc();
	virtual ~ChatSpecialchatDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
