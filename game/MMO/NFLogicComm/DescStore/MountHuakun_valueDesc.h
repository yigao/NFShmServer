#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_HUAKUN_VALUE_NUM 512

class MountHuakun_valueDesc : public NFIDescTemplate<MountHuakun_valueDesc, proto_ff_s::E_MountHuakun_value_s, EOT_CONST_MOUNT_HUAKUN_VALUE_DESC_ID, MAX_MOUNT_HUAKUN_VALUE_NUM>
{
public:
	MountHuakun_valueDesc();
	virtual ~MountHuakun_valueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
