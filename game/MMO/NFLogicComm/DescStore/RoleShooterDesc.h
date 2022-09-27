#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_SHOOTER_NUM 2000

class RoleShooterDesc : public NFIDescStore
{
public:
	RoleShooterDesc(NFIPluginManager* pPluginManager);
	virtual ~RoleShooterDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::roleshooter_s* GetDesc(int id) const;
	proto_ff_s::roleshooter_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::roleshooter_s, MAX_ROLE_SHOOTER_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::roleshooter_s, MAX_ROLE_SHOOTER_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::roleshooter_s, roleshooter, MAX_ROLE_SHOOTER_NUM);
DECLARE_IDCREATE(RoleShooterDesc);
};
