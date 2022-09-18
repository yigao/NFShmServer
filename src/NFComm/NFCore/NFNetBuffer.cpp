// -------------------------------------------------------------------------
//    @FileName         :    NFNetBuffer.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFNetBuffer.h"

const char NFNetBuffer::kCRLF[] = "\r\n";

const size_t NFNetBuffer::kCheapPrependSize = 8;
const size_t NFNetBuffer::kInitialSize = 1024;

