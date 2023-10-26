// -------------------------------------------------------------------------
//    @FileName         :    NFCSharedMemModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFShmCore/NFCSharedMem.h"
#include <unordered_map>

#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFTypeDefines.h"
#include "NFIDRuntimeClass.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"


class NFTransBase;

class NFCSharedMemModule;

class NFGlobalID;

class NFShmObjSeg;

class NFShmObjSegSwapCounter
{
    friend class NFCSharedMemModule;

public:
    NFShmObjSegSwapCounter()

    {
        m_nObjSize = 0;
        m_iItemCount = 0;
        m_iObjType = 0;
        m_iUseHash = false;
        m_singleton = false;
        m_pResumeFn = NULL;
        m_pCreatefn = NULL;
        m_pDestroyFn = NULL;
        m_pObjSeg = NULL;
    }

    void SetObjSeg(NFShmObjSeg *pObjSeg);

public:
    std::string m_szClassName;
    size_t m_nObjSize;
    int m_iItemCount;
    int m_iObjType;
    bool m_iUseHash;
    bool m_singleton;
    NFShmObjSeg *m_pObjSeg;

    NFShmObj *(*m_pResumeFn)(NFIPluginManager *, void *);
    NFShmObj *(*m_pCreatefn)(NFIPluginManager* pPluginManager);
    void(*m_pDestroyFn)(NFIPluginManager* pPluginManager, NFShmObj *);

    NFIDRuntimeClass m_pidRuntimeClass;
};

class NFCSharedMemModule : public NFISharedMemModule
{
public:
    NFCSharedMemModule(NFIPluginManager *p);

    virtual ~NFCSharedMemModule();

public:
    virtual bool AfterLoadAllPlugin() override;

    virtual bool ReadyExecute() override;

    virtual bool Execute() override;

    /**
    * 创建共享内存
    */
    virtual bool Finalize() override;

    /**
    * 创建共享内存
    */
    virtual bool OnReloadConfig() override;

    virtual bool AfterOnReloadConfig() override;

    /**
    * 分配共享内存
    */
    virtual int AllocShm() override;

    /**
    * 分配共享内存
    */
    virtual int AllocShm(int iKey, size_t siShmSize);

    /**
    * 从共享内存里获得一块内存
    */
    virtual void *CreateSegment(size_t siSize) override;

    /**
    * 共享内存模式
    */
    virtual EN_OBJ_MODE GetInitMode() override;

    /**
    * 共享内存模式
    */
    virtual void SetInitMode(EN_OBJ_MODE mode) override;

    /**
    * 共享内存创建对象模式
    */
    virtual EN_OBJ_MODE GetCreateMode() override;

    /**
    * 共享内存创建对象模式
    */
    virtual void SetCreateMode(EN_OBJ_MODE mode) override;

    /**
    * @brief  对象seq自增
    */
    virtual int IncreaseObjSeqNum() override;

    /**
    * @brief  获得偏移地址
    */
    virtual size_t GetAddrOffset() override;

    /**
    * @brief  NFGlobalID
    */
    virtual NFGlobalID *GetGlobalID();

    /**
    * @brief  设置功能内存初始化成功
    */
    virtual void SetShmInitSuccessFlag() override;

    /**
    * @brief  运行时文件ID
    */
    virtual uint32_t GetRunTimeFileId() override;

    //delete objid
    virtual int DeleteTimer(NFShmObj *pObj, int timeObjId);

    virtual int DeleteAllTimer(NFShmObj *pObj);

    virtual int DeleteAllTimer(NFShmObj *pObj, NFRawShmObj* pRawShmObj);

    //注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
    virtual int SetTimer(NFShmObj *pObj, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj = NULL);

    //注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
    virtual int SetCalender(NFShmObj *pObj, int hour, int minutes, int second, NFRawShmObj* pRawShmObj = NULL);

    //注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
    virtual int SetCalender(NFShmObj *pObj, uint64_t timestamp, NFRawShmObj* pRawShmObj = NULL);

    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
    virtual int SetTimer(NFShmObj *pObj, int interval, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj = NULL);

    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    virtual int SetDayTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj = NULL);

    //注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
    virtual int SetDayCalender(NFShmObj *pObj, int callcount, int hour, int minutes, int second, NFRawShmObj* pRawShmObj = NULL);

    //周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    virtual int SetWeekTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj = NULL);

    //注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
    virtual int SetWeekCalender(NFShmObj *pObj, int callcount, int weekDay, int hour, int minutes, int second, NFRawShmObj* pRawShmObj = NULL);

    //月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
    virtual int SetMonthTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj = NULL);

    //注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
    virtual int SetMonthCalender(NFShmObj *pObj, int callcount, int day, int hour, int minutes, int second, NFRawShmObj* pRawShmObj = NULL);

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
    virtual int FireExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message) override;

    /**
    * @brief 订阅事件
    *
    * @param nEventID	事件ID
    * @param nSrcID		事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType	事件源类型，玩家类型，怪物类型之类的
    * @param desc		事件描述，用于打印，获取信息，查看BUG之类的
    * @return			订阅事件是否成功
    */
    virtual int Subscribe(NFShmObj *pObj, uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string &desc) override;

    /**
    * @brief 取消订阅事件
    *
    * @param nEventID	事件ID
    * @param nSrcID		事件源ID，一般都是玩家，生物唯一id
    * @param bySrcType	事件源类型，玩家类型，怪物类型之类的
    * @return			取消订阅事件是否成功
    */
    virtual int UnSubscribe(NFShmObj *pObj, uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID) override;

    /**
    * @brief 取消NFEventObj所有订阅事件
    *
    * @return			取消订阅事件是否成功
    */
    virtual int UnSubscribeAll(NFShmObj *pObj) override;
public:
    int ReadRunMode();

public:
    virtual NFShmObjSeg *GetObjSeg(int iType);
    
    virtual NFShmObjSegSwapCounter *GetObjSegSwapCounter(int iType);

    virtual int GetItemCount(int iType) override;

    virtual int GetUsedCount(int iType) override;

    virtual int GetFreeCount(int iType) override;

    virtual int GetGlobalId(int iType, int iIndex, NFShmObj *pObj) override;

    virtual int GetObjId(int iType, NFShmObj *pObj) override;

    virtual void *AllocMemForObject(int iType) override;

    virtual void FreeMemForObject(int iType, void *pMem) override;

    virtual NFShmObj *GetObjByObjId(int iType, int iIndex) override;

    virtual NFShmObj *CreateObjByHashKey(int iType, ShmObjHashKey hashKey) override;

    virtual NFShmObj *GetObjByHashKey(int iType, ShmObjHashKey hashKey) override;

    virtual NFShmObj *CreateObj(int iType) override;

    virtual NFShmObj *GetHeadObj(int iType) override;

    virtual NFShmObj *GetNextObj(int iType, NFShmObj *pObj) override;

    virtual void DestroyObj(NFShmObj *pObj) override;

    virtual void ClearAllObj(int iType) override;;

    const std::unordered_set<int>& GetChildrenType(int iType) override;

    virtual int DestroyObjAutoErase(int iType, int maxNum = INVALID_ID, const DESTROY_SHM_AUTO_ERASE_FUNCTION &func = NULL) override;

    virtual NFShmObj *GetObjByGlobalId(int iType, int iGlobalID, bool withChildrenType = false) override;

    virtual NFShmObj *GetObjByGlobalIdWithNoCheck(int iGlobalID) override;

    // 根据混合ID获得对象
    // iType不为-1表示校验对象类型
    virtual NFShmObj *GetObjByMiscId(int iMiscID, int iType = -1) override;

    virtual NFIDRuntimeClass *GetIDRuntimeClass(int iType);

    virtual bool IsEnd(int iType, int iIndex) override;

    /**
     * @brief ShmObj类链表迭代器+1
     * @param iType
     * @param iPos
     * @return
     */
    virtual size_t IterIncr(int iType, size_t iPos) override;

    /**
     * @brief ShmObj类链表迭代器-1
     * @param iType
     * @param iPos
     * @return
     */
    virtual size_t IterDecr(int iType, size_t iPos) override;

    virtual iterator IterBegin(int iType) override;

    virtual iterator IterEnd(int iType) override;

    virtual const_iterator IterBegin(int iType) const override;

    virtual const_iterator IterEnd(int iType) const override;

    virtual iterator Erase(iterator iter) override;

    virtual NFShmObj* GetIterObj(int iType, size_t iPos) override;

    virtual const NFShmObj* GetIterObj(int iType, size_t iPos) const override;

    virtual bool IsTypeValid(int iType) const override;

    virtual NFTransBase *CreateTrans(int iType) override;

    virtual NFTransBase *GetTrans(uint64_t ullTransId) override;

    virtual int Get32UUID() override;

public:
    /**
    * 创建共享内存
    */
    NFCSharedMem *CreateShareMem(int iKey, size_t siSize, EN_OBJ_MODE enInitFlag, bool bCheckShmInitSuccessFlag);

    /**
    * 摧毁共享内存
    */
    int DestroyShareMem();

    virtual std::string GetClassName(int bType) override;

    virtual int GetClassType(int bType) override;

public:
    NFShmObjSegSwapCounter *CreateCounterObj(int bType);

    int InitAllObjSeg();

    virtual void RegisterClassToObjSeg(int bType, size_t nObjSize, int iItemCount, NFShmObj *(*pfResumeObj)(NFIPluginManager *pPluginManager, void *),
                                       NFShmObj *(*pCreatefn)(NFIPluginManager *pPluginManager),
                                       void(*pDestroy)(NFIPluginManager *pPluginManager, NFShmObj *), int parentType, const std::string &pszClassName,
                                       bool useHash = false, bool singleton = false) override;

    virtual size_t GetAllObjSize() override;

    virtual int InitializeAllObj() override;

    virtual int InitShmObjectGlobal() override;

    virtual int InitSpecialShmObj();

private:
    size_t m_iObjSegSizeTotal;
    int m_iTotalObjCount;
    std::vector<NFShmObjSegSwapCounter> m_nObjSegSwapCounter;
    NFCSharedMem *m_pSharedMemMgr;
    EN_OBJ_MODE m_enRunMode;
    EN_OBJ_MODE m_enCreateMode; //创建对象模式
    size_t m_siShmSize;
    NFGlobalID *m_pGlobalID;
    uint32_t m_nRunTimeFileID;
};
