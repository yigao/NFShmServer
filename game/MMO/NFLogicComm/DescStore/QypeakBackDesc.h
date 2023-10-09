#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Qypeak_s.h"

#define MAX_QYPEAK_BACK_NUM 16

class QypeakBackDesc : public NFIDescStore
{
public:
	QypeakBackDesc();
	virtual ~QypeakBackDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_QypeakBack_s* GetDesc(int64_t id) const;
	proto_ff_s::E_QypeakBack_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_QypeakBack_s* GetDescByIndex(int index) const;
	proto_ff_s::E_QypeakBack_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(QypeakBackDesc, proto_ff_s::E_QypeakBack_s, E_QypeakBack, MAX_QYPEAK_BACK_NUM);
DECLARE_IDCREATE(QypeakBackDesc);
};
