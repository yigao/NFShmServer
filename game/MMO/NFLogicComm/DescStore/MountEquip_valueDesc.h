#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EQUIP_VALUE_NUM 4096

class MountEquip_valueDesc : public NFIDescTemplate<MountEquip_valueDesc, proto_ff_s::E_MountEquip_value_s, EOT_CONST_MOUNT_EQUIP_VALUE_DESC_ID, MAX_MOUNT_EQUIP_VALUE_NUM>
{
public:
	MountEquip_valueDesc();
	virtual ~MountEquip_valueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
