#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/manor_s.h"

#define MAX_MANOR_ITEMCOST_NUM 20

class ManorItemcostDesc : public NFIDescStore
{
public:
	ManorItemcostDesc(NFIPluginManager* pPluginManager);
	virtual ~ManorItemcostDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::manoritemCost_s* GetDesc(int id) const;
	proto_ff_s::manoritemCost_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::manoritemCost_s, MAX_MANOR_ITEMCOST_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::manoritemCost_s, MAX_MANOR_ITEMCOST_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::manoritemCost_s, manoritemCost, MAX_MANOR_ITEMCOST_NUM);
DECLARE_IDCREATE(ManorItemcostDesc);
};
