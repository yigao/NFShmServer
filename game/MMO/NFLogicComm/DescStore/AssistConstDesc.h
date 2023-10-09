#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Assist_s.h"

#define MAX_ASSIST_CONST_NUM 2

class AssistConstDesc : public NFIDescStore
{
public:
	AssistConstDesc();
	virtual ~AssistConstDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AssistConst_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AssistConst_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AssistConst_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AssistConst_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AssistConstDesc, proto_ff_s::E_AssistConst_s, E_AssistConst, MAX_ASSIST_CONST_NUM);
DECLARE_IDCREATE(AssistConstDesc);
};
