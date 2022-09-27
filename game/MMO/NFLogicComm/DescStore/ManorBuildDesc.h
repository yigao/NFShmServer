#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/manor_s.h"

#define MAX_MANOR_BUILD_NUM 20

class ManorBuildDesc : public NFIDescStore
{
public:
	ManorBuildDesc(NFIPluginManager* pPluginManager);
	virtual ~ManorBuildDesc();
	const proto_ff_s::manorbuild_s* GetDesc(int id) const;
	proto_ff_s::manorbuild_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::manorbuild_s, MAX_MANOR_BUILD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::manorbuild_s, MAX_MANOR_BUILD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::manorbuild_s, manorbuild, MAX_MANOR_BUILD_NUM);
DECLARE_IDCREATE(ManorBuildDesc);
};
