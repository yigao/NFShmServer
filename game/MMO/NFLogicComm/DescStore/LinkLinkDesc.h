#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/link_s.h"

#define MAX_LINK_LINK_NUM 160

class LinkLinkDesc : public NFIDescStore
{
public:
	LinkLinkDesc();
	virtual ~LinkLinkDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_LinkLink_s* GetDesc(int64_t id) const;
	proto_ff_s::E_LinkLink_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_LinkLink_s* GetDescByIndex(int index) const;
	proto_ff_s::E_LinkLink_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(LinkLinkDesc, proto_ff_s::E_LinkLink_s, E_LinkLink, MAX_LINK_LINK_NUM);
DECLARE_IDCREATE(LinkLinkDesc);
};
