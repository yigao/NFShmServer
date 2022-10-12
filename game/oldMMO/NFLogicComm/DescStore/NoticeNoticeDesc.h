#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/notice_s.h"

#define MAX_NOTICE_NOTICE_NUM 20

class NoticeNoticeDesc : public NFIDescStore
{
public:
	NoticeNoticeDesc(NFIPluginManager* pPluginManager);
	virtual ~NoticeNoticeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::noticenotice_s* GetDesc(int id) const;
	proto_ff_s::noticenotice_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::noticenotice_s, MAX_NOTICE_NOTICE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::noticenotice_s, MAX_NOTICE_NOTICE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::noticenotice_s, noticenotice, MAX_NOTICE_NOTICE_NUM);
DECLARE_IDCREATE(NoticeNoticeDesc);
};
