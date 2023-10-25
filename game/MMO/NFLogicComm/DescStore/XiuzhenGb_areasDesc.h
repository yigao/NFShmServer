#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GB_AREAS_NUM 64

class XiuzhenGb_areasDesc : public NFIDescStore
{
public:
	XiuzhenGb_areasDesc();
	virtual ~XiuzhenGb_areasDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenGb_areas_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenGb_areas_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenGb_areas_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenGb_areas_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenGb_areasDesc, proto_ff_s::E_XiuzhenGb_areas_s, E_XiuzhenGb_areas, MAX_XIUZHEN_GB_AREAS_NUM);
DECLARE_IDCREATE_GLOBAL(XiuzhenGb_areasDesc);
};
