// -------------------------------------------------------------------------
//    @FileName         :    NFGameFish2004Desk.h
//    @Author           :    gaoyi
//    @Date             :    23-9-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFish2004Desk
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFIGameDeskImpl.h"
#include "Player/NFGameFishPlayer.h"
#include "Player/NFFishWayBillMgr.h"
#include "Fish/NFGameFish.h"
#include "FishTypeHandler/NFFishTypeMgr.h"
#include "Config/NFFishConfigConfig.h"
#include "Config/NFFishGroupConfig.h"
#include "Config/NFFishPromptConfig.h"
#include "Config/NFFishSettingConfig.h"
#include "CSFish.pb.h"

#define GAME_FISH_DESK_PLAYER_COUNT 4
#define GAME_FISH_DESK_FISH_COUNT 1000

class NFGameFishDesk : public NFIGameDeskImpl
{
public:
    NFGameFishDesk();

    virtual ~NFGameFishDesk();

    int CreateInit();

    int ResumeInit();

public:
    /**
     * @brief 初始化
     * @param pGameHandle
     * @param gameId
     * @param roomId
     * @param deskId
     * @param sitNum
     * @param maxUserNum
     * @return
     */
    virtual int Init(NFIGameDesk *pGameHandle, uint32_t gameId, uint32_t roomId, int32_t deskId, uint32_t sitNum, uint32_t maxUserNum);

public:
    virtual int OnTimer(int timeId, int callcount);

public:
    /**
     * @brief
     * @return
     */
    int GameStart();

    /**
     * @brief
     * @return
     */
    int GameEnd();

public:
    NFFishConfigConfig *GetFishConfigConfig();

    NFFishGroupConfig *GetFishGroupConfig();

    NFFishPromptConfig *GetFishPromptConfig();

    NFFishSettingConfig *GetFishSettingConfig();

    NFFishTraceConfig *GetFishTraceConfig();

    NFFishWayBillConfig *GetFishWayBillConfig();

public:
    /**
     * @brief
     * @param iDeskStation
     * @return
     */
    virtual bool IsPlayGame(int iDeskStation) override;

    /**
     * @brief
     * @param iDeskStation
     * @return
     */
    virtual bool IsPlayGameCanLeave(int iDeskStation) override;

    /**
     * @brief
     * @param playerId
     * @return
     */
    virtual bool IsGamePlayerReady(uint64_t playerId) override;

public:
    /**
     * @brief 玩家重进游戏
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserReCome(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail) override;

    /**
     * @brief 玩家坐
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserSitDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail) override;

    /**
     * @brief 玩家离开
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserLeftDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail) override;

    /**
     * @brief 玩家重连
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserReconDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail) override;

    /**
     * @brief 玩家同意
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserAgreeGame(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail) override;

    /**
     * @brief 玩家掉线
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserDisconnect(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail) override;

public:
    /**
     * @brief 更新玩家信息
     * @param deskId
     * @param playerId
     * @param pPlayerDetail
     * @return
     */
    virtual int UpdateUserInfo(uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s *pPlayerDetail) override;

public:
    /**
     * @brief 清理修改奖池
     * @return
     */
    virtual int ClearJiangChi() override;

    /**
     * @brief 清理修改奖池
     * @param jiangchi
     * @return
     */
    virtual int ChangeJiangChi(int64_t jiangchi) override;

public:
    /**
     * @brief 处理游戏客户端协议
     * @return
     */
    virtual int OnHandleClientMessage(uint64_t playerId, NFDataPackage &packet) override;

    /**
     * @brief 处理游戏服务器协议
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t playerId, NFDataPackage &packet) override;

public:
    /**
     * @brief
     * @param pPlayer
     */
    void UserLeaveDesk(NFGameFishPlayer *pPlayer);


    /**
     * @brief
     * @param pPlayer
     * @param playerDetail
     */
    void UserEnterDesk(NFGameFishPlayer *pPlayer, proto_ff_s::GamePlayerDetailData_s &playerDetail);

    /**
     * @brief
     * @param playerId
     * @return
     */
    int UserQuitGame(uint64_t playerId);

public:
    /**
     * @brief
     * @param msgId
     * @param xData
     * @return
     */
    int SendMsgToAllClient(uint32_t msgId, const google::protobuf::Message &xData, uint64_t excludePlayerId = 0);

    /**
     * @brief
     * @return
     */
    int32_t GetRealPlayerChairIdForRobot();

public:
    /**
     * @brief
     * @param playerId
     * @return
     */
    NFGameFishPlayer *GetPlayer(uint64_t playerId);

    /**
     * @brief
     * @param chairId
     * @return
     */
    NFGameFishPlayer *GetPlayerByChairId(uint32_t chairId);

    /**
     * @brief
     * @param playerId
     * @param iDeskStation
     * @return
     */
    NFGameFishPlayer *CreatePlayer(uint64_t playerId, int32_t iDeskStation);

    /**
     * @brief
     * @param playerId
     * @return
     */
    int DelPlayer(uint64_t playerId);

    /**
     * @brief
     * @return
     */
    std::list<NFGameFishPlayer *> GetOnlinePlayers();

    /**
     * @brief
     * @return
     */
    int GetPlayerCount();

    /**
     * @brief
     * @return
     */
    int TickPlayer();

public:
    /**
     * @brief
     * @param rspMsg
     * @return
     */
    int GetUserLoginDeskInfoMsg(gamefish::GameStatusRsp &rspMsg);

    /**
     * @brief
     * @param iBulletLevel
     * @return
     */
    int GetCannonValue(int iBulletLevel);

public:
    bool GetTypeRandAlgoRate(int iCannonIndex, int nBaseMul, double &dbRate);
public:
    int CreateFishEx(NFGameFish& fish, const CFish& fishCfg, uint16_t nDefaultFishKind, int16_t nOffsetPosX, int16_t nOffsetPosY, bool bIsRedFish = false);

    NFGameFish *CreateFish();

    NFGameFish *GetFish(uint32_t uFishId);

    void ClearFishes();

    int GetFishCount();

    std::vector<NFGameFish *> GetFishesByKind(uint8_t nFishKind);

    std::vector<NFGameFish *> GetFishesByKinds(std::vector<uint8_t> &vecFishKinds);

    std::vector<NFGameFish *> GetFishes(uint8_t nFishKind, CHMPoint ptCenter, int iRadius);

    std::vector<NFGameFish *> GetFishes(CHMPoint ptCenter, int iRadius, int iKillPercent);

    std::vector<NFGameFish *> GetFishesByType(uint8_t nFishType);

    std::vector<NFGameFish *> GetAllFishes();

    uint32_t GetFishForRobotLock();

    CHMPoint GetPointByIndex(unsigned int uTraceId, unsigned int uIndex);

    FishKind GetFishKind(FishConfig *pFishConfig);

    void CheckFishOverTime();

    void SyncFishes(uint64_t playerId);

    void SendUserStatus(uint64_t playerId);

    uint32_t GetSceneChangeInfo(float &fTimeSeconds, int &iChangeType);

    bool IsFreeze() { return m_FishTypeMgr->IsFreeze(); }

    void SetIsFreezs(bool isfreeze) { m_FishTypeMgr->SetIsFreezs(isfreeze); }

public:
    int OnHandleFishGameStatus(uint64_t playerId, NFDataPackage &packet);

    int OnHandleUserStaus(uint64_t playerId, NFDataPackage &packet);

    int OnHandleFishShootBullet(uint64_t playerId, NFDataPackage &packet);

    int OnHandleFishBulletSpeed(uint64_t playerId, NFDataPackage &packet);

    int OnHandleFishHitFish(uint64_t playerId, NFDataPackage &packet);

    int OnHandleFishAutoShoot(uint64_t playerId, NFDataPackage &packet);

    int OnHandleFishLockOnOff(uint64_t playerId, NFDataPackage &packet);

    int OnHandleFishLockFish(uint64_t playerId, NFDataPackage &packet);

    int OnHandleChangeCannon(uint64_t playerId, NFDataPackage &packet);

    int OnHandleChangeScene(uint64_t playerId, NFDataPackage &packet);

public:
    int FishGroupBaseTimer(uint32_t uTimerCount);

    bool WayBillPlayPolling(uint32_t uTimerCount, CFishWayBill *pCurWayBill, bool bIsRegularWayBill = false);

    int CreateGroupFishes(std::vector<NFGameFish> &vecGroupFishes, int iGroupId, uint8_t byDefaultFishKind = 0, bool bIsWithRedFish = false, uint16_t nDstPosX = 0, uint16_t nDstPoxY = 0);

    gamefish::FishList GetGroupFishList(std::vector<NFGameFish> &vecGroupFishes);

    int SaveGroupFishes(const std::vector<NFGameFish> &vecGroupFishes);

    CFishGroup *GetFishGroup(uint16_t nGroupId);

    void SendFishGroup(int iGroupId, uint8_t byDefaultFishKind = 0, bool bIsWithRedFish = false, uint16_t nDstPosX = 0, uint16_t nDstPoxY = 0);

    int GetPromptFishKind(CFishGroup *pFishGroup);

    void SendPromptInfo(uint32_t uInfoType, uint32_t uFishKind);

    void SendChangScene(uint32_t uSceneId, float fFishGowayTime, int iChangeType);

public:
    bool IsFishCanBeKilledByKillType(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet);

    bool IsFishCanBeKilled(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet);

public:
    NFShmVector<NFGameFishPlayer, GAME_FISH_DESK_PLAYER_COUNT> m_playerList;
public:
    int m_iCurStatus;
    uint64_t m_ullNextTime;

    int m_iCurWayBillSts;

    uint32_t m_uSceneCount;
    int32_t m_uSceneIndex;

    NFFishWayBillMgr m_FishWayBillMgr;
    NFFishWayBillMgr m_FishWayBillMgrExt;

    int m_iTimerObjId;
    int m_iTimerPlayerId;

    uint32_t m_maxFishId;
    NFShmHashMap<uint32_t, NFGameFish, GAME_FISH_DESK_FISH_COUNT> m_gameFishMap;

    NFShmPtr<NFFishTypeMgr> m_FishTypeMgr;

    NFRawShmPtr<CFishWayBill> m_pCurWayBill;
    bool m_bIsCurRegularWayBill;
    bool m_bForceRegularWayBill;

    uint16_t m_nCurGroupId;
    uint16_t m_nGroupIdToSend;

    int64_t m_llLastTotalShoot;
    int64_t m_llTotalShootInCtrlTime;

    NFCommonStr m_strLastWayBillName;
    bool m_bIsLastWayBillPrior;
private:
DECLARE_IDCREATE(NFGameFishDesk)
};