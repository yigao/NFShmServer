// -------------------------------------------------------------------------
//    @FileName         :    NFIGameDeskImpl.h
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFIGameDeskImpl
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "AllProtocol.h"

class NFIGameDesk;
class NFIGamePlayer;
class NFIGameDeskImpl : public NFShmObj
{
public:
    NFIGameDeskImpl();

    virtual ~NFIGameDeskImpl();

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
    virtual int Init(NFIGameDesk* pGameHandle, uint32_t gameId, uint32_t roomId, int32_t deskId, uint32_t sitNum, uint32_t maxUserNum);
public:
    uint32_t GetGameId() const { return m_gameId; }

    uint32_t GetRoomId() const { return m_roomId; }

    int32_t GetDeskId() const { return m_deskId; }

    uint32_t GetSitNum() const { return m_siteNum; }

    uint32_t GetMaxUserNum() const { return m_maxUserNum; }
public:
    /**
     * @brief
     * @param iDeskStation
     * @return
     */
    virtual bool IsPlayGame(int iDeskStation) = 0;

    /**
     * @brief
     * @param iDeskStation
     * @return
     */
    virtual bool IsPlayGameCanLeave(int iDeskStation) { return false; }

    /**
     * @brief
     * @param playerId
     * @return
     */
    virtual bool IsGamePlayerReady(uint64_t playerId) { return false; };
public:
    /**
     * @brief 玩家重进游戏
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserReCome(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;

    /**
     * @brief 玩家坐
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserSitDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;

    /**
     * @brief 玩家离开
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserLeftDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;

    /**
     * @brief 玩家重连
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserReconDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;

    /**
     * @brief 玩家同意
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserAgreeGame(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;

    /**
     * @brief 玩家掉线
     * @param playerId
     * @param iDeskStation
     * @param pPlayer
     * @return
     */
    virtual int UserDisconnect(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;
public:
    /**
     * @brief 更新玩家信息
     * @param deskId
     * @param playerId
     * @param pPlayerDetail
     * @return
     */
    virtual int UpdateUserInfo(uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s* pPlayerDetail) = 0;
public:
    /**
     * @brief 清理修改奖池
     * @return
     */
    virtual int ClearJiangChi() = 0;

    /**
     * @brief 清理修改奖池
     * @param jiangchi
     * @return
     */
    virtual int ChangeJiangChi(int64_t jiangchi) = 0;
public:
    /**
     * @brief 处理游戏客户端协议
     * @return
     */
    virtual int OnHandleClientMessage(uint64_t playerId, NFDataPackage &packet) = 0;

    /**
     * @brief 处理游戏服务器协议
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t playerId, NFDataPackage &packet) = 0;
protected:
    uint32_t m_gameId;
    uint32_t m_roomId;
    int32_t m_deskId;
    uint32_t m_siteNum;
    uint32_t m_maxUserNum;
    NFRawShmPtr<NFIGameDesk> m_deskHandle;
};