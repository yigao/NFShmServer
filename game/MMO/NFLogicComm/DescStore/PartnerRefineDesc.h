#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/partner_s.h"

#define MAX_PARTNER_REFINE_NUM 200

class PartnerRefineDesc : public NFIDescStore
{
public:
	PartnerRefineDesc(NFIPluginManager* pPluginManager);
	virtual ~PartnerRefineDesc();
	const proto_ff_s::partnerrefine_s* GetDesc(int id) const;
	proto_ff_s::partnerrefine_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::partnerrefine_s, MAX_PARTNER_REFINE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::partnerrefine_s, MAX_PARTNER_REFINE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::partnerrefine_s, partnerrefine, MAX_PARTNER_REFINE_NUM);
DECLARE_IDCREATE(PartnerRefineDesc);
};
