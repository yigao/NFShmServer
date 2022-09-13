// -------------------------------------------------------------------------
//    @FileName         :    NFStringUtility.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include <vector>
#include <string>
#include <string.h>

#include "NFPlatform.h"

/**
 * @brief tea算法，通常用第二代算法
 */
class NFTea
{
public:

    /**
     * @brief 加密.
     *
     * @param key       加密的key, 16个字节
     * @param sIn       输入buffer
     * @param iLength   输入buffer长度
     * @param buffer    vector<char>, 加密后二进制串
     */
    static void encrypt(const char *key, const char *sIn, size_t iLength, std::vector<char> &buffer);

    /**
     * @brief 解密.
     *
     * @param key      解密的key, 16个字节
     * @param sIn      需要解密的buffer
     * @param iLength  buffer长度
     * @param buffer   vector<char>, 解密后二进制串
     * @return bool,   成功失败
     */
    static bool decrypt(const char *key, const char *sIn, size_t iLength, std::vector<char> &buffer);
};