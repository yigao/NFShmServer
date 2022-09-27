#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_TUTOR_NUM 80

class OperateTutorDesc : public NFIDescStore
{
public:
	OperateTutorDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateTutorDesc();
	const proto_ff_s::operatetutor_s* GetDesc(int id) const;
	proto_ff_s::operatetutor_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operatetutor_s, MAX_OPERATE_TUTOR_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operatetutor_s, MAX_OPERATE_TUTOR_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operatetutor_s, operatetutor, MAX_OPERATE_TUTOR_NUM);
DECLARE_IDCREATE(OperateTutorDesc);
};
