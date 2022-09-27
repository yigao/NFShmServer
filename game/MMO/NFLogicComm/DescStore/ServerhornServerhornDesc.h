#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/serverHorn_s.h"

#define MAX_SERVERHORN_SERVERHORN_NUM 20

class ServerhornServerhornDesc : public NFIDescStore
{
public:
	ServerhornServerhornDesc(NFIPluginManager* pPluginManager);
	virtual ~ServerhornServerhornDesc();
	const proto_ff_s::serverHornserverHorn_s* GetDesc(int id) const;
	proto_ff_s::serverHornserverHorn_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::serverHornserverHorn_s, MAX_SERVERHORN_SERVERHORN_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::serverHornserverHorn_s, MAX_SERVERHORN_SERVERHORN_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::serverHornserverHorn_s, serverHornserverHorn, MAX_SERVERHORN_SERVERHORN_NUM);
DECLARE_IDCREATE(ServerhornServerhornDesc);
};
