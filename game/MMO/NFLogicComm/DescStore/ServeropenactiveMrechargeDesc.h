#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/serveropenactive_s.h"

#define MAX_SERVEROPENACTIVE_MRECHARGE_NUM 200

class ServeropenactiveMrechargeDesc : public NFIDescStore
{
public:
	ServeropenactiveMrechargeDesc(NFIPluginManager* pPluginManager);
	virtual ~ServeropenactiveMrechargeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::serveropenactivemRecharge_s* GetDesc(int id) const;
	proto_ff_s::serveropenactivemRecharge_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::serveropenactivemRecharge_s, MAX_SERVEROPENACTIVE_MRECHARGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::serveropenactivemRecharge_s, MAX_SERVEROPENACTIVE_MRECHARGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::serveropenactivemRecharge_s, serveropenactivemRecharge, MAX_SERVEROPENACTIVE_MRECHARGE_NUM);
DECLARE_IDCREATE(ServeropenactiveMrechargeDesc);
};
