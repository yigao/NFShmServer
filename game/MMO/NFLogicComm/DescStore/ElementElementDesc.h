#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/element_s.h"

#define MAX_ELEMENT_ELEMENT_NUM 2000

class ElementElementDesc : public NFIDescStore
{
public:
	ElementElementDesc(NFIPluginManager* pPluginManager);
	virtual ~ElementElementDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::elementelement_s* GetDesc(int id) const;
	proto_ff_s::elementelement_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::elementelement_s, MAX_ELEMENT_ELEMENT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::elementelement_s, MAX_ELEMENT_ELEMENT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::elementelement_s, elementelement, MAX_ELEMENT_ELEMENT_NUM);
DECLARE_IDCREATE(ElementElementDesc);
};
