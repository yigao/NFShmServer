#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/assist_s.h"

#define MAX_ASSIST_ASSISTTHANK_NUM 20

class AssistAssistthankDesc : public NFIDescStore
{
public:
	AssistAssistthankDesc();
	virtual ~AssistAssistthankDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AssistAssistthank_s* GetDesc(int id) const;
	proto_ff_s::E_AssistAssistthank_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_AssistAssistthank_s, E_AssistAssistthank, MAX_ASSIST_ASSISTTHANK_NUM);
DECLARE_IDCREATE(AssistAssistthankDesc);
};
