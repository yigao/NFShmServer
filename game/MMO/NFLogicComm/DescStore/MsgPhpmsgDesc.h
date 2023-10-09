#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Msg_s.h"

#define MAX_MSG_PHPMSG_NUM 128

class MsgPhpmsgDesc : public NFIDescStore
{
public:
	MsgPhpmsgDesc();
	virtual ~MsgPhpmsgDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MsgPhpmsg_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MsgPhpmsg_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MsgPhpmsg_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MsgPhpmsg_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MsgPhpmsgDesc, proto_ff_s::E_MsgPhpmsg_s, E_MsgPhpmsg, MAX_MSG_PHPMSG_NUM);
DECLARE_IDCREATE(MsgPhpmsgDesc);
};
