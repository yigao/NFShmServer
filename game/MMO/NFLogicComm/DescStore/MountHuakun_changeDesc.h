#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_HUAKUN_CHANGE_NUM 8

class MountHuakun_changeDesc : public NFIDescTemplate<MountHuakun_changeDesc, proto_ff_s::E_MountHuakun_change_s, EOT_CONST_MOUNT_HUAKUN_CHANGE_DESC_ID, MAX_MOUNT_HUAKUN_CHANGE_NUM>
{
public:
	MountHuakun_changeDesc();
	virtual ~MountHuakun_changeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
