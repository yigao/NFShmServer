#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mount_s.h"

#define MAX_MOUNT_STARUP_NUM 80

class MountStarupDesc : public NFIDescStore
{
public:
	MountStarupDesc(NFIPluginManager* pPluginManager);
	virtual ~MountStarupDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::mountstarUp_s* GetDesc(int id) const;
	proto_ff_s::mountstarUp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::mountstarUp_s, MAX_MOUNT_STARUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::mountstarUp_s, MAX_MOUNT_STARUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::mountstarUp_s, mountstarUp, MAX_MOUNT_STARUP_NUM);
DECLARE_IDCREATE(MountStarupDesc);
};
