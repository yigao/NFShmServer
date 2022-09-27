#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_OPERATE_NUM 40

class OperateOperateDesc : public NFIDescStore
{
public:
	OperateOperateDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateOperateDesc();
	const proto_ff_s::operateoperate_s* GetDesc(int id) const;
	proto_ff_s::operateoperate_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operateoperate_s, MAX_OPERATE_OPERATE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operateoperate_s, MAX_OPERATE_OPERATE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operateoperate_s, operateoperate, MAX_OPERATE_OPERATE_NUM);
DECLARE_IDCREATE(OperateOperateDesc);
};
