#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EMPOWERMENT_EVENT_NUM 16

class MountEmpowerment_eventDesc : public NFIDescTemplate<MountEmpowerment_eventDesc, proto_ff_s::E_MountEmpowerment_event_s, EOT_CONST_MOUNT_EMPOWERMENT_EVENT_DESC_ID, MAX_MOUNT_EMPOWERMENT_EVENT_NUM>
{
public:
	MountEmpowerment_eventDesc();
	virtual ~MountEmpowerment_eventDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
