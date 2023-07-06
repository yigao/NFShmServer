// -------------------------------------------------------------------------
//    @FileName         :    NFLogicError.h
//    @Author           :    gaoyi
//    @Date             :    23-3-29
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicError
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFError.h"

class NFLogicError : public NFError
{
public:
    virtual std::string GetErrorStr(int32_t retCode) override;
};