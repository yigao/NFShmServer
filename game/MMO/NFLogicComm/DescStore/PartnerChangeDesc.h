#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/partner_s.h"

#define MAX_PARTNER_CHANGE_NUM 40

class PartnerChangeDesc : public NFIDescStore
{
public:
	PartnerChangeDesc(NFIPluginManager* pPluginManager);
	virtual ~PartnerChangeDesc();
	const proto_ff_s::partnerchange_s* GetDesc(int id) const;
	proto_ff_s::partnerchange_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::partnerchange_s, MAX_PARTNER_CHANGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::partnerchange_s, MAX_PARTNER_CHANGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::partnerchange_s, partnerchange, MAX_PARTNER_CHANGE_NUM);
DECLARE_IDCREATE(PartnerChangeDesc);
};
