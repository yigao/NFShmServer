#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_QUALITYLV_NUM 16

class GodevilQualitylvDesc : public NFIDescStore
{
public:
	GodevilQualitylvDesc();
	virtual ~GodevilQualitylvDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodevilQualitylv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilQualitylv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilQualitylv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilQualitylv_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodevilQualitylvDesc, proto_ff_s::E_GodevilQualitylv_s, E_GodevilQualitylv, MAX_GODEVIL_QUALITYLV_NUM);
DECLARE_IDCREATE_GLOBAL(GodevilQualitylvDesc);
};
