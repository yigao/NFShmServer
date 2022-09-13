// -------------------------------------------------------------------------
//    @FileName         :    NFShmTimer.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFShmTimer.cpp
//
// -------------------------------------------------------------------------

#include "NFShmTimer.h"
#include "NFComm/NFShmCore/NFTypeDefines.h"
#include "NFComm/NFCore/NFSnprintf.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFShmTimer, EOT_TYPE_TIMER_OBJ, NFShmObj)

NFShmTimer::NFShmTimer() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFShmTimer::~NFShmTimer() {
    DeleteFunc();
}

void NFShmTimer::DeleteFunc() {
    // 是在SubscriberSlot 创建的，必须在这销毁
    m_obj.Reset();
}

int NFShmTimer::CreateInit() {
    m_obj.Reset();
    m_type = OnceTimer;
    m_beginTime = 0;
    m_nextRun = 0;
    m_interval = 0;
    m_delFlag = false;
    m_round = 0;
    m_slotIndex = -1;
    m_waitDel = false;
    m_listIndex = -1;
    m_callCount = 0;
    m_curCallCount = 0;
    return 0;
}

int NFShmTimer::ResumeInit() {
    return 0;
}

std::string NFShmTimer::GetDetailStructMsg() {
    std::ostringstream oss;

	oss << " type:" << m_type
        << " begintime:" << m_beginTime
        << " nextRun:" << m_nextRun
        << " interval:" << m_interval
        << " delFlag:" << m_delFlag
        << " round:" << m_round
        << " slotIndex:" << m_slotIndex
        << " waitDel:" << m_waitDel
        << " listIndex:" << m_listIndex
        << " objID:" << GetObjectID()
        << " globalID:" << GetGlobalID();

    return oss.str();
}

bool NFShmTimer::IsTimeOut(int64_t tick) {
    --m_round;
//	LOGSVR_TRACE("is time out: " << GetDetailStructMsg());
    if (tick - m_nextRun >= 0 || m_round <= 0) {
        return true;
    }

    return false;
}

NFTimerRetType NFShmTimer::OnTick(int64_t tick) {
    if (tick - m_nextRun >= 0 || m_round <= 0) {
        if (m_obj.m_pObjPtr) {
//			LOGSVR_TRACE("time out: " << GetDetailStructMsg());
            if (m_callCount != (int32_t)NFSHM_INFINITY_CALL && m_callCount > 0)
            {
                m_callCount--;
            }
            m_curCallCount++;
            return m_obj.OnTimer(GetObjectID(), m_curCallCount);
        } else {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "timer ontick error:{} ", GetDetailStructMsg());
            return eTimerHandlerNull;
        }
    }

    return eTimerNotTrigger;
}

bool NFShmTimer::IsDelete() {
    return m_delFlag;
}

void NFShmTimer::SetDelete() {
    m_delFlag = true;
}

bool NFShmTimer::IsWaitDelete() {
    return m_waitDel;
}

void NFShmTimer::SetWaitDelete() {
    m_waitDel = true;
}


