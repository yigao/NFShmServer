#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_VALUE_NUM 1024

class FacadeValueDesc : public NFIDescStore
{
public:
	FacadeValueDesc();
	virtual ~FacadeValueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FacadeValue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FacadeValue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FacadeValue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FacadeValue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FacadeValueDesc, proto_ff_s::E_FacadeValue_s, E_FacadeValue, MAX_FACADE_VALUE_NUM);
DECLARE_IDCREATE_GLOBAL(FacadeValueDesc);
};
