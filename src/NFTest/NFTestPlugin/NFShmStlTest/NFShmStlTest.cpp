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
#include "NFComm/NFShmStl/NFShmList.h"

#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFShmStlTest.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFRandom.hpp"

int checkPair()
{
    NFShmPair<uint64_t, uint64_t> pair(1, 2);
    NFShmPair<uint64_t, uint64_t> pair2(3, 4);
    NFShmPair<uint64_t, uint64_t> pair3(pair);

    CHECK_EQ(pair == pair3);
    CHECK_EQ(pair != pair2);
    CHECK_EQ(pair <= pair2);
    CHECK_EQ(pair == (MakePair<uint64_t, uint64_t>(1, 2)));
    return 0;
}

/**
 * vector 的操作
 */
template<typename T, size_t MAX_SIZE>
void printVector(const NFShmVector<T, MAX_SIZE> &vec)
{
    for (int i = 0; i < (int) vec.size(); i++)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "vev[{}] = {}", i, vec[i]);
    }
}

int checkAlgoVector()
{
    NFShmVector<int, 20> vec1;
    for (int i = 0; i < 10; i++)
    {
        vec1.push_back(NFRandInt(1, 10));
    }
    printVector(vec1);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "test random_shuffle");
    vec1.random_shuffle();
    printVector(vec1);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "test sort");
    vec1.sort();
    printVector(vec1);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "test unique");
    vec1.unique();
    printVector(vec1);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "test random_shuffle");
    vec1.random_shuffle();
    printVector(vec1);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "test remove_if");
    vec1.remove_if([](int n) { return n <= 5; });
    printVector(vec1);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "test sort");
    vec1.sort();
    printVector(vec1);

    for (int i = 0; i < 10; i++)
    {
        int rand = NFRandInt(1, 10);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "insert rand:{}", rand);
        vec1.binary_insert(rand);
        printVector(vec1);
    }

    NFShmVector<int, 20> vec2 = vec1;
    vec2.sort();
    vec2.unique();
    vec2.random_shuffle();
    for (auto iter = vec2.begin(); iter != vec2.end(); iter++)
    {
        int num = *iter;
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "will seach :{}", num);
        auto vecIter = vec1.binary_search_array(num);
        for (int i = 0; i < (int) vecIter.size(); i++)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "search num:{}", *vecIter[i]);
        }
    }

    for (auto iter = vec2.begin(); iter != vec2.end(); iter++)
    {
        int num = *iter;
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "will delete:{}", num);
        vec1.binary_delete(num);
        printVector(vec1);
    }

    return 0;
}

int checkVector()
{
    {
        NFShmVector<int, 5> vec;
        vec.push_back(0);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        for (int i = 0; i < (int) vec.size(); i++)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "vev[{}] = {}", i, vec[i]);
        }
    }

    {
        NFShmVector<NFShmPair<uint64_t, uint64_t>, 5> vecPair;
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(0, 0));
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(1, 1));
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(2, 2));
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(3, 3));
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(4, 4));
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(5, 5));

        for (int i = 0; i < (int) vecPair.size(); i++)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "vevPair[{}] = (first:{} second:{})", i, vecPair[i].first, vecPair[i].second);
        }
    }

    {
        // 构造函数:四种形式
        {
            NFShmVector<std::string, 5> iv0(0, "hi");
            printVector(iv0);

            NFShmVector<std::string, 5> iv(2, "hi");
            printVector(iv);

            NFShmVector<std::string, 5> iv2(6, "hi");
            printVector(iv2);

            NFShmVector<std::string, 5> sv_t_0{};
            printVector(sv_t_0);

            NFShmVector<std::string, 5> sv_t_6{"why", "always", "me", "no", "fuck", "you"};
            printVector(sv_t_6);
        }

        NFShmVector<std::string, 5> sv{"why", "always", "me"};
        printVector(sv);

        {
            NFShmVector<int, 5> sv2_0(0, 1);
            printVector(sv2_0);

            NFShmVector<int, 5> sv2_1(2, 3);
            printVector(sv2_1);

            NFShmVector<int, 5> sv2_2(6, 4);
            printVector(sv2_2);
        }

        {
            NFShmVector<std::string, 5> sv2(sv.begin(), sv.end());
            printVector(sv2);

            NFShmVector<std::string, 0> sv2_s_0(sv.begin(), sv.end());
            printVector(sv2_s_0);

            NFShmVector<std::string, 2> sv2_s_1(sv.begin(), sv.end());
            printVector(sv2_s_1);

            NFShmVector<std::string, 3> sv2_s_2(sv.begin(), sv.end());
            printVector(sv2_s_2);

            NFShmVector<std::string, 6> sv2_s_3(sv.begin(), sv.end());
            printVector(sv2_s_3);
        }

        {
            std::list<std::string> sv2_list_0 = {"fuck", "your", "mother"};

            NFShmVector<std::string, 2> sv2_list_1(sv2_list_0.begin(), sv2_list_0.end());
            printVector(sv2_list_1);

            NFShmVector<std::string, 3> sv2_list_2(sv2_list_0.begin(), sv2_list_0.end());
            printVector(sv2_list_2);

            NFShmVector<std::string, 5> sv2_list_3(sv2_list_0.begin(), sv2_list_0.end());
            printVector(sv2_list_3);
        }

        {
            NFShmVector<std::string, 0> sv3_1(sv);
            printVector(sv3_1);

            NFShmVector<std::string, 2> sv3_2(sv);
            printVector(sv3_2);

            NFShmVector<std::string, 5> sv3_5(sv);
            printVector(sv3_5);

            NFShmVector<std::string, 6> sv3_6(sv);
            printVector(sv3_6);
        }

        {
            // operator= 赋值运算符
            NFShmVector<std::string, 5> sv4_0 = {"a", "b", "c", "d", "e"};
            sv4_0 = sv;
            printVector(sv4_0);

            NFShmVector<std::string, 2> sv4_1 = {"a", "b", "c", "d", "e"};
            sv4_1 = sv;
            printVector(sv4_1);

            NFShmVector<std::string, 3> sv4_2 = {"a", "b", "c", "d", "e"};
            sv4_2 = sv;
            printVector(sv4_2);

            NFShmVector<std::string, 6> sv4_6;
            sv4_6 = sv;
            printVector(sv4_6);
        }

        // assign
        NFShmVector<std::string, 5> cv;
        cv.assign(5, "aaaa");
        printVector(cv);
        cv.assign(3, "bbb");
        printVector(cv);
        cv.assign(6, "ccc");
        printVector(cv);

        NFShmVector<std::string, 5> cv1;
        cv1.assign(cv.begin(), cv.end());
        printVector(cv1);

        NFShmVector<std::string, 0> cv1_0;
        cv1_0.assign(cv.begin(), cv.end());
        printVector(cv1_0);

        NFShmVector<std::string, 5> cv1_1 = {"x", "y", "z"};
        cv1_1.assign(cv.begin(), cv.end());
        printVector(cv1_1);

        NFShmVector<std::string, 2> cv1_2;
        cv1_2.assign(cv.begin(), cv.end());
        printVector(cv1_2);

        NFShmVector<std::string, 6> cv1_6 = {"a", "b", "c", "d", "e", "f"};
        cv1_6.assign(cv.begin(), cv.end());
        printVector(cv1_6);

        // at(索引)
        for (int i = 0; i < (int) cv1.size(); i++)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "cv1.at: {}:{}", i, cv1.at(i));
        }

        // operator[]
        for (int i = 0; i < (int) cv1.size(); i++)
        {
            cv1[i] = "aaa" + NFCommon::tostr(cv1[i]);
        }

        printVector(cv1);

        // front 容器首元素
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "sv.front:{}", sv.front());

        // back 容器最后一个元素
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "sv.back:{}", sv.back());


        // rbegin 返回一个指向容器最后一个元素的反向迭代器
        // rend 返回一个指向容器前端的反向迭代器
        for (auto it = sv.rbegin(); it != sv.rend(); it++)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "reverse_iterator:{}", *it);
        }

        // empty 若容器为空则为 true ，否则为 false
        if (sv.empty())
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "container is null.");
        }
        else
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "container is not null.");
        }

        // size	容器中的元素个数
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "container size:{}", sv.size());

        // max_size 元素数量的最大值
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "container max_size:{}", sv.max_size());

        // capacity 当前分配存储的容量
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "container capacity:{}", sv.capacity());

        // resize 改变容器中可存储元素的个数
        printVector(sv);
        sv.resize(10, "111");
        printVector(sv);

        sv.resize(2, "111");
        printVector(sv);

        // clear 从容器移除所有元素

        // insert:三种形式
        auto it = sv.begin();
        it = sv.insert(it, "YES");
        printVector(sv);

        sv.insert(it, 2, "NO");
        printVector(sv);

        it = sv.begin();
        it = sv.insert(it, "YES");
        printVector(sv);

        sv.insert(it, 2, "NO");
        printVector(sv);

        it = sv.begin();
        NFShmVector<std::string, 10> sv5(2, "xx");
        sv.insert(it + 2, sv5.begin(), sv5.end());
        printVector(sv);

        sv.pop_back();
        printVector(sv);
        it = sv.begin();
        sv.insert(it + 2, sv5.begin(), sv5.end());
        printVector(sv);

        sv.pop_back();
        sv.pop_back();
        printVector(sv);
        it = sv.begin();
        sv.insert(it + 2, sv5.begin(), sv5.end());
        printVector(sv);

        it = sv.begin();
        std::set<std::string> sv5_list = {"111", "222", "333", "444", "555"};
        sv.insert(it + 2, sv5_list.begin(), sv5_list.end());
        printVector(sv);

        sv.pop_back();
        printVector(sv);
        it = sv.begin();
        sv.insert(it + 2, sv5_list.begin(), sv5_list.end());
        printVector(sv);

        sv.pop_back();
        sv.pop_back();
        printVector(sv);
        it = sv.begin();
        sv.insert(it + 2, sv5_list.begin(), sv5_list.end());
        printVector(sv);

        // erase 从容器移除指定的元素
        sv.erase(sv.begin());
        printVector(sv);

        sv.erase(sv.begin() + 2, sv.begin() + 4);
        printVector(sv);

        // push_back 向容器尾部插入元素
        sv.push_back("add");
        printVector(sv);

        // pop_back 移除容器的最末元素
        sv.pop_back();
        printVector(sv);
    }

    return 0;
}

/**
 * list 的操作
 */
template<typename T, size_t MAX_SIZE>
void printList(const NFShmList<T, MAX_SIZE> &list)
{
    int i = 0;
    for (auto iter = list.begin(); iter != list.end(); iter++, i++)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "list {}:{}", i, *iter);
    }
}

int checkList()
{
    {
        NFShmList<int, 5> vec;
        vec.push_back(0);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        printList(vec);
    }

    {
        NFShmList<NFShmPair<uint64_t, uint64_t>, 5> vecPair;
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(0, 0));
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(1, 1));
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(2, 2));
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(3, 3));
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(4, 4));
        vecPair.push_back(NFShmPair<uint64_t, uint64_t>(5, 5));

        int i = 0;
        for (auto iter = vecPair.begin(); iter != vecPair.end(); iter++, i++)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "vevPair[{}] = (first:{} second:{})", i, iter->first, iter->second);
        }
    }

    {
        // 构造函数:四种形式
        {
            NFShmList<std::string, 5> iv0(0, "hi");
            printList(iv0);

            NFShmList<std::string, 5> iv(2, "hi");
            printList(iv);

            NFShmList<std::string, 5> iv2(6, "hi");
            printList(iv2);

            NFShmList<std::string, 5> sv_t_0{};
            printList(sv_t_0);

            NFShmList<std::string, 5> sv_t_6{"why", "always", "me", "no", "fuck", "you"};
            printList(sv_t_6);
        }

        NFShmList<std::string, 5> sv{"why", "always", "me"};
        printList(sv);

        {
            NFShmList<int, 5> sv2_0(0, 1);
            printList(sv2_0);

            NFShmList<int, 5> sv2_1(2, 3);
            printList(sv2_1);

            NFShmList<int, 5> sv2_2(6, 4);
            printList(sv2_2);
        }

        {
            NFShmList<std::string, 5> sv2(sv.begin(), sv.end());
            printList(sv2);

            NFShmList<std::string, 0> sv2_s_0(sv.begin(), sv.end());
            printList(sv2_s_0);

            NFShmList<std::string, 2> sv2_s_1(sv.begin(), sv.end());
            printList(sv2_s_1);

            NFShmList<std::string, 3> sv2_s_2(sv.begin(), sv.end());
            printList(sv2_s_2);

            NFShmList<std::string, 6> sv2_s_3(sv.begin(), sv.end());
            printList(sv2_s_3);
        }

        {
            std::list<std::string> sv2_list_0 = {"fuck", "your", "mother"};

            NFShmList<std::string, 2> sv2_list_1(sv2_list_0.begin(), sv2_list_0.end());
            printList(sv2_list_1);

            NFShmList<std::string, 3> sv2_list_2(sv2_list_0.begin(), sv2_list_0.end());
            printList(sv2_list_2);

            NFShmList<std::string, 5> sv2_list_3(sv2_list_0.begin(), sv2_list_0.end());
            printList(sv2_list_3);
        }

        {
            NFShmList<std::string, 0> sv3_1(sv);
            printList(sv3_1);

            NFShmList<std::string, 2> sv3_2(sv);
            printList(sv3_2);

            NFShmList<std::string, 5> sv3_5(sv);
            printList(sv3_5);

            NFShmList<std::string, 6> sv3_6(sv);
            printList(sv3_6);
        }

        {
            // operator= 赋值运算符
            NFShmList<std::string, 5> sv4_0 = {"a", "b", "c", "d", "e"};
            sv4_0 = sv;
            printList(sv4_0);

            NFShmList<std::string, 2> sv4_1 = {"a", "b", "c", "d", "e"};
            sv4_1 = sv;
            printList(sv4_1);

            NFShmList<std::string, 3> sv4_2 = {"a", "b", "c", "d", "e"};
            sv4_2 = sv;
            printList(sv4_2);

            NFShmList<std::string, 6> sv4_6;
            sv4_6 = sv;
            printList(sv4_6);
        }

        // assign
        NFShmList<std::string, 5> cv;
        cv.assign(5, "aaaa");
        printList(cv);
        cv.assign(3, "bbb");
        printList(cv);
        cv.assign(6, "ccc");
        printList(cv);

        NFShmList<std::string, 5> cv1;
        cv1.assign(cv.begin(), cv.end());
        printList(cv1);

        NFShmList<std::string, 0> cv1_0;
        cv1_0.assign(cv.begin(), cv.end());
        printList(cv1_0);

        NFShmList<std::string, 5> cv1_1 = {"x", "y", "z"};
        cv1_1.assign(cv.begin(), cv.end());
        printList(cv1_1);

        NFShmList<std::string, 2> cv1_2;
        cv1_2.assign(cv.begin(), cv.end());
        printList(cv1_2);

        NFShmList<std::string, 6> cv1_6 = {"a", "b", "c", "d", "e", "f"};
        cv1_6.assign(cv.begin(), cv.end());
        printList(cv1_6);

        // front 容器首元素
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "sv.front:{}", sv.front());

        // back 容器最后一个元素
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "sv.back:{}", sv.back());


        // rbegin 返回一个指向容器最后一个元素的反向迭代器
        // rend 返回一个指向容器前端的反向迭代器
        for (auto it = sv.rbegin(); it != sv.rend(); it++)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "reverse_iterator:{}", *it);
        }

        // empty 若容器为空则为 true ，否则为 false
        if (sv.empty())
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "container is null.");
        }
        else
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "container is not null.");
        }

        // size	容器中的元素个数
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "container size:{}", sv.size());

        // max_size 元素数量的最大值
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "container max_size:{}", sv.max_size());

        // capacity 当前分配存储的容量
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "container capacity:{}", sv.capacity());

        // resize 改变容器中可存储元素的个数
        printList(sv);
        sv.resize(10, "111");
        printList(sv);

        sv.resize(2, "111");
        printList(sv);

        // clear 从容器移除所有元素

        // insert:三种形式
        auto it = sv.begin();
        it = sv.insert(it, "YES");
        printList(sv);

        sv.insert(it, 2, "NO");
        printList(sv);

        it = sv.begin();
        it = sv.insert(it, "YES");
        printList(sv);

        sv.insert(it, 2, "NO");
        printList(sv);

        it = sv.begin();
        NFShmVector<std::string, 10> sv5(2, "xx");
        sv.insert(it, sv5.begin(), sv5.end());
        printList(sv);

        sv.pop_back();
        printList(sv);
        it = sv.begin();
        sv.insert(it, sv5.begin(), sv5.end());
        printList(sv);

        sv.pop_back();
        sv.pop_back();
        printList(sv);
        it = sv.begin();
        sv.insert(it, sv5.begin(), sv5.end());
        printList(sv);

        it = sv.begin();
        std::set<std::string> sv5_list = {"111", "222", "333", "444", "555"};
        sv.insert(it, sv5_list.begin(), sv5_list.end());
        printList(sv);

        sv.pop_back();
        printList(sv);
        it = sv.begin();
        sv.insert(it, sv5_list.begin(), sv5_list.end());
        printList(sv);

        sv.pop_back();
        sv.pop_back();
        printList(sv);
        it = sv.begin();
        sv.insert(it, sv5_list.begin(), sv5_list.end());
        printList(sv);

        // erase 从容器移除指定的元素
        sv.erase(sv.begin());
        printList(sv);

        sv.erase(sv.begin(), sv.end());
        printList(sv);

        // push_back 向容器尾部插入元素
        sv.push_back("add");
        printList(sv);

        // pop_back 移除容器的最末元素
        sv.pop_back();
        printList(sv);
    }

    return 0;
}

int checkAlgoList()
{
    NFShmList<int, 20> vec1;
    for (int i = 0; i < 10; i++)
    {
        vec1.push_back(NFRandInt(1, 10));
    }
    printList(vec1);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "test sort");
    vec1.sort();
    printList(vec1);
/*
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "test unique");
    vec1.unique();
    printList(vec1);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "test random_shuffle");
    vec1.random_shuffle();
    printList(vec1);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "test remove_if");
    vec1.remove_if([](int n) { return n <= 5; });
    printList(vec1);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "test sort");
    vec1.sort();
    printList(vec1);

    for (int i = 0; i < 10; i++)
    {
        int rand = NFRandInt(1, 10);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "insert rand:{}", rand);
        vec1.binary_insert(rand);
        printVector(vec1);
    }

    NFShmVector<int, 20> vec2 = vec1;
    vec2.sort();
    vec2.unique();
    vec2.random_shuffle();
    for (auto iter = vec2.begin(); iter != vec2.end(); iter++)
    {
        int num = *iter;
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "will seach :{}", num);
        auto vecIter = vec1.binary_search_array(num);
        for (int i = 0; i < (int) vecIter.size(); i++)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "search num:{}", *vecIter[i]);
        }
    }

    for (auto iter = vec2.begin(); iter != vec2.end(); iter++)
    {
        int num = *iter;
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "will delete:{}", num);
        vec1.binary_delete(num);
        printVector(vec1);
    }*/

    return 0;
}

int testMain()
{
    //CHECK_RET(checkPair(), "checkPair Failed");
    //CHECK_RET(checkVector(), "checkVector Failed");
    //CHECK_RET(checkAlgoVector(), "checkAlgoVector Failed");
    checkList();
    return 0;
}
