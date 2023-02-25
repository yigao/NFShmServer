#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mall_s.h"

#define MAX_MALL_MALLTYPE_TAB_NUM 20

class MallMalltype_tabDesc : public NFIDescStore
{
public:
	MallMalltype_tabDesc();
	virtual ~MallMalltype_tabDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MallMalltype_tab_s* GetDesc(int id) const;
	proto_ff_s::E_MallMalltype_tab_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MallMalltype_tab_s, E_MallMalltype_tab, MAX_MALL_MALLTYPE_TAB_NUM);
DECLARE_IDCREATE(MallMalltype_tabDesc);
};