// -------------------------------------------------------------------------
//    @FileName         :    NFShmNodeList.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmNodeList
//
// -------------------------------------------------------------------------

#include "NFShmNodeList.h"

int NFIListNodeObj::s_iListCheckIDSeq = 0;

int NFIListNodeObj::GetListCheckIDSeq()
{
    s_iListCheckIDSeq++;

    if (s_iListCheckIDSeq <= 0)
    {
        s_iListCheckIDSeq = 1;
    }

    return s_iListCheckIDSeq;
}

