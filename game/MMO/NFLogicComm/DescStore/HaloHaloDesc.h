#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/halo_s.h"

#define MAX_HALO_HALO_NUM 20

class HaloHaloDesc : public NFIDescStore
{
public:
	HaloHaloDesc();
	virtual ~HaloHaloDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_HaloHalo_s* GetDesc(int id) const;
	proto_ff_s::E_HaloHalo_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_HaloHalo_s, E_HaloHalo, MAX_HALO_HALO_NUM);
DECLARE_IDCREATE(HaloHaloDesc);
};
