#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EMPOWERMENT_SLOT_NUM 16

class MountEmpowerment_slotDesc : public NFIDescTemplate<MountEmpowerment_slotDesc, proto_ff_s::E_MountEmpowerment_slot_s, EOT_CONST_MOUNT_EMPOWERMENT_SLOT_DESC_ID, MAX_MOUNT_EMPOWERMENT_SLOT_NUM>
{
public:
	MountEmpowerment_slotDesc();
	virtual ~MountEmpowerment_slotDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
