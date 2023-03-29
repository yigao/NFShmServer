// -------------------------------------------------------------------------
//    @FileName         :    NFError.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFSingleton.hpp"

#include <string>

class NFError : public NFSingleton<NFError>
{
public:
    virtual std::string GetErrorStr(int32_t retCode);
};


std::string GetErrorStr(int32_t retCode);
