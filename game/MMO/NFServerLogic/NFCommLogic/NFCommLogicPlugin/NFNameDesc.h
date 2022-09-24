// -------------------------------------------------------------------------
//    @FileName         :    NFNameDesc.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFNameDesc.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFServerLogicMessage/NameDesc_s.h"

#define MAX_NAME_DESC_NUM 5000

class NFNameDesc : public NFIDescStore
{
public:
    NFNameDesc(NFIPluginManager* pPluginManager);
    virtual ~NFNameDesc();
    int CreateInit();
    int ResumeInit();
    const proto_ff_s::NameDesc_s *GetDesc(int id) const;
    proto_ff_s::NameDesc_s *GetDesc(int id);
public:
IMPL_RES_ARRAY_DESC(proto_ff_s::NameDesc_s, NameDesc, MAX_NAME_DESC_NUM);
DECLARE_IDCREATE(NFNameDesc);
};
