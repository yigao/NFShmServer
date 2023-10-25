#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_CHILDEXP_NUM 32

class MarryChildexpDesc : public NFIDescStore
{
public:
	MarryChildexpDesc();
	virtual ~MarryChildexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryChildexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryChildexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryChildexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryChildexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryChildexpDesc, proto_ff_s::E_MarryChildexp_s, E_MarryChildexp, MAX_MARRY_CHILDEXP_NUM);
DECLARE_IDCREATE_GLOBAL(MarryChildexpDesc);
};
