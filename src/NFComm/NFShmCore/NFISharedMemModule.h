// -------------------------------------------------------------------------
//    @FileName         :    NFISharedMemModule.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include <unordered_set>
#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFShmDefine.h"
#include "NFTypeDefines.h"
#include "NFShmObjIterator.h"

class NFShmObj;

class NFTransBase;

class NFShmObj;

class NFISharedMemModule : public NFIModule
{
public:
    typedef NFShmObjIterator<NFShmObj, NFShmObj &, NFShmObj *, NFISharedMemModule> iterator;
    typedef NFShmObjIterator<NFShmObj, const NFShmObj &, const NFShmObj *, NFISharedMemModule> const_iterator;

    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
public:

    NFISharedMemModule(NFIPluginManager *p) : NFIModule(p)
    {

    }

    virtual ~NFISharedMemModule()
    {

    }

    virtual int AllocShm() = 0;

    /**
    * 从共享内存里获得一块内存
    */
    virtual void *CreateSegment(size_t siSize) = 0;

    /**
    * 共享内存模式
    */
    virtual EN_OBJ_MODE GetInitMode() = 0;

    /**
    * 共享内存模式
    */
    virtual void SetInitMode(EN_OBJ_MODE mode) = 0;

    /**
    * @brief  对象seq自增
    */
    virtual int IncreaseObjSeqNum() = 0;

    /**
    * @brief  获得偏移地址
    */
    virtual size_t GetAddrOffset() = 0;

    /**
    * @brief  获得类名
    */
    virtual std::string GetClassName(int bType) = 0;

    virtual int GetClassType(int bType) = 0;

    virtual void *AllocMemForObject(int iType) = 0;

    virtual void FreeMemForObject(int iType, void *pMem) = 0;

    virtual void RegisterClassToObjSeg(int bType, size_t nObjSize, int iItemCount, NFShmObj *(*pfResumeObj)(NFIPluginManager *pPluginManager, void *),
                                       NFShmObj *(*pCreatefn)(NFIPluginManager *pPluginManager),
                                       void(*pDestroy)(NFIPluginManager *pPluginManager, NFShmObj *), int parentType,
                                       const std::string &pszClassName, bool useHash = false, bool singleton = false) = 0;

    virtual size_t GetAllObjSize() = 0;

    virtual int InitializeAllObj() = 0;

    virtual int InitShmObjectGlobal() = 0;

    /**
    * @brief  设置功能内存初始化成功
    */
    virtual void SetShmInitSuccessFlag() = 0;

    virtual NFShmObj *CreateObjByHashKey(int iType, uint64_t hashKey) = 0;

    virtual NFShmObj *GetObjByHashKey(int iType, uint64_t hashKey) = 0;

    virtual const std::unordered_set<int>& GetChildrenType(int iType) = 0;

    virtual int GetItemCount(int iType) = 0;

    virtual int GetUsedCount(int iType) = 0;

    virtual int GetFreeCount(int iType) = 0;

    virtual int GetGlobalId(int iType, int iIndex, NFShmObj *pObj) = 0;

    virtual int GetObjId(int iType, NFShmObj *pObj) = 0;

    virtual NFShmObj *CreateObj(int iType) = 0;

    template<typename ShmObjType>
    ShmObjType *CreateObj()
    {
        return dynamic_cast<ShmObjType*>(CreateObj(ShmObjType::GetClassType(m_pObjPluginManager)));
    }

    template<typename ShmObjType>
    ShmObjType *CreateObjByHashKey(uint64_t hashKey)
    {
        return dynamic_cast<ShmObjType*>(CreateObjByHashKey(ShmObjType::GetClassType(m_pObjPluginManager), hashKey));
    }

    template<typename ShmObjType>
    ShmObjType *GetObjByHashKey(uint64_t hashKey)
    {
        return dynamic_cast<ShmObjType*>(GetObjByHashKey(ShmObjType::GetClassType(m_pObjPluginManager), hashKey));
    }

    virtual NFShmObj *GetHeadObj(int iType) = 0;

    template<typename ShmObjType>
    ShmObjType *GetHeadObj()
    {
        return dynamic_cast<ShmObjType*>(GetHeadObj(ShmObjType::GetClassType(m_pObjPluginManager)));
    }

    virtual NFShmObj *GetNextObj(int iType, NFShmObj *pObj) = 0;

    template<typename ShmObjType>
    ShmObjType *GetNextObj(NFShmObj *pObj)
    {
        return dynamic_cast<ShmObjType*>(GetNextObj(ShmObjType::GetClassType(m_pObjPluginManager), pObj));
    }

    virtual void DestroyObj(NFShmObj *pObj) = 0;

    virtual void ClearAllObj(int iType) = 0;

    virtual int DestroyObjAutoErase(int iType, int maxNum = INVALID_ID, const DESTROY_SHM_AUTO_ERASE_FUNCTION &func = NULL) = 0;

    virtual NFShmObj *GetObjByObjId(int iType, int iIndex) = 0;

    virtual NFShmObj *GetObjByGlobalId(int iType, int iGlobalID, bool withChildrenType = false) = 0;

    template<typename ShmObjType>
    ShmObjType *GetObjByGlobalId(int iGlobalID, int iStrongType = 1)
    {
        return dynamic_cast<ShmObjType*>(GetObjByGlobalId(iGlobalID, ShmObjType::GetClassType(m_pObjPluginManager), iStrongType));
    }

    virtual NFShmObj *GetObjByGlobalIdWithNoCheck(int iGlobalID) = 0;

    // 根据混合ID获得对象
    // iType不为-1表示校验对象类型
    virtual NFShmObj *GetObjByMiscId(int iMiscID, int iType = -1) = 0;

    virtual bool IsEnd(int iType, int iIndex) = 0;
public:
    /**
     * @brief ShmObj类链表迭代器+1
     * @param iType
     * @param iPos
     * @return
     */
    virtual size_t IterIncr(int iType, size_t iPos) = 0;

    /**
     * @brief ShmObj类链表迭代器-1
     * @param iType
     * @param iPos
     * @return
     */
    virtual size_t IterDecr(int iType, size_t iPos) = 0;

    virtual iterator IterBegin(int iType) = 0;

    virtual iterator IterEnd(int iType) = 0;

    virtual const_iterator IterBegin(int iType) const = 0;

    virtual const_iterator IterEnd(int iType) const = 0;

    virtual reverse_iterator IterRBegin(int iType) { return reverse_iterator(IterEnd(iType)); }

    virtual reverse_iterator IterREnd(int iType) { return reverse_iterator(IterBegin(iType)); }

    virtual const_reverse_iterator IterRBegin(int iType) const { return const_reverse_iterator(IterEnd(iType)); }

    virtual const_reverse_iterator IterREnd(int iType) const { return const_reverse_iterator(IterBegin(iType)); }

    virtual iterator Erase(iterator iter) = 0;

    virtual NFShmObj* GetIterObj(int iType, size_t iPos) = 0;
    virtual const NFShmObj* GetIterObj(int iType, size_t iPos) const = 0;
public:
    virtual bool IsTypeValid(int iType) const = 0;

    virtual NFTransBase *CreateTrans(int iType) = 0;

    template<typename ShmObjType>
    ShmObjType *CreateTrans()
    {
        return dynamic_cast<ShmObjType*>(CreateTrans(ShmObjType::GetClassType(m_pObjPluginManager)));
    }

    virtual NFTransBase *GetTrans(uint64_t ullTransId) = 0;

    template<typename ShmObjType>
    ShmObjType *GetTrans(uint64_t ullTransId)
    {
        return dynamic_cast<ShmObjType*>(GetTrans(ullTransId));
    }

    /**
    * 共享内存创建对象模式
    */
    virtual EN_OBJ_MODE GetCreateMode() = 0;

    /**
    * 共享内存创建对象模式
    */
    virtual void SetCreateMode(EN_OBJ_MODE mode) = 0;

    virtual int Get32UUID() = 0;

    /**
    * @brief  运行时文件ID
    */
    virtual uint32_t GetRunTimeFileId() = 0;

    //delete objid
    virtual int DeleteTimer(NFShmObj *pObj, int timeObjId) = 0;

    virtual int DeleteAllTimer(NFShmObj *pObj) = 0;

    //注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
    virtual int SetTimer(NFShmObj *pObj, int hour, int minutes, int second, int microSec) = 0;

    //注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
    virtual int SetCalender(NFShmObj *pObj, int hour, int minutes, int second) = 0;

    //注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
    virtual int SetCalender(NFShmObj *pObj, uint64_t timestamp) = 0;

    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
    virtual int SetTimer(NFShmObj *pObj, int interval, int callcount, int hour, int minutes, int second, int microSec) = 0;

    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    virtual int SetDayTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec) = 0;

    //注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
    virtual int SetDayCalender(NFShmObj *pObj, int callcount, int hour, int minutes, int second) = 0;

    //周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    virtual int SetWeekTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec) = 0;

    //注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
    virtual int SetWeekCalender(NFShmObj *pObj, int callcount, int weekDay, int hour, int minutes, int second) = 0;

    //月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
    virtual int SetMonthTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec) = 0;

    //注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
    virtual int SetMonthCalender(NFShmObj *pObj, int callcount, int day, int hour, int minutes, int second) = 0;

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
    virtual int FireExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message) = 0;

    /**
    * @brief 订阅事件
    *
    * @param nEventID	事件ID
    * @param nSrcID		事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType	事件源类型，玩家类型，怪物类型之类的
    * @param desc		事件描述，用于打印，获取信息，查看BUG之类的
    * @return			订阅事件是否成功
    */
    virtual int Subscribe(NFShmObj *pObj, uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string &desc) = 0;

    /**
    * @brief 取消订阅事件
    *
    * @param nEventID	事件ID
    * @param nSrcID		事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType	事件源类型，玩家类型，怪物类型之类的
    * @return			取消订阅事件是否成功
    */
    virtual int UnSubscribe(NFShmObj *pObj, uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID) = 0;

    /**
    * @brief 取消NFEventObj所有订阅事件
    *
    * @return			取消订阅事件是否成功
    */
    virtual int UnSubscribeAll(NFShmObj *pObj) = 0;
};
