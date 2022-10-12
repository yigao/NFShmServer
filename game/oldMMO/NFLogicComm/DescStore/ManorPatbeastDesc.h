#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/manor_s.h"

#define MAX_MANOR_PATBEAST_NUM 20

class ManorPatbeastDesc : public NFIDescStore
{
public:
	ManorPatbeastDesc(NFIPluginManager* pPluginManager);
	virtual ~ManorPatbeastDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::manorpatBeast_s* GetDesc(int id) const;
	proto_ff_s::manorpatBeast_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::manorpatBeast_s, MAX_MANOR_PATBEAST_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::manorpatBeast_s, MAX_MANOR_PATBEAST_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::manorpatBeast_s, manorpatBeast, MAX_MANOR_PATBEAST_NUM);
DECLARE_IDCREATE(ManorPatbeastDesc);
};
