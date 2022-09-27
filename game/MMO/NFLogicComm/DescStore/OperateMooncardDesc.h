#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_MOONCARD_NUM 60

class OperateMooncardDesc : public NFIDescStore
{
public:
	OperateMooncardDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateMooncardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::operatemooncard_s* GetDesc(int id) const;
	proto_ff_s::operatemooncard_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operatemooncard_s, MAX_OPERATE_MOONCARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operatemooncard_s, MAX_OPERATE_MOONCARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operatemooncard_s, operatemooncard, MAX_OPERATE_MOONCARD_NUM);
DECLARE_IDCREATE(OperateMooncardDesc);
};
