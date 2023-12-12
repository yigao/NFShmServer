#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_HUAKUN_NUM 8

class MountHuakunDesc : public NFIDescTemplate<MountHuakunDesc, proto_ff_s::E_MountHuakun_s, EOT_CONST_MOUNT_HUAKUN_DESC_ID, MAX_MOUNT_HUAKUN_NUM>
{
public:
	MountHuakunDesc();
	virtual ~MountHuakunDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
