// -------------------------------------------------------------------------
//    @FileName         :    NFCSharedMemModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFShmCore/NFCSharedMem.h"
#include <unordered_map>
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFTypeDefines.h"
#include "NFIDRuntimeClass.h"


class NFTransBase;
class NFCSharedMemModule;
class NFGlobalID;
class NFShmObjSeg;

class NFShmObjSegSwapCounter
{
	friend class NFCSharedMemModule;
public:
	NFShmObjSegSwapCounter():
		m_nObjSize(0), m_iItemCount(0), m_pFn(0), m_iObjType(0), m_pidRuntimeClass(), m_singleton(false)
	{

	}
	void SetObjSeg(NFShmObjSeg *pObjSeg);
private:
	size_t	m_nObjSize;
	int		m_iItemCount;
	NFShmObj* (*m_pFn)(void *);
	std::string m_szClassName;

	int  m_iObjType;
	NFIDRuntimeClass m_pidRuntimeClass;
	bool m_singleton;
};

class NFCSharedMemModule : public NFISharedMemModule
{
public:
	NFCSharedMemModule(NFIPluginManager* p);
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
	virtual bool OnReloadPlugin() override;

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
	virtual void*	CreateSegment(size_t siSize) override;

	/**
	* 共享内存模式
	*/
	virtual EN_OBJ_MODE	GetInitMode() override;

	/**
	* 共享内存模式
	*/
	virtual void SetInitMode(EN_OBJ_MODE mode) override;

	/**
	* 共享内存创建对象模式
	*/
	virtual EN_OBJ_MODE	GetCreateMode() override;

	/**
	* 共享内存创建对象模式
	*/
	virtual void	SetCreateMode(EN_OBJ_MODE mode) override;

	/**
	* @brief  对象seq自增
	*/
	virtual int	IncreaseObjSeqNum() override;

	/**
	* @brief  获得偏移地址
	*/
	virtual size_t   GetAddrOffset() override;

	/**
	* @brief  NFGlobalID
	*/
	virtual NFGlobalID* GetGlobalID();

	/**
	* @brief  设置功能内存初始化成功
	*/
	virtual void	SetShmInitSuccessFlag() override;

    /**
    * @brief  运行时文件ID
    */
    virtual uint32_t GetRunTimeFileId() override;

    //delete objid
    virtual int DeleteTimer(NFShmTimerObj *pObj, int timeObjId);

    //注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
    virtual int SetTimer(NFShmTimerObj *pObj, int hour, int minutes, int second, int microSec);

    //注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
    virtual int SetCalender(NFShmTimerObj *pObj, int hour, int minutes, int second);

    //注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
    virtual  int SetCalender(NFShmTimerObj *pObj, uint64_t timestamp);

    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
    virtual int SetTimer(NFShmTimerObj *pObj, int interval, int callcount, int hour, int minutes, int second, int microSec);

    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    virtual  int SetDayTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec);

    //注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
    virtual  int SetDayCalender(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second);

    //周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    virtual int SetWeekTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec);

    //注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
    virtual int SetWeekCalender(NFShmTimerObj *pObj, int callcount, int weekDay, int hour, int minutes, int second);

    //月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
    virtual int SetMonthTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec);

    //注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
    virtual int SetMonthCalender(NFShmTimerObj *pObj, int callcount, int day, int hour, int minutes, int second);
public:
	int		ReadRunMode();
public:
	virtual NFShmObjSeg *GetObjSeg(int iType);

    virtual int GetItemCount(int iType) override;
    virtual int GetUsedCount(int iType) override;
    virtual int GetFreeCount(int iType) override;
    virtual int GetUsedHead(int iType) override;
    virtual int GetFreeHead(int iType) override;
    virtual int GetObjectID(int iType, NFShmObj *pObj) override;
    virtual int GetNextObjectID(int iType, int iObjID) override;
    virtual void* AllocMemForObject(int iType) override;
    virtual void FreeMemForObject(int iType, void * pMem) override;
    virtual int GetExternalDataSize(int iType) override;
    virtual int GetExternalItemCount(int iType) override;
    virtual char* GetExternalBuffer(int iType) override;

    virtual NFShmObj   *GetObj(int iType, int iIndex) override;

    virtual NFShmObj   *CreateObj(uint64_t hashKey, int iType) override;
    virtual NFShmObj   *GetObjFromHashKey(uint64_t hashKey, int iType) override;

	virtual NFShmObj   *CreateObj(int iType) override;
	virtual NFShmObj   *GetHeadObj(int iType) override;
	virtual NFShmObj   *GetNextObj(int iType, NFShmObj *pObj) override;
	virtual void     DestroyObj(NFShmObj *pObj) override;
    virtual int      DestroyObjAutoErase(int iType, int maxNum = INVALID_ID, const DESTROY_SHM_AUTO_ERASE_FUNCTION& func = NULL) override;

	virtual NFShmObj   *GetObjFromGlobalID(int iGlobalID, int iType, int iStrongType = 1) override;
    virtual NFShmObj   *GetObjFromGlobalIDWithNoCheck(int iGlobalID) override;
	// 根据混合ID获得对象
	// iType不为-1表示校验对象类型
	virtual NFShmObj *GetObjFromMiscID(int iMiscID, int iType = -1) override;

	virtual NFIDRuntimeClass *GetIDRuntimeClass(int iType);

	virtual bool   IsEnd(int iType, int iIndex) override;

	virtual bool IsTypeValid(int iType) override;

	virtual NFTransBase* CreateTrans(int iType) override;

    virtual NFTransBase* GetTrans(uint64_t ullTransId) override;

	virtual int	Get32UUID() override;
public:
	/**
	* 创建共享内存
	*/
	NFCSharedMem*	CreateShareMem(int iKey, size_t siSize, EN_OBJ_MODE enInitFlag, bool bCheckShmInitSuccessFlag);

	/**
	* 摧毁共享内存
	*/
	int				DestroyShareMem();

	virtual std::string GetClassName(int bType) override;
	virtual int GetClassType(int bType) override;

public:
	NFShmObjSegSwapCounter* CreateCounterObj(int bType);

	int InitAllObjSeg();

	virtual void SetObjSegParam(int bType, size_t nObjSize, int iItemCount, NFShmObj* (*pfResumeObj)(void *)
		, NFShmObj *(*pCreatefn)(), void(*pDestroy)(NFShmObj *), int parentType, const std::string& pszClassName, bool useHash = false, int exterDataSize = 0, int externalItemCount = 0, bool singleton = false) override;

	virtual size_t GetAllObjSize() override;

	virtual int InitializeAllObj() override;

	virtual int InitShmObjectGlobal() override;

	virtual int InitSpecialShmObj();
private:
	size_t		m_iObjSegSizeTotal;
	int			m_iTotalObjCount;
	std::vector<NFShmObjSegSwapCounter> m_nObjSegSwapCounter;
	NFCSharedMem*   m_pSharedMemMgr;
	EN_OBJ_MODE		m_enRunMode;
	EN_OBJ_MODE     m_enCreateMode; //创建对象模式
	size_t			m_siShmSize;
	NFGlobalID*		m_pGlobalID;
	uint32_t        m_nRunTimeFileID;
};
