#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_UNLIMITED_NUM 20

class OperateUnlimitedDesc : public NFIDescStore
{
public:
	OperateUnlimitedDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateUnlimitedDesc();
	const proto_ff_s::operateunlimited_s* GetDesc(int id) const;
	proto_ff_s::operateunlimited_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operateunlimited_s, MAX_OPERATE_UNLIMITED_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operateunlimited_s, MAX_OPERATE_UNLIMITED_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operateunlimited_s, operateunlimited, MAX_OPERATE_UNLIMITED_NUM);
DECLARE_IDCREATE(OperateUnlimitedDesc);
};
