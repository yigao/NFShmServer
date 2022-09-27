#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/vip_s.h"

#define MAX_VIP_VIP_NUM 40

class VipVipDesc : public NFIDescStore
{
public:
	VipVipDesc(NFIPluginManager* pPluginManager);
	virtual ~VipVipDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::vipvip_s* GetDesc(int id) const;
	proto_ff_s::vipvip_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::vipvip_s, MAX_VIP_VIP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::vipvip_s, MAX_VIP_VIP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::vipvip_s, vipvip, MAX_VIP_VIP_NUM);
DECLARE_IDCREATE(VipVipDesc);
};
