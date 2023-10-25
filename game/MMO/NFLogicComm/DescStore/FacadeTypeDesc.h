#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_TYPE_NUM 8

class FacadeTypeDesc : public NFIDescStore
{
public:
	FacadeTypeDesc();
	virtual ~FacadeTypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FacadeType_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FacadeType_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FacadeType_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FacadeType_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FacadeTypeDesc, proto_ff_s::E_FacadeType_s, E_FacadeType, MAX_FACADE_TYPE_NUM);
DECLARE_IDCREATE_GLOBAL(FacadeTypeDesc);
};
