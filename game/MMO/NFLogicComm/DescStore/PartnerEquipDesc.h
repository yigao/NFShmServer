#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/partner_s.h"

#define MAX_PARTNER_EQUIP_NUM 40

class PartnerEquipDesc : public NFIDescStore
{
public:
	PartnerEquipDesc(NFIPluginManager* pPluginManager);
	virtual ~PartnerEquipDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::partnerequip_s* GetDesc(int id) const;
	proto_ff_s::partnerequip_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::partnerequip_s, MAX_PARTNER_EQUIP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::partnerequip_s, MAX_PARTNER_EQUIP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::partnerequip_s, partnerequip, MAX_PARTNER_EQUIP_NUM);
DECLARE_IDCREATE(PartnerEquipDesc);
};
