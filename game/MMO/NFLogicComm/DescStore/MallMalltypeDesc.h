#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mall_s.h"

#define MAX_MALL_MALLTYPE_NUM 20

class MallMalltypeDesc : public NFIDescStore
{
public:
	MallMalltypeDesc();
	virtual ~MallMalltypeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MallMalltype_s* GetDesc(int id) const;
	proto_ff_s::E_MallMalltype_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MallMalltype_s, E_MallMalltype, MAX_MALL_MALLTYPE_NUM);
DECLARE_IDCREATE(MallMalltypeDesc);
};