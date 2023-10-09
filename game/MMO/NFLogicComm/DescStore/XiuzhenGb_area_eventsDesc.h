#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GB_AREA_EVENTS_NUM 32

class XiuzhenGb_area_eventsDesc : public NFIDescStore
{
public:
	XiuzhenGb_area_eventsDesc();
	virtual ~XiuzhenGb_area_eventsDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenGb_area_events_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenGb_area_events_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenGb_area_events_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenGb_area_events_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenGb_area_eventsDesc, proto_ff_s::E_XiuzhenGb_area_events_s, E_XiuzhenGb_area_events, MAX_XIUZHEN_GB_AREA_EVENTS_NUM);
DECLARE_IDCREATE(XiuzhenGb_area_eventsDesc);
};
