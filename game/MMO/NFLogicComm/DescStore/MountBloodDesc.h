#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_BLOOD_NUM 32

class MountBloodDesc : public NFIDescTemplate<MountBloodDesc, proto_ff_s::E_MountBlood_s, EOT_CONST_MOUNT_BLOOD_DESC_ID, MAX_MOUNT_BLOOD_NUM>
{
public:
	MountBloodDesc();
	virtual ~MountBloodDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
