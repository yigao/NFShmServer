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
	const proto_ff_s::E_AssistThank_s* GetDesc(int id) const;
	proto_ff_s::E_AssistThank_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_AssistThank_s, E_AssistThank, MAX_ASSIST_THANK_NUM);
DECLARE_IDCREATE(AssistThankDesc);
};
