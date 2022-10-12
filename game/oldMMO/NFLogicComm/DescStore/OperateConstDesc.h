#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_CONST_NUM 100

class OperateConstDesc : public NFIDescStore
{
public:
	OperateConstDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateConstDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::operateconst_s* GetDesc(int id) const;
	proto_ff_s::operateconst_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operateconst_s, MAX_OPERATE_CONST_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operateconst_s, MAX_OPERATE_CONST_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operateconst_s, operateconst, MAX_OPERATE_CONST_NUM);
DECLARE_IDCREATE(OperateConstDesc);
};
