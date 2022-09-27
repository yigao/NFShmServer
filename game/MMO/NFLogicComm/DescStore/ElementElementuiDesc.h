#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/element_s.h"

#define MAX_ELEMENT_ELEMENTUI_NUM 20

class ElementElementuiDesc : public NFIDescStore
{
public:
	ElementElementuiDesc(NFIPluginManager* pPluginManager);
	virtual ~ElementElementuiDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::elementelementUI_s* GetDesc(int id) const;
	proto_ff_s::elementelementUI_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::elementelementUI_s, MAX_ELEMENT_ELEMENTUI_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::elementelementUI_s, MAX_ELEMENT_ELEMENTUI_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::elementelementUI_s, elementelementUI, MAX_ELEMENT_ELEMENTUI_NUM);
DECLARE_IDCREATE(ElementElementuiDesc);
};
