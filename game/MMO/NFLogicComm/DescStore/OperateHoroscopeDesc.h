#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_HOROSCOPE_NUM 20

class OperateHoroscopeDesc : public NFIDescStore
{
public:
	OperateHoroscopeDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateHoroscopeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::operatehoroscope_s* GetDesc(int id) const;
	proto_ff_s::operatehoroscope_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operatehoroscope_s, MAX_OPERATE_HOROSCOPE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operatehoroscope_s, MAX_OPERATE_HOROSCOPE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operatehoroscope_s, operatehoroscope, MAX_OPERATE_HOROSCOPE_NUM);
DECLARE_IDCREATE(OperateHoroscopeDesc);
};
