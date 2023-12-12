#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EQUIPTOPVALUE_NUM 128

class MountEquiptopvalueDesc : public NFIDescTemplate<MountEquiptopvalueDesc, proto_ff_s::E_MountEquiptopvalue_s, EOT_CONST_MOUNT_EQUIPTOPVALUE_DESC_ID, MAX_MOUNT_EQUIPTOPVALUE_NUM>
{
public:
	MountEquiptopvalueDesc();
	virtual ~MountEquiptopvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
