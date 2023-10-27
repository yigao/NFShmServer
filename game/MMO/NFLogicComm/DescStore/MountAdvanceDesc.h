#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_ADVANCE_NUM 64

class MountAdvanceDesc : public NFIDescTemplate<MountAdvanceDesc, proto_ff_s::E_MountAdvance_s, EOT_CONST_MOUNT_ADVANCE_DESC_ID, MAX_MOUNT_ADVANCE_NUM>
{
public:
	MountAdvanceDesc();
	virtual ~MountAdvanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
