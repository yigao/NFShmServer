// -------------------------------------------------------------------------
//    @FileName         :    NFRoleSimple.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleSimple
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "AllProtocol.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFCore/NFTime.h"

class NFPlayerSimple : public NFShmObj, public NFSeqOP
{
public:
    NFPlayerSimple();

    virtual ~NFPlayerSimple();

    int CreateInit();

    int ResumeInit();

public:
    uint64_t GetPlayerId() const;

    void SetPlayerId(uint64_t playerId);

    const proto_ff_s::tbFishSnsPlayerSimpleData_s &GetBaseData() const;

    void SetBaseData(const proto_ff_s::tbFishSnsPlayerSimpleData_s &baseData);

    void ReadFromPB(const proto_ff::tbFishSnsPlayerSimpleData &dbData);

    bool IsInited() const;

    void SetIsInited(bool isInited);
public:
    /**
     * @brief
     * @param dbData
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(const proto_ff::tbFishSnsPlayerSimpleData &dbData, bool bCreatePlayer = false);

    /**
     * @brief
     * @return
     */
    virtual int UnInit();
public:
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::tbFishSnsPlayerSimpleData& data);

    /**
     * @brief
     * @param data
     * @return
     */
    virtual int SaveDB(proto_ff::tbFishSnsPlayerSimpleData& data);

    /**
     * @brief
     * @return
     */
    virtual int InitConfig(const proto_ff::tbFishSnsPlayerSimpleData& data);
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

public:
    ////////////////////////////////// 每日每周刷新接口 ///////////////////////////////////
    /**
     * @brief 每日刷新接口
     * @param unixSec
     * @return
     */
    virtual int DailyZeroUpdate() { return 0; }

    /**
     * @brief 每周刷新接口
     * @param unixSec
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; };

    /**
     * @brief 每月刷新接口
     * @param unixSec
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; };
public:
    bool CanDelete();


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
private:
    /**
     * @brief
     */
    bool m_isInited;
public:
    /**
     * @brief 线上系统，更在线有关
     */

    uint64_t m_playerId;
private:
    proto_ff_s::tbFishSnsPlayerSimpleData_s m_simpleData;
private:
    /**
     * @brief 存db的时间
     */
    uint64_t m_lastSavingDBTime;
DECLARE_IDCREATE(NFPlayerSimple)
};