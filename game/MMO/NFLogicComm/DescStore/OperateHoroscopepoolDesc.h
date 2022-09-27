#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_HOROSCOPEPOOL_NUM 1000

class OperateHoroscopepoolDesc : public NFIDescStore
{
public:
	OperateHoroscopepoolDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateHoroscopepoolDesc();
	const proto_ff_s::operatehoroscopePool_s* GetDesc(int id) const;
	proto_ff_s::operatehoroscopePool_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operatehoroscopePool_s, MAX_OPERATE_HOROSCOPEPOOL_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operatehoroscopePool_s, MAX_OPERATE_HOROSCOPEPOOL_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operatehoroscopePool_s, operatehoroscopePool, MAX_OPERATE_HOROSCOPEPOOL_NUM);
DECLARE_IDCREATE(OperateHoroscopepoolDesc);
};
