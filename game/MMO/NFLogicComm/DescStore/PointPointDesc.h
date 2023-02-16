#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/point_s.h"

#define MAX_POINT_POINT_NUM 100

class PointPointDesc : public NFIDescStore
{
public:
	PointPointDesc();
	virtual ~PointPointDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PointPoint_s* GetDesc(int id) const;
	proto_ff_s::E_PointPoint_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_PointPoint_s, pointpoint, MAX_POINT_POINT_NUM);
DECLARE_IDCREATE(PointPointDesc);
};
