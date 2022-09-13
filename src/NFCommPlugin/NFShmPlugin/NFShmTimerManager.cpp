// -------------------------------------------------------------------------
//    @FileName         :    NFShmTimerManager.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFShmTimerManager.cpp
//
// -------------------------------------------------------------------------

#include "NFShmTimerManager.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFMagicTimeUtil.h"

int Slot::CreateInit() {
    m_headData.nextIndex = -1;
    m_headData.preIndex = -1;
    m_headData.curIndex = -1;
    m_headData.objID = -1;
    m_headData.slotID = -1;
    m_headData.isValid = false;
    m_index = -1;
    m_slotSeq = 0;
    m_curRunIndex = -1;
    m_count = 0;

    return 0;
}

int Slot::ResumeInit() {
    return 0;
}

int Slot::AddTimer(NFShmTimer *timer, STimerIDData *idData, STimerIDData *allIDData) {
    idData->objID = timer->GetObjectID();
    idData->slotID = m_index;
    timer->SetSlotIndex(m_index);
    timer->SetListIndex(idData->curIndex);
    if (m_headData.preIndex == -1) {
        m_headData.preIndex = idData->curIndex;
        m_headData.nextIndex = idData->curIndex;
        idData->preIndex = -1;
        idData->nextIndex = -1;
    } else {
        if (m_headData.preIndex >= 0 && m_headData.preIndex < ALL_TIMER_COUNT) {
            allIDData[m_headData.preIndex].nextIndex = idData->curIndex;
            idData->nextIndex = -1;
            idData->preIndex = allIDData[m_headData.preIndex].curIndex;
            m_headData.preIndex = idData->curIndex;
        } else {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "head data index error :{} {}", m_index, timer->GetDetailStructMsg());
            return -1;
        }
    }

    ++m_count;
//	LOGSVR_TRACE("on tick:" << m_count << " " << m_curRunIndex << " slotIndexx:" << m_index << " " << oss.str());

    return 0;
}

void Slot::ClearRunStatus(uint32_t seq) {
    m_curRunIndex = -1;
    m_slotSeq = seq;
}

bool Slot::OnTick(int64_t tick, list<NFShmTimer *> &timeoutList, uint32_t seq, STimerIDData *allIDData) {
    if (seq == m_slotSeq) {
        // 表示已经遍历完了
        return true;
    } else {
        if (m_count <= 0) {
            m_count = 0;
            ClearRunStatus(seq);
            return true;
        }

        int curCount = 0;
        STimerIDData *tmpData = 0;
        int curTmpIndex = m_curRunIndex;
        int curTmpCount = m_count;

        if (m_curRunIndex == -1) {
            tmpData = &m_headData;
        } else {
            if (m_curRunIndex < 0 || m_curRunIndex >= ALL_TIMER_COUNT) {
                // 这个序号错误，就不再往下继续执行
                ClearRunStatus(seq);
                NFLogError(NF_LOG_SYSTEMLOG, 0, "slot cur run index error:{} {}", m_curRunIndex, m_index);
                return true;
            }

            tmpData = &allIDData[m_curRunIndex];
        }

        // -1代表是已经到了头节点
        while (tmpData->nextIndex != -1) {
            if (tmpData->nextIndex < 0 || tmpData->nextIndex >= ALL_TIMER_COUNT) {
                ClearRunStatus(seq);
                NFLogError(NF_LOG_SYSTEMLOG, 0, "list next index error:{} {}", tmpData->curIndex, m_index);
                return true;
            }

            // 超出就下一帧来遍历
            if (curCount >= CUR_SLOT_TICK_MAX)
                break;

            tmpData = &allIDData[tmpData->nextIndex];
            if (!tmpData->isValid) {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "slot list index error : {} {} {} {}", m_index, curTmpCount,
                           curTmpIndex, tmpData->curIndex);
            }

            m_curRunIndex = tmpData->curIndex;
            NFShmTimer *pTimer = NFShmTimerManager::GetTimer(tmpData->objID);
            if (pTimer && !pTimer->IsDelete()) {
                if (pTimer->GetListIndex() != tmpData->curIndex) {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "time list index not equal to cur index: {} {}", tmpData->curIndex,
                               pTimer->GetDetailStructMsg());
                }

                if (pTimer->IsTimeOut(tick)) {
                    ++curCount;
                    // 这个会自动返回一个tmpData
                    tmpData = UnBindListTimer(pTimer, tmpData, allIDData);
                    //超时的定时器
                    timeoutList.push_back(pTimer);
                }
            } else {
                if (!pTimer) {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "list index timer error : {} {} {}", m_index, tmpData->curIndex,
                               tmpData->objID);
                }

                ++curCount;
                tmpData = UnBindListTimer(pTimer, tmpData, allIDData);
            }

            if (!tmpData) {
                ClearRunStatus(seq);
                NFLogError(NF_LOG_SYSTEMLOG, 0, "UnBindListTimer error:{} {}", m_curRunIndex, m_index);
                return true;
            }
        }

        if (tmpData->nextIndex == -1) {
            ClearRunStatus(seq);
            return true;
        }
    }

    return false;
}

STimerIDData *Slot::UnBindListTimer(NFShmTimer *timer, STimerIDData *tmpData, STimerIDData *allIDData) {
    if (!tmpData || !allIDData)
        return 0;

    STimerIDData *nextData = 0;
    STimerIDData *prefData = 0;

    if (tmpData->nextIndex == -1) {
        nextData = &m_headData;
    } else {
        nextData = &allIDData[tmpData->nextIndex];
    }

    if (tmpData->preIndex == -1) {
        prefData = &m_headData;
    } else {
        prefData = &allIDData[tmpData->preIndex];
    }

    nextData->preIndex = prefData->curIndex;
    prefData->nextIndex = nextData->curIndex;
    --m_count;
    if (m_curRunIndex == tmpData->curIndex) {
        m_curRunIndex = prefData->curIndex;
    }

    if (timer)
        timer->SetListIndex(-1);

    NFShmTimerManager *timeMgr = NFShmTimerManager::GetTimerManager();
    if (timeMgr) {
        timeMgr->ReleaseTimerIDData(tmpData->curIndex);
    }

    return prefData;
}

bool Slot::DeleteTimer(NFShmTimer *timer, STimerIDData *allIDData) {
    if (!allIDData || !timer || timer->IsDelete() || timer->IsWaitDelete()) {
        return false;
    }

    if (timer->GetListIndex() < 0 || timer->GetListIndex() >= ALL_TIMER_COUNT) {
        return false;
    }

    STimerIDData *tmpData = &allIDData[timer->GetListIndex()];
    if (tmpData->objID != timer->GetObjectID()) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "timer objid not equal id data : {} {}", tmpData->objID,
                   timer->GetDetailStructMsg());
        return false;
    }

    if (tmpData->slotID != m_index) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "list index not equal slot index : {} {} {}", tmpData->slotID, m_index,
                   timer->GetDetailStructMsg());
        return false;
    }

//	LOGSVR_TRACE("slot delete timer : " << m_index << " " << m_count << timer->GetDetailStructMsg());
    UnBindListTimer(timer, tmpData, allIDData);

    return true;
}

IMPLEMENT_IDCREATE_WITHTYPE(NFShmTimerManager, EOT_TYPE_TIMER_MNG, NFShmObj)

NFShmTimerManager::NFShmTimerManager() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFShmTimerManager::~NFShmTimerManager() {
}

int NFShmTimerManager::CreateInit() {
    for (int i = 0; i < SLOT_COUNT; ++i) {
        m_slots[i].CreateInit();
        m_slots[i].SetIndex(i);
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, " init timer manager : {}", NFTime::Now().UnixMSec());
    m_currSlot = 0;
    m_beforeTick = NFTime::Now().UnixMSec();
    m_iFreeIndex = 0;
    m_timerSeq = 1;
    for (int i = 0; i < ALL_TIMER_COUNT; ++i) {
        m_timerIDData[i].nextIndex = i + 1;
        m_timerIDData[i].preIndex = 0;
        m_timerIDData[i].curIndex = i;
        m_timerIDData[i].objID = -1;
        m_timerIDData[i].slotID = -1;
        m_timerIDData[i].isValid = false;
    }

    m_timerIDData[ALL_TIMER_COUNT].nextIndex = ALL_TIMER_COUNT;
    m_timerIDData[ALL_TIMER_COUNT].preIndex = ALL_TIMER_COUNT;
    m_timerIDData[ALL_TIMER_COUNT].curIndex = ALL_TIMER_COUNT;
    m_timerIDData[ALL_TIMER_COUNT].objID = -1;
    m_timerIDData[ALL_TIMER_COUNT].slotID = -1;
    m_timerIDData[ALL_TIMER_COUNT].isValid = false;

    return 0;
}

int NFShmTimerManager::ResumeInit() {
    NFShmTimer* pTimer = dynamic_cast<NFShmTimer*>(NFShmMgr::Instance()->GetHeadObj(EOT_TYPE_TIMER_OBJ));
    while(pTimer)
    {
        if(pTimer->IsDelete() || pTimer->IsWaitDelete())
        {
            continue;
        }

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, " time set callback : {}", pTimer->GetDetailStructMsg());

        if(pTimer->GetListIndex() < 0)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "timer not in list: {}", pTimer->GetDetailStructMsg());
            if(!AttachTimer(pTimer, m_beforeTick, 0 ))
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "timer attach err");
            }
        }

        pTimer = dynamic_cast<NFShmTimer*>(NFShmMgr::Instance()->GetNextObj(EOT_TYPE_TIMER_OBJ, pTimer));
    }
    return 0;
}

NFShmTimer *NFShmTimerManager::GetTimer(int global_id) {
    return (NFShmTimer *) NFShmTimer::GetObjectByID(global_id);
}

NFShmTimerManager *NFShmTimerManager::GetTimerManager() {
    return (NFShmTimerManager *) NFShmMgr::Instance()->GetHeadObj(EOT_TYPE_TIMER_MNG);
}

int NFShmTimerManager::Delete(int global_id) {
    NFShmTimer *timer = GetTimer(global_id);
    if (!timer) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "--delete timer error, not exist: {}", global_id);
        return -1;
    }

    if (timer->IsDelete()) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "--delete timer error, timer is delete: {}", timer->GetDetailStructMsg());
        return -1;
    }

    if (timer->IsWaitDelete()) {
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "--delete timer error, timer is IsWaitDelete: {}", timer->GetDetailStructMsg());
        return -1;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--delete timer : {}", timer->GetDetailStructMsg());

    int index = timer->GetSlotIndex();
    if (index >= 0 && index < SLOT_COUNT) {
        if (!m_slots[index].DeleteTimer(timer, m_timerIDData)) {
            // 删除时找不到，只可能在OnTick的临时list中
            // 将它置成可删除状态
            timer->SetWaitDelete();
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "delete timer in temp list:{}", timer->GetDetailStructMsg());
            return 0;
        }
    } else {
        timer->PrintfDebug();
        NFLogError(NF_LOG_SYSTEMLOG, 0, "delete timer index error: {}", timer->GetDetailStructMsg());
        return -1;
    }

    if (!timer->IsDelete()) {
        timer->SetDelete();
        NFShmTimer::DestroyObject(timer);
    } else {
        timer->PrintfDebug();
        NFLogError(NF_LOG_SYSTEMLOG, 0, "delete timer status error:{}", timer->GetDetailStructMsg());
        return -1;
    }

    return 0;
}

void NFShmTimerManager::OnTick(int64_t tick) {
    int tickCount = 0;

    while (true) {
        if (m_beforeTick + SLOT_TICK_TIME > tick) {
            return;
        }

        list<NFShmTimer *> lRetsetTimer;

        // m_currSlot的里面，是时间在m_beforeTick ~ （m_beforeTick + SLOT_TICK_TIME）区间的timer
        bool isNext = m_slots[m_currSlot].OnTick(m_beforeTick + SLOT_TICK_TIME, lRetsetTimer, m_timerSeq,
                                                 m_timerIDData);

        list<NFShmTimer *>::iterator it;
        for (it = lRetsetTimer.begin(); it != lRetsetTimer.end(); it++) {
            (*it)->PrintfDebug();

            bool isDel = true;

            if (!(*it)->IsWaitDelete()) {
                if (eTimerHandlerNull != (*it)->OnTick(m_beforeTick + SLOT_TICK_TIME)) {
                    // 如果不是一次性的定时器，就又加入槽
                    if ((*it)->GetType() != NFShmTimer::OnceTimer && ((*it)->GetCallCount() > 0 || (*it)->GetCallCount() == (int32_t)NFSHM_INFINITY_CALL)) {
                        // 一定要确保用了m_currSlot就必须是m_beforeTick作为时间，这样才能一致
                        // 由于attacktimer里面用的是m_currSLot作为起始点，那么时间传m_beforeTick
                        if (AttachTimer(*it, m_beforeTick, 0)) {
                            isDel = false;
                        }
                    }
                }
            }

            if (isDel && !(*it)->IsDelete()) {
//				LOGSVR_TRACE("--delete timer tick : "<< tick << (*it)->GetDetailStructMsg());
                (*it)->SetDelete();
                NFShmTimer::DestroyObject(*it);
            }
        }

        ++tickCount;
        if (isNext) {
            m_beforeTick += SLOT_TICK_TIME;
            ++m_timerSeq;
            if (++m_currSlot >= (uint32_t) SLOT_COUNT)
                m_currSlot = 0;
        }

        if (tickCount >= 10000 || (tick - m_beforeTick) < (2 * SLOT_TICK_TIME))
            break;
    }
}

int NFShmTimerManager::AddTimer(NFShmTimer *timer, int64_t tick, bool isNewTimer) {
    if (!timer)
        return -1;

    if (timer->GetBeginTime() <= 0 || timer->GetNextRun() <= 0 || (timer->GetNextRun() - timer->GetBeginTime()) <= 0) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "add timer error: {}", timer->GetDetailStructMsg());
        return -1;
    }

    if (!AttachTimer(timer, tick, isNewTimer)) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "attach timer error:{}", timer->GetDetailStructMsg());
        return -1;
    }

    return 0;
}

int NFShmTimerManager::AddTimer(NFShmTimer *timer, int slot) {
    if (slot < 0 || SLOT_COUNT <= slot) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "slot index error : {} {}", slot, timer->GetDetailStructMsg());
        return -1;
    }

    STimerIDData *idData = GetFreeTimerIDData();
    if (!idData) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "get free timer id error : {} {}", slot, timer->GetDetailStructMsg());
        return -1;
    }

    if (m_slots[slot].AddTimer(timer, idData, m_timerIDData)) {
        ReleaseTimerIDData(idData->curIndex);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "add slot timer error: {} {}", slot, timer->GetDetailStructMsg());
        return -1;
    }

    timer->PrintfDebug();
//	LOGSVR_TRACE("add timer success: " << slot << " " << m_slots[slot].GetCount() << timer->GetDetailStructMsg());

    return slot;
}

bool NFShmTimerManager::CheckFull() {
    if (m_iFreeIndex == ALL_TIMER_COUNT)
        return true;

    return false;
}

void NFShmTimerManager::ReleaseTimerIDData(int index) {
    if (index < 0 || index >= ALL_TIMER_COUNT) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "release timer id data error : {}", index);
        return;
    }

    STimerIDData *tmpBlock = &m_timerIDData[index];

    tmpBlock->nextIndex = m_iFreeIndex;
    tmpBlock->preIndex = 0;
    tmpBlock->objID = -1;
    tmpBlock->slotID = -1;
    tmpBlock->isValid = false;
    m_iFreeIndex = index;
}

STimerIDData *NFShmTimerManager::GetFreeTimerIDData() {
    if (CheckFull()) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "timer id data is full");
        return 0;
    }

    int curIndex = m_iFreeIndex;
    if (m_timerIDData[m_iFreeIndex].nextIndex < 0 && m_timerIDData[m_iFreeIndex].nextIndex >= ALL_TIMER_COUNT) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "get id data but freeindex is invalid : {} {}", m_iFreeIndex,
                   m_timerIDData[m_iFreeIndex].nextIndex);
        return 0;
    }

    m_iFreeIndex = m_timerIDData[m_iFreeIndex].nextIndex;
    if (m_timerIDData[curIndex].isValid) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "get id data is invalid : {}", curIndex);
        return 0;
    }

    if (m_timerIDData[m_iFreeIndex].isValid) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "get id data, but free data invalid: {}", m_iFreeIndex);
    }

    m_timerIDData[curIndex].isValid = true;

    return &m_timerIDData[curIndex];
}

bool NFShmTimerManager::AttachTimer(NFShmTimer *timer, int64_t tick, bool isNewTimer) {
    if (timer == 0 || timer->IsDelete() || timer->IsWaitDelete()) {
        return false;
    }

    int slotNum = 0;
    int ticks = 0;

    if (isNewTimer) {
        // 新定时器，加入的时候，有两种情况（tick表示的是服务器最新时间）：
        // 第一种：m_currSlot还没有运行，那么tick>=m_beforeTick
        // 第二种：m_currSlot已经运行，但是m_currSlot里面的定时器数量大于CUR_SLOT_TICK_MAX，那么tick >= (m_beforeTick+SLOT_TICK_TIME)
        // (timer->GetNextRun() - tick)>=SLOT_TICK_TIME,所以ticks>=1
        if (timer->GetNextRun() <= m_beforeTick) {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "next running time is less than cur ticked time : {}",
                       timer->GetDetailStructMsg());
            NFLogError(NF_LOG_SYSTEMLOG, 0, "bext run: {}, m_beforeTick:{} ", timer->GetNextRun(), m_beforeTick);
            return false;
        }

        // 有一种可能性，造成注册时间，跟定时实际运行的时间不一致
        // 就是当服务器逻辑卡住了一会儿，或者m_currSlot里面的定时器数量大于CUR_SLOT_TICK_MAX，会造成后面注册的定时器起始时间
        // 跟定时器的当前时间有误差，因此修正
        int64_t distance = tick - m_beforeTick;
        if (distance < 0)
            distance = 0;

        ticks = (timer->GetNextRun() - tick + distance) / SLOT_TICK_TIME;
    } else {
        if (timer->GetType() == NFShmTimer::MonthLoopTimer) {
            // 间隔月的天数不同，需要额外算间隔时间
            time_t t = timer->GetNextRun() / 1000;
            int nmonth = 0;
            int iYear = 0, iMonth = 0, iMonthDay = 0;

            NFMagicTimeUtil::GetCurDate((unsigned int) t, iYear, iMonth, iMonthDay);
            int64_t interval = NFMagicTimeUtil::GetNextMonthDay(iYear, iMonth, iMonthDay, nmonth);
            if (interval > 0) {
                timer->SetInterval(interval);
            } else {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "interval of timer is less than 0 :{}", timer->GetDetailStructMsg());
            }
        }

        timer->SetNextRun();
        if (timer->GetNextRun() - tick >= 0) {
            ticks = (timer->GetNextRun() - tick) / SLOT_TICK_TIME;
        } else {
            // 只有某一次定时器没有运行，当下一次论寻到他的时候，会发生这种情况
            NFLogError(NF_LOG_SYSTEMLOG, 0, "next run time is less than tick : {} {} {}", tick,
                       m_slots[m_currSlot].GetCount(), timer->GetDetailStructMsg());
            ticks = 1;
        }
    }

    slotNum = (m_currSlot + (ticks % SLOT_COUNT)) % SLOT_COUNT;
    timer->SetRound(ticks / SLOT_COUNT + 1);
    slotNum = AddTimer(timer, slotNum);
    if (slotNum < 0) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "--add timer to slot but slot is less than 0 : {}",
                   timer->GetDetailStructMsg());
        return false;
    }

    return true;
}

bool
NFShmTimerManager::SetDistanceTime(NFShmTimer *stime, int hour, int minutes, int second, int microSec, int interval, int callCount) {
    int64_t start =
            (int64_t) hour * 3600 * 1000 + (int64_t) minutes * 60 * 1000 + (int64_t) second * 1000 + (int64_t) microSec;
    if (start < SLOT_TICK_TIME)
        start = SLOT_TICK_TIME;

    int64_t nowTime = NFTime::Now().UnixMSec();//SKYNET_TIMENOW_MS();
    stime->SetBeginTime(nowTime);
    stime->SetInterval(interval);
    stime->SetCallCount(callCount);
    stime->SetNextRun(nowTime + start);

    if (AddTimer(stime, nowTime)) {
        return false;
    }

    return true;
}

bool NFShmTimerManager::SetDayTime(NFShmTimer *stime, uint64_t timestamp, int interval, int callCount) {
    int64_t diftime = 0;
    int64_t nowTime = NFTime::Now().UnixMSec();//SKYNET_TIMENOW_MS();

    diftime = (timestamp * 1000 - nowTime);
    if (diftime < 0) {
        diftime += 24 * 3600 * 1000;
    }

    if (diftime < SLOT_TICK_TIME)
        diftime = SLOT_TICK_TIME;

    stime->SetBeginTime(nowTime);
    stime->SetInterval(interval);
    stime->SetCallCount(callCount);
    stime->SetNextRun(nowTime + diftime);

    if (AddTimer(stime, nowTime)) {
        return false;
    }

    return true;
}

bool NFShmTimerManager::SetDayTime(NFShmTimer *stime, int hour, int minutes, int second, int interval, int callCount) {
    int64_t diftime = 0;
    time_t t = NFTime::Now().UnixSec();//SKYNET_TIMENOW();
    int nowWeek = 0, nowHour = 0, nowMinute = 0, nowSecond = 0;

    NFMagicTimeUtil::GetCurTime((unsigned int) t, nowWeek, nowHour, nowMinute, nowSecond);

    diftime = ((int64_t) hour - (int64_t) nowHour) * 3600 * 1000 + ((int64_t) minutes -
                                                                    (int64_t) nowMinute) * 60 * 1000 +
              ((int64_t) second - (int64_t) nowSecond) * 1000;
    if (diftime < 0) {
        diftime += 24 * 3600 * 1000;
    }

    if (diftime < SLOT_TICK_TIME)
        diftime = SLOT_TICK_TIME;

    int64_t nowTime = NFTime::Now().UnixMSec();//SKYNET_TIMENOW_MS();
    stime->SetBeginTime(nowTime);
    stime->SetInterval(interval);
    stime->SetCallCount(callCount);
    stime->SetNextRun(nowTime + diftime);

    if (AddTimer(stime, nowTime)) {
        return false;
    }

    return true;
}

bool NFShmTimerManager::SetWeekTime(NFShmTimer *stime, int weekDay, int hour, int minutes, int second, int callCount) {
    int64_t diftime = 0;
    time_t t = NFTime::Now().UnixSec();//SKYNET_TIMENOW();
    int nowWeek = 0, nowHour = 0, nowMinute = 0, nowSecond = 0;

    NFMagicTimeUtil::GetCurTime((unsigned int) t, nowWeek, nowHour, nowMinute, nowSecond);

    diftime = ((int64_t) weekDay - (int64_t) nowWeek) * 24 * 3600 * 1000 +
              ((int64_t) hour - (int64_t) nowHour) * 3600 * 1000 +
              ((int64_t) minutes - (int64_t) nowMinute) * 60 * 1000 + ((int64_t) second - (int64_t) nowSecond) * 1000;
    if (diftime < 0) {
        diftime += 7 * 24 * 3600 * 1000;
    }

    if (diftime < SLOT_TICK_TIME)
        diftime = SLOT_TICK_TIME;

    int64_t nowTime = NFTime::Now().UnixMSec();//SKYNET_TIMENOW_MS();
    stime->SetBeginTime(nowTime);
    stime->SetInterval((int64_t) 7 * 24 * 3600 * 1000);
    stime->SetCallCount(callCount);
    stime->SetNextRun(nowTime + diftime);

    if (AddTimer(stime, nowTime)) {
        return false;
    }

    return true;
}

bool NFShmTimerManager::SetMonthTime(NFShmTimer *stime, int day, int hour, int minutes, int second, int callCount) {
    int64_t diftime = 0;
    time_t t = NFTime::Now().UnixSec();//SKYNET_TIMENOW();
    int nmonth = 0;
    int nowWeek = 0, nowHour = 0, nowMinute = 0, nowSecond = 0;
    int iYear = 0, iMonth = 0, iMonthDay = 0;

    NFMagicTimeUtil::GetCurDate((unsigned int) t, iYear, iMonth, iMonthDay);
    NFMagicTimeUtil::GetCurTime((unsigned int) t, nowWeek, nowHour, nowMinute, nowSecond);

    if (day > NFMagicTimeUtil::GetCurMonthDay(iYear, iMonth)) {
        // 如果设定的日期超过了这个月的最大天数，就设定下次有这个月天数的月为执行时间
        diftime += NFMagicTimeUtil::GetNextMonthDay(iYear, iMonth, day, nmonth);
        diftime += ((int64_t) day - (int64_t) iMonthDay) * 24 * 3600 * 1000 +
                   ((int64_t) hour - (int64_t) nowHour) * 3600 * 1000 +
                   ((int64_t) minutes - (int64_t) nowMinute) * 60 * 1000 +
                   ((int64_t) second - (int64_t) nowSecond) * 1000;
    } else {
        diftime = ((int64_t) day - (int64_t) iMonthDay) * 24 * 3600 * 1000 +
                  ((int64_t) hour - (int64_t) nowHour) * 3600 * 1000 +
                  ((int64_t) minutes - (int64_t) nowMinute) * 60 * 1000 +
                  ((int64_t) second - (int64_t) nowSecond) * 1000;
        if (diftime < 0) {
            diftime += NFMagicTimeUtil::GetNextMonthDay(iYear, iMonth, day, nmonth);
        }
    }

    if (diftime < SLOT_TICK_TIME)
        diftime = SLOT_TICK_TIME;

    int64_t nowTime = NFTime::Now().UnixMSec();//SKYNET_TIMENOW_MS();
    stime->SetBeginTime(nowTime);
    stime->SetCallCount(callCount);
    stime->SetNextRun(nowTime + diftime);

    if (AddTimer(stime, nowTime)) {
        return false;
    }

    return true;
}

int
NFShmTimerManager::SetTimer(NFShmTimerObj *pObj, int hour, int minutes, int second, int microSec) {
    NFShmTimer *newTimer = (NFShmTimer *) NFShmTimer::CreateObject();
    if (!newTimer) {
        //S_STATIC_MANAGER->AddTimerMngStat(strErr.c_str(), EN_TIMER_STATISTIC_COUNT_CREATE);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Create timer Obj Failed");
        return INVALID_ID;
    }

    newTimer->SetTimerShmObj(pObj);
    newTimer->SetType(NFShmTimer::OnceTimer);
    if (!SetDistanceTime(newTimer, hour, minutes, second, microSec, 0, 1)) {
        //S_STATIC_MANAGER->AddTimerMngStat(newTimer->GetDetailMsg(), EN_TIMER_STATISTIC_COUNT_ADD);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "create time error :{}", newTimer->GetObjectID());
        newTimer->SetDelete();
        NFShmTimer::DestroyObject(newTimer);

        return INVALID_ID;
    }

    return newTimer->GetObjectID();
}

int NFShmTimerManager::SetCalender(NFShmTimerObj *pObj, uint64_t timestamp) {
    CHECK_EXPR(timestamp > (uint64_t) NFTime::Now().UnixSec(), INVALID_ID, "Create timer timestamp err");

    NFShmTimer *newTimer = (NFShmTimer *) NFShmTimer::CreateObject();
    if (!newTimer) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Create timer Obj Failed");
        return INVALID_ID;
    }

    newTimer->SetTimerShmObj(pObj);
    newTimer->SetType(NFShmTimer::OnceTimer);
    if (!SetDayTime(newTimer, timestamp, 0, 1)) {
        //S_STATIC_MANAGER->AddTimerMngStat(newTimer->GetDetailMsg(), EN_TIMER_STATISTIC_COUNT_ADD);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "create time error :{}", newTimer->GetObjectID());
        newTimer->SetDelete();
        NFShmTimer::DestroyObject(newTimer);

        return INVALID_ID;
    }

    return newTimer->GetObjectID();
}

int
NFShmTimerManager::SetCalender(NFShmTimerObj *pObj, int hour, int minutes, int second) {
    CHECK_EXPR(hour >= 0 && hour <= 23, INVALID_ID, "Create timer hour err");
    CHECK_EXPR(minutes >= 0 && minutes <= 59, INVALID_ID, "Create timer minute err");
    CHECK_EXPR(second >= 0 && second <= 59, INVALID_ID, "Create timer second err");

    NFShmTimer *newTimer = (NFShmTimer *) NFShmTimer::CreateObject();
    if (!newTimer) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Create timer Obj Failed");
        return INVALID_ID;
    }

    newTimer->SetTimerShmObj(pObj);
    newTimer->SetType(NFShmTimer::OnceTimer);
    if (!SetDayTime(newTimer, hour, minutes, second, 0, 1)) {
        //S_STATIC_MANAGER->AddTimerMngStat(newTimer->GetDetailMsg(), EN_TIMER_STATISTIC_COUNT_ADD);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "create time error :{}", newTimer->GetObjectID());
        newTimer->SetDelete();
        NFShmTimer::DestroyObject(newTimer);

        return INVALID_ID;
    }

    return newTimer->GetObjectID();
}

int
NFShmTimerManager::SetTimer(NFShmTimerObj *pObj, int interval, int callcount, int hour, int minutes, int second, int microSec
) {
    if (interval < SLOT_TICK_TIME) {
        interval = SLOT_TICK_TIME;
    }

    NFShmTimer *newTimer = (NFShmTimer *) NFShmTimer::CreateObject();
    if (!newTimer) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Create timer Obj Failed");
        return INVALID_ID;
    }

    newTimer->SetTimerShmObj(pObj);
    newTimer->SetType(NFShmTimer::LoopTimer);
    if (callcount <= 0)
    {
        callcount = NFSHM_INFINITY_CALL; //无线次数
    }
    if (!SetDistanceTime(newTimer, hour, minutes, second, microSec, interval, callcount)) {
        //S_STATIC_MANAGER->AddTimerMngStat(newTimer->GetDetailMsg(), EN_TIMER_STATISTIC_COUNT_ADD);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "create time error :{}", newTimer->GetObjectID());
        newTimer->SetDelete();
        NFShmTimer::DestroyObject(newTimer);

        return INVALID_ID;
    }

    return newTimer->GetObjectID();
}

int NFShmTimerManager::SetDayTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec
) {
    NFShmTimer *newTimer = (NFShmTimer *) NFShmTimer::CreateObject();
    if (!newTimer) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Create timer Obj Failed");
        return INVALID_ID;
    }

    newTimer->SetTimerShmObj(pObj);
    newTimer->SetType(NFShmTimer::LoopTimer);
    if (callcount <= 0)
    {
        callcount = NFSHM_INFINITY_CALL; //无线次数
    }
    if (!SetDistanceTime(newTimer, hour, minutes, second, microSec, 24 * 3600 * 1000, callcount)) {
        //S_STATIC_MANAGER->AddTimerMngStat(newTimer->GetDetailMsg(), EN_TIMER_STATISTIC_COUNT_ADD);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "create time error :{}", newTimer->GetObjectID());
        newTimer->SetDelete();
        NFShmTimer::DestroyObject(newTimer);

        return INVALID_ID;
    }

    return newTimer->GetObjectID();
}

int NFShmTimerManager::SetDayCalender(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second) {
    CHECK_EXPR(hour >= 0 && hour <= 23, INVALID_ID, "Create timer hour err");
    CHECK_EXPR(minutes >= 0 && minutes <= 59, INVALID_ID, "Create timer minute err");
    CHECK_EXPR(second >= 0 && second <= 59, INVALID_ID, "Create timer second err");

    NFShmTimer *newTimer = (NFShmTimer *) NFShmTimer::CreateObject();
    if (!newTimer) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Create timer Obj Failed");
        return INVALID_ID;
    }

    newTimer->SetTimerShmObj(pObj);
    newTimer->SetType(NFShmTimer::LoopTimer);
    if (callcount <= 0)
    {
        callcount = NFSHM_INFINITY_CALL; //无线次数
    }
    if (!SetDayTime(newTimer, hour, minutes, second, 24 * 3600 * 1000, callcount)) {
        //S_STATIC_MANAGER->AddTimerMngStat(newTimer->GetDetailMsg(), EN_TIMER_STATISTIC_COUNT_ADD);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "create time error :{}", newTimer->GetObjectID());
        newTimer->SetDelete();
        NFShmTimer::DestroyObject(newTimer);

        return INVALID_ID;
    }

    return newTimer->GetObjectID();
}

int NFShmTimerManager::SetWeekTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec) {
    NFShmTimer *newTimer = (NFShmTimer *) NFShmTimer::CreateObject();
    if (!newTimer) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Create timer Obj Failed");
        return INVALID_ID;
    }

    newTimer->SetTimerShmObj(pObj);
    newTimer->SetType(NFShmTimer::LoopTimer);
    if (callcount <= 0) {
        callcount = NFSHM_INFINITY_CALL; //无线次数
    }
    if (!SetDistanceTime(newTimer, hour, minutes, second, microSec, 7 * 24 * 3600 * 1000, callcount)) {
        //S_STATIC_MANAGER->AddTimerMngStat(newTimer->GetDetailMsg(), EN_TIMER_STATISTIC_COUNT_ADD);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "create time error :{}", newTimer->GetObjectID());
        newTimer->SetDelete();
        NFShmTimer::DestroyObject(newTimer);

        return INVALID_ID;
    }

    return newTimer->GetObjectID();
}

int NFShmTimerManager::SetWeekCalender(NFShmTimerObj *pObj, int callcount, int weekDay, int hour, int minutes, int second) {
    CHECK_EXPR(weekDay >= 1 && weekDay <= 7, INVALID_ID, "Create timer week day err");
    CHECK_EXPR(hour >= 0 && hour <= 23, INVALID_ID, "Create timer hour err");
    CHECK_EXPR(minutes >= 0 && minutes <= 59, INVALID_ID, "Create timer minute err");
    CHECK_EXPR(second >= 0 && second <= 59, INVALID_ID, "Create timer second err");

    NFShmTimer *newTimer = (NFShmTimer *) NFShmTimer::CreateObject();
    if (!newTimer) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Create timer Obj Failed");
        return INVALID_ID;
    }

    if (callcount <= 0)
    {
        callcount = NFSHM_INFINITY_CALL; //无线次数
    }
    newTimer->SetTimerShmObj(pObj);
    newTimer->SetType(NFShmTimer::LoopTimer);
    if (!SetWeekTime(newTimer, weekDay, hour, minutes, second, callcount)) {
        //S_STATIC_MANAGER->AddTimerMngStat(newTimer->GetDetailMsg(), EN_TIMER_STATISTIC_COUNT_ADD);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "create time error :{}", newTimer->GetObjectID());
        newTimer->SetDelete();
        NFShmTimer::DestroyObject(newTimer);

        return INVALID_ID;
    }

    return newTimer->GetObjectID();
}

int NFShmTimerManager::SetMonthTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec) {
    NFShmTimer *newTimer = (NFShmTimer *) NFShmTimer::CreateObject();
    if (!newTimer) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Create timer Obj Failed");
        return INVALID_ID;
    }

    if (callcount <= 0) {
        callcount = NFSHM_INFINITY_CALL; //无线次数
    }
    newTimer->SetTimerShmObj(pObj);
    newTimer->SetType(NFShmTimer::MonthLoopTimer);
    if (!SetDistanceTime(newTimer, hour, minutes, second, microSec, 0, callcount)) {
        //S_STATIC_MANAGER->AddTimerMngStat(newTimer->GetDetailMsg(), EN_TIMER_STATISTIC_COUNT_ADD);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "create time error :{}", newTimer->GetObjectID());
        newTimer->SetDelete();
        NFShmTimer::DestroyObject(newTimer);

        return INVALID_ID;
    }

    return newTimer->GetObjectID();
}

int NFShmTimerManager::SetMonthCalender(NFShmTimerObj *pObj, int callcount, int day, int hour, int minutes, int second) {
    CHECK_EXPR(day >= 1 && day <= 31, INVALID_ID, "Create timer month day err");
    CHECK_EXPR(hour >= 0 && hour <= 23, INVALID_ID, "Create timer hour err");
    CHECK_EXPR(minutes >= 0 && minutes <= 59, INVALID_ID, "Create timer minute err");
    CHECK_EXPR(second >= 0 && second <= 59, INVALID_ID, "Create timer second err");

    NFShmTimer *newTimer = (NFShmTimer *) NFShmTimer::CreateObject();
    if (!newTimer) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Create timer Obj Failed");
        return INVALID_ID;
    }

    if (callcount <= 0)
    {
        callcount = NFSHM_INFINITY_CALL; //无线次数
    }
    newTimer->SetTimerShmObj(pObj);
    newTimer->SetType(NFShmTimer::MonthLoopTimer);
    if (!SetMonthTime(newTimer, day, hour, minutes, second, callcount)) {
        //S_STATIC_MANAGER->AddTimerMngStat(newTimer->GetDetailMsg(), EN_TIMER_STATISTIC_COUNT_ADD);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "create time error :{}", newTimer->GetObjectID());
        newTimer->SetDelete();
        NFShmTimer::DestroyObject(newTimer);

        return INVALID_ID;
    }

    return newTimer->GetObjectID();
}
