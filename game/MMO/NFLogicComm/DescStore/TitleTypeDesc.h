#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/title_s.h"

#define MAX_TITLE_TYPE_NUM 20

class TitleTypeDesc : public NFIDescStore
{
public:
	TitleTypeDesc();
	virtual ~TitleTypeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_TitleType_s* GetDesc(int id) const;
	proto_ff_s::E_TitleType_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_TitleType_s, E_TitleType, MAX_TITLE_TYPE_NUM);
DECLARE_IDCREATE(TitleTypeDesc);
};
