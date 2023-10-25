#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EMPOWERMENT_EVENT_NUM 16

class MountEmpowerment_eventDesc : public NFIDescStore
{
public:
	MountEmpowerment_eventDesc();
	virtual ~MountEmpowerment_eventDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountEmpowerment_event_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountEmpowerment_event_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountEmpowerment_event_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountEmpowerment_event_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountEmpowerment_eventDesc, proto_ff_s::E_MountEmpowerment_event_s, E_MountEmpowerment_event, MAX_MOUNT_EMPOWERMENT_EVENT_NUM);
DECLARE_IDCREATE_GLOBAL(MountEmpowerment_eventDesc);
};
