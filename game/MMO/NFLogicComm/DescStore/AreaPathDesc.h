#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/area_s.h"

#define MAX_AREA_PATH_NUM 2000

class AreaPathDesc : public NFIDescStore
{
public:
	AreaPathDesc(NFIPluginManager* pPluginManager);
	virtual ~AreaPathDesc();
	const proto_ff_s::areapath_s* GetDesc(int id) const;
	proto_ff_s::areapath_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::areapath_s, MAX_AREA_PATH_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::areapath_s, MAX_AREA_PATH_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::areapath_s, areapath, MAX_AREA_PATH_NUM);
DECLARE_IDCREATE(AreaPathDesc);
};
