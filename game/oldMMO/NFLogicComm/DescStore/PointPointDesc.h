#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/point_s.h"

#define MAX_POINT_POINT_NUM 400

class PointPointDesc : public NFIDescStore
{
public:
	PointPointDesc();
	virtual ~PointPointDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PointPoint_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PointPoint_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PointPoint_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PointPoint_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(PointPointDesc, proto_ff_s::E_PointPoint_s, E_PointPoint, MAX_POINT_POINT_NUM);
DECLARE_IDCREATE(PointPointDesc);
};
