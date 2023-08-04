// -------------------------------------------------------------------------
//    @FileName         :    NFLogicError.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-29
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicError
//
// -------------------------------------------------------------------------

#include "NFLogicError.h"
#include "proto_kernel.pb.h"
#include "ComDefine.pb.h"
#include "NFComm/NFCore/NFCommon.h"

std::string GetLogicErrorStr(int32_t retCode)
{
    if (proto_ff::Proto_CS_ErrorCode_IsValid(retCode))
    {
        return proto_ff::Proto_CS_ErrorCode_Name((proto_ff::Proto_CS_ErrorCode)retCode);
    }
    else if (proto_ff::Proto_Kernel_ErrorCode_IsValid(retCode))
    {
        return proto_ff::Proto_Kernel_ErrorCode_Name((proto_ff::Proto_Kernel_ErrorCode)retCode);
    }
    else
    {
        return NFCommon::tostr(retCode);
    }
}


