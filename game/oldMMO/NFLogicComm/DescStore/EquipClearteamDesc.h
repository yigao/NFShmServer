#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_CLEARTEAM_NUM 200

class EquipClearteamDesc : public NFIDescStore
{
public:
	EquipClearteamDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipClearteamDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::equipclearteam_s* GetDesc(int id) const;
	proto_ff_s::equipclearteam_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipclearteam_s, MAX_EQUIP_CLEARTEAM_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipclearteam_s, MAX_EQUIP_CLEARTEAM_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipclearteam_s, equipclearteam, MAX_EQUIP_CLEARTEAM_NUM);
DECLARE_IDCREATE(EquipClearteamDesc);
};
