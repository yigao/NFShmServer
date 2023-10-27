// -------------------------------------------------------------------------
//    @FileName         :    NFShmEventMgr.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmEventMgr
//
// -------------------------------------------------------------------------

#include "NFShmEventMgr.h"
#include "NFComm/NFShmCore/NFTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

NFShmEventMgr::NFShmEventMgr()
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

NFShmEventMgr::~NFShmEventMgr()
{

}

int NFShmEventMgr::CreateInit()
{
    m_nFireLayer = 0;
    m_eventKeyAllSubscribe.CreateInit();
    m_shmObjAllSubscribe.CreateInit();
    return 0;
}

int NFShmEventMgr::ResumeInit()
{
    return 0;
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
int NFShmEventMgr::Subscribe(NFShmObj *pSink, uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string &desc)
{
    if (nullptr == pSink) return -1;
    CHECK_EXPR_ASSERT(pSink->GetGlobalId() != INVALID_ID, -1, "NFShmObj GetGlobalId == INVALID_ID, desc:{}", desc);

    NFShmEventKey skey;
    skey.nServerType = nServerType;
    skey.nEventID = nEventID;
    skey.bySrcType = bySrcType;
    skey.nSrcID = nSrcID;

    /**
    *@brief 先判断指针pSink对象有没有注册，然后把skey放入
    *       这个指针的的集合里，如果skey已经存在，
    *       说明已经存入，直接退出
    */
    auto pObjList = m_shmObjAllSubscribe.Find(pSink->GetGlobalId());
    if (pObjList == NULL)
    {
        pObjList = m_shmObjAllSubscribe.Insert(pSink->GetGlobalId());
        CHECK_EXPR(pObjList, -1, "m_shmobjAllSubscribe Insert Failed, Space Not Enough, desc:{}", desc);
    }

    auto pEventKeyList = m_eventKeyAllSubscribe.Find(skey);
    if (pEventKeyList == NULL)
    {
        pEventKeyList = m_eventKeyAllSubscribe.Insert(skey);
        CHECK_EXPR(pEventKeyList, -1, "m_eventKeyAllSubscribe Insert Failed, Space Not Enough, desc:{}", desc);
    }

    //一般一个对象不会定义太多事件, 效率耗得起
/*    auto pNode = pObjList->GetHeadNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1);
    while(pNode)
    {
        if (pNode->m_eventKey == skey)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "ShmObj Subscribe Same Event, desc:{}", desc);
            return -1;
        }
        pNode = pObjList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pNode);
    }*/

    /**
    *@brief 判断skey有没有存在，把对象存入skey的链表里
    */
    NFShmSubscribeInfo *pInfo = dynamic_cast<NFShmSubscribeInfo *>(FindModule<NFISharedMemModule>()->CreateObj(EOT_TYPE_SUBSCRIBEINFO_OBJ));
    CHECK_EXPR(pInfo, -1, "CreateObj NFShmSubscribeInfo Failed, desc:{}", desc);
    pInfo->pSink = pSink;
    pInfo->szDesc = desc;
    pInfo->m_eventKey = skey;
    pInfo->m_shmObjId = pSink->GetGlobalId();

    int ret = pObjList->AddNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pInfo);
    CHECK_EXPR_ASSERT(ret == 0, -1, "AddNode Failed, desc:{}", desc);
    ret = pEventKeyList->AddNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pInfo);
    CHECK_EXPR_ASSERT(ret == 0, -1, "AddNode Failed, desc:{}", desc);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ShmObj:{} ShmObjType:{} Subscribe:{}", pSink->GetGlobalId(), pSink->GetClassName(), pInfo->ToString());
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
int NFShmEventMgr::UnSubscribe(NFShmObj *pSink, uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID)
{
    if (nullptr == pSink) return -1;

    NFShmEventKey skey;
    skey.nServerType = nServerType;
    skey.nEventID = nEventID;
    skey.bySrcType = bySrcType;
    skey.nSrcID = nSrcID;

    /**
    *@brief 判断pSink指针对象有没有存在，不存在直接退出
    *		存在的话，删除对应的key, 如果pSink集合为空的话，
    *       删除pSink
    */
    auto pShmObjList = m_shmObjAllSubscribe.Find(pSink->GetGlobalId());
    if (pShmObjList == NULL)
    {
        return -1;
    }

    auto pNode = pShmObjList->GetHeadNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1);
    while (pNode)
    {
        CHECK_EXPR_ASSERT(pNode->m_shmObjId == pSink->GetGlobalId(), -1, "");
        if (pNode->m_eventKey == skey)
        {
            auto pLastNode = pNode;
            pNode = pShmObjList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pNode);
            pShmObjList->RemoveNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pLastNode);
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ShmObj:{} ShmObjType:{} Delete Subscribe:{}", pSink->GetGlobalId(), pSink->GetClassName(), pLastNode->ToString());
            DelEventKeyListSubcribeInfo(pLastNode);
        }
        else
        {
            pNode = pShmObjList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pNode);
        }
    }

    if (pShmObjList->IsEmpty())
    {
        m_shmObjAllSubscribe.Erase(pSink->GetGlobalId());
    }

    return 0;
}

/**
* @brief 取消pSink所有订阅事件
*
* @param pSink		订阅对象
* @return			取消订阅事件是否成功
*/
int NFShmEventMgr::UnSubscribeAll(NFShmObj *pSink)
{
    if (nullptr == pSink) return -1;

    return UnSubscribeAll(pSink->GetGlobalId());
}

int NFShmEventMgr::UnSubscribeAll(int globalId)
{
    auto pShmObjList = m_shmObjAllSubscribe.Find(globalId);
    if (pShmObjList == NULL)
    {
        return -1;
    }

    auto pNode = pShmObjList->GetHeadNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1);
    while (pNode)
    {
        CHECK_EXPR_ASSERT(pNode->m_shmObjId == globalId, -1, "");
        auto pLastNode = pNode;
        pNode = pShmObjList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pNode);
        pShmObjList->RemoveNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pLastNode);

        DelEventKeyListSubcribeInfo(pLastNode);
    }

    m_shmObjAllSubscribe.Erase(globalId);

    return 0;
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
int NFShmEventMgr::Fire(uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message)
{
    NFShmEventKey skey;
    skey.nServerType = nServerType;
    skey.nEventID = nEventID;
    skey.bySrcType = bySrcType;
    skey.nSrcID = nSrcID;

    /**
    * @brief 先执行完全匹配的
    */
    if (skey.nSrcID != 0)
    {
        int ret = Fire(skey, nServerType, nEventID, bySrcType, nSrcID, message);
        if (ret != 0)
        {
            return ret;
        }
    }

    /**
    * @brief 再执行， 针对整个事件nEventID,类型为bySrcType
    * 比如订阅时，订阅了所有玩家类的事件，而不是对一个玩家的事件，
    * 订阅时将nSrcId=0，会受到所有玩家产生的该类事件
    */
    skey.nSrcID = 0;
    return Fire(skey, nServerType, nEventID, bySrcType, nSrcID, message);
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
int NFShmEventMgr::Fire(const NFShmEventKey &skey, uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message)
{
    m_nFireLayer++;
    if (m_nFireLayer >= EVENT_FIRE_MAX_LAYER)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0,
                   "m_nFireLayer >= EVENT_FIRE_MAX_LAYER.....{} fireLayer:{}", skey.ToString(), m_nFireLayer);
        m_nFireLayer--;
        return -1;
    }

    std::vector<int> errVec;
    auto pEventKeyList = m_eventKeyAllSubscribe.Find(skey);
    if (pEventKeyList)
    {
        auto pNode = pEventKeyList->GetHeadNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0);
        while (pNode)
        {
            if (pNode->nRefCount >= EVENT_REF_MAX_CNT)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "pSubscribeInfo->nRefCount >= EVENT_REF_MAX_CNT....{}", pNode->ToString());
                m_nFireLayer--;
                return -1;
            }

            if (!pNode->bRemoveFlag)
            {
                int bRes = 0;
                try
                {
                    pNode->Add();
                    //智能指针，自动转空
                    if (pNode->pSink)
                    {
                        bRes = pNode->pSink->OnExecute(nServerType, nEventID, bySrcType, nSrcID, &message);
                    }
                    else
                    {
                        errVec.push_back(pNode->m_shmObjId);

                        NFLogError(NF_LOG_SYSTEMLOG, 0, "[Event] pNode->pSink = NULL....{}", pNode->ToString());
                    }
                    pNode->Sub();
                }
                catch (...)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[Event] pSubscribeInfo->nRefCount >= EVENT_REF_MAX_CNT....{}", pNode->ToString());
                    m_nFireLayer--;
                    return -1;
                }

                if (pNode->bRemoveFlag && 0 == pNode->nRefCount)
                {
                    auto pLastNode = pNode;
                    pNode = pEventKeyList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pNode);
                    pEventKeyList->RemoveNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pLastNode);
                    FindModule<NFISharedMemModule>()->DestroyObj(pLastNode);
                }
                else
                {
                    pNode = pEventKeyList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pNode);
                }
                if (bRes != 0)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[Event] ret != 0 ....{}", pNode->ToString());
                }
            }
            else
            {
                if (0 == pNode->nRefCount)
                {
                    auto pLastNode = pNode;
                    pNode = pEventKeyList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pNode);
                    pEventKeyList->RemoveNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pLastNode);
                    FindModule<NFISharedMemModule>()->DestroyObj(pLastNode);
                }
                else
                {
                    pNode = pEventKeyList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pNode);
                }
            }
        }

        if (pEventKeyList->IsEmpty())
        {
            m_eventKeyAllSubscribe.Erase(skey);
        }
    }

    m_nFireLayer--;

    for (int i = 0; i < (int) errVec.size(); i++)
    {
        UnSubscribeAll(errVec[i]);
    }

    return 0;
}

int NFShmEventMgr::DelEventKeyListSubcribeInfo(NFShmSubscribeInfo *pLastNode)
{
    auto pEventKeyList = m_eventKeyAllSubscribe.Find(pLastNode->m_eventKey);
    if (pEventKeyList)
    {
        if (pLastNode->nRefCount == 0)
        {
            pEventKeyList->RemoveNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pLastNode);
            FindModule<NFISharedMemModule>()->DestroyObj(pLastNode);
        }
        else
        {
            pLastNode->bRemoveFlag = true;
        }

        if (pEventKeyList->IsEmpty())
        {
            m_eventKeyAllSubscribe.Erase(pLastNode->m_eventKey);
        }
    }

    return 0;
}
