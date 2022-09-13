// -------------------------------------------------------------------------
//    @FileName         :    NFGameDesk.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameDesk.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFServer/NFCommHead/NFIGameDeskHandle.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFShmCore/NFArray.h"
#include "NFServer/NFCommHead/NFIGameDesk.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFMessageDefine/proto_svr_game.pb.h"

#define MAX_GAME_DESK_CHAIR_NUM 50

class NFGameRoom;
class NFGameSession;

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
        m_lastSendAchDataTime = 0;
        m_iCurUserMoney = 0;
        m_iEnterUserMoney = 0;
        m_playerDetail.CreateInit();
        m_wealthData.CreateInit();
        m_achievementData.CreateInit();
        m_userManagerData.CreateInit();
        m_gmCtrlGiveData.CreateInit();
        m_lastSaveUserManagerTime = 0;
	}

	void ClearData()
    {
        SaveAchievementData(true);
        WriteBackUserManagerData(true);
        ResetData();
    }

	int Tick()
    {
        SaveAchievementData(false);
        WriteBackUserManagerData(false);
        return 0;
    }

    int SaveAchievementData(bool force)
    {
        if (m_isRobot) return 0;

        if (m_achievementData.IsUrgentNeedSave())
        {
            if (force || NFTime::Now().UnixSec() - m_lastSendAchDataTime >= 60)
            {
                proto_ff::Proto_GameTSns_GamePlayerAchInfoReq req;
                req.set_user_id(m_playerId);
                req.mutable_ach_data()->set_cur_fee(m_achievementData.cur_fee);
                req.mutable_ach_data()->set_cur_ach(m_achievementData.cur_ach);

                NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_GAME_SERVER, proto_ff::E_GameTSns_GAME_PLAYER_ACH_INFO_SEND, req);

                m_achievementData.ResetCurSeq();
                m_achievementData.cur_ach = 0;
                m_achievementData.cur_fee = 0;

                m_lastSendAchDataTime = NFTime::Now().UnixSec();
            }
        }

        return 0;
    }

    int SetUserManagerData(const proto_ff_s::tbGameUserManagerData_s* pData)
    {
        CHECK_NULL(pData);

        if (pData->id == m_userManagerData.id)
        {
            memset(&m_userManagerData, 0, sizeof(m_userManagerData));
            memcpy(&m_userManagerData, pData, sizeof(m_userManagerData));
        }
        else
        {
            if (pData->state == proto_ff::WHITE_BLACK_STATE_USEING)
            {
                WriteBackUserManagerData();
                memset(&m_userManagerData, 0, sizeof(m_userManagerData));
                memcpy(&m_userManagerData, pData, sizeof(m_userManagerData));
            }
        }

        proto_ff::tbGameUserManagerData userData;
        proto_ff_s::tbGameUserManagerData_s::write_to_pbmsg(m_userManagerData, userData);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "SetUserManagerData:{}", userData.Utf8DebugString());
        return 0;
    }

    proto_ff_s::tbGameUserManagerData_s *GetUserManagerData()
    {
        return &m_userManagerData;
    }

    uint64_t GetMaxWinJetton()
    {
        if (m_userManagerData.state != proto_ff::WHITE_BLACK_STATE_USEING)
        {
            return 100000000000;
        }

        return m_userManagerData.max_win_jetton;
    }

    int WriteBackUserManagerData(bool bForce = false)
    {
        if (m_isRobot) return 0;
#ifdef NF_DEBUG_MODE
        if (NFTime::Now().UnixSec() - m_lastSaveUserManagerTime >= 5 || bForce)
#else
            if (NFTime::Now().UnixSec() - m_lastSaveUserManagerTime >= 60 || bForce)
#endif
        {
            if (m_userManagerData.IsUrgentNeedSave())
            {
                m_lastSaveUserManagerTime = NFTime::Now().UnixSec();
                m_userManagerData.ResetCurSeq();

                proto_ff::Proto_GameTSns_WriteBackUserManagerInfo msg;
                proto_ff_s::tbGameUserManagerData_s::write_to_pbmsg(m_userManagerData, *msg.mutable_user_manager_data());
                NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_GAME_SERVER, proto_ff::E_GameTSns_WRITE_BACK_USER_MANAGER_IFNO, msg);

                proto_ff::tbGameUserManagerData userData;
                proto_ff_s::tbGameUserManagerData_s::write_to_pbmsg(m_userManagerData, userData);
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WriteBackUserManagerData:{}", userData.Utf8DebugString());
            }
        }

        return 0;
    }

    int UpdateUserManagerAddMoney(int64_t iChangedMoney)
    {
        proto_ff_s::tbGameUserManagerData_s& ctrl = m_userManagerData;
        if (ctrl.state == proto_ff::WHITE_BLACK_STATE_USEING)
        {
            ctrl.cur_win += iChangedMoney;
            if (proto_ff::WHITE_BLACK_ROSTER_TYPE_WHITE == ctrl.roster_type)
            {
                if (ctrl.cur_win >= ctrl.opt_mark)
                {
                    DisableOperateCtrl();
                }
            }
            else if (proto_ff::WHITE_BLACK_ROSTER_TYPE_BLACK == ctrl.roster_type)
            {
                if (ctrl.cur_win <= ctrl.opt_mark)
                {
                    DisableOperateCtrl();
                }
            }
            ctrl.MarkDirty();

            proto_ff::tbGameUserManagerData userData;
            proto_ff_s::tbGameUserManagerData_s::write_to_pbmsg(m_userManagerData, userData);
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "UpdateUserManagerAddMoney:{}", userData.Utf8DebugString());
            return 0;
        }
        return -1;
    }

    bool GetOperateCtrlVal(int *iOperateCtrlRate, int *iOperateCtrlLevel = NULL, uint64_t *iOperateMaxWinJetton = NULL)
    {
        bool bOperateCtrl = false;
        if (iOperateCtrlRate)
        {
            *iOperateCtrlRate = 0;
        }

        if (iOperateCtrlLevel)
        {
            *iOperateCtrlLevel = 0;
        }

        if (iOperateMaxWinJetton)
        {
            *iOperateMaxWinJetton = 100000000000;
        }

        proto_ff_s::tbGameUserManagerData_s& ctrl = m_userManagerData;

        if (ctrl.state != proto_ff::WHITE_BLACK_STATE_USEING)
        {
            return false;
        }

        if (iOperateCtrlLevel)
        {
            *iOperateCtrlLevel = ctrl.control_level;
        }

        if (iOperateMaxWinJetton)
        {
            *iOperateMaxWinJetton = ctrl.max_win_jetton;
        }

        //超端控制
        if (proto_ff::WHITE_BLACK_ROSTER_TYPE_WHITE == ctrl.roster_type)
        {
            if (ctrl.cur_win < ctrl.opt_mark)
            {
                //这个配置表算法里统一配置，不需要每个游戏单独配置；
                if (iOperateCtrlRate)
                {
                    *iOperateCtrlRate = ctrl.rate_mark;
                }
                bOperateCtrl = true;
            }
            else
            {
                //超过控制值, 设置控制状态失效
                DisableOperateCtrl();
            }
        }
        else if (proto_ff::WHITE_BLACK_ROSTER_TYPE_BLACK == ctrl.roster_type)
        {
            if (ctrl.cur_win > ctrl.opt_mark)
            {
                //这个配置表算法里统一配置，不需要每个游戏单独配置；
                if (iOperateCtrlRate)
                {
                    *iOperateCtrlRate = ctrl.rate_mark;
                }
                bOperateCtrl = true;
            }
            else
            {
                //超过控制值, 设置控制状态失效
                DisableOperateCtrl();
            }
        }

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetOperateCtrlVal:bOperateCtrl:{}, reate_mark:{}", bOperateCtrl, iOperateCtrlRate ? *iOperateCtrlRate : 0);
        return bOperateCtrl;
    }

    void DisableOperateCtrl() {
        proto_ff_s::tbGameUserManagerData_s &ctrl = m_userManagerData;
        ctrl.state = proto_ff::WHITE_BLACK_STATE_FINISH;
        ctrl.MarkDirty();

        WriteBackUserManagerData();

        proto_ff::tbGameUserManagerData userData;
        proto_ff_s::tbGameUserManagerData_s::write_to_pbmsg(m_userManagerData, userData);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "DisableOperateCtrl:{}", userData.Utf8DebugString());
    }

    int SetGmCtrlGiveData(const proto_ff_s::tbGmCtrlGiveCtrlData_s* pData)
    {
        memset(&m_gmCtrlGiveData, 0, sizeof(m_gmCtrlGiveData));
        memcpy(&m_gmCtrlGiveData, pData, sizeof(m_gmCtrlGiveData));

        proto_ff::tbGmCtrlGiveCtrlData userData;
        proto_ff_s::tbGmCtrlGiveCtrlData_s::write_to_pbmsg(m_gmCtrlGiveData, userData);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "SetGmCtrlGiveData:{}", userData.Utf8DebugString());
        return 0;
    }

    proto_ff_s::tbGmCtrlGiveCtrlData_s *GetGmCtrlGiveData()
    {
        return &m_gmCtrlGiveData;
    }

    int FinishGmCtrlGiveData()
    {
        if (m_gmCtrlGiveData.state == proto_ff::GM_CTRL_GIVE_DATA_STATE_WAITING)
        {
            m_gmCtrlGiveData.state = proto_ff::GM_CTRL_GIVE_DATA_STATE_FINISH;

            proto_ff::Proto_GameTSns_FinishGMCtrlGiveData msg;
            proto_ff_s::tbGmCtrlGiveCtrlData_s::write_to_pbmsg(m_gmCtrlGiveData, *msg.mutable_gm_ctrl_data());
            NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_GAME_SERVER, proto_ff::E_GameTSns_FINISH_GM_CTRL_GIVE_DATA, msg);
            return 0;
        }
        return -1;
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
    proto_ff_s::tbGameUserManagerData_s m_userManagerData;//GM控制数据
    proto_ff_s::tbGmCtrlGiveCtrlData_s m_gmCtrlGiveData;
    uint64_t m_lastSaveUserManagerTime;
	uint64_t m_lastSendAchDataTime;
};

class NFGameDesk : public NFIGameDesk
{
public:
    NFGameDesk();

    virtual ~NFGameDesk();

    int CreateInit();

    int ResumeInit();

public:
	virtual bool AddMessageCallBack(uint16_t subMsgId);

	virtual int SendMsgToClient(uint64_t playerId, uint16_t nSubMsgId, const google::protobuf::Message &xData);

	virtual int BroadCastMsgToDesk(uint16_t nSubMsgId, const google::protobuf::Message &xData, int32_t chairId = INVALID_ID);

	virtual int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData);

	virtual int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId);

	virtual int SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData);

	virtual int ModifyGameMoney(uint64_t playerId, uint32_t changeType, uint64_t moneyChange);

	virtual int PaoMaDengNotify(const std::string& playerName, uint64_t winJetton);

    virtual int LogGameRecord(uint64_t recordId, uint64_t playerId, const google::protobuf::Message& betInfo, const google::protobuf::Message& resultInfo);

    virtual int ForceExitGame(uint64_t playerId);

    virtual int GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win);

    virtual int64_t CommissionCount(uint64_t userid, int64_t CountByFee, int64_t pourJetton);

    //统计玩家的流水
    virtual int AchievementCount(uint64_t userid, uint64_t Count, uint64_t fee);

    virtual int DeduceGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement = false);
    virtual int AddGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement = false);
    virtual int ProcUserSettlement(uint64_t playerId);

    virtual uint64_t GetPlayerCurMoney(uint64_t playerId);
    virtual bool GetOperateCtrlVal(uint64_t playerId, int *iOperateCtrlRate, int *iOperateCtrlLevel = NULL, uint64_t *iOperateMaxWinJetton = NULL);
    virtual proto_ff_s::tbGameUserManagerData_s *GetUserManagerData(uint64_t playerId);
    virtual uint64_t GetMaxWinJetton(uint64_t userid);
    virtual proto_ff_s::tbGmCtrlGiveCtrlData_s *GetGmCtrlGiveData(uint64_t playerId);
    virtual int FinishGmCtrlGiveData(uint64_t playerId);
public:

    int Init(uint32_t gameId, uint32_t roomId, int32_t deskId, uint32_t sitNum, uint32_t maxUserNum, NFGameRoom* pRoomHandle);

    int OnHandleClientMsg(uint64_t playerId, uint16_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandleServerMsg(uint64_t playerId, uint32_t nMsgId, const char* msg, uint32_t nLen);

	int UpdateUserMoney(uint64_t playerId, uint32_t changeType, uint64_t moneyChange);

    int SetUserManagerInfo(uint64_t playerId, const proto_ff_s::tbGameUserManagerData_s* pUserManagerData);

    int UpdateUserInfo(uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s* pUserDetailInfo);

    int ProcUserSettlement(NFGameDeskStation* pDeskStation);

    int SetGmCtrlGiveData(uint64_t playerId, const proto_ff_s::tbGmCtrlGiveCtrlData_s* pGmCtrlGiveDta);
public:
	int OnHandleEnterGameMsg(NFGameSession *pPlayer, int chairId);

	std::vector<int> GetPlayerInfo(int& realPlayerCount, int& robotCount);
	std::vector<uint64_t> GetRobots(int& realPlayerCount);
    int LookingSuitSeatForPlayer(uint64_t playerId, int &iDeskStation);
	int LookingSuitSeatForRobot(uint64_t playerId, int &iDeskStation, int maxRobotPerDesk, bool bIsNeedRealPlayer=true);
	void GetDeadRobots(std::vector<uint64_t>& vec);

    int Looking4SeatBySequence(uint64_t playerId, int &iDeskStation);

    int ReserveSeat(uint64_t playerId, int iDeskStation);

    int LoginDesk(NFGameSession *pPlayer, int chairIndex, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    int LogOutDesk(uint64_t playerId, bool bOffline);

    virtual int GetPlayerCount();

    //获取状态
    virtual uint32_t GetGameStatus() const { return m_bGameStatus; }
    //设置状态
    virtual void SetGameStatus(uint32_t bGameStatus) { m_bGameStatus = bGameStatus; }

public:
    int UserReCome(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    int UserSitDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    int UserLeftDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    int UserExitGame(uint64_t playerId);

    int UserReconDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    int UserAgreeGame(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    int UserDisconnect(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);

	NFGameDeskStation* GetDeskStation(int iDeskStation);
	NFGameDeskStation* GetDeskStationByPlayerId(uint64_t playerId);
    int ClearJiangChi();
    int ChangeJiangChi(int64_t jiangchi);
public:
    //游戏开始时，通知平台
    int OnGameBegin();

    //游戏结束时，通知平台
    int OnGameFinish();

    //判断用户是否在桌子里
    bool IsInDesk(uint64_t playerId);

    //锁定状态
    virtual bool IsTableLocked() { return m_bTableLocked; }
    //游戏状态
    virtual bool IsGameStarted() { return m_bGameStarted; }

    bool IsPlayGame(int iChairIndex);

	bool IsPlayGameCanLeave(int iChairIndex);

    //清理用户异常退出后的残留的脏数据
    int ClearDirtyData(uint64_t playerId);

    //清理超时不操作用户
    int ClearTimeOutUser(uint64_t playerId);

    //清理不在线用户
    int ClearOfflineUser(uint64_t playerId);

    //桌子号码
    //virtual int32_t GetTableID() { return m_deskId; }
    //游戏人数
    virtual uint32_t GetChairCount() const { return m_chairCount; }

	int32_t GetDeskId() { return m_deskId; }

	void NotifyServerPlayerExitGame(uint64_t playerId, int32_t chairId);

    int Tick();
public:
    uint32_t m_gameId;
    uint32_t m_roomId;
    int32_t m_deskId;//start from 0
    uint32_t m_chairCount;
    uint32_t m_maxUserNum;
    NFSizeString<64> m_passWd;
    NFRawShmPtr<NFIGameDeskHandle> m_deskHandle;
    NFRawShmPtr<NFGameRoom> m_roomHandle;
    NFArray<NFGameDeskStation, MAX_GAME_DESK_CHAIR_NUM> m_arrDeskStationId;
public:
    bool m_bTableLocked;                        //锁定标志
    bool m_bGameStarted;                        //开始标志
    uint32_t m_bGameStatus;                        //游戏状态
    uint32_t m_dwTimeStart;                        //开始时间
DECLARE_IDCREATE(NFGameDesk)
};