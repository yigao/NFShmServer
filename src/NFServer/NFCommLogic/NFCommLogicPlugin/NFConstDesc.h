// -------------------------------------------------------------------------
//    @FileName         :    NFConstDesc.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFConstDesc.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFIDescStore.h"
#include "NFComm/NFMessageDefine/ResMeta_s.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

#define MAX_CONST_DESC_NUM 1000

class NFConstDesc : public NFIDescStore
{
public:
	NFConstDesc();
    virtual ~NFConstDesc();
    int CreateInit();
    int ResumeInit();
    const proto_ff_s::ConstDesc_s* GetDesc(proto_ff::enConstType type) const;
	std::string GetValue(proto_ff::enConstType type) const;
public:
	IMPL_RES_DESC(proto_ff_s::ConstDesc_s, ConstDesc, MAX_CONST_DESC_NUM);
	int m_aiIndex[MAX_CONST_DESC_NUM];
	DECLARE_IDCREATE(NFConstDesc);
};
