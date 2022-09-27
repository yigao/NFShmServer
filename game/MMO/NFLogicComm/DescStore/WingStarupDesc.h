#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/wing_s.h"

#define MAX_WING_STARUP_NUM 40

class WingStarupDesc : public NFIDescStore
{
public:
	WingStarupDesc(NFIPluginManager* pPluginManager);
	virtual ~WingStarupDesc();
	const proto_ff_s::wingstarUp_s* GetDesc(int id) const;
	proto_ff_s::wingstarUp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::wingstarUp_s, MAX_WING_STARUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::wingstarUp_s, MAX_WING_STARUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::wingstarUp_s, wingstarUp, MAX_WING_STARUP_NUM);
DECLARE_IDCREATE(WingStarupDesc);
};
