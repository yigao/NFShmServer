#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Point_s.h"

#define MAX_POINT_POINT_NUM 2048

class PointPointDesc : public NFIDescStore
{
public:
	PointPointDesc();
	virtual ~PointPointDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PointPoint_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PointPoint_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PointPoint_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PointPoint_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PointPointDesc, proto_ff_s::E_PointPoint_s, E_PointPoint, MAX_POINT_POINT_NUM);
DECLARE_IDCREATE(PointPointDesc);
};
