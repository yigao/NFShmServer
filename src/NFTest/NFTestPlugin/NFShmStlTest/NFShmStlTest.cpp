// -------------------------------------------------------------------------
//    @FileName         :    NFShmStlTest.cpp
//    @Author           :    gaoyi
//    @Date             :    23-1-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmStlTest
//
// -------------------------------------------------------------------------

#include "NFComm/NFShmStl/NFShmPair.h"
#include "NFComm/NFShmStl/NFShmVector.h"

#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFShmStlTest.h"

int checkPair()
{
    NFShmPair<uint64_t, uint64_t> pair(1,2);
    NFShmPair<uint64_t, uint64_t> pair2(3,4);
    NFShmPair<uint64_t, uint64_t> pair3(pair);

    CHECK_EQ(pair == pair3);
    CHECK_EQ(pair != pair2);
    CHECK_EQ(pair <= pair2);
    CHECK_EQ(pair == (MakePair<uint64_t, uint64_t>(1,2)));
    return 0;
}

int testMain()
{
    CHECK_RET(checkPair(), "checkPair Failed");
    return 0;
}
