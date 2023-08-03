// -------------------------------------------------------------------------
//    @FileName         :    NFGameDeskSIt.h
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameDeskSIt
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "AllProtocol.h"

class NFGameDeskStation
{
public:
    NFGameDeskStation()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        } else {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        ResetData();
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    void ResetData()
    {
        m_playerId = 0;
        m_isRobot = false;
        m_reservedPlayerId = 0;
        m_reservedTime = 0;
        m_onlineFlags = 0;
        m_agreeFlags = 0;
        m_chairId = INVALID_ID;
        m_iCurUserMoney = 0;
        m_iEnterUserMoney = 0;
    }

    void ClearData()
    {
        ResetData();
    }

    int Tick()
    {
        return 0;
    }

    uint64_t m_playerId;    //用户Uin对应坐的位置
    bool m_isRobot;
    uint64_t m_reservedPlayerId;  //桌子座位对应的预定玩家的Uin(找位置的时候)
    uint64_t m_reservedTime;  //桌子座位对应的预定玩家的时间(找位置的时候)
    uint32_t m_onlineFlags;  //桌子座位的在线标志位
    uint32_t m_agreeFlags;   //桌子座位的Agree标志位
    uint64_t m_iCurUserMoney;
    uint64_t m_iEnterUserMoney;
    int32_t m_chairId;
    proto_ff_s::GamePlayerDetailData_s m_playerDetail;
    proto_ff_s::GamePlayerWealthData_s m_wealthData;
    proto_ff_s::GamePlayerAchievementData_s m_achievementData;
};