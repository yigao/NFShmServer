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
#include <functional>

typedef std::function<std::string(int32_t retCode)> NFErrorFunction;

class NFError : public NFSingleton<NFError>
{
public:
    virtual std::string GetErrorStr(int32_t retCode);

    void SetErrorFunction(const NFErrorFunction& func);
private:
    NFErrorFunction m_func;
};


std::string GetErrorStr(int32_t retCode);
