#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/button_s.h"

#define MAX_BUTTON_BUTTON_NUM 80

class ButtonButtonDesc : public NFIDescStore
{
public:
	ButtonButtonDesc(NFIPluginManager* pPluginManager);
	virtual ~ButtonButtonDesc();
	const proto_ff_s::buttonbutton_s* GetDesc(int id) const;
	proto_ff_s::buttonbutton_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::buttonbutton_s, MAX_BUTTON_BUTTON_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::buttonbutton_s, MAX_BUTTON_BUTTON_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::buttonbutton_s, buttonbutton, MAX_BUTTON_BUTTON_NUM);
DECLARE_IDCREATE(ButtonButtonDesc);
};
