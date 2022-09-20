// -------------------------------------------------------------------------
//    @FileName         :    NFServerDefine.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include <stdint.h>
#include <functional>
#include <string>
#include <vector>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFSlice.hpp"
#include "NFComm/NFCore/NFSimpleBuffer.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"

class NFServerCommon
{
public:
    NFServerCommon()
    {
    }

    virtual ~NFServerCommon()
    {
    };
};
