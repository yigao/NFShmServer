#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/serveropenactive_s.h"

#define MAX_SERVEROPENACTIVE_SERVICEACTIVITY_NUM 20

class ServeropenactiveServiceactivityDesc : public NFIDescStore
{
public:
	ServeropenactiveServiceactivityDesc(NFIPluginManager* pPluginManager);
	virtual ~ServeropenactiveServiceactivityDesc();
	const proto_ff_s::serveropenactiveserviceActivity_s* GetDesc(int id) const;
	proto_ff_s::serveropenactiveserviceActivity_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::serveropenactiveserviceActivity_s, MAX_SERVEROPENACTIVE_SERVICEACTIVITY_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::serveropenactiveserviceActivity_s, MAX_SERVEROPENACTIVE_SERVICEACTIVITY_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::serveropenactiveserviceActivity_s, serveropenactiveserviceActivity, MAX_SERVEROPENACTIVE_SERVICEACTIVITY_NUM);
DECLARE_IDCREATE(ServeropenactiveServiceactivityDesc);
};
