#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_DISPLAY_NUM 32

class MountDisplayDesc : public NFIDescTemplate<MountDisplayDesc, proto_ff_s::E_MountDisplay_s, EOT_CONST_MOUNT_DISPLAY_DESC_ID, MAX_MOUNT_DISPLAY_NUM>
{
public:
	MountDisplayDesc();
	virtual ~MountDisplayDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
