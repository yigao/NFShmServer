#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EMPOWERMENT_NUM 128

class MountEmpowermentDesc : public NFIDescStore
{
public:
	MountEmpowermentDesc();
	virtual ~MountEmpowermentDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountEmpowerment_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountEmpowerment_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountEmpowerment_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountEmpowerment_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountEmpowermentDesc, proto_ff_s::E_MountEmpowerment_s, E_MountEmpowerment, MAX_MOUNT_EMPOWERMENT_NUM);
DECLARE_IDCREATE(MountEmpowermentDesc);
};
