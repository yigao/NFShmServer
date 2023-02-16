#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/attribute_s.h"

#define MAX_ATTRIBUTE_SUPPRESS_NUM 600

class AttributeSuppressDesc : public NFIDescStore
{
public:
	AttributeSuppressDesc();
	virtual ~AttributeSuppressDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AttributeSuppress_s* GetDesc(int id) const;
	proto_ff_s::E_AttributeSuppress_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_AttributeSuppress_s, E_AttributeSuppress, MAX_ATTRIBUTE_SUPPRESS_NUM);
DECLARE_IDCREATE(AttributeSuppressDesc);
};
