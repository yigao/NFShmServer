#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Halo_s.h"

#define MAX_HALO_HALO_NUM 8

class HaloHaloDesc : public NFIDescTemplate<HaloHaloDesc, proto_ff_s::E_HaloHalo_s, EOT_CONST_HALO_HALO_DESC_ID, MAX_HALO_HALO_NUM>
{
public:
	HaloHaloDesc();
	virtual ~HaloHaloDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
