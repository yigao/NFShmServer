#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_YT_DUP_NUM 1024

class DupYt_dupDesc : public NFIDescStore
{
public:
	DupYt_dupDesc();
	virtual ~DupYt_dupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DupYt_dup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupYt_dup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupYt_dup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupYt_dup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DupYt_dupDesc, proto_ff_s::E_DupYt_dup_s, E_DupYt_dup, MAX_DUP_YT_DUP_NUM);
DECLARE_IDCREATE(DupYt_dupDesc);
};
