// -------------------------------------------------------------------------
//    @FileName         :    NFEventTemplate.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include <stdint.h>
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFHash.hpp"
#include "google/protobuf/message.h"
#include "NFLogMgr.h"

/**
 *@brief  对所有事件最大嵌套层数支持20层.
 * 比如在Fire一个事件里，又Fire了别的事件，不断嵌套
 */
#define EVENT_FIRE_MAX_LAYER 20

/**
*@brief  对单一事件最大嵌套层数支持5层.
* 比如在Fire一个事件里，又对这个事件经行了Fire
*/
#define EVENT_REF_MAX_CNT 5



/**
 *@brief 事件系统模版类
 */
template<class TEventSink, class TEventKey>
class NFEventTemplate
{
private:
    /**
     *@brief 事件描述信息
     */
    struct SubscribeInfo
    {
        /**
        *@brief 事件对象
        */
        TEventSink *pSink;

        /**
        *@brief 描述信息
        */
        std::string szDesc;

        /**
        *@brief 引用次数
        */
        int32_t nRefCount;

        /**
        *@brief 移除标志
        */
        bool bRemoveFlag;

        /**
        *@brief 构造函数
        */
        SubscribeInfo(TEventSink *pParamSink, const std::string &desc) : szDesc(desc)
        {
            pSink = pParamSink;
            szDesc = desc;
            nRefCount = 0;
            bRemoveFlag = false;
        }

        /**
        *@brief 增加引用
        */
        void Add()
        {
            nRefCount++;
        }

        /**
        *@brief 减少引用
        */
        void Sub()
        {
            --nRefCount;
        }

        std::string ToString() const
        {
            return NF_FORMAT("nRefCount:{} bRemoveFlag:{}, desc:{}", nRefCount, bRemoveFlag, szDesc);
        }
    };

public:
    /**
    *@brief 构造函数
    */
    NFEventTemplate()
    {
        m_nFireLayer = 0;
    }

    /**
    *@brief 析构函数
    */
    virtual ~NFEventTemplate()
    {
        m_mapAllSubscribeKey.clear();
        m_mapAllSubscribeObj.clear();
    }

    /**
    * @brief 订阅事件
    *
    * @param pSink		订阅对象
    * @param nEventID	事件ID
    * @param nSrcID		事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType	事件源类型，玩家类型，怪物类型之类的
    * @param desc		事件描述，用于打印，获取信息，查看BUG之类的
    * @return			订阅事件是否成功
    */
    bool Subscribe(TEventSink *pSink, const TEventKey& skey, const std::string &desc)
    {
        if (nullptr == pSink) return false;

        /**
        *@brief 先判断指针pSink对象有没有注册，然后把skey放入
        *       这个指针的的集合里，如果skey已经存在，
        *       说明已经存入，直接退出
        */
        auto iter = m_mapAllSubscribeKey.find(pSink);
        if (iter == m_mapAllSubscribeKey.end())
        {
            m_mapAllSubscribeKey[pSink].insert(skey);
        }
        else
        {
            auto iterSet = iter->second.find(skey);
            if (iterSet != iter->second.end())
            {
                return true;
            }
            iter->second.insert(skey);
        }

        /**
        *@brief 判断skey有没有存在，把对象存入skey的链表里
        */
        SubscribeInfo info(pSink, desc);
        auto iterObj = m_mapAllSubscribeObj.find(skey);
        if (iterObj != m_mapAllSubscribeObj.end())
        {
            iterObj->second.push_front(info);
        }
        else
        {
            m_mapAllSubscribeObj[skey].push_front(info);
        }
        return true;
    }

    /**
    * @brief 取消订阅事件
    *
    * @param pSink		订阅对象
    * @param nEventID	事件ID
    * @param nSrcID		事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType	事件源类型，玩家类型，怪物类型之类的
    * @return			取消订阅事件是否成功
    */
    bool UnSubscribe(TEventSink *pSink, const TEventKey& skey)
    {
        if (nullptr == pSink) return false;

        /**
        *@brief 判断pSink指针对象有没有存在，不存在直接退出
        *		存在的话，删除对应的key, 如果pSink集合为空的话，
        *       删除pSink
        */
        auto iter = m_mapAllSubscribeKey.find(pSink);
        if (iter == m_mapAllSubscribeKey.end())
        {
            return false;
        }

        if (iter->second.find(skey) == iter->second.end())
        {
            return false;
        }

        iter->second.erase(skey);
        if (iter->second.empty())
        {
            m_mapAllSubscribeKey.erase(iter);
        }

        /**
        *@brief 删除skey链表里的pSink
        */
        DelSubcribeInfo(pSink, skey);

        return true;
    }

    /**
    * @brief 取消pSink所有订阅事件
    *
    * @param pSink		订阅对象
    * @return			取消订阅事件是否成功
    */
    bool UnSubscribeAll(TEventSink *pSink)
    {
        if (nullptr == pSink) return false;

        auto iter = m_mapAllSubscribeKey.find(pSink);
        if (iter == m_mapAllSubscribeKey.end())
        {
            return false;
        }

        for (auto iterSet = iter->second.begin(); iterSet != iter->second.end(); ++iterSet)
        {
            DelSubcribeInfo(pSink, (*iterSet));
        }
        m_mapAllSubscribeKey.erase(iter);

        return true;
    }

    /**
    * @brief 发送事件,并执行收到事件的对象的对应函数
    *
    * @param nEventID		事件ID
    * @param nSrcID			事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType		事件源类型，玩家类型，怪物类型之类的
    * @param pEventContext	事件传输的数据
    * @return				执行是否成功
    */
    /*
    * 几个威胁，可能导致问题, 但不会导致崩溃, 可能与你预想的不一样:
    * 问题1:假设我在Fire事件里，相同的key，删除不同的pSink,
    *		可能导致将要执行的事件被删除，这可能与你预想的设计不一样
    * 问题2:假设我在Fire事件里，相同的key，删除相同的pSink, 由于事件系统利用SubscribeInfo的Add,Sub引用计数做了预防，
    *       迭代器不会立马被删除，不会导致std::list迭代器失效， 这样删除不会导致问题
    * 问题3:假设我在Fire事件里， Fire了别的事件，会导致迭代问题，事件系统已经了做了预付， 相同的事件，最多迭代5次，
    *       所有的Fire事件最多迭代20次
    */
    /**
    * @brief 执行所有订阅事件key的函数
    *
    * @param skey			事件合成key，skey.nsrcid可能为0，可能=nEventID
    * @param nEventID		事件ID
    * @param nSrcID			事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType		事件源类型，玩家类型，怪物类型之类的
    * @param pEventContext	事件传输的数据
    * @return				执行是否成功
    */
    template<typename... ARGS>
    bool Fire(const TEventKey &skey, const ARGS& ... args)
    {
        m_nFireLayer++;
        if (m_nFireLayer >= EVENT_FIRE_MAX_LAYER)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0,
                       "[Event] m_nFireLayer >= EVENT_FIRE_MAX_LAYER.....skey:{}, fireLayer:{}",
                       skey.ToString(), m_nFireLayer);
            m_nFireLayer--;
            return false;
        }

        auto iterLst = m_mapAllSubscribeObj.find(skey);
        if (iterLst != m_mapAllSubscribeObj.end())
        {
            for (auto iter = iterLst->second.begin(); iter != iterLst->second.end();)
            {
                SubscribeInfo *pSubscribeInfo = &(*iter);
                if (pSubscribeInfo->nRefCount >= EVENT_REF_MAX_CNT)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0,
                               "[Event] pSubscribeInfo->nRefCount >= EVENT_REF_MAX_CNT....skey:{}, refcont:{}, removeflag:{}, szdesc:{}",
                               skey.ToString(), pSubscribeInfo->nRefCount,
                               static_cast<int32_t>(pSubscribeInfo->bRemoveFlag), pSubscribeInfo->szDesc);
                    m_nFireLayer--;
                    return false;
                }
                if (!pSubscribeInfo->bRemoveFlag)
                {
                    int bRes = 0;
                    try
                    {
                        pSubscribeInfo->Add();
                        if (pSubscribeInfo->pSink)
                        {
                            bRes = pSubscribeInfo->pSink->OnExecuteImple(skey, args...);
                        }
                        pSubscribeInfo->Sub();
                    }
                    catch (...)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0,
                                   "[Event] pSubscribeInfo->nRefCount >= EVENT_REF_MAX_CNT....skey:{}, refcont:{}, removeflag:{}, szdesc:{}",
                                   skey.ToString(), pSubscribeInfo->nRefCount,
                                   static_cast<int32_t>(pSubscribeInfo->bRemoveFlag), pSubscribeInfo->szDesc);
                        m_nFireLayer--;
                        return false;
                    }
                    if (pSubscribeInfo->bRemoveFlag && 0 == pSubscribeInfo->nRefCount)
                    {
                        iter = iterLst->second.erase(iter);
                    }
                    else
                    {
                        ++iter;
                    }
                    if (bRes != 0)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0,
                                   "[Event] ret != 0 ....skey:{}, refcont:{}, removeflag:{}, szdesc:{}",
                                   skey.ToString(), pSubscribeInfo->nRefCount,
                                   static_cast<int32_t>(pSubscribeInfo->bRemoveFlag), pSubscribeInfo->szDesc);
                    }
                } // end of if (!subInfo.bRemoveFlag)
                else
                {
                    if (0 == pSubscribeInfo->nRefCount)
                    {
                        iter = iterLst->second.erase(iter);
                    }
                    else
                    {
                        ++iter;
                    }
                }
            } // end of for (; iter != pLstSubscribe->end();)

            if (iterLst->second.empty())
            {
                m_mapAllSubscribeObj.erase(iterLst);
            }
        } // enf of if (iterLst != m_mapAllSubscribeObj.end())

        m_nFireLayer--;

        return true;
    }

private:
    /**
    * @brief 删除skey的链表里的pSink
    *
    * @param pSink		订阅对象
    * @param TEventKey	事件合成key
    * @return			删除skey的链表里的pSink是否成功
    */
    bool DelSubcribeInfo(TEventSink *pSink, const TEventKey &skey)
    {
        auto iter = m_mapAllSubscribeObj.find(skey);
        if (iter != m_mapAllSubscribeObj.end())
        {
            for (auto iterLst = iter->second.begin(); iterLst != iter->second.end(); ++iterLst)
            {
                SubscribeInfo &sInfo = (*iterLst);
                if (sInfo.pSink == pSink)
                {
                    if (sInfo.nRefCount == 0)
                    {
                        iter->second.erase(iterLst);
                    }
                    else
                    {
                        sInfo.bRemoveFlag = true;
                    }
                    break;
                }
            }
            if (iter->second.empty())
            {
                m_mapAllSubscribeObj.erase(iter);
            }
        }

        return true;
    }



private:
    std::unordered_map<TEventKey, std::list<SubscribeInfo>> m_mapAllSubscribeObj;
    //
    std::unordered_map<void *, std::unordered_set<TEventKey>> m_mapAllSubscribeKey;
    //
    int32_t m_nFireLayer;
};

