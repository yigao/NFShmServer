#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/occupation_s.h"

#define MAX_OCCUPATION_APTITUDE_NUM 80

class OccupationAptitudeDesc : public NFIDescStore
{
public:
	OccupationAptitudeDesc(NFIPluginManager* pPluginManager);
	virtual ~OccupationAptitudeDesc();
	const proto_ff_s::occupationaptitude_s* GetDesc(int id) const;
	proto_ff_s::occupationaptitude_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::occupationaptitude_s, MAX_OCCUPATION_APTITUDE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::occupationaptitude_s, MAX_OCCUPATION_APTITUDE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::occupationaptitude_s, occupationaptitude, MAX_OCCUPATION_APTITUDE_NUM);
DECLARE_IDCREATE(OccupationAptitudeDesc);
};
