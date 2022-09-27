#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/partner_s.h"

#define MAX_PARTNER_STARUP_NUM 40

class PartnerStarupDesc : public NFIDescStore
{
public:
	PartnerStarupDesc(NFIPluginManager* pPluginManager);
	virtual ~PartnerStarupDesc();
	const proto_ff_s::partnerstarUp_s* GetDesc(int id) const;
	proto_ff_s::partnerstarUp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::partnerstarUp_s, MAX_PARTNER_STARUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::partnerstarUp_s, MAX_PARTNER_STARUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::partnerstarUp_s, partnerstarUp, MAX_PARTNER_STARUP_NUM);
DECLARE_IDCREATE(PartnerStarupDesc);
};
