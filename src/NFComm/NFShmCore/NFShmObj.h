// -------------------------------------------------------------------------
//    @FileName         :    NFShmObj.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFShmDefine.h"
#include "NFDynamicHead.h"
#include "NFShmTimerObj.h"
#include "NFComm/NFPluginModule/NFEventObj.h"

class NFShmObj : public NFShmTimerObj, public NFEventObjBase
{
public:
    NFShmObj(NFIPluginManager *pPluginManager);

    virtual ~NFShmObj();

    //非继承函数, 不要加virtual
    int CreateInit();

    //非继承函数, 不要加virtual
    int ResumeInit()
    {
        return 0;
    }

    virtual int AfterOnReloadConfig()
    {
        return 0;
    }

    //must be virtual
    virtual void OnTimer(int timeId, int callcount)
    {

    }

#if defined(_DEBUG) | defined(_DEBUG_)

    void CheckMemMagicNum()
    {
        assert(m_iMagicCheckNum == OBJECT_MAGIC_CHECK_NUMBER);
    }

#endif

    virtual int GetHashKey(void *pvKey, int &iKeyLength);

    virtual int SetHashKey(const void *pvKey, int iKeyLength);

    virtual int Show(FILE *fpOut);

    void SetInRecycle(bool bRet)
    {
        m_bIsInRecycle = bRet;
    }

    bool IsInRecycle()
    {
        return m_bIsInRecycle;
    }

    int GetGlobalID() const
    {
        return m_iGlobalID;
    }

    void SetGlobalID(int iID)
    {
        m_iGlobalID = iID;
    }

    int GetTypeIndexID()
    {
        return ((GetClassType() << 23) | 0x80000000) | GetObjectID();
    }

    int GetMiscID()
    {
        if (m_iGlobalID >= 0)
        {
            return m_iGlobalID;
        }
        else
        {
            return GetTypeIndexID();
        }
    }

public:
    /**
    * @brief 收到事件函数, 对收到的事件进行处理
    *
    * @param nEventID		事件ID
    * @param nSrcID			事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType		事件源类型，玩家类型，怪物类型之类的
    * @param pEventContext	发过来的事件数据
    * @return
    */
    /*
    * 由Fire的问题，导致的问题:
    * 问题1:如果在OnExecute函数里， 调用别的对象的UnSubscribe函数, 如果key一致(也就是nEventID,nSrcID,bySrcType都一样),
    *		可能导致将要执行的事件被删除，这可能与你预想的设计不一样
    * 问题2:如果在OnExecute函数里， Fire了别的事件，会导致迭代问题，事件系统已经了做了预付， 相同的事件，最多迭代5次，
    *       所有的Fire事件最多迭代20次
    */
    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
    {
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
    virtual void FireExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message);

    /**
    * @brief 订阅事件
    *
    * @param nEventID	事件ID
    * @param nSrcID		事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType	事件源类型，玩家类型，怪物类型之类的
    * @param desc		事件描述，用于打印，获取信息，查看BUG之类的
    * @return			订阅事件是否成功
    */
    virtual bool Subscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const std::string &desc);

    /**
    * @brief 取消订阅事件
    *
    * @param nEventID	事件ID
    * @param nSrcID		事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType	事件源类型，玩家类型，怪物类型之类的
    * @return			取消订阅事件是否成功
    */
    virtual bool UnSubscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType);

    /**
    * @brief 取消NFEventObj所有订阅事件
    *
    * @return			取消订阅事件是否成功
    */
    virtual bool UnSubscribeAll();

public:

#if defined(_DEBUG) | defined(_DEBUG_)
    int m_iMagicCheckNum;
#endif
    int m_iGlobalID;
    int m_iObjectID;
    int m_iObjSeq;
    int m_iHashID;

    bool m_bIsInRecycle;

DECLARE_IDCREATE(NFShmObj)
};

