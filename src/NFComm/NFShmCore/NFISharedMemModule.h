// -------------------------------------------------------------------------
//    @FileName         :    NFISharedMemModule.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFShmDefine.h"
#include "NFTypeDefines.h"

class NFShmObj;
class NFTransBase;
class NFShmTimerObj;

class NFISharedMemModule : public NFIModule
{
public:
	NFISharedMemModule(NFIPluginManager* p) :NFIModule(p)
	{

	}

	virtual ~NFISharedMemModule()
	{

	}

	virtual int AllocShm() = 0;

	/**
	* 从共享内存里获得一块内存
	*/
	virtual void*	CreateSegment(size_t siSize) = 0;

	/**
	* 共享内存模式
	*/
	virtual EN_OBJ_MODE	GetInitMode() = 0;

	/**
	* 共享内存模式
	*/
	virtual void SetInitMode(EN_OBJ_MODE mode) = 0;

	/**
	* @brief  对象seq自增
	*/
	virtual int	IncreaseObjSeqNum() = 0;

	/**
	* @brief  获得偏移地址
	*/
	virtual size_t   GetAddrOffset() = 0;

	/**
	* @brief  获得类名
	*/
	virtual std::string GetClassName(int bType) = 0;
    virtual int GetClassType(int bType) = 0;
    virtual void* AllocMemForObject(int iType) = 0;
    virtual void FreeMemForObject(int iType, void * pMem) = 0;

	virtual void SetObjSegParam(int bType, size_t nObjSize, int iItemCount, NFShmObj* (*pfResumeObj)(void *)
			, NFShmObj *(*pCreatefn)(), void(*pDestroy)(NFShmObj *), int parentType,
			const std::string& pszClassName, bool useHash = false, int exterDataSize = 0, int exterItemCount = 0, bool singleton = false) = 0;

	virtual size_t GetAllObjSize() = 0;

	virtual int InitializeAllObj() = 0;

	virtual int InitShmObjectGlobal() = 0;

	/**
	* @brief  设置功能内存初始化成功
	*/
	virtual void	SetShmInitSuccessFlag() = 0;

    virtual NFShmObj *CreateObj(uint64_t hashKey, int iType) = 0;
    virtual NFShmObj *GetObjFromHashKey(uint64_t hashKey, int iType) = 0;

    virtual int GetItemCount(int iType) = 0;
    virtual int GetUsedCount(int iType) = 0;
    virtual int GetFreeCount(int iType) = 0;
    virtual int GetUsedHead(int iType) = 0;
    virtual int GetFreeHead(int iType) = 0;
    virtual int GetObjectID(int iType, NFShmObj *pObj) = 0;
    virtual int GetNextObjectID(int iType, int iObjID) = 0;
    virtual int GetExternalDataSize(int iType) = 0;
    virtual int GetExternalItemCount(int iType) = 0;
    virtual char* GetExternalBuffer(int iType) = 0;


	virtual NFShmObj   *GetObj(int iType, int iIndex) = 0;

	virtual NFShmObj   *CreateObj(int iType) = 0;
	virtual NFShmObj   *GetHeadObj(int iType) = 0;
	virtual NFShmObj   *GetNextObj(int iType, NFShmObj *pObj) = 0;
	virtual void     DestroyObj(NFShmObj *pObj) = 0;
    virtual int      DestroyObjAutoErase(int iType, int maxNum = INVALID_ID, const DESTROY_SHM_AUTO_ERASE_FUNCTION& func = NULL) = 0;
	virtual NFShmObj   *GetObjFromGlobalID(int iGlobalID, int iType, int iStrongType = 1) = 0;
    virtual NFShmObj   *GetObjFromGlobalIDWithNoCheck(int iGlobalID) = 0;
	// 根据混合ID获得对象
	// iType不为-1表示校验对象类型
	virtual NFShmObj *GetObjFromMiscID(int iMiscID, int iType = -1) = 0;

	virtual bool   IsEnd(int iType, int iIndex) = 0;

	virtual bool IsTypeValid(int iType) = 0;

    virtual NFTransBase* CreateTrans(int iType) = 0;

    virtual NFTransBase* GetTrans(uint64_t ullTransId) = 0;

	/**
	* 共享内存创建对象模式
	*/
	virtual EN_OBJ_MODE	GetCreateMode() = 0;

    /**
    * 共享内存创建对象模式
    */
    virtual void SetCreateMode(EN_OBJ_MODE mode) = 0;

	virtual int	Get32UUID() = 0;

    /**
    * @brief  运行时文件ID
    */
    virtual uint32_t GetRunTimeFileId() = 0;

    //delete objid
    virtual int DeleteTimer(NFShmTimerObj *pObj, int timeObjId) = 0;

    //注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
    virtual int SetTimer(NFShmTimerObj *pObj, int hour, int minutes, int second, int microSec) = 0;

    //注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
    virtual int SetCalender(NFShmTimerObj *pObj, int hour, int minutes, int second) = 0;

    //注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
    virtual  int SetCalender(NFShmTimerObj *pObj, uint64_t timestamp) = 0;

    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
    virtual int SetTimer(NFShmTimerObj *pObj, int interval, int callcount, int hour, int minutes, int second, int microSec) = 0;

    //注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    virtual  int SetDayTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec) = 0;

    //注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
    virtual  int SetDayCalender(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second) = 0;

    //周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
    virtual int SetWeekTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec) = 0;

    //注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
    virtual int SetWeekCalender(NFShmTimerObj *pObj, int callcount, int weekDay, int hour, int minutes, int second) = 0;

    //月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
    virtual int SetMonthTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec) = 0;

    //注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
    virtual int SetMonthCalender(NFShmTimerObj *pObj, int callcount, int day, int hour, int minutes, int second) = 0;
};
