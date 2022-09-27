#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/link_s.h"

#define MAX_LINK_LINK_NUM 300

class LinkLinkDesc : public NFIDescStore
{
public:
	LinkLinkDesc(NFIPluginManager* pPluginManager);
	virtual ~LinkLinkDesc();
	const proto_ff_s::linklink_s* GetDesc(int id) const;
	proto_ff_s::linklink_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::linklink_s, MAX_LINK_LINK_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::linklink_s, MAX_LINK_LINK_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::linklink_s, linklink, MAX_LINK_LINK_NUM);
DECLARE_IDCREATE(LinkLinkDesc);
};
