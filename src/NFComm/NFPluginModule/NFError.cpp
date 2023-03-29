// -------------------------------------------------------------------------
//    @FileName         :    NFError.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFError.h"
#include "proto_kernel.pb.h"
#include "NFComm/NFCore/NFCommon.h"

std::string NFError::GetErrorStr(int32_t retCode)
{
    if (proto_ff::Proto_Kernel_ErrorCode_IsValid(retCode))
    {
        return proto_ff::Proto_Kernel_ErrorCode_Name((proto_ff::Proto_Kernel_ErrorCode)retCode);
    }
    else
    {
        return NFCommon::tostr(retCode);
    }
}

std::string GetErrorStr(int32_t retCode)
{
    return NFError::Instance()->GetErrorStr(retCode);
}


