#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/assist_s.h"

#define MAX_ASSIST_THANK_NUM 20

class AssistThankDesc : public NFIDescStore
{
public:
	AssistThankDesc();
	virtual ~AssistThankDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AssistThank_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AssistThank_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AssistThank_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AssistThank_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(AssistThankDesc, proto_ff_s::E_AssistThank_s, E_AssistThank, MAX_ASSIST_THANK_NUM);
DECLARE_IDCREATE(AssistThankDesc);
};
