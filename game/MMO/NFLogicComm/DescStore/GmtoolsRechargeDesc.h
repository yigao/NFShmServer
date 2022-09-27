#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/GMtools_s.h"

#define MAX_GMTOOLS_RECHARGE_NUM 20

class GmtoolsRechargeDesc : public NFIDescStore
{
public:
	GmtoolsRechargeDesc(NFIPluginManager* pPluginManager);
	virtual ~GmtoolsRechargeDesc();
	const proto_ff_s::GMtoolsrecharge_s* GetDesc(int id) const;
	proto_ff_s::GMtoolsrecharge_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::GMtoolsrecharge_s, MAX_GMTOOLS_RECHARGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::GMtoolsrecharge_s, MAX_GMTOOLS_RECHARGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::GMtoolsrecharge_s, GMtoolsrecharge, MAX_GMTOOLS_RECHARGE_NUM);
DECLARE_IDCREATE(GmtoolsRechargeDesc);
};
