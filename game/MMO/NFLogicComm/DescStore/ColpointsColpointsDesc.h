#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/colPoints_s.h"

#define MAX_COLPOINTS_COLPOINTS_NUM 20

class ColpointsColpointsDesc : public NFIDescStore
{
public:
	ColpointsColpointsDesc(NFIPluginManager* pPluginManager);
	virtual ~ColpointsColpointsDesc();
	const proto_ff_s::colPointscolPoints_s* GetDesc(int id) const;
	proto_ff_s::colPointscolPoints_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::colPointscolPoints_s, MAX_COLPOINTS_COLPOINTS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::colPointscolPoints_s, MAX_COLPOINTS_COLPOINTS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::colPointscolPoints_s, colPointscolPoints, MAX_COLPOINTS_COLPOINTS_NUM);
DECLARE_IDCREATE(ColpointsColpointsDesc);
};
