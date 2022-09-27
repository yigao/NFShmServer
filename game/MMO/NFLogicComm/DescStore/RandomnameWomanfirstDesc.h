#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/randomname_s.h"

#define MAX_RANDOMNAME_WOMANFIRST_NUM 300

class RandomnameWomanfirstDesc : public NFIDescStore
{
public:
	RandomnameWomanfirstDesc(NFIPluginManager* pPluginManager);
	virtual ~RandomnameWomanfirstDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::randomnamewomanfirst_s* GetDesc(int id) const;
	proto_ff_s::randomnamewomanfirst_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::randomnamewomanfirst_s, MAX_RANDOMNAME_WOMANFIRST_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::randomnamewomanfirst_s, MAX_RANDOMNAME_WOMANFIRST_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::randomnamewomanfirst_s, randomnamewomanfirst, MAX_RANDOMNAME_WOMANFIRST_NUM);
DECLARE_IDCREATE(RandomnameWomanfirstDesc);
};
