#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_CHANGE_NUM 32

class MountChangeDesc : public NFIDescTemplate<MountChangeDesc, proto_ff_s::E_MountChange_s, EOT_CONST_MOUNT_CHANGE_DESC_ID, MAX_MOUNT_CHANGE_NUM>
{
public:
	MountChangeDesc();
	virtual ~MountChangeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
