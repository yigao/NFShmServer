// -------------------------------------------------------------------------
//    @FileName         :    NFShmMap.h
//    @Author           :    gaoyi
//    @Date             :    23-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmMap
//
// -------------------------------------------------------------------------

#pragma once

#include <map>

template<class Key, class Tp, int MAX_SIZE,
        class HashFcn = std::hash<Key>,
        class EqualKey = std::equal_to<Key>>
class NFShmMap;

template<class Key, class Tp, int MAX_SIZE, class HashFcn, class EqualKey>
class NFShmMap : public std::map<Key, Tp, HashFcn>
{

};

template<class Key, class Tp, int MAX_SIZE,
        class HashFcn = std::hash<Key>,
        class EqualKey = std::equal_to<Key>>
class NFShmMultiMap;

template<class Key, class Tp, int MAX_SIZE, class HashFcn, class EqualKey>
class NFShmMultiMap : public std::multimap<Key, Tp, HashFcn>
{

};