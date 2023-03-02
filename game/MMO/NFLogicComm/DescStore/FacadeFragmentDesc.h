#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_FRAGMENT_NUM 20

class FacadeFragmentDesc : public NFIDescStore
{
public:
	FacadeFragmentDesc();
	virtual ~FacadeFragmentDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FacadeFragment_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FacadeFragment_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FacadeFragment_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FacadeFragment_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_FacadeFragment_s, E_FacadeFragment, MAX_FACADE_FRAGMENT_NUM);
DECLARE_IDCREATE(FacadeFragmentDesc);
};
