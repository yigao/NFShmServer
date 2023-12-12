#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Msg_s.h"

#define MAX_MSG_PHPMSG_NUM 128

class MsgPhpmsgDesc : public NFIDescTemplate<MsgPhpmsgDesc, proto_ff_s::E_MsgPhpmsg_s, EOT_CONST_MSG_PHPMSG_DESC_ID, MAX_MSG_PHPMSG_NUM>
{
public:
	MsgPhpmsgDesc();
	virtual ~MsgPhpmsgDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
