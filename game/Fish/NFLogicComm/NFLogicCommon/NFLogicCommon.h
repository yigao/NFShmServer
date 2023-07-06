//
// Created by gaoyi on 2022/9/21.
//

#pragma once

#include "NFComm/NFShmCore/NFShmString.h"

#define NF_SERVER_COMMON_MAX_STRING_32 32
#define NF_SERVER_COMMON_MAX_STRING_64 64
#define NF_SERVER_COMMON_MAX_STRING_128 128
#define NF_SERVER_COMMON_MAX_STRING_256 256
#define NF_SERVER_COMMON_USE_STRING NF_SERVER_COMMON_MAX_STRING_128

typedef NFShmString<NF_SERVER_COMMON_USE_STRING> NFCommonStr;

class NFLogicCommon {
public:
    NFLogicCommon();
    virtual ~NFLogicCommon();
public:
    static std::string GetLoginToken(const std::string& account, uint64_t userId, uint64_t time, const std::string& specialStr);
};


