#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_HUAKUN_ADVANCE_NUM 128

class MountHuakun_advanceDesc : public NFIDescTemplate<MountHuakun_advanceDesc, proto_ff_s::E_MountHuakun_advance_s, EOT_CONST_MOUNT_HUAKUN_ADVANCE_DESC_ID, MAX_MOUNT_HUAKUN_ADVANCE_NUM>
{
public:
	MountHuakun_advanceDesc();
	virtual ~MountHuakun_advanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
