// -------------------------------------------------------------------------
//    @FileName         :    NFISaveDB.h
//    @Author           :    gaoyi
//    @Date             :    23-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFISaveDB
//
// -------------------------------------------------------------------------

#pragma once

#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFTransBase.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFCharactorDefine.h"

class NFISaveDB : public NFSeqOP
{
public:
    NFISaveDB();
    
    virtual ~NFISaveDB();
    
    int CreateInit();
    int ResumeInit();
public:
    /**
     * @brief save db
     * @return
     */
    uint64_t GetLastSaveDBTime() const { return m_lastSavingDBTime; }

    void SetLastSaveDBTime(uint64_t saveTime) { m_lastSavingDBTime = saveTime; }

    virtual bool IsInSaving() { return m_lastSavingDBTime > 0 && m_lastSavingDBTime + TRANS_ACTIVE_TIMEOUT + 5 >= (uint64_t) NFTime::Now().UnixSec(); }

    virtual bool IsNeedSave();

    /**
     * @brief
     * @param iReason
     * @return
     */
    virtual int SendTransToDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL);

    /**
     * @brief
     * @param iReason
     * @param bForce
     * @return
     */
    virtual int SaveToDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL, bool bForce = false);

    /**
     * @brief
     * @param success
     * @param seq
     * @return
     */
    virtual int OnSaveDB(bool success, uint32_t seq);

    /**
     * @brief
     * @return
     */
    virtual uint32_t GetAllSeq();

    /**
     * @brief
     */
    virtual void ClearAllSeq();
protected:
    uint64_t m_lastSavingDBTime;
    int m_saveDBTimer;
};