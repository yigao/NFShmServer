#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EMPOWERMENTTOUR_DEBRIS_NUM 16

class MountEmpowermenttour_debrisDesc : public NFIDescStore
{
public:
	MountEmpowermenttour_debrisDesc();
	virtual ~MountEmpowermenttour_debrisDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountEmpowermenttour_debris_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountEmpowermenttour_debris_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountEmpowermenttour_debris_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountEmpowermenttour_debris_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountEmpowermenttour_debrisDesc, proto_ff_s::E_MountEmpowermenttour_debris_s, E_MountEmpowermenttour_debris, MAX_MOUNT_EMPOWERMENTTOUR_DEBRIS_NUM);
DECLARE_IDCREATE(MountEmpowermenttour_debrisDesc);
};
