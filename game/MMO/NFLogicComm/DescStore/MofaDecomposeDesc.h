#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_DECOMPOSE_NUM 8

class MofaDecomposeDesc : public NFIDescStore
{
public:
	MofaDecomposeDesc();
	virtual ~MofaDecomposeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MofaDecompose_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MofaDecompose_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MofaDecompose_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MofaDecompose_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MofaDecomposeDesc, proto_ff_s::E_MofaDecompose_s, E_MofaDecompose, MAX_MOFA_DECOMPOSE_NUM);
DECLARE_IDCREATE_GLOBAL(MofaDecomposeDesc);
};
