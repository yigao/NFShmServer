// -------------------------------------------------------------------------
//    @FileName         :    NFCTestActorModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFTestPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmStl/NFShmHashMap.h"

#include <map>
#include <set>
#include <unordered_map>

void TestShmHashMap()
{
    std::vector<int> vec;
    std::set<int> setNum;
    {
        while(vec.size() < 1000000)
        {
            int rand = NFRandInt<int>(0, 100000000);
            if (setNum.find(rand) == setNum.end())
            {
                setNum.insert(rand);
                vec.push_back(rand);
            }
        }
    }

    {
        uint64_t startTime = NFGetTime();
        NFShmHashMap<int, int, 1000000> hashMap;
        for(int i = 0; i < 1000000; i++)
        {
            hashMap[i] = vec[i];
        }

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "shm hash map insert 1000000 use time:{} ms", NFGetTime() - startTime);

        startTime = NFGetTime();
        for(int i = 0; i < 1000000; i++)
        {
            hashMap[i];
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "shm hash map Find 1000000 use time:{} ms", NFGetTime() - startTime);
        
        startTime = NFGetTime();
        for(int i = 0; i < 1000000; i++)
        {
            vec[i];
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "vector Find 1000000 use time:{} ms", NFGetTime() - startTime);
    }
}
