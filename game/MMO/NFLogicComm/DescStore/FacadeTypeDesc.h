#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_TYPE_NUM 20

class FacadeTypeDesc : public NFIDescStore
{
public:
	FacadeTypeDesc();
	virtual ~FacadeTypeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FacadeType_s* GetDesc(int id) const;
	proto_ff_s::E_FacadeType_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_FacadeType_s, E_FacadeType, MAX_FACADE_TYPE_NUM);
DECLARE_IDCREATE(FacadeTypeDesc);
};
