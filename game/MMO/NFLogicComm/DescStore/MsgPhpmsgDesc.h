#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/msg_s.h"

#define MAX_MSG_PHPMSG_NUM 200

class MsgPhpmsgDesc : public NFIDescStore
{
public:
	MsgPhpmsgDesc();
	virtual ~MsgPhpmsgDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MsgPhpmsg_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MsgPhpmsg_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MsgPhpmsg_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MsgPhpmsg_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(MsgPhpmsgDesc, proto_ff_s::E_MsgPhpmsg_s, E_MsgPhpmsg, MAX_MSG_PHPMSG_NUM);
DECLARE_IDCREATE(MsgPhpmsgDesc);
};
