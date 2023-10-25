#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EMPOWERMENT_POSITION_NUM 8

class MountEmpowerment_positionDesc : public NFIDescStore
{
public:
	MountEmpowerment_positionDesc();
	virtual ~MountEmpowerment_positionDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountEmpowerment_position_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountEmpowerment_position_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountEmpowerment_position_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountEmpowerment_position_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountEmpowerment_positionDesc, proto_ff_s::E_MountEmpowerment_position_s, E_MountEmpowerment_position, MAX_MOUNT_EMPOWERMENT_POSITION_NUM);
DECLARE_IDCREATE_GLOBAL(MountEmpowerment_positionDesc);
};
