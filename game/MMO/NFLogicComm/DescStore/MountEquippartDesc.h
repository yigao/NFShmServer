#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EQUIPPART_NUM 16

class MountEquippartDesc : public NFIDescTemplate<MountEquippartDesc, proto_ff_s::E_MountEquippart_s, EOT_CONST_MOUNT_EQUIPPART_DESC_ID, MAX_MOUNT_EQUIPPART_NUM>
{
public:
	MountEquippartDesc();
	virtual ~MountEquippartDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
