// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogic.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogic.cpp
//
// -------------------------------------------------------------------------

#include "NFCommLogic.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFComm/NFCore/NFCommon.h"

std::string NFCommLogic::GetLoginToken(const std::string& account, uint64_t userId, uint64_t time, const std::string& specialStr)
{
    std::string token = account + NFCommon::tostr(userId) + NFCommon::tostr(time) + specialStr;
    return NFMD5::md5str(token);
}
