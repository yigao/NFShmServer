#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_STARUP_NUM 512

class FacadeStarupDesc : public NFIDescStore
{
public:
	FacadeStarupDesc();
	virtual ~FacadeStarupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FacadeStarup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FacadeStarup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FacadeStarup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FacadeStarup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FacadeStarupDesc, proto_ff_s::E_FacadeStarup_s, E_FacadeStarup, MAX_FACADE_STARUP_NUM);
DECLARE_IDCREATE(FacadeStarupDesc);
};
