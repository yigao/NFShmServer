#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_VALUE_NUM 2048

class MountValueDesc : public NFIDescTemplate<MountValueDesc, proto_ff_s::E_MountValue_s, EOT_CONST_MOUNT_VALUE_DESC_ID, MAX_MOUNT_VALUE_NUM>
{
public:
	MountValueDesc();
	virtual ~MountValueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
