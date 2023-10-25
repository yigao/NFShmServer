#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Jinglian_s.h"

#define MAX_JINGLIAN_LV_NUM 1024

class JinglianLvDesc : public NFIDescStore
{
public:
	JinglianLvDesc();
	virtual ~JinglianLvDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_JinglianLv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_JinglianLv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_JinglianLv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_JinglianLv_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(JinglianLvDesc, proto_ff_s::E_JinglianLv_s, E_JinglianLv, MAX_JINGLIAN_LV_NUM);
DECLARE_IDCREATE_GLOBAL(JinglianLvDesc);
};
