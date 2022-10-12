#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/wing_s.h"

#define MAX_WING_FRAGMENT_NUM 20

class WingFragmentDesc : public NFIDescStore
{
public:
	WingFragmentDesc(NFIPluginManager* pPluginManager);
	virtual ~WingFragmentDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::wingfragment_s* GetDesc(int id) const;
	proto_ff_s::wingfragment_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::wingfragment_s, MAX_WING_FRAGMENT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::wingfragment_s, MAX_WING_FRAGMENT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::wingfragment_s, wingfragment, MAX_WING_FRAGMENT_NUM);
DECLARE_IDCREATE(WingFragmentDesc);
};
