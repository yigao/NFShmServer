// -------------------------------------------------------------------------
//    @FileName         :    NFGameDesc.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameDesc
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFGameDeskStation.h"
#include "NFLogicCommon/NFRoomDefine.h"
#include "NFLogicCommon/NFIGameDesk.h"

class NFGameRoom;
class NFIGameDeskImpl;
class NFGameDesk : public  NFShmObjTemplate<NFGameDesk, EOT_NFGameDesc_ID, NFIGameDesk>
{
public:
    NFGameDesk();

    virtual ~NFGameDesk();

    int CreateInit();

    int ResumeInit();
public:
    /**
     * @brief 初始化桌子
     * @param gameId
     * @param roomId
     * @param deskId
     * @param sitNum
     * @param maxUserNum
     * @param pRoomHandle
     * @return
     */
    int Init(uint32_t gameId, uint32_t roomId, int32_t deskId, uint32_t sitNum, uint32_t maxUserNum, NFGameRoom* pRoomHandle);
public:
    /**
     * @brief
     * @return
     */
    int Tick();
public:
    /**
     * @brief 通过ID查找到玩家的位置
     * @param iDeskStation
     * @return
     */
    NFGameDeskStation* GetDeskStation(int iDeskStation);

    /**
     * @brief 通过玩家ID查找到玩家的位置
     * @param playerId
     * @return
     */
    NFGameDeskStation* GetDeskStationByPlayerId(uint64_t playerId);
public:
    /**
     * @brief 游戏开始时，通知平台
     * @return
     */
    int OnGameBegin();

    /** 游戏结束时，通知平台
     * @brief
     * @return
     */
    int OnGameFinish();
public:
    /**
     * @brief 判断用户是否在桌子里
     * @param playerId
     * @return
     */
    bool IsInDesk(uint64_t playerId);

    /**
     * @brief 锁定状态
     * @return
     */
    virtual bool IsTableLocked() { return m_bTableLocked; }

    /**
     * @brief 游戏状态
     * @return
     */
    virtual bool IsGameStarted() { return m_bGameStarted; }

    /**
     * @brief 是否玩家正在打游戏
     * @param iChairIndex
     * @return
     */
    bool IsPlayGame(int iChairIndex);

    /**
     * @brief 玩家是否可以离开游戏
     * @param iChairIndex
     * @return
     */
    bool IsPlayGameCanLeave(int iChairIndex);
public:
    /**
     * @brief 为玩家需要合适的位置
     * @param playerId
     * @param iDeskStation
     * @return
     */
    int LookingSuitSeatForPlayer(uint64_t playerId, int &iDeskStation);

    /**
     * @brief 为玩家需要合适的位置
     * @param playerId
     * @param iDeskStation
     * @return
     */
    int Looking4SeatBySequence(uint64_t playerId, int &iDeskStation);

    /**
     * @brief 预定位置
     * @param playerId
     * @param iDeskStation
     * @return
     */
    int ReserveSeat(uint64_t playerId, int iDeskStation);
public:
    /** 清理用户异常退出后的残留的脏数据
     * @brief
     * @param playerId
     * @return
     */
    int ClearDirtyData(uint64_t playerId);

    /** 清理超时不操作用户
     * @brief
     * @param playerId
     * @return
     */
    int ClearTimeOutUser(uint64_t playerId);

    /** 清理不在线用户
     * @brief
     * @param playerId
     * @return
     */
    int ClearOfflineUser(uint64_t playerId);
public:
    /**
    * @brief 更改玩家金钱信息
    * @param deskId
    * @param playerId
    * @param changeType
    * @param moneyChange
    * @return
    */
    virtual int UpdateUserMoney(uint64_t playerId, uint32_t changeType, uint64_t moneyChange);

    /**
     * @brief 更新玩家信息
     * @param deskId
     * @param playerId
     * @param pPlayerDetail
     * @return
     */
    int UpdateUserInfo(uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s* pPlayerDetail);
public:
    /**
     * @brief 处理玩家一段时间的输赢金钱，并同步全服
     * @param pDeskStation
     * @return
     */
    int ProcUserSettlement(NFGameDeskStation* pDeskStation);

    virtual int ProcUserSettlement(uint64_t playerId);

    /**
     * @brief 游戏中加减游戏币
     * @param playerId
     * @param moneyChange
     * @param procUserSettlement
     * @return
     */
    virtual int DeduceGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement = false);

    /**
     * @brief 游戏中加减游戏币
     * @param playerId
     * @param moneyChange
     * @param procUserSettlement
     * @return
     */
    virtual int AddGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement = false);

    /**
     * @brief 玩家金钱
     * @param playerId
     * @return
     */
    virtual uint64_t GetPlayerCurMoney(uint64_t playerId);
public:
    /**
     * @brief 玩家重进游戏
     * @param playerId
     * @param iChairIndex
     * @param pPlayer
     * @return
     */
    virtual int UserReCome(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    /**
     * @brief 玩家坐
     * @param playerId
     * @param iChairIndex
     * @param pPlayer
     * @return
     */
    virtual int UserSitDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    /**
     * @brief 玩家离开
     * @param playerId
     * @param iChairIndex
     * @param pPlayer
     * @return
     */
    virtual int UserLeftDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    /**
     * @brief 玩家重连
     * @param playerId
     * @param iChairIndex
     * @param pPlayer
     * @return
     */
    virtual int UserReconDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    /**
     * @brief 玩家同意
     * @param playerId
     * @param iChairIndex
     * @param pPlayer
     * @return
     */
    virtual int UserAgreeGame(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    /**
     * @brief 玩家掉线
     * @param playerId
     * @param iChairIndex
     * @param pPlayer
     * @return
     */
    virtual int UserDisconnect(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail);
public:
    /**
     * @brief 通知其他服，玩家离开
     * @param playerId
     * @param chairId
     * @return
     */
    int NotifyServerPlayerExitGame(uint64_t playerId, int32_t chairId);
public:
    /**
     * @brief 清理修改奖池
     * @return
     */
    int ClearJiangChi();

    /**
     * @brief 清理修改奖池
     * @param jiangchi
     * @return
     */
    int ChangeJiangChi(int64_t jiangchi);
public:
    /**
     * @brief 游戏统计
     */

    /**
     * @brief 游戏统计 玩家输赢
     * @param cur_fee
     * @param cur_pour
     * @param cur_win
     * @return
     */
    virtual int GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win);

    /**
     * @brief 放回抽水后剩余的钱
     * @param userid
     * @param CountByFee
     * @param pourJetton
     * @return
     */
    virtual int64_t CommissionCount(uint64_t userid, int64_t CountByFee, int64_t pourJetton);

    /**
     * @brief 统计玩家的流水
     * @param userid
     * @param Count
     * @param fee
     * @return
     */
    virtual int AchievementCount(uint64_t userid, uint64_t Count, uint64_t fee);

public:
    /**
     * @brief 登陆桌子
     * @param playerId
     * @param chairIndex
     * @param playerDetail
     * @return
     */
    int EnterGame(uint64_t playerId, int chairIndex, proto_ff_s::GamePlayerDetailData_s& playerDetail);

    /**
     * @brief 退出座子
     * @param playerId
     * @param bOffline
     * @return
     */
    int ExitGame(uint64_t playerId, bool bOffline);

    /**
     * @brief
     * @param playerId
     * @param chairId
     * @return
     */
    int CheckDeskStation(uint64_t playerId, int chairId);
public:
    virtual int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId);

    virtual int BroadCastMsgToDesk(uint32_t nMsgId, const google::protobuf::Message &xData, int32_t chairId = INVALID_ID);

    virtual int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId = 0);

    virtual int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId);

    virtual int SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId = 0);
public:
    /**
     * @brief 处理游戏客户端协议
     * @return
     */
    virtual int OnHandleClientMessage(uint64_t playerId, NFDataPackage &packet);

    /**
     * @brief 处理游戏服务器协议
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t playerId, NFDataPackage &packet);
public:
    uint32_t m_gameId;
    uint32_t m_roomId;
    int32_t m_deskId;//start from 0
    uint32_t m_chairCount;
    uint32_t m_maxUserNum;
    NFCommonStr m_passWd;
    NFRawShmPtr<NFIGameDeskImpl> m_deskHandle;
    NFRawShmPtr<NFGameRoom> m_roomHandle;
    NFShmVector<NFGameDeskStation, MAX_GAME_DESK_CHAIR_NUM> m_arrDeskStationId;
public:
    bool m_bTableLocked;                        //锁定标志
    bool m_bGameStarted;                        //开始标志
    uint32_t m_bGameStatus;                        //游戏状态
    uint32_t m_dwTimeStart;                        //开始时间
};