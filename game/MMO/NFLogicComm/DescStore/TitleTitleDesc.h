#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/title_s.h"

#define MAX_TITLE_TITLE_NUM 120

class TitleTitleDesc : public NFIDescStore
{
public:
	TitleTitleDesc(NFIPluginManager* pPluginManager);
	virtual ~TitleTitleDesc();
	const proto_ff_s::titletitle_s* GetDesc(int id) const;
	proto_ff_s::titletitle_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::titletitle_s, MAX_TITLE_TITLE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::titletitle_s, MAX_TITLE_TITLE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::titletitle_s, titletitle, MAX_TITLE_TITLE_NUM);
DECLARE_IDCREATE(TitleTitleDesc);
};
