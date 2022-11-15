// -------------------------------------------------------------------------
//    @FileName         :    NFShmEventMgr.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmEventMgr
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include <stddef.h>
#include <string.h>
#include <NFComm/NFPluginModule/NFEventTemplate.h>
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"
#include "NFComm/NFShmCore/NFShmNodeList.h"
#include "NFShmEventKey.h"
#include "NFShmSubscribeInfo.h"

#define NF_SHM_EVENT_KEY_MAX_NUM 50000
#define NF_SHM_OBJ_MAX_EVENT_NUM 100

class NFShmEventMgr : public NFShmObj
{
public:
    NFShmEventMgr(NFIPluginManager *pPluginManager);

    virtual ~NFShmEventMgr();

public:
    int CreateInit();

    int ResumeInit();

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
    int Subscribe(NFShmObj *pSink, uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const std::string &desc)
    {
        if (nullptr == pSink) return -1;

        NFShmEventKey skey;
        skey.nEventID = nEventID;
        skey.nSrcID = nSrcID;
        skey.bySrcType = bySrcType;

        /**
        *@brief 先判断指针pSink对象有没有注册，然后把skey放入
        *       这个指针的的集合里，如果skey已经存在，
        *       说明已经存入，直接退出
        */
        auto pArray = m_mapAllSubscribeKey.Find(pSink->GetGlobalID());
        if (pArray == NULL)
        {
            pArray = m_mapAllSubscribeKey.Insert(pSink->GetGlobalID());
            CHECK_EXPR(pArray, -1, "m_mapAllSubscribeKey Insert Failed, Space Not Enough, desc:{}", desc);
            int ret = pArray->Add(skey);
            CHECK_EXPR(ret >= 0, -1, "m_mapAllSubscribeKey Arrray Add Failed, Space Not Enough, desc:{}", desc);
        }
        else
        {
            int ret = pArray->Add(skey);
            CHECK_EXPR(ret >= 0, -1, "m_mapAllSubscribeKey Arrray Add Failed, Space Not Enough, desc:{}", desc);
        }

        /**
        *@brief 判断skey有没有存在，把对象存入skey的链表里
        */
        NFShmSubscribeInfo *pInfo = dynamic_cast<NFShmSubscribeInfo *>(FindModule<NFISharedMemModule>()->CreateObj(EOT_TYPE_SUBSCRIBEINFO_OBJ));
        CHECK_EXPR(pInfo, -1, "CreateObj NFShmSubscribeInfo Failed, desc:{}", desc);
        pInfo->pSink = pSink;
        pInfo->szDesc = desc;
        auto pNodeList = m_mapAllSubscribeObj.Find(skey);
        if (pNodeList)
        {
            pNodeList->AddNode(m_pObjPluginManager, pInfo);
        }
        else
        {
            pNodeList = m_mapAllSubscribeObj.Insert(skey);
            CHECK_EXPR(pNodeList, -1, "m_mapAllSubscribeObj Insert Failed, Space Not Enough, desc:{}", desc);
            pNodeList->AddNode(m_pObjPluginManager, pInfo);
        }
        return 0;
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
    int UnSubscribe(NFShmObj *pSink, uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType)
    {
        if (nullptr == pSink) return -1;

        NFShmEventKey skey;
        skey.nEventID = nEventID;
        skey.nSrcID = nSrcID;
        skey.bySrcType = bySrcType;

        /**
        *@brief 判断pSink指针对象有没有存在，不存在直接退出
        *		存在的话，删除对应的key, 如果pSink集合为空的话，
        *       删除pSink
        */
        auto pArray = m_mapAllSubscribeKey.Find(pSink->GetGlobalID());
        if (pArray == NULL)
        {
            return -1;
        }

        bool notHas = true;
        for (int i = 0; i < pArray->Size();)
        {
            if (skey == (*pArray)[i])
            {
                pArray->Del(i);
                notHas = false;
            }
            else {
                i++;
            }
        }

        if(notHas)
        {
            return -1;
        }

        if (pArray->Size() <= 0)
        {
            m_mapAllSubscribeKey.Erase(pSink->GetGlobalID());
        }

        /**
        *@brief 删除skey链表里的pSink
        */
        DelSubcribeInfo(pSink, skey);

        return 0;
    }

    /**
    * @brief 取消pSink所有订阅事件
    *
    * @param pSink		订阅对象
    * @return			取消订阅事件是否成功
    */
    int UnSubscribeAll(NFShmObj *pSink)
    {
        if (nullptr == pSink) return false;

        auto pArray = m_mapAllSubscribeKey.Find(pSink->GetGlobalID());
        if (pArray == NULL)
        {
            return -1;
        }

        for (int i = 0; i < (int)pArray->Size(); i++)
        {
            DelSubcribeInfo(pSink, (*pArray)[i]);
        }

        m_mapAllSubscribeKey.Erase(pSink->GetGlobalID());

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
    bool Fire(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message)
    {
        SEventKey skey;
        skey.nEventID = nEventID;
        skey.nSrcID = nSrcID;
        skey.bySrcType = bySrcType;

        /**
        * @brief 先执行完全匹配的
        */
        if (skey.nSrcID != 0)
        {
            bool bRes = Fire(skey, nEventID, nSrcID, bySrcType, message);
            if (!bRes)
            {
                return false;
            }
        }

        /**
        * @brief 再执行， 针对整个事件nEventID,类型为bySrcType
        * 比如订阅时，订阅了所有玩家类的事件，而不是对一个玩家的事件，
        * 订阅时将nSrcId=0，会受到所有玩家产生的该类事件
        */
        skey.nSrcID = 0;
        bool bRes = Fire(skey, nEventID, nSrcID, bySrcType, message);
        if (!bRes)
        {
            return false;
        }
        return true;
    }

private:
    /**
    * @brief 删除skey的链表里的pSink
    *
    * @param pSink		订阅对象
    * @param SEventKey	事件合成key
    * @return			删除skey的链表里的pSink是否成功
    */
    bool DelSubcribeInfo(NFShmObj *pSink, const NFShmEventKey &skey)
    {
        auto pNodeList = m_mapAllSubscribeObj.Find(skey);
        if (pNodeList)
        {
            NFShmSubscribeInfo* pNode = pNodeList->GetHeadNodeObj(m_pObjPluginManager);
            while(pNode)
            {
                if (pNode->pSink.GetPoint() == pSink)
                {
                    if (pNode->nRefCount == 0)
                    {
                        pNodeList->RemoveNode(m_pObjPluginManager, pNode);
                    }
                    else
                    {
                        pNode->bRemoveFlag = true;
                    }
                    break;
                }
                pNode = pNodeList->GetNextNodeObj(m_pObjPluginManager, pNode);
            }

            if (pNodeList->GetNodeCount() == 0)
            {
                m_mapAllSubscribeObj.Erase(skey);
            }
        }

        return true;
    }

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
    bool Fire(const SEventKey &skey, uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType,
              const google::protobuf::Message &message)
    {
        m_nFireLayer++;
        if (m_nFireLayer >= EVENT_FIRE_MAX_LAYER)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0,
                       "[Event] m_nFireLayer >= EVENT_FIRE_MAX_LAYER.....nEventID:{}, nSrcID:{}, bySrcType:{}, fireLayer:{}",
                       nEventID, nSrcID, bySrcType, m_nFireLayer);
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
                               "[Event] pSubscribeInfo->nRefCount >= EVENT_REF_MAX_CNT....eventid:{}, srcid:{}, type:{}, refcont:{}, removeflag:{}, szdesc:{}",
                               nEventID, nSrcID, bySrcType, pSubscribeInfo->nRefCount,
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
                        bRes = m_FireEventObj(pSubscribeInfo->pSink, nEventID, nSrcID, bySrcType, message);
                        pSubscribeInfo->Sub();
                    }
                    catch (...)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0,
                                   "[Event] pSubscribeInfo->nRefCount >= EVENT_REF_MAX_CNT....eventid:{}, srcid:{}, type:{}, refcont:{}, removeflag:{}, szdesc:{}",
                                   nEventID, nSrcID, bySrcType, pSubscribeInfo->nRefCount,
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
                                   "[Event] ret != 0 ....eventid:{}, srcid:{}, type:{}, refcont:{}, removeflag:{}, szdesc:{}",
                                   nEventID, nSrcID, bySrcType, pSubscribeInfo->nRefCount,
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

public:
    //
    NFShmHashMap<NFShmEventKey, NFShmNodeObjList<NFShmSubscribeInfo>, NF_SHM_EVENT_KEY_MAX_NUM> m_mapAllSubscribeObj;
    //
    NFShmHashMap<int, NFArray<NFShmEventKey, NF_SHM_OBJ_MAX_EVENT_NUM>, NF_SHM_EVENT_KEY_MAX_NUM> m_mapAllSubscribeKey;
    //
    int32_t m_nFireLayer;
DECLARE_IDCREATE(NFShmEventMgr)
};