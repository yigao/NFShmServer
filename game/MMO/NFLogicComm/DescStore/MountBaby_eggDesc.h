#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_BABY_EGG_NUM 8

class MountBaby_eggDesc : public NFIDescTemplate<MountBaby_eggDesc, proto_ff_s::E_MountBaby_egg_s, EOT_CONST_MOUNT_BABY_EGG_DESC_ID, MAX_MOUNT_BABY_EGG_NUM>
{
public:
	MountBaby_eggDesc();
	virtual ~MountBaby_eggDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
