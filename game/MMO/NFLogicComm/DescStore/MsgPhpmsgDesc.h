#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/msg_s.h"

#define MAX_MSG_PHPMSG_NUM 200

class MsgPhpmsgDesc : public NFIDescStore
{
public:
	MsgPhpmsgDesc(NFIPluginManager* pPluginManager);
	virtual ~MsgPhpmsgDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::msgphpmsg_s* GetDesc(int id) const;
	proto_ff_s::msgphpmsg_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::msgphpmsg_s, MAX_MSG_PHPMSG_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::msgphpmsg_s, MAX_MSG_PHPMSG_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::msgphpmsg_s, msgphpmsg, MAX_MSG_PHPMSG_NUM);
DECLARE_IDCREATE(MsgPhpmsgDesc);
};
