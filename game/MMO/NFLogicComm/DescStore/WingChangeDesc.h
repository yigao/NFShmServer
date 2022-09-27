#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/wing_s.h"

#define MAX_WING_CHANGE_NUM 40

class WingChangeDesc : public NFIDescStore
{
public:
	WingChangeDesc(NFIPluginManager* pPluginManager);
	virtual ~WingChangeDesc();
	const proto_ff_s::wingchange_s* GetDesc(int id) const;
	proto_ff_s::wingchange_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::wingchange_s, MAX_WING_CHANGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::wingchange_s, MAX_WING_CHANGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::wingchange_s, wingchange, MAX_WING_CHANGE_NUM);
DECLARE_IDCREATE(WingChangeDesc);
};
