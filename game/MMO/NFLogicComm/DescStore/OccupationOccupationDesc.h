#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/occupation_s.h"

#define MAX_OCCUPATION_OCCUPATION_NUM 40

class OccupationOccupationDesc : public NFIDescStore
{
public:
	OccupationOccupationDesc(NFIPluginManager* pPluginManager);
	virtual ~OccupationOccupationDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::occupationoccupation_s* GetDesc(int id) const;
	proto_ff_s::occupationoccupation_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::occupationoccupation_s, MAX_OCCUPATION_OCCUPATION_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::occupationoccupation_s, MAX_OCCUPATION_OCCUPATION_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::occupationoccupation_s, occupationoccupation, MAX_OCCUPATION_OCCUPATION_NUM);
DECLARE_IDCREATE(OccupationOccupationDesc);
};
