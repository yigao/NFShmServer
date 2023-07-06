//
// Created by gaoyi on 2022/9/21.
//

#include "NFLogicCommon.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFMD5.h"

NFLogicCommon::NFLogicCommon()
{

}

NFLogicCommon::~NFLogicCommon()
{

}

std::string NFLogicCommon::GetLoginToken(const std::string& account, uint64_t userId, uint64_t time, const std::string& specialStr)
{
    std::string token = account + NFCommon::tostr(userId) + NFCommon::tostr(time) + specialStr;
    return NFMD5::md5str(token);
}