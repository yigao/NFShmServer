#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_HUAKUN_EQUIP_NUM 64

class MountHuakun_equipDesc : public NFIDescTemplate<MountHuakun_equipDesc, proto_ff_s::E_MountHuakun_equip_s, EOT_CONST_MOUNT_HUAKUN_EQUIP_DESC_ID, MAX_MOUNT_HUAKUN_EQUIP_NUM>
{
public:
	MountHuakun_equipDesc();
	virtual ~MountHuakun_equipDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
