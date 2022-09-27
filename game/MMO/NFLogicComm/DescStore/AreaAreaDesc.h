#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/area_s.h"

#define MAX_AREA_AREA_NUM 300

class AreaAreaDesc : public NFIDescStore
{
public:
	AreaAreaDesc(NFIPluginManager* pPluginManager);
	virtual ~AreaAreaDesc();
	const proto_ff_s::areaarea_s* GetDesc(int id) const;
	proto_ff_s::areaarea_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::areaarea_s, MAX_AREA_AREA_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::areaarea_s, MAX_AREA_AREA_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::areaarea_s, areaarea, MAX_AREA_AREA_NUM);
DECLARE_IDCREATE(AreaAreaDesc);
};
