#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EMPOWERMENT_NUM 128

class MountEmpowermentDesc : public NFIDescTemplate<MountEmpowermentDesc, proto_ff_s::E_MountEmpowerment_s, EOT_CONST_MOUNT_EMPOWERMENT_DESC_ID, MAX_MOUNT_EMPOWERMENT_NUM>
{
public:
	MountEmpowermentDesc();
	virtual ~MountEmpowermentDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
