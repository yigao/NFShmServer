#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/assist_s.h"

#define MAX_ASSIST_BOX_NUM 20

class AssistBoxDesc : public NFIDescStore
{
public:
	AssistBoxDesc();
	virtual ~AssistBoxDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AssistBox_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AssistBox_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AssistBox_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AssistBox_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(AssistBoxDesc, proto_ff_s::E_AssistBox_s, E_AssistBox, MAX_ASSIST_BOX_NUM);
DECLARE_IDCREATE(AssistBoxDesc);
};
