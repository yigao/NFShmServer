#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/getTreasure_s.h"

#define MAX_GETTREASURE_HELP_NUM 20

class GettreasureHelpDesc : public NFIDescStore
{
public:
	GettreasureHelpDesc(NFIPluginManager* pPluginManager);
	virtual ~GettreasureHelpDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::getTreasurehelp_s* GetDesc(int id) const;
	proto_ff_s::getTreasurehelp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::getTreasurehelp_s, MAX_GETTREASURE_HELP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::getTreasurehelp_s, MAX_GETTREASURE_HELP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::getTreasurehelp_s, getTreasurehelp, MAX_GETTREASURE_HELP_NUM);
DECLARE_IDCREATE(GettreasureHelpDesc);
};
