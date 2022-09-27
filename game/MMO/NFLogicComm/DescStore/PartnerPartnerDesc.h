#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/partner_s.h"

#define MAX_PARTNER_PARTNER_NUM 500

class PartnerPartnerDesc : public NFIDescStore
{
public:
	PartnerPartnerDesc(NFIPluginManager* pPluginManager);
	virtual ~PartnerPartnerDesc();
	const proto_ff_s::partnerpartner_s* GetDesc(int id) const;
	proto_ff_s::partnerpartner_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::partnerpartner_s, MAX_PARTNER_PARTNER_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::partnerpartner_s, MAX_PARTNER_PARTNER_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::partnerpartner_s, partnerpartner, MAX_PARTNER_PARTNER_NUM);
DECLARE_IDCREATE(PartnerPartnerDesc);
};
