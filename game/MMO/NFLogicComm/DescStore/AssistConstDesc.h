#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/assist_s.h"

#define MAX_ASSIST_CONST_NUM 20

class AssistConstDesc : public NFIDescStore
{
public:
	AssistConstDesc();
	virtual ~AssistConstDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AssistConst_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AssistConst_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AssistConst_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AssistConst_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(AssistConstDesc, proto_ff_s::E_AssistConst_s, E_AssistConst, MAX_ASSIST_CONST_NUM);
DECLARE_IDCREATE(AssistConstDesc);
};
