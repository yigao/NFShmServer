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

IMPLEMENT_IDCREATE_WITHTYPE(NFShmEventMgr, EOT_TYPE_EVENT_MGR, NFShmObj)

NFShmEventMgr::NFShmEventMgr(NFIPluginManager* pPluginManager):NFShmObj(pPluginManager)
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
int NFShmEventMgr::Subscribe(NFShmObj *pSink, uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const std::string &desc)
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
    auto pObjList = m_shmObjAllSubscribe.Find(pSink->GetGlobalID());
    if (pObjList == NULL)
    {
        pObjList = m_shmObjAllSubscribe.Insert(pSink->GetGlobalID());
        CHECK_EXPR(pObjList, -1, "m_shmobjAllSubscribe Insert Failed, Space Not Enough, desc:{}", desc);
    }

    auto pEventKeyList = m_eventKeyAllSubscribe.Find(skey);
    if (pEventKeyList == NULL)
    {
        pEventKeyList = m_eventKeyAllSubscribe.Insert(skey);
        CHECK_EXPR(pEventKeyList, -1, "m_eventKeyAllSubscribe Insert Failed, Space Not Enough, desc:{}", desc);
    }

    /**
    *@brief 判断skey有没有存在，把对象存入skey的链表里
    */
    NFShmSubscribeInfo *pInfo = dynamic_cast<NFShmSubscribeInfo *>(FindModule<NFISharedMemModule>()->CreateObj(EOT_TYPE_SUBSCRIBEINFO_OBJ));
    CHECK_EXPR(pInfo, -1, "CreateObj NFShmSubscribeInfo Failed, desc:{}", desc);
    pInfo->pSink = pSink;
    pInfo->szDesc = desc;
    pInfo->m_eventKey = skey;

    int ret = pObjList->AddNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pInfo);
    CHECK_EXPR_ASSERT(ret == 0, -1, "AddNode Failed, desc:{}", desc);
    ret = pEventKeyList->AddNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pInfo);
    CHECK_EXPR_ASSERT(ret == 0, -1, "AddNode Failed, desc:{}", desc);
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
int NFShmEventMgr::UnSubscribe(NFShmObj *pSink, uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType)
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
    auto pShmObjList = m_shmObjAllSubscribe.Find(pSink->GetGlobalID());
    if (pShmObjList == NULL)
    {
        return -1;
    }

    auto pEventKeyList = m_eventKeyAllSubscribe.Find(skey);

    auto pNode = pShmObjList->GetHeadNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1);
    while(pNode)
    {
        CHECK_EXPR_ASSERT(pNode->pSink->GetGlobalID() == pSink->GetGlobalID(), -1, "");
        if (pNode->m_eventKey == skey)
        {
            auto pLastNode = pNode;
            pNode = pShmObjList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pNode);
            pShmObjList->RemoveNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pLastNode);

            if (pEventKeyList)
            {
                pEventKeyList->RemoveNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pLastNode);
            }

            FindModule<NFISharedMemModule>()->DestroyObj(pLastNode);
        }
        else {
            pNode = pShmObjList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pNode);
        }
    }

    if (pShmObjList->IsEmpty())
    {
        m_shmObjAllSubscribe.Erase(pSink->GetGlobalID());
    }

    if (pEventKeyList && pEventKeyList->IsEmpty())
    {
        m_eventKeyAllSubscribe.Erase(skey);
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
    if (nullptr == pSink) return false;

    auto pShmObjList = m_shmObjAllSubscribe.Find(pSink->GetGlobalID());
    if (pShmObjList == NULL)
    {
        return -1;
    }

    auto pNode = pShmObjList->GetHeadNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1);
    while(pNode)
    {
        CHECK_EXPR_ASSERT(pNode->pSink->GetGlobalID() == pSink->GetGlobalID(), -1, "");
        auto pLastNode = pNode;
        pNode = pShmObjList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pNode);
        pShmObjList->RemoveNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1, pLastNode);

        auto pEventKeyList = m_eventKeyAllSubscribe.Find(pLastNode->m_eventKey);
        if (pEventKeyList)
        {
            pEventKeyList->RemoveNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pLastNode);

            if (pEventKeyList->IsEmpty())
            {
                m_eventKeyAllSubscribe.Erase(pLastNode->m_eventKey);
            }
        }

        FindModule<NFISharedMemModule>()->DestroyObj(pLastNode);
    }

    m_shmObjAllSubscribe.Erase(pSink->GetGlobalID());

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
int NFShmEventMgr::Fire(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message)
{
    NFShmEventKey skey;
    skey.nEventID = nEventID;
    skey.nSrcID = nSrcID;
    skey.bySrcType = bySrcType;

    /**
    * @brief 先执行完全匹配的
    */
    if (skey.nSrcID != 0)
    {
        int ret = Fire(skey, nEventID, nSrcID, bySrcType, message);
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
    return Fire(skey, nEventID, nSrcID, bySrcType, message);
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
int NFShmEventMgr::Fire(const NFShmEventKey &skey, uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType,
         const google::protobuf::Message &message)
{
    m_nFireLayer++;
    if (m_nFireLayer >= EVENT_FIRE_MAX_LAYER)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0,
                   "[Event] m_nFireLayer >= EVENT_FIRE_MAX_LAYER.....nEventID:{}, nSrcID:{}, bySrcType:{}, fireLayer:{}",
                   nEventID, nSrcID, bySrcType, m_nFireLayer);
        m_nFireLayer--;
        return -1;
    }

    auto pEventKeyList = m_eventKeyAllSubscribe.Find(skey);
    if (pEventKeyList)
    {
        auto pNode = pEventKeyList->GetHeadNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0);
        while(pNode)
        {
            if (pNode->nRefCount >= EVENT_REF_MAX_CNT)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "[Event] pSubscribeInfo->nRefCount >= EVENT_REF_MAX_CNT....eventid:{}, srcid:{}, type:{}, refcont:{}, removeflag:{}, szdesc:{}",
                           nEventID, nSrcID, bySrcType, pNode->nRefCount,
                           static_cast<int32_t>(pNode->bRemoveFlag), pNode->szDesc.ToString());
                m_nFireLayer--;
                return -1;
            }
            if (!pNode->bRemoveFlag)
            {
                int bRes = 0;
                try
                {
                    pNode->Add();
                    bRes = pNode->pSink->OnExecute(nEventID, nSrcID, bySrcType, message);
                    pNode->Sub();
                }
                catch (...)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0,
                               "[Event] pSubscribeInfo->nRefCount >= EVENT_REF_MAX_CNT....eventid:{}, srcid:{}, type:{}, refcont:{}, removeflag:{}, szdesc:{}",
                               nEventID, nSrcID, bySrcType, pNode->nRefCount,
                               static_cast<int32_t>(pNode->bRemoveFlag), pNode->szDesc.ToString());
                    m_nFireLayer--;
                    return false;
                }
                if (pNode->bRemoveFlag && 0 == pNode->nRefCount)
                {
                    auto pLastNode = pNode;
                    pNode = pEventKeyList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pNode);
                    pEventKeyList->RemoveNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pLastNode);
                }
                else
                {
                    pNode = pEventKeyList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pNode);
                }
                if (bRes != 0)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0,
                               "[Event] ret != 0 ....eventid:{}, srcid:{}, type:{}, refcont:{}, removeflag:{}, szdesc:{}",
                               nEventID, nSrcID, bySrcType, pNode->nRefCount,
                               static_cast<int32_t>(pNode->bRemoveFlag), pNode->szDesc.ToString());
                }
            }
            else
            {
                if (0 == pNode->nRefCount)
                {
                    auto pLastNode = pNode;
                    pNode = pEventKeyList->GetNextNodeObj(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pNode);
                    pEventKeyList->RemoveNode(m_pObjPluginManager, NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0, pLastNode);
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

    return true;
}
