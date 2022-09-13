// -------------------------------------------------------------------------
//    @FileName         :    NFSeqOP.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFSeqOP.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFShmMgr.h"

class NFSeqOP {
public:
    NFSeqOP() {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        } else {
            ResumeInit();
        }
    }

    virtual ~NFSeqOP() {}

    int CreateInit() {
        m_dwCurSeq = 0;
        m_bIsUrgentNeedSave = false;
        return 0;
    }

    void ResetCurSeq() {
        m_dwCurSeq = 0;
        m_bIsUrgentNeedSave = false;
    }

    int ResumeInit() {
        return 0;
    }

    bool IsUrgentNeedSave() const {
        return m_bIsUrgentNeedSave;
    }

    uint32_t GetCurSeq() const {
        return m_dwCurSeq;
    }

    void MarkDirty() {
        m_dwCurSeq++;
        m_bIsUrgentNeedSave = true;
    }

    void MarkUrgent() {
        m_dwCurSeq++;
        m_bIsUrgentNeedSave = true;
    }

    void ClearUrgent() {
        m_bIsUrgentNeedSave = false;
    }

protected:
    uint32_t m_dwCurSeq;
    bool m_bIsUrgentNeedSave;
};

class NFDescStoreSeqOP {
public:
    NFDescStoreSeqOP() {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        } else {
            ResumeInit();
        }
    }

    int CreateInit() {
        m_dwCurSeq = 0;
        m_bIsUrgentNeedSave = false;
        return 0;
    }

    void ResetCurSeq() {
        m_dwCurSeq = 0;
        m_bIsUrgentNeedSave = false;
    }

    int ResumeInit() {
        return 0;
    }

    bool IsUrgentNeedSave() const {
        return m_bIsUrgentNeedSave;
    }

    uint32_t GetCurSeq() const {
        return m_dwCurSeq;
    }

    void MarkDirty() {
        m_dwCurSeq++;
        m_bIsUrgentNeedSave = true;
    }

    void MarkUrgent() {
        m_dwCurSeq++;
        m_bIsUrgentNeedSave = true;
    }

    void ClearUrgent() {
        m_bIsUrgentNeedSave = false;
    }

protected:
    uint32_t m_dwCurSeq;
    bool m_bIsUrgentNeedSave;
};
