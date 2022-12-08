#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_SOULACTIVE_NUM 40

class FacadeSoulactiveDesc : public NFIDescStore
{
public:
	FacadeSoulactiveDesc();
	virtual ~FacadeSoulactiveDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::facadesoulActive_s* GetDesc(int id) const;
	proto_ff_s::facadesoulActive_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::facadesoulActive_s, facadesoulActive, MAX_FACADE_SOULACTIVE_NUM);
DECLARE_IDCREATE(FacadeSoulactiveDesc);
};
