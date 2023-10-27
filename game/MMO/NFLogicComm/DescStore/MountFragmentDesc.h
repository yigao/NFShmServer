#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_FRAGMENT_NUM 16

class MountFragmentDesc : public NFIDescTemplate<MountFragmentDesc, proto_ff_s::E_MountFragment_s, EOT_CONST_MOUNT_FRAGMENT_DESC_ID, MAX_MOUNT_FRAGMENT_NUM>
{
public:
	MountFragmentDesc();
	virtual ~MountFragmentDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
