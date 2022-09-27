#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/partner_s.h"

#define MAX_PARTNER_ATTRIBUTE_NUM 2000

class PartnerAttributeDesc : public NFIDescStore
{
public:
	PartnerAttributeDesc(NFIPluginManager* pPluginManager);
	virtual ~PartnerAttributeDesc();
	const proto_ff_s::partnerattribute_s* GetDesc(int id) const;
	proto_ff_s::partnerattribute_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::partnerattribute_s, MAX_PARTNER_ATTRIBUTE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::partnerattribute_s, MAX_PARTNER_ATTRIBUTE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::partnerattribute_s, partnerattribute, MAX_PARTNER_ATTRIBUTE_NUM);
DECLARE_IDCREATE(PartnerAttributeDesc);
};
