// -------------------------------------------------------------------------
//    @FileName         :    NFShmSlot.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFShmSlot.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmPtr.h"

enum NFTimerRetType {
    eTimerTypeSuccess = 0, // 执行成功
    eTimerHandlerNull = 1, // 回调为空
    eTimerNotTrigger = 2, // 没有触发
};

class NFShmObj;

/*
 * 中间参数类，用来new回调类
 * 此类可减少TimerManager的注册接口数量
 */
class NFShmTimerSlot {
public:
    void SetParam(NFShmTimerObj* pObj)
    {
        if (pObj)
        {
            m_pObjPtr = pObj;
        }
    }

    virtual NFTimerRetType OnTimer(int timeId, int callcount) {
        if (!m_pObjPtr) {
            return eTimerHandlerNull;
        }

// #if defined(_DEBUG) | defined(_DEBUG_)
//         NFShmObj *pObjGetObjFromTypeIndex = NFIDRuntimeClass::GetObj(m_iType, m_iIndex);
//         assert(pObjGetObjFromTypeIndex == m_pObjPtr);
// #endif

        m_pObjPtr->OnTimer(timeId, callcount);

        return eTimerTypeSuccess;
    }

    virtual void Reset() {
        m_pObjPtr = NULL;
    }

    NFRawShmPtr<NFShmTimerObj> m_pObjPtr;
};