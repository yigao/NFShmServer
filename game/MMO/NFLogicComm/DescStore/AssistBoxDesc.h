#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Assist_s.h"

#define MAX_ASSIST_BOX_NUM 8

class AssistBoxDesc : public NFIDescStore
{
public:
	AssistBoxDesc();
	virtual ~AssistBoxDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AssistBox_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AssistBox_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AssistBox_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AssistBox_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AssistBoxDesc, proto_ff_s::E_AssistBox_s, E_AssistBox, MAX_ASSIST_BOX_NUM);
DECLARE_IDCREATE_GLOBAL(AssistBoxDesc);
};
