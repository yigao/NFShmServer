#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/closetest_s.h"

#define MAX_CLOSETEST_REBATE_NUM 20

class ClosetestRebateDesc : public NFIDescStore
{
public:
	ClosetestRebateDesc(NFIPluginManager* pPluginManager);
	virtual ~ClosetestRebateDesc();
	const proto_ff_s::closetestRebate_s* GetDesc(int id) const;
	proto_ff_s::closetestRebate_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::closetestRebate_s, MAX_CLOSETEST_REBATE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::closetestRebate_s, MAX_CLOSETEST_REBATE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::closetestRebate_s, closetestRebate, MAX_CLOSETEST_REBATE_NUM);
DECLARE_IDCREATE(ClosetestRebateDesc);
};
