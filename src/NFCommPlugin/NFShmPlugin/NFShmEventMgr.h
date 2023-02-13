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
#include "NFComm/NFShmCore/NFShmOldHashMap.h"
#include "NFComm/NFShmCore/NFShmNodeList.h"
#include "NFShmEventKey.h"
#include "NFShmSubscribeInfo.h"

#define NF_SHM_EVENT_KEY_MAX_NUM 50000
#define NF_SHM_OBJ_MAX_EVENT_NUM 100

class NFShmEventMgr : public NFShmObj
{
public:
    NFShmEventMgr();

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
    int Subscribe(NFShmObj *pSink, uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string &desc);

    /**
    * @brief 取消订阅事件
    *
    * @param pSink		订阅对象
    * @param nEventID	事件ID
    * @param nSrcID		事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType	事件源类型，玩家类型，怪物类型之类的
    * @return			取消订阅事件是否成功
    */
    int UnSubscribe(NFShmObj *pSink, uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID);

    /**
    * @brief 取消pSink所有订阅事件
    *
    * @param pSink		订阅对象
    * @return			取消订阅事件是否成功
    */
    int UnSubscribeAll(NFShmObj *pSink);
    int UnSubscribeAll(int globalId);

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
    int Fire(uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message);

private:
    /**
    * @brief 删除skey的链表里的pSink
    *
    * @param pSink		订阅对象
    * @param SEventKey	事件合成key
    * @return			删除skey的链表里的pSink是否成功
    */
    int DelEventKeyListSubcribeInfo(NFShmSubscribeInfo* pLastNode);

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
    int Fire(const NFShmEventKey &skey, uint32_t nServerType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID,
              const google::protobuf::Message &message);

private:
    /**
     * @brief
     */
    NFShmOldHashMap<NFShmEventKey, NFShmNodeObjMultiList<NFShmSubscribeInfo>, NF_SHM_EVENT_KEY_MAX_NUM> m_eventKeyAllSubscribe;

    /**
     * @brief
     */
    NFShmOldHashMap<int, NFShmNodeObjMultiList<NFShmSubscribeInfo>, NF_SHM_EVENT_KEY_MAX_NUM> m_shmObjAllSubscribe;

    /**
     * @brief
     */
    int32_t m_nFireLayer;
DECLARE_IDCREATE(NFShmEventMgr)
};