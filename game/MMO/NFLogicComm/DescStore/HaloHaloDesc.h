#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Halo_s.h"

#define MAX_HALO_HALO_NUM 8

class HaloHaloDesc : public NFIDescStore
{
public:
	HaloHaloDesc();
	virtual ~HaloHaloDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_HaloHalo_s* GetDesc(int64_t id) const;
	proto_ff_s::E_HaloHalo_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_HaloHalo_s* GetDescByIndex(int index) const;
	proto_ff_s::E_HaloHalo_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(HaloHaloDesc, proto_ff_s::E_HaloHalo_s, E_HaloHalo, MAX_HALO_HALO_NUM);
DECLARE_IDCREATE(HaloHaloDesc);
};
