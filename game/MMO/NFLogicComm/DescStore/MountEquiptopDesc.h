#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EQUIPTOP_NUM 16

class MountEquiptopDesc : public NFIDescTemplate<MountEquiptopDesc, proto_ff_s::E_MountEquiptop_s, EOT_CONST_MOUNT_EQUIPTOP_DESC_ID, MAX_MOUNT_EQUIPTOP_NUM>
{
public:
	MountEquiptopDesc();
	virtual ~MountEquiptopDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
