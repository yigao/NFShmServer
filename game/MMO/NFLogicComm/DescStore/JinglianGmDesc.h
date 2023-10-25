#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Jinglian_s.h"

#define MAX_JINGLIAN_GM_NUM 16

class JinglianGmDesc : public NFIDescStore
{
public:
	JinglianGmDesc();
	virtual ~JinglianGmDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_JinglianGm_s* GetDesc(int64_t id) const;
	proto_ff_s::E_JinglianGm_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_JinglianGm_s* GetDescByIndex(int index) const;
	proto_ff_s::E_JinglianGm_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(JinglianGmDesc, proto_ff_s::E_JinglianGm_s, E_JinglianGm, MAX_JINGLIAN_GM_NUM);
DECLARE_IDCREATE_GLOBAL(JinglianGmDesc);
};
