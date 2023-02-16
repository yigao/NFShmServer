#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/assist_s.h"

#define MAX_ASSIST_ASSISTBOX_NUM 20

class AssistAssistboxDesc : public NFIDescStore
{
public:
	AssistAssistboxDesc();
	virtual ~AssistAssistboxDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AssistAssistbox_s* GetDesc(int id) const;
	proto_ff_s::E_AssistAssistbox_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_AssistAssistbox_s, E_AssistAssistbox, MAX_ASSIST_ASSISTBOX_NUM);
DECLARE_IDCREATE(AssistAssistboxDesc);
};
