// -------------------------------------------------------------------------
//    @FileName         :    NFShmMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFTypeDefines.h"
#include "NFShmDefine.h"
#include "NFTypeDefines.h"

class NFShmObj;
class NFISharedMemModule;
class NFTransBase;
class NFShmTimerObj;

class NFShmMgr : public NFSingleton<NFShmMgr>
{
public:
	NFShmMgr();
	virtual ~NFShmMgr();
public:
    bool IsInited() const { return m_inited; }
	bool Init(NFISharedMemModule* pShmModule = nullptr);
	void UnInit();
public:
	/**
	* 从共享内存里获得一块内存
	*/
	virtual void*	CreateSegment(size_t siSize);

	NFISharedMemModule* GetShmModule();

	/**
	* 共享内存模式
	*/
	virtual EN_OBJ_MODE	GetInitMode();

	/**
	* 共享内存模式
	*/
	virtual void SetInitMode(EN_OBJ_MODE mode);

    virtual NFShmObj *CreateObj(uint64_t hashKey, int iType);
    virtual NFShmObj *GetObjFromHashKey(uint64_t hashKey, int iType);

	/**
	* @brief  对象seq自增
	*/
	virtual int	IncreaseObjSeqNum();

	/**
	* @brief  获得偏移地址
	*/
	virtual size_t   GetAddrOffset();

	/**
	* @brief  获得类名
	*/
	virtual std::string GetClassName(int iType);
    virtual int GetClassType(int bType);
    virtual void* AllocMemForObject(int iType);
    virtual void FreeMemForObject(int iType, void * pMem);

    virtual void SetObjSegParam(int bType, size_t nObjSize, int iItemCount, NFShmObj* (*pfResumeObj)(void *)
			, NFShmObj *(*pCreatefn)(), void(*pDestroy)(NFShmObj *), int parentType, const std::string& pszClassName,
			bool useHash = false, int exterDataSize = 0, int exterItemCount = 0, bool singleton = false);

	virtual size_t GetAllObjSize();

	virtual int InitializeAllObj();

	/**
	* 分配共享内存
	*/
	virtual int AllocShm();

	/**
	* @brief  设置功能内存初始化成功
	*/
	virtual void	SetShmInitSuccessFlag();

	virtual int InitShmObjectGlobal();

	virtual int GetItemCount(int iType);
	virtual int GetUsedCount(int iType);
	virtual int GetFreeCount(int iType);
	virtual int GetUsedHead(int iType);
	virtual int GetFreeHead(int iType);
    virtual int GetObjectID(int iType, NFShmObj *pObj);
    virtual int GetNextObjectID(int iType, int iObjID);
    virtual int GetExternalDataSize(int iType);
    virtual int GetExternalItemCount(int iType);
    virtual char* GetExternalBuffer(int iType);

    virtual NFShmObj   *GetObj(int iType, int iIndex);

	virtual NFShmObj   *CreateObj(int iType);
	virtual NFShmObj   *GetHeadObj(int iType);
	virtual NFShmObj   *GetNextObj(int iType, NFShmObj *pObj);
	virtual void     DestroyObj(NFShmObj *pObj);
    virtual int      DestroyObjAutoErase(int iType, int maxNum = INVALID_ID, const DESTROY_SHM_AUTO_ERASE_FUNCTION& func = NULL);
	virtual NFShmObj   *GetObjFromGlobalID(int iGlobalID, int iType, int iStrongType = 1);
    virtual NFShmObj   *GetObjFromGlobalIDWithNoCheck(int iGlobalID);

    virtual NFTransBase* CreateTrans(int iType);

    virtual NFTransBase* GetTrans(uint64_t ullTransId);

	// 根据混合ID获得对象
	// iType不为-1表示校验对象类型
	virtual NFShmObj *GetObjFromMiscID(int iMiscID, int iType = -1);

	virtual bool   IsEnd(int iType, int iIndex);

	virtual bool IsTypeValid(int iType);

	/**
	* 共享内存创建对象模式
	*/
	virtual EN_OBJ_MODE	GetCreateMode();

	/**
	* 共享内存创建对象模式
	*/
	virtual void	SetCreateMode(EN_OBJ_MODE mode);

	virtual int		Get32UUID();

    /**
    * @brief  运行时文件ID
    */
    virtual uint32_t GetRunTimeFileId();

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
protected:
	NFISharedMemModule* m_pShmModule;
	bool m_inited;
};

