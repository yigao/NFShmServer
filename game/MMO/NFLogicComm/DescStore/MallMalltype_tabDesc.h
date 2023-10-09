#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mall_s.h"

#define MAX_MALL_MALLTYPE_TAB_NUM 16

class MallMalltype_tabDesc : public NFIDescStore
{
public:
	MallMalltype_tabDesc();
	virtual ~MallMalltype_tabDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MallMalltype_tab_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MallMalltype_tab_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MallMalltype_tab_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MallMalltype_tab_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MallMalltype_tabDesc, proto_ff_s::E_MallMalltype_tab_s, E_MallMalltype_tab, MAX_MALL_MALLTYPE_TAB_NUM);
DECLARE_IDCREATE(MallMalltype_tabDesc);
};
