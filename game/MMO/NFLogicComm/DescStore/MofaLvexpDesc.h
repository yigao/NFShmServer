#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_LVEXP_NUM 128

class MofaLvexpDesc : public NFIDescStore
{
public:
	MofaLvexpDesc();
	virtual ~MofaLvexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MofaLvexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MofaLvexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MofaLvexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MofaLvexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MofaLvexpDesc, proto_ff_s::E_MofaLvexp_s, E_MofaLvexp, MAX_MOFA_LVEXP_NUM);
DECLARE_IDCREATE_GLOBAL(MofaLvexpDesc);
};
