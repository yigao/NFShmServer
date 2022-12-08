#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_VALUE_NUM 500

class FacadeValueDesc : public NFIDescStore
{
public:
	FacadeValueDesc();
	virtual ~FacadeValueDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::facadevalue_s* GetDesc(int id) const;
	proto_ff_s::facadevalue_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::facadevalue_s, facadevalue, MAX_FACADE_VALUE_NUM);
DECLARE_IDCREATE(FacadeValueDesc);
};
