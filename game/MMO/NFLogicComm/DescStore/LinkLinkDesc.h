#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/link_s.h"

#define MAX_LINK_LINK_NUM 40

class LinkLinkDesc : public NFIDescStore
{
public:
	LinkLinkDesc();
	virtual ~LinkLinkDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_LinkLink_s* GetDesc(int id) const;
	proto_ff_s::E_LinkLink_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_LinkLink_s, linklink, MAX_LINK_LINK_NUM);
DECLARE_IDCREATE(LinkLinkDesc);
};
