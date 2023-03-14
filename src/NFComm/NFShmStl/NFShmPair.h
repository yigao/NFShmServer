// -------------------------------------------------------------------------
//    @FileName         :    NFShmPair.h
//    @Author           :    gaoyi
//    @Date             :    23-1-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmPair
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

template <class T1, class T2>
struct NFShmPair {
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    NFShmPair()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    NFShmPair(const T1& __a, const T2& __b) : first(__a), second(__b)
    {

    }

    template <class _U1, class _U2>
    NFShmPair(const std::pair<_U1, _U2>& __p) : first(__p.first), second(__p.second)
    {

    }

    NFShmPair(const std::pair<T1, T2>& __p) : first(__p.first), second(__p.second)
    {

    }


    template <class _U1, class _U2>
    NFShmPair(const NFShmPair<_U1, _U2>& __p) : first(__p.first), second(__p.second)
    {

    }

    virtual ~NFShmPair()
    {

    }

    int CreateInit()
    {
        first = T1();
        second = T2();
        return 0;
    }

    int ResumeInit()
    {
       return 0;
    }
};


template <class T1, class T2>
inline bool operator==(const NFShmPair<T1, T2>& __x, const NFShmPair<T1, T2>& __y)
{
    return __x.first == __y.first && __x.second == __y.second;
}

template <class T1, class T2>
inline bool operator<(const NFShmPair<T1, T2>& __x, const NFShmPair<T1, T2>& __y)
{
    return __x.first < __y.first ||
           (!(__y.first < __x.first) && __x.second < __y.second);
}

template <class T1, class T2>
inline bool operator!=(const NFShmPair<T1, T2>& __x, const NFShmPair<T1, T2>& __y) {
    return !(__x == __y);
}

template <class T1, class T2>
inline bool operator>(const NFShmPair<T1, T2>& __x, const NFShmPair<T1, T2>& __y) {
    return __y < __x;
}

template <class T1, class T2>
inline bool operator<=(const NFShmPair<T1, T2>& __x, const NFShmPair<T1, T2>& __y) {
    return !(__y < __x);
}

template <class T1, class T2>
inline bool operator>=(const NFShmPair<T1, T2>& __x, const NFShmPair<T1, T2>& __y) {
    return !(__x < __y);
}

template <class T1, class T2>
inline NFShmPair<T1, T2> MakePair(const T1& __x, const T2& __y)
{
    return NFShmPair<T1, T2>(__x, __y);
}