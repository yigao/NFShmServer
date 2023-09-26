// -------------------------------------------------------------------------
//    @FileName         :    NFShmTimer.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmTimer.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmNodeList.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmCore/NFRawShmObj.h"

#define NFSHM_INFINITY_CALL                0xffffffff    // 调用无限次
enum NFTimerRetType {
    eTimerTypeSuccess = 0, // 执行成功
    eTimerHandlerNull = 1, // 回调为空
    eTimerNotTrigger = 2, // 没有触发
};

class NFShmTimer : public NFShmObj, public NFListNodeObjWithGlobalID<NFShmTimer, EOT_TYPE_TIMER_OBJ>
{
public:
    enum NFShmTimerType
    {
        LoopTimer,
        OnceTimer,
        MonthLoopTimer,
    };

    NFShmTimer();

    virtual ~NFShmTimer();

    int CreateInit();

    int ResumeInit();

    NFShmObj *GetTimerShmObj()
    {
        return m_shmObj.GetPoint();
    }

    int GetTimerShmObjId()
    {
        return m_shmObjId;
    }

    void SetTimerShmObj(NFShmObj *pObj)
    {
        m_shmObj = pObj;
        m_shmObjId = pObj->GetGlobalId();
    }

    void SetTimerRawShmObj(NFRawShmObj *pObj)
    {
        m_rawShmObj = pObj;
    }

    void PrintfDebug()
    {
//	 cout << "ID:" << m_iGlobalID << " Type:" << m_type << " begin:" << m_beginTime << " next:" << m_nextRun << " interval:" << m_interval << " round:" << m_round <<endl;
        /*LOGSVR_DEBUG("print ID:" << GetObjectID() << " Type:" << m_type << " begin:" << m_beginTime << " next:" << m_nextRun << " interval:" <<
    		m_interval << " round:" << m_round<<" slotindex:"<<m_slotIndex); */
    }

    NFTimerRetType HandleTimer(int timeId, int callcount);

    bool IsTimeOut(int64_t tick);

    NFTimerRetType OnTick(int64_t tick);

    bool IsDelete();

    void SetDelete();

    bool IsWaitDelete();

    void SetWaitDelete();

    NFShmTimerType GetType() { return m_type; }

    int64_t GetBeginTime() { return m_beginTime; }

    int64_t GetInterval() { return m_interval; }

    int64_t GetNextRun() { return m_nextRun; }

    int32_t GetCallCount() { return m_callCount; }

    int GetSlotIndex() { return m_slotIndex; }

    int GetListIndex() { return m_listIndex; }

    std::string GetDetailStructMsg();

    void SetType(NFShmTimerType type) { m_type = type; }

    void SetCallCount(int32_t t) { m_callCount = t; }

    void SetInterval(int64_t interval) { m_interval = interval; }

    void SetNextRun() { m_nextRun += m_interval; }

    void SetNextRun(int64_t nexttime) { m_nextRun = nexttime; }

    void SetBeginTime(int64_t time) { m_beginTime = time; }

    void SetRound(int round) { m_round = round; }

    void SetSlotIndex(int index) { m_slotIndex = index; }

    void SetListIndex(int index) { m_listIndex = index; }

private:

    void DeleteFunc();

private:
    NFShmPtr<NFShmObj> m_shmObj;
    NFRawShmPtr<NFRawShmObj> m_rawShmObj;
    int m_shmObjId;
    NFShmTimerType m_type;

    int64_t m_beginTime;        // 开始的时间
    int64_t m_nextRun;            // 下一次执行的时间
    int64_t m_interval;        // 间隔时间
    int32_t m_callCount;
    int32_t m_curCallCount;
    bool m_delFlag;        // 是否删除
    int m_round;
    int m_slotIndex;        // 槽id
    bool m_waitDel;            // 等待删除标记
    int m_listIndex;        // 绑定的list的序号，当为-1时，代表已经脱离绑定

DECLARE_IDCREATE(NFShmTimer)
};