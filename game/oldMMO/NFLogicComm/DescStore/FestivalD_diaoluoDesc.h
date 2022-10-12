#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_D_DIAOLUO_NUM 20

class FestivalD_diaoluoDesc : public NFIDescStore
{
public:
	FestivalD_diaoluoDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalD_diaoluoDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivald_diaoluo_s* GetDesc(int id) const;
	proto_ff_s::festivald_diaoluo_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivald_diaoluo_s, MAX_FESTIVAL_D_DIAOLUO_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivald_diaoluo_s, MAX_FESTIVAL_D_DIAOLUO_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivald_diaoluo_s, festivald_diaoluo, MAX_FESTIVAL_D_DIAOLUO_NUM);
DECLARE_IDCREATE(FestivalD_diaoluoDesc);
};
