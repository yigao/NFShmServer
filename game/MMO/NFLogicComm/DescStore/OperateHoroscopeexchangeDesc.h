#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_HOROSCOPEEXCHANGE_NUM 200

class OperateHoroscopeexchangeDesc : public NFIDescStore
{
public:
	OperateHoroscopeexchangeDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateHoroscopeexchangeDesc();
	const proto_ff_s::operatehoroscopeExchange_s* GetDesc(int id) const;
	proto_ff_s::operatehoroscopeExchange_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operatehoroscopeExchange_s, MAX_OPERATE_HOROSCOPEEXCHANGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operatehoroscopeExchange_s, MAX_OPERATE_HOROSCOPEEXCHANGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operatehoroscopeExchange_s, operatehoroscopeExchange, MAX_OPERATE_HOROSCOPEEXCHANGE_NUM);
DECLARE_IDCREATE(OperateHoroscopeexchangeDesc);
};
