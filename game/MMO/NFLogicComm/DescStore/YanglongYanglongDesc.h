#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Yanglong_s.h"

#define MAX_YANGLONG_YANGLONG_NUM 16

class YanglongYanglongDesc : public NFIDescStore
{
public:
	YanglongYanglongDesc();
	virtual ~YanglongYanglongDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_YanglongYanglong_s* GetDesc(int64_t id) const;
	proto_ff_s::E_YanglongYanglong_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_YanglongYanglong_s* GetDescByIndex(int index) const;
	proto_ff_s::E_YanglongYanglong_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(YanglongYanglongDesc, proto_ff_s::E_YanglongYanglong_s, E_YanglongYanglong, MAX_YANGLONG_YANGLONG_NUM);
DECLARE_IDCREATE(YanglongYanglongDesc);
};
