#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/field_s.h"

#define MAX_FIELD_STONG_NUM 100

class FieldStongDesc : public NFIDescStore
{
public:
	FieldStongDesc(NFIPluginManager* pPluginManager);
	virtual ~FieldStongDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::fieldstong_s* GetDesc(int id) const;
	proto_ff_s::fieldstong_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::fieldstong_s, MAX_FIELD_STONG_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::fieldstong_s, MAX_FIELD_STONG_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::fieldstong_s, fieldstong, MAX_FIELD_STONG_NUM);
DECLARE_IDCREATE(FieldStongDesc);
};
