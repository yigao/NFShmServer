#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/randomname_s.h"

#define MAX_RANDOMNAME_MANFIRST_NUM 100

class RandomnameManfirstDesc : public NFIDescStore
{
public:
	RandomnameManfirstDesc(NFIPluginManager* pPluginManager);
	virtual ~RandomnameManfirstDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::randomnamemanfirst_s* GetDesc(int id) const;
	proto_ff_s::randomnamemanfirst_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::randomnamemanfirst_s, MAX_RANDOMNAME_MANFIRST_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::randomnamemanfirst_s, MAX_RANDOMNAME_MANFIRST_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::randomnamemanfirst_s, randomnamemanfirst, MAX_RANDOMNAME_MANFIRST_NUM);
DECLARE_IDCREATE(RandomnameManfirstDesc);
};
