#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_BIGYANHUARECHARGE_NUM 20

class FestivalBigyanhuarechargeDesc : public NFIDescStore
{
public:
	FestivalBigyanhuarechargeDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalBigyanhuarechargeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivalbigyanhuarecharge_s* GetDesc(int id) const;
	proto_ff_s::festivalbigyanhuarecharge_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalbigyanhuarecharge_s, MAX_FESTIVAL_BIGYANHUARECHARGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalbigyanhuarecharge_s, MAX_FESTIVAL_BIGYANHUARECHARGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalbigyanhuarecharge_s, festivalbigyanhuarecharge, MAX_FESTIVAL_BIGYANHUARECHARGE_NUM);
DECLARE_IDCREATE(FestivalBigyanhuarechargeDesc);
};
