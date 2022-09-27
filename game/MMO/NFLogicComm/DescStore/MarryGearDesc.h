#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/marry_s.h"

#define MAX_MARRY_GEAR_NUM 20

class MarryGearDesc : public NFIDescStore
{
public:
	MarryGearDesc(NFIPluginManager* pPluginManager);
	virtual ~MarryGearDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::marrygear_s* GetDesc(int id) const;
	proto_ff_s::marrygear_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::marrygear_s, MAX_MARRY_GEAR_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::marrygear_s, MAX_MARRY_GEAR_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::marrygear_s, marrygear, MAX_MARRY_GEAR_NUM);
DECLARE_IDCREATE(MarryGearDesc);
};
