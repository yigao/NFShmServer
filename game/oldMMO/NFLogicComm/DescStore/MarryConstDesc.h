#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/marry_s.h"

#define MAX_MARRY_CONST_NUM 20

class MarryConstDesc : public NFIDescStore
{
public:
	MarryConstDesc(NFIPluginManager* pPluginManager);
	virtual ~MarryConstDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::marryconst_s* GetDesc(int id) const;
	proto_ff_s::marryconst_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::marryconst_s, MAX_MARRY_CONST_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::marryconst_s, MAX_MARRY_CONST_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::marryconst_s, marryconst, MAX_MARRY_CONST_NUM);
DECLARE_IDCREATE(MarryConstDesc);
};
