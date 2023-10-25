#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_CHANGE_NUM 64

class FacadeChangeDesc : public NFIDescStore
{
public:
	FacadeChangeDesc();
	virtual ~FacadeChangeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FacadeChange_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FacadeChange_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FacadeChange_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FacadeChange_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FacadeChangeDesc, proto_ff_s::E_FacadeChange_s, E_FacadeChange, MAX_FACADE_CHANGE_NUM);
DECLARE_IDCREATE_GLOBAL(FacadeChangeDesc);
};
