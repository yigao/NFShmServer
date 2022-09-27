#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/wing_s.h"

#define MAX_WING_WING_NUM 500

class WingWingDesc : public NFIDescStore
{
public:
	WingWingDesc(NFIPluginManager* pPluginManager);
	virtual ~WingWingDesc();
	const proto_ff_s::wingwing_s* GetDesc(int id) const;
	proto_ff_s::wingwing_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::wingwing_s, MAX_WING_WING_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::wingwing_s, MAX_WING_WING_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::wingwing_s, wingwing, MAX_WING_WING_NUM);
DECLARE_IDCREATE(WingWingDesc);
};
