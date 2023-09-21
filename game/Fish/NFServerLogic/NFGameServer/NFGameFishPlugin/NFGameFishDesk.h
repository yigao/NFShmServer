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
    virtual int UserReCome(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) override;

    /**
     * @brief 玩家坐
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserSitDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) override;

    /**
     * @brief 玩家离开
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserLeftDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) override;

    /**
     * @brief 玩家重连
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserReconDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) override;

    /**
     * @brief 玩家同意
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserAgreeGame(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) override;

    /**
     * @brief 玩家掉线
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserDisconnect(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) override;
public:
    /**
     * @brief 更新玩家信息
     * @param deskId
     * @param playerId
     * @param pPlayerDetail
     * @return
     */
    virtual int UpdateUserInfo(uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s* pPlayerDetail) override;
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
private:
DECLARE_IDCREATE(NFGameFishDesk)
};