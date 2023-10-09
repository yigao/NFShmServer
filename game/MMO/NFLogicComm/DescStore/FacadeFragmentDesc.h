#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_FRAGMENT_NUM 16

class FacadeFragmentDesc : public NFIDescStore
{
public:
	FacadeFragmentDesc();
	virtual ~FacadeFragmentDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FacadeFragment_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FacadeFragment_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FacadeFragment_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FacadeFragment_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FacadeFragmentDesc, proto_ff_s::E_FacadeFragment_s, E_FacadeFragment, MAX_FACADE_FRAGMENT_NUM);
DECLARE_IDCREATE(FacadeFragmentDesc);
};
