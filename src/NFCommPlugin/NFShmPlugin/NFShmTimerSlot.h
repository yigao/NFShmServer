// -------------------------------------------------------------------------
//    @FileName         :    NFShmSlot.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmSlot.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

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
#if NF_DEBUG_MODE
NFShmTimerSlot(NFIPluginManager* pPluginManager):pDebugPluginManager(pPluginManager)
#else
    NFShmTimerSlot()
#endif
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        } else {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        m_pObjPtr = NULL;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    void SetParam(NFShmObj* pObj)
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

#if NF_DEBUG_MODE
        if (m_iType > 0)
        {
            NFShmObj *pObjGetObjFromTypeIndex = pDebugPluginManager->FindModule<NFISharedMemModule>()->GetObj(m_iType, m_iIndex);
            assert(pObjGetObjFromTypeIndex == m_pObjPtr.GetPoint());
        }
#endif

        m_pObjPtr->OnTimer(timeId, callcount);

        return eTimerTypeSuccess;
    }

    virtual void Reset() {
        m_pObjPtr = NULL;
    }

    NFRawShmPtr<NFShmObj> m_pObjPtr;
#if defined(_DEBUG) | defined(_DEBUG_)
    uint32_t m_iType;
    uint32_t m_iIndex;
    NFIPluginManager* pDebugPluginManager;
#endif
};