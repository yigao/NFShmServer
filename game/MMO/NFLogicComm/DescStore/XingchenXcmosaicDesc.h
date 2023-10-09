#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCMOSAIC_NUM 16

class XingchenXcmosaicDesc : public NFIDescStore
{
public:
	XingchenXcmosaicDesc();
	virtual ~XingchenXcmosaicDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXcmosaic_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXcmosaic_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXcmosaic_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXcmosaic_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXcmosaicDesc, proto_ff_s::E_XingchenXcmosaic_s, E_XingchenXcmosaic, MAX_XINGCHEN_XCMOSAIC_NUM);
DECLARE_IDCREATE(XingchenXcmosaicDesc);
};
