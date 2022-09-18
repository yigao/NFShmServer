// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogic.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCommLogic.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFMD5.h"
#include <vector>
#include <string>

#define LOGIN_TOKEN "ShmNFrame"


class NFCommLogic
{
public:
    NFCommLogic() { }
    virtual ~NFCommLogic() { }
public:
    static std::string GetLoginToken(const std::string& account, uint64_t userId, uint64_t time, const std::string& specialStr);
};