#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_FUND_NUM 60

class OperateFundDesc : public NFIDescStore
{
public:
	OperateFundDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateFundDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::operatefund_s* GetDesc(int id) const;
	proto_ff_s::operatefund_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operatefund_s, MAX_OPERATE_FUND_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operatefund_s, MAX_OPERATE_FUND_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operatefund_s, operatefund, MAX_OPERATE_FUND_NUM);
DECLARE_IDCREATE(OperateFundDesc);
};
