#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mount_s.h"

#define MAX_MOUNT_MOUNT_NUM 80

class MountMountDesc : public NFIDescStore
{
public:
	MountMountDesc(NFIPluginManager* pPluginManager);
	virtual ~MountMountDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::mountmount_s* GetDesc(int id) const;
	proto_ff_s::mountmount_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::mountmount_s, MAX_MOUNT_MOUNT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::mountmount_s, MAX_MOUNT_MOUNT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::mountmount_s, mountmount, MAX_MOUNT_MOUNT_NUM);
DECLARE_IDCREATE(MountMountDesc);
};
