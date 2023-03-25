// -------------------------------------------------------------------------
//    @FileName         :    NFIRpcService.h
//    @Author           :    gaoyi
//    @Date             :    23-3-24
//    @Email			:    445267987@qq.com
//    @Module           :    NFIRpcService
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFObject.h"

#ifdef NF_DEBUG_MODE
#define DEFINE_RPC_SERVICE_TIME_OUT_MS (200000) //200s
#else
#define DEFINE_RPC_SERVICE_TIME_OUT_MS (3000) //3s
#endif

class NFIRpcService : public NFObject
{
public:
    NFIRpcService(NFIPluginManager* p):NFObject(p)
    {

    }

    virtual int run(uint64_t unLinkId, const proto_ff::Proto_SvrPkg& reqSvrPkg) = 0;
};
