// -------------------------------------------------------------------------
//    @FileName         :    NFCTestActorModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFTestPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmHashMap.h"

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
        NFShmHashMap<int, std::string, 1000000, 500000> hashMap;
        for(int i = 0; i < 1000000; i++)
        {
            int ret = hashMap.Insert(vec[i], NFCommon::tostr(vec[i]));
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "hahsMap Insert failed, i:{} ", vec[i]);
            }
        }

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "shm hash map insert 1000000 use time:{} ms", NFGetTime() - startTime);


        for(int i = 0; i < 1000000; i++)
        {
            int ret = hashMap.Update(vec[i], NFCommon::tostr(vec[i]));
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "hahsMap Update failed, i:{} ", vec[i]);
            }
        }

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "shm hash map update 1000000 use time:{} ms", NFGetTime() - startTime);

        for(int i = 0; i < 1000000; i++)
        {
            int ret = hashMap.Erase(vec[i]);
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "hahsMap Erase failed, i:{} ", vec[i]);
            }
            ret = hashMap.Replace(vec[i], NFCommon::tostr(vec[i]*2));
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "hahsMap Update failed, i:{} ", vec[i]);
            }
        }

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "shm hash map Replace 1000000 use time:{} ms", NFGetTime() - startTime);

        startTime = NFGetTime();
        for(int i = 0; i < 1000000; i++)
        {
            std::string* pTmp = hashMap.Find(vec[i]);
            if (pTmp == NULL || *pTmp != NFCommon::tostr(vec[i]*2))
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "hahsMap Find failed, i:{} ", vec[i]);
            }
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "shm hash map Find 1000000 use time:{} ms", NFGetTime() - startTime);
    }

    {
        uint64_t startTime = NFGetTime();
        std::map<int, std::string> hashMap;
        for(int i = 0; i < 1000000; i++)
        {
            hashMap.emplace(vec[i], NFCommon::tostr(vec[i]));
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "std::map insert 1000000 use time:{} ms", NFGetTime() - startTime);

        startTime = NFGetTime();
        for(int i = 0; i < 1000000; i++)
        {
            auto iter = hashMap.find(vec[i]);
            if (iter != hashMap.end())
            {
                if (iter->second != NFCommon::tostr(vec[i]))
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "std::map Find failed, i:{} ", vec[i]);
                }
            }
            else {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "std::map Find failed, i:{} ", vec[i]);
            }

        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "std::map Find 1000000 use time:{} ms", NFGetTime() - startTime);
    }

    {
        uint64_t startTime = NFGetTime();
        std::unordered_map<int, std::string> hashMap;
        for(int i = 0; i < 1000000; i++)
        {
            hashMap.emplace(vec[i], NFCommon::tostr(vec[i]));
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "std::unordered_map insert 1000000 use time:{} ms", NFGetTime() - startTime);

        startTime = NFGetTime();
        for(int i = 0; i < 1000000; i++)
        {
            auto iter = hashMap.find(vec[i]);
            if (iter != hashMap.end())
            {
                if (iter->second != NFCommon::tostr(vec[i]))
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "std::unordered_map Find failed, i:{} ", vec[i]);
                }
            }
            else {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "std::unordered_map Find failed, i:{} ", vec[i]);
            }

        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "std::unordered_map Find 1000000 use time:{} ms", NFGetTime() - startTime);
    }
}