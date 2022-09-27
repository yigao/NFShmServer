#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/partner_s.h"

#define MAX_PARTNER_SLOT_NUM 20

class PartnerSlotDesc : public NFIDescStore
{
public:
	PartnerSlotDesc(NFIPluginManager* pPluginManager);
	virtual ~PartnerSlotDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::partnerslot_s* GetDesc(int id) const;
	proto_ff_s::partnerslot_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::partnerslot_s, MAX_PARTNER_SLOT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::partnerslot_s, MAX_PARTNER_SLOT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::partnerslot_s, partnerslot, MAX_PARTNER_SLOT_NUM);
DECLARE_IDCREATE(PartnerSlotDesc);
};
