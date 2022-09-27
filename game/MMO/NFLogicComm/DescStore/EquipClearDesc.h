#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_CLEAR_NUM 20

class EquipClearDesc : public NFIDescStore
{
public:
	EquipClearDesc(NFIPluginManager* pPluginManager);
	virtual ~EquipClearDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::equipclear_s* GetDesc(int id) const;
	proto_ff_s::equipclear_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::equipclear_s, MAX_EQUIP_CLEAR_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::equipclear_s, MAX_EQUIP_CLEAR_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipclear_s, equipclear, MAX_EQUIP_CLEAR_NUM);
DECLARE_IDCREATE(EquipClearDesc);
};
