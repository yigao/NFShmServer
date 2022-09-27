#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/title_s.h"

#define MAX_TITLE_TYPE_NUM 20

class TitleTypeDesc : public NFIDescStore
{
public:
	TitleTypeDesc(NFIPluginManager* pPluginManager);
	virtual ~TitleTypeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::titletype_s* GetDesc(int id) const;
	proto_ff_s::titletype_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::titletype_s, MAX_TITLE_TYPE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::titletype_s, MAX_TITLE_TYPE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::titletype_s, titletype, MAX_TITLE_TYPE_NUM);
DECLARE_IDCREATE(TitleTypeDesc);
};
