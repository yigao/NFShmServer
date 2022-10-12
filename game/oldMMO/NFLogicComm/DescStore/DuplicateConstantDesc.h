#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/duplicate_s.h"

#define MAX_DUPLICATE_CONSTANT_NUM 20

class DuplicateConstantDesc : public NFIDescStore
{
public:
	DuplicateConstantDesc(NFIPluginManager* pPluginManager);
	virtual ~DuplicateConstantDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::duplicateconstant_s* GetDesc(int id) const;
	proto_ff_s::duplicateconstant_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::duplicateconstant_s, MAX_DUPLICATE_CONSTANT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::duplicateconstant_s, MAX_DUPLICATE_CONSTANT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::duplicateconstant_s, duplicateconstant, MAX_DUPLICATE_CONSTANT_NUM);
DECLARE_IDCREATE(DuplicateConstantDesc);
};
