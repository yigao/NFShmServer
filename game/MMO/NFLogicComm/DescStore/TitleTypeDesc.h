#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Title_s.h"

#define MAX_TITLE_TYPE_NUM 8

class TitleTypeDesc : public NFIDescStore
{
public:
	TitleTypeDesc();
	virtual ~TitleTypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_TitleType_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TitleType_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TitleType_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TitleType_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(TitleTypeDesc, proto_ff_s::E_TitleType_s, E_TitleType, MAX_TITLE_TYPE_NUM);
DECLARE_IDCREATE_GLOBAL(TitleTypeDesc);
};
