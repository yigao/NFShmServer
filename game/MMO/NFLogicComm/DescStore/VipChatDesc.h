#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Vip_s.h"

#define MAX_VIP_CHAT_NUM 16

class VipChatDesc : public NFIDescTemplate<VipChatDesc, proto_ff_s::E_VipChat_s, EOT_CONST_VIP_CHAT_DESC_ID, MAX_VIP_CHAT_NUM>
{
public:
	VipChatDesc();
	virtual ~VipChatDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
