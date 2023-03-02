#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/avatar_s.h"

#define MAX_AVATAR_CHANGETAB_NUM 20

class AvatarChangetabDesc : public NFIDescStore
{
public:
	AvatarChangetabDesc();
	virtual ~AvatarChangetabDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AvatarChangetab_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AvatarChangetab_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AvatarChangetab_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AvatarChangetab_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_AvatarChangetab_s, E_AvatarChangetab, MAX_AVATAR_CHANGETAB_NUM);
DECLARE_IDCREATE(AvatarChangetabDesc);
};
