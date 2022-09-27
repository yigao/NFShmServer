#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/element_s.h"

#define MAX_ELEMENT_FRAGMENT_NUM 20

class ElementFragmentDesc : public NFIDescStore
{
public:
	ElementFragmentDesc(NFIPluginManager* pPluginManager);
	virtual ~ElementFragmentDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::elementfragment_s* GetDesc(int id) const;
	proto_ff_s::elementfragment_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::elementfragment_s, MAX_ELEMENT_FRAGMENT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::elementfragment_s, MAX_ELEMENT_FRAGMENT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::elementfragment_s, elementfragment, MAX_ELEMENT_FRAGMENT_NUM);
DECLARE_IDCREATE(ElementFragmentDesc);
};
