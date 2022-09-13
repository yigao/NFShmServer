// -------------------------------------------------------------------------
//    @FileName         :    NFTransMng.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransMng.cpp
//
// -------------------------------------------------------------------------

#include "NFTransMng.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransMng, EOT_TRANS_MNG, NFShmObj)


NFTransMng::NFTransMng() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFTransMng::~NFTransMng() {

}

int NFTransMng::CreateInit() {
    m_iTotalTransNum = 0;
    memset(m_aiTransObjIDList, 0, sizeof(m_aiTransObjIDList));
    memset(m_apTransObjList, 0, sizeof(m_apTransObjList));
    return 0;
}

int NFTransMng::ResumeInit() {
    return 0;
}

NFTransBase *NFTransMng::CreateTrans(uint32_t bTransObjType) {
    if (m_iTotalTransNum >= (int) ARRAYSIZE(m_aiTransObjIDList)) {
        NFLogFatal(NF_LOG_SYSTEMLOG, 0, "TransMng is FULL err, objType:{}, TotalNum:{}, MaxNum:{}", bTransObjType,
                   m_iTotalTransNum, ARRAYSIZE(m_aiTransObjIDList));
        return NULL;
    }

    NFTransBase *pTransBase = CreateTrans_i(bTransObjType);
    CHECK_EXPR(pTransBase, NULL, "CreateTrans_i Failed, TransObjType:{}", bTransObjType);

    m_aiTransObjIDList[m_iTotalTransNum] = pTransBase->GetGlobalID();
    m_apTransObjList[m_iTotalTransNum] = pTransBase;
    m_iTotalTransNum++;
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "Create Trans End TotalNum:{} Type:{} GlobalID:{} Pointer:{}", m_iTotalTransNum,
               bTransObjType, pTransBase->GetGlobalID(), (void *) pTransBase);

    return pTransBase;
}

NFTransBase *NFTransMng::GetTransBase(uint64_t ullTransID) {
    CHECK_EXPR(ullTransID < INT_MAX, NULL, "TrandID Max:{} IntMax:{}", ullTransID, INT_MAX);

    return dynamic_cast<NFTransBase *>(NFShmMgr::Instance()->GetObjFromGlobalID(ullTransID, EOT_TRANS_BASE, 0));
}

NFTransBase *NFTransMng::CreateTrans_i(uint32_t bTransObjType) {
    return dynamic_cast<NFTransBase *>(NFShmMgr::Instance()->CreateObj((int) bTransObjType));
}

int NFTransMng::CheckAllTransFinished(bool &bAllTransFinished) {
    bAllTransFinished = true;
    int iTransIndex = 0;
    while (iTransIndex < m_iTotalTransNum) {
        NFTransBase *pTransBase = m_apTransObjList[iTransIndex];
        if (pTransBase) {
            bAllTransFinished = false;
            NFLogError(NF_LOG_SYSTEMLOG, 0, "trans obj type:{}", pTransBase->GetClassType());
            break;
        }
        iTransIndex++;
    }
    return 0;
}

int NFTransMng::RebuildTransObjPointerListForResume() {
    InnerRebuildList();

    for (int i = 0; i < m_iTotalTransNum; i++) {
        NFTransBase *pObj = GetTransBase(m_aiTransObjIDList[i]);
        if (pObj == NULL) {
            m_apTransObjList[i] = NULL;
            NFLogFatal(NF_LOG_SYSTEMLOG, 0, "Invalid TransObj Index:{} GlobalID:{}", i, m_aiTransObjIDList[i]);
            continue;
        }

        m_apTransObjList[i] = pObj;
    }

    return 0;
}

void NFTransMng::InnerRebuildList() {
//    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "Begin TotalNum:{}", m_iTotalTransNum);

    int j = 0;
    for (int i = 0; i < m_iTotalTransNum; i++) {
        if (m_aiTransObjIDList[i] != 0 && m_apTransObjList != NULL) {
            if (i != j) {
                m_aiTransObjIDList[j] = m_aiTransObjIDList[i];
                m_apTransObjList[j] = m_apTransObjList[i];
            }
            j++;
        }

        if ((m_aiTransObjIDList[i] == 0 && m_apTransObjList[i] != NULL) ||
            (m_aiTransObjIDList[i] != 0 && m_apTransObjList[i] == NULL)) {
            NFLogFatal(NF_LOG_SYSTEMLOG, 0, "TransObjIndex Err:i:{} j:{} IndexGlobalID:{} Pointer:{}", i, j,
                       m_aiTransObjIDList[i], (void *) m_apTransObjList[i]);
        }
    }

//    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "End OrdTotalNum:{} NewTotalNum:{}", m_iTotalTransNum, j);
    m_iTotalTransNum = j;
}

int NFTransMng::DoTick(uint32_t dwCurRunIndex, bool bIsTickAll) {
    bool bIsDestroiedTrans = false;
    int iPerTickNumThisTime = m_iNumPerTick;

    while (m_iTickedNum < iPerTickNumThisTime || bIsTickAll) {
        if (m_iLastTickIndex >= m_iTotalTransNum) {
            m_iLastTickIndex = 0;
            m_bIsTickFinished = true;
            break;
        }

        NFTransBase *pTransBase = m_apTransObjList[m_iLastTickIndex];

        if (pTransBase) {
            if (pTransBase->GetGlobalID() == m_aiTransObjIDList[m_iLastTickIndex]) {
                if (pTransBase->IsTimeOut()) {
                    pTransBase->SetFinished(proto_ff::ERR_CODE_SVR_SYSTEM_TIMEOUT);   //time out
                }

                if (pTransBase->CanRelease()) {
                    bIsDestroiedTrans = true;
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0,
                               "Free Trans END Index: {} Type:{} GlobalID:{} Pointer:{}", m_iLastTickIndex,
                               pTransBase->GetClassType(),
                               pTransBase->GetGlobalID(),
                               (void *) pTransBase);
                    NFShmMgr::Instance()->DestroyObj(pTransBase);
                    //mark dirty
                    m_aiTransObjIDList[m_iLastTickIndex] = 0;
                    m_apTransObjList[m_iLastTickIndex] = NULL;
                }
            } else {
                NFLogFatal(NF_LOG_SYSTEMLOG, 0, "Trans Index Err ObjGlobalID:{} != IndexGlobalID:{} ObjPointer:{}",
                           pTransBase->GetGlobalID(),
                           m_aiTransObjIDList[m_iTotalTransNum], (void *) pTransBase);
            }

            m_iTickedNum++;
        }

        m_iLastTickIndex++;
    }

    /*NFLogTrace(NF_LOG_SYSTEMLOG, 0,
               "TickEnd... Index:{} TickedNum:{} NumPerTick:{} m_dwLastTickRunIndex:{} m_dwWaitTickIndex:{} dwCurRunIndex:{}",
               m_iLastTickIndex, m_iTickedNum, m_iNumPerTick, m_dwLastTickRunIndex, m_dwWaitTickIndex, dwCurRunIndex);*/

    if (bIsDestroiedTrans && m_bIsTickFinished) {
        InnerRebuildList();
    }

    return 0;
}
