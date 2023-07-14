// -------------------------------------------------------------------------
//    @FileName         :    NFRoleDetail.h
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleDetail
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "AllProtocol.h"
#include "NFLogicCommon/NFPlayerDefine.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFCore/NFTime.h"

class NFSnsPart;
class NFPlayerSimple;
class NFPlayerDetail : public NFShmObj, public NFSeqOP
{
public:
    NFPlayerDetail();

    virtual ~NFPlayerDetail();

    int CreateInit();

    int ResumeInit();

public:
    uint64_t GetPlayerId() const;

    void SetPlayerId(uint64_t roleId);

public:
    bool IsInited() const;

    void SetIsInited(bool isInited);

public:
    bool CanDelete();

public:
    /**
     * @brief
     * @param data
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(const proto_ff::tbFishSnsPlayerDetailData &data, bool bCreatePlayer = false);

    /**
     * @brief
     * @return
     */
    virtual int UnInit();
public:
public:
    /**
     * @brief save db
     * @return
     */
    uint64_t GetLastSaveDBTime() const { return m_lastSavingDBTime; }
    void SetLastSaveDBTime(uint64_t saveTime) { m_lastSavingDBTime = saveTime; }
    bool IsInSaving() { return m_lastSavingDBTime > 0 && m_lastSavingDBTime + TRANS_ACTIVE_TIMEOUT + 5 >= (uint64_t)NFTime::Now().UnixSec(); }

    /**
     * @brief
     * @param iReason
     * @return
     */
    int SendTransToDB();

    /**
     * @brief
     * @param iReason
     * @param bForce
     * @return
     */
    int SaveToDB(bool bForce = false);

    /**
     * @brief
     * @param success
     * @param seq
     * @return
     */
    int OnSaveDB(bool success, uint32_t seq);
public:
    NFSnsPart *CreatePart(uint32_t partType, const ::proto_ff::tbFishSnsPlayerDetailData &data, bool bCreatePlayer);
    int RecylePart(NFSnsPart *pPart);
    //获取对应部件指针
    virtual NFSnsPart *GetPart(uint32_t partType);

    template<typename PART>
    PART *GetPart(uint32_t partType)
    {
        return dynamic_cast<PART *>(GetPart(partType));
    }
public:
    NFPlayerSimple* GetRoleSimple() const;
public:
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::tbFishSnsPlayerDetailData& data);

    /**
     * @brief
     * @param data
     * @return
     */
    virtual int SaveDB(proto_ff::tbFishSnsPlayerDetailData& data);

    /**
     * @brief
     * @return
     */
    virtual int InitConfig(const proto_ff::tbFishSnsPlayerDetailData& data);

    /**
     * @brief
     * @return
     */
    virtual int Update();
public:
    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin();

    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout();

    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect();

    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect();

    ////////////////////////////////// 每日每周刷新接口 ///////////////////////////////////
    /**
     * @brief 每日刷新接口
     * @param unixSec
     * @return
     */
    virtual int DailyZeroUpdate();

    /**
     * @brief 每周刷新接口
     * @param unixSec
     * @return
     */
    virtual int WeekZeroUpdate();

    /**
     * @brief 每月刷新接口
     * @param unixSec
     * @return
     */
    virtual int MonthZeroUpdate();
private:
    /**
     * @brief
     */
    bool m_isInited;

    /**
     * @brief
     */
    uint64_t m_playerId;
private:
    /**
     * @brief 存db的时间
     */
    uint64_t m_lastSavingDBTime;
private:
    NFShmVector<NFShmPtr<NFSnsPart>, PART_MAX> m_pPart;
DECLARE_IDCREATE(NFPlayerDetail)
};