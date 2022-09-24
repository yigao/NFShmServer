// -------------------------------------------------------------------------
//    @FileName         :    NFConstDesc.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFConstDesc.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFServerLogicMessage/ConstDesc_s.h"

#define MAX_CONST_DESC_NUM 1000

class NFConstDesc : public NFIDescStore
{
public:
	NFConstDesc(NFIPluginManager* pPluginManager);
    virtual ~NFConstDesc();
    int CreateInit();
    int ResumeInit();
    const proto_ff_s::ConstDesc_s* GetDesc(int id) const;
    proto_ff_s::ConstDesc_s* GetDesc(int id);
    virtual bool IsFileLoad() override
    {
        return false;
    }
public:
    IMPL_RES_HASH_DESC(proto_ff_s::ConstDesc_s, ConstDesc, MAX_CONST_DESC_NUM);
	DECLARE_IDCREATE(NFConstDesc);
};
