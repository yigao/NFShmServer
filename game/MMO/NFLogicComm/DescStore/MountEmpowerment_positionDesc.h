#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EMPOWERMENT_POSITION_NUM 8

class MountEmpowerment_positionDesc : public NFIDescTemplate<MountEmpowerment_positionDesc, proto_ff_s::E_MountEmpowerment_position_s, EOT_CONST_MOUNT_EMPOWERMENT_POSITION_DESC_ID, MAX_MOUNT_EMPOWERMENT_POSITION_NUM>
{
public:
	MountEmpowerment_positionDesc();
	virtual ~MountEmpowerment_positionDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
