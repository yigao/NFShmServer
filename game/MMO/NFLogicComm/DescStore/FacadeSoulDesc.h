#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_SOUL_NUM 20

class FacadeSoulDesc : public NFIDescStore
{
public:
	FacadeSoulDesc();
	virtual ~FacadeSoulDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::facadesoul_s* GetDesc(int id) const;
	proto_ff_s::facadesoul_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::facadesoul_s, facadesoul, MAX_FACADE_SOUL_NUM);
DECLARE_IDCREATE(FacadeSoulDesc);
};
