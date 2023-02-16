#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_STARUP_NUM 40

class FacadeStarupDesc : public NFIDescStore
{
public:
	FacadeStarupDesc();
	virtual ~FacadeStarupDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FacadeStarup_s* GetDesc(int id) const;
	proto_ff_s::E_FacadeStarup_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_FacadeStarup_s, facadestarUp, MAX_FACADE_STARUP_NUM);
DECLARE_IDCREATE(FacadeStarupDesc);
};
