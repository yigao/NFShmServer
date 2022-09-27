#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/indultTask_s.h"

#define MAX_INDULTTASK_INDULTTASK_NUM 20

class IndulttaskIndulttaskDesc : public NFIDescStore
{
public:
	IndulttaskIndulttaskDesc(NFIPluginManager* pPluginManager);
	virtual ~IndulttaskIndulttaskDesc();
	const proto_ff_s::indultTaskindultTask_s* GetDesc(int id) const;
	proto_ff_s::indultTaskindultTask_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::indultTaskindultTask_s, MAX_INDULTTASK_INDULTTASK_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::indultTaskindultTask_s, MAX_INDULTTASK_INDULTTASK_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::indultTaskindultTask_s, indultTaskindultTask, MAX_INDULTTASK_INDULTTASK_NUM);
DECLARE_IDCREATE(IndulttaskIndulttaskDesc);
};
