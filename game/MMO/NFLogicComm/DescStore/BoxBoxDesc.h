#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/box_s.h"

#define MAX_BOX_BOX_NUM 6000

class BoxBoxDesc : public NFIDescStore
{
public:
	BoxBoxDesc(NFIPluginManager* pPluginManager);
	virtual ~BoxBoxDesc();
	const proto_ff_s::boxbox_s* GetDesc(int id) const;
	proto_ff_s::boxbox_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::boxbox_s, MAX_BOX_BOX_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::boxbox_s, MAX_BOX_BOX_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::boxbox_s, boxbox, MAX_BOX_BOX_NUM);
DECLARE_IDCREATE(BoxBoxDesc);
};
