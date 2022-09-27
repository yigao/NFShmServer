#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/marry_s.h"

#define MAX_MARRY_LEVELEXP_NUM 2000

class MarryLevelexpDesc : public NFIDescStore
{
public:
	MarryLevelexpDesc(NFIPluginManager* pPluginManager);
	virtual ~MarryLevelexpDesc();
	const proto_ff_s::marrylevelexp_s* GetDesc(int id) const;
	proto_ff_s::marrylevelexp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::marrylevelexp_s, MAX_MARRY_LEVELEXP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::marrylevelexp_s, MAX_MARRY_LEVELEXP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::marrylevelexp_s, marrylevelexp, MAX_MARRY_LEVELEXP_NUM);
DECLARE_IDCREATE(MarryLevelexpDesc);
};
