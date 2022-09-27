#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/partner_s.h"

#define MAX_PARTNER_EXP_NUM 200

class PartnerExpDesc : public NFIDescStore
{
public:
	PartnerExpDesc(NFIPluginManager* pPluginManager);
	virtual ~PartnerExpDesc();
	const proto_ff_s::partnerexp_s* GetDesc(int id) const;
	proto_ff_s::partnerexp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::partnerexp_s, MAX_PARTNER_EXP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::partnerexp_s, MAX_PARTNER_EXP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::partnerexp_s, partnerexp, MAX_PARTNER_EXP_NUM);
DECLARE_IDCREATE(PartnerExpDesc);
};
