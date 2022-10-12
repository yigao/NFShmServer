//
// Created by gaoyi on 2022/9/21.
//

#include "NFLogicCommon.h"
#include "NFComm/NFCore/NFMD5.h"

NFLogicCommon::NFLogicCommon()
{

}

NFLogicCommon::~NFLogicCommon()
{

}

std::string NFLogicCommon::MakeToken(uint32_t uid, uint64_t timeStamp)
{
    std::string gameStr = NF_FORMAT("ADDX{}_{}_{}", uid, timeStamp, "cgyx_loginaccount00102");

    return NFMD5::md5str(gameStr);
}

