#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_CHILD_NUM 16

class MarryChildDesc : public NFIDescStore
{
public:
	MarryChildDesc();
	virtual ~MarryChildDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryChild_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryChild_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryChild_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryChild_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryChildDesc, proto_ff_s::E_MarryChild_s, E_MarryChild, MAX_MARRY_CHILD_NUM);
DECLARE_IDCREATE(MarryChildDesc);
};
