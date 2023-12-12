#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_HUAKUN_ADVANCEVALUE_NUM 128

class MountHuakun_advancevalueDesc : public NFIDescTemplate<MountHuakun_advancevalueDesc, proto_ff_s::E_MountHuakun_advancevalue_s, EOT_CONST_MOUNT_HUAKUN_ADVANCEVALUE_DESC_ID, MAX_MOUNT_HUAKUN_ADVANCEVALUE_NUM>
{
public:
	MountHuakun_advancevalueDesc();
	virtual ~MountHuakun_advancevalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
