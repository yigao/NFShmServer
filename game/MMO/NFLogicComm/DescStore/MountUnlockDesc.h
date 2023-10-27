#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_UNLOCK_NUM 8

class MountUnlockDesc : public NFIDescTemplate<MountUnlockDesc, proto_ff_s::E_MountUnlock_s, EOT_CONST_MOUNT_UNLOCK_DESC_ID, MAX_MOUNT_UNLOCK_NUM>
{
public:
	MountUnlockDesc();
	virtual ~MountUnlockDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
