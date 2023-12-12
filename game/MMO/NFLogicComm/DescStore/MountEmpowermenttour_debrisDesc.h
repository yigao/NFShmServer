#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EMPOWERMENTTOUR_DEBRIS_NUM 16

class MountEmpowermenttour_debrisDesc : public NFIDescTemplate<MountEmpowermenttour_debrisDesc, proto_ff_s::E_MountEmpowermenttour_debris_s, EOT_CONST_MOUNT_EMPOWERMENTTOUR_DEBRIS_DESC_ID, MAX_MOUNT_EMPOWERMENTTOUR_DEBRIS_NUM>
{
public:
	MountEmpowermenttour_debrisDesc();
	virtual ~MountEmpowermenttour_debrisDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
