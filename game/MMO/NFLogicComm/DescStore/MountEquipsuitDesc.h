#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EQUIPSUIT_NUM 32

class MountEquipsuitDesc : public NFIDescTemplate<MountEquipsuitDesc, proto_ff_s::E_MountEquipsuit_s, EOT_CONST_MOUNT_EQUIPSUIT_DESC_ID, MAX_MOUNT_EQUIPSUIT_NUM>
{
public:
	MountEquipsuitDesc();
	virtual ~MountEquipsuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
