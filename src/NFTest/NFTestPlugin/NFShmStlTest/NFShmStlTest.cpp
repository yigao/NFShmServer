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
#include "NFComm/NFCore/NFCommon.h"

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

/**
 * vector 的操作
 */
template <typename T, int MAX_SIZE>
void printVector(const NFShmVector<T, MAX_SIZE>& vec)
{
    for(int i = 0; i < (int)vec.size(); i++)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "vev[{}] = {}", i, vec[i]);
    }

    cout << endl;
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
       for(int i = 0; i < (int)cv1.size(); i++)
       {
           NFLogInfo(NF_LOG_SYSTEMLOG, 0, "cv1.at: {}:{}", i, cv1.at(i));
       }

       // operator[]
        for(int i = 0; i < (int)cv1.size(); i++)
        {
            cv1[i] = "aaa" + NFCommon::tostr(cv1[i]);
        }
        cv1[6] = "aaa";
        printVector(cv1);

/*          // front 容器首元素
        cout << sv.front() << endl;

        // back 容器最后一个元素
        cout << sv.back() << endl;

        // begin 返回指向容器第一个元素的迭代器
        // end 返回指向容器尾端的迭代器
        for (vector<string>::iterator it = sv.begin(); it != sv.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;

        // rbegin 返回一个指向容器最后一个元素的反向迭代器
        // rend 返回一个指向容器前端的反向迭代器
        for (vector<string>::reverse_iterator it = sv.rbegin(); it != sv.rend(); it++) {
            cout << *it << " ";
        }
        cout << endl;

        // empty 若容器为空则为 true ，否则为 false
        if (sv.empty()) {
            cout << "container is null." << endl;
        } else {
            cout << "container is not null." << endl;
        }

        // size	容器中的元素个数
        cout << sv.size() << endl;

        // max_size 元素数量的最大值
        cout << sv.max_size() << endl;

        // capacity 当前分配存储的容量
        cout << sv.capacity() << endl;

        // resize 改变容器中可存储元素的个数
        sv.resize(10);
        cout << sv.capacity() << endl;

        // shrink_to_fit 请求移除未使用的容量
        sv.shrink_to_fit();
        cout << sv.capacity() << endl;

        // clear 从容器移除所有元素
        iv.clear();
        printVector(iv);

        // insert:三种形式
        auto it = sv.begin();
        it = sv.insert(it, "YES");
        printVector(sv);

        sv.insert(it, 2, "NO");
        printVector(sv);

        it = sv.begin();
        vector<string> sv5(2, "xx");
        sv.insert(it+2, sv5.begin(), sv5.end());
        printVector(sv);

        // erase 从容器移除指定的元素
        sv.erase(sv.begin());
        printVector(sv);

        sv.erase(sv.begin() + 2, sv.begin() + 4);
        printVector(sv);

        // push_back 向容器尾部插入元素
        cout << sv.size() << endl;
        sv.push_back("add");
        printVector(sv);

        // pop_back 移除容器的最末元素
        sv.pop_back();
        printVector(sv);

        // swap
        sv.swap(sv5);
        printVector(sv);
        printVector(sv5);*/
    }
    return 0;
}

int testMain()
{
    CHECK_RET(checkPair(), "checkPair Failed");
    CHECK_RET(checkVector(), "checkVector Failed");
    return 0;
}
