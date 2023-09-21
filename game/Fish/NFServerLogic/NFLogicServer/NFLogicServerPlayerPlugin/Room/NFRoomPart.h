// -------------------------------------------------------------------------
//    @FileName         :    NFRoomPart.h
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoomPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFPart.h"

enum {
    PLAYER_ROOM_STATUS_NONE,
    PLAYER_ROOM_STATUS_DeskListing,
    PLAYER_ROOM_STATUS_DeskListed,
};

class NFRoomPart : public NFPart
{
public:
    NFRoomPart();

    virtual ~NFRoomPart();

    int CreateInit();

    int ResumeInit();
public:
    //******************part调用接口******************
    /**
     * @brief 初始化part
     * @param pMaster
     * @param partType
     * @param dbData
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::tbFishPlayerData &dbData, bool bCreatePlayer);

    /**
     * @brief 释放part资源
     * @return
     */
    virtual int UnInit();
public:
    /**
     * @brief 从数据库中加载数据
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::tbFishPlayerData& data);

    /**
     * @brief 从配置中初始化数据
     * @return
     */
    virtual int InitConfig(const proto_ff::tbFishPlayerData& data);

    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::tbFishPlayerData &dbData);

    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin() { return 0; }

    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout() { return 0; }

    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect() { return 0; }

    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect() { return 0; }

    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int DailyZeroUpdate() { return 0; }

    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; }

    /**
     * @brief 每月刷新接口
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; };
public:
    /**
     * @brief update
     */
    virtual int Update() { return 0; }

public:
    /**
     * @brief 注册要处理的消息
     * @return
     */
    virtual int RegisterMessage();
public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet);

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet);
public:
    /**
     * @brief 请求获得一个桌子和座位
     * @param request
     * @param respone
     * @return
     */
    int GetDeskListReq(proto_ff::DeskListReq& request, proto_ff::DeskListRsp& respone);

    /**
     * @brief 请求进入游戏
     * @return
     */
    int EnterGameReq(proto_ff::EnterGameReq& request, proto_ff::EnterGameRsp& respone);

    /**
     * @brief 退出游戏
     * @param request
     * @param respone
     * @return
     */
    int ExitGameReq(proto_ff::ExitGameReq& request, proto_ff::ExitGameRsp& respone);

    /**
     * @brief 游戏服务器被修改
     * @param request
     * @param respone
     * @return
     */
    int ChangeGameReq(proto_ff::Proto_STS_PlayerChangeGameServerReq& request, proto_ff::Proto_STS_PlayerChangeGameServerRsp& respone);
public:
    /**
     * @brief 通知玩家离开游戏
     * @param msgId
     * @param packet
     * @return
     */
    int OnHandleNotifyPlayerLeaveGame(uint32_t msgId, NFDataPackage &packet);
public:
    uint32_t GetGameId() const { return m_gameId; }
    uint32_t GetRoomId() const { return m_roomId; }
    uint32_t GetGameBusId() const { return m_gameBusId; }
    void SetGameId(uint32_t gameId) { m_gameId = gameId; }
    void SetGameBusId(uint32_t gameBusId) { m_gameBusId = gameBusId;}
    void SetRoomId(uint32_t roomId) { m_roomId = m_roomId; }
private:
    uint32_t m_gameId;
    uint32_t m_roomId;
    uint32_t m_gameBusId;
DECLARE_IDCREATE(NFRoomPart)
};