#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Assist_s.h"

#define MAX_ASSIST_THANK_NUM 16

class AssistThankDesc : public NFIDescStore
{
public:
	AssistThankDesc();
	virtual ~AssistThankDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AssistThank_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AssistThank_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AssistThank_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AssistThank_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AssistThankDesc, proto_ff_s::E_AssistThank_s, E_AssistThank, MAX_ASSIST_THANK_NUM);
DECLARE_IDCREATE(AssistThankDesc);
};
