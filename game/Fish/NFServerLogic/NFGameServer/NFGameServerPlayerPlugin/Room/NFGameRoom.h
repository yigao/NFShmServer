// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoom.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameRoom
//
// -------------------------------------------------------------------------

#pragma once

#include <NFLogicCommon/NFLogicShmTypeDefines.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "AllProtocol.h"
#include "NFLogicCommon/NFRoomDefine.h"

class NFGameDesk;
class NFGamePlayer;

class NFGameRoom : public NFShmObjTemplate<NFGameRoom, EOT_NFGameRoom_ID, NFShmObj>
{
public:
	NFGameRoom();

	virtual ~NFGameRoom();

	int CreateInit();

	int ResumeInit();
public:
	virtual int OnTimer(int timeId, int callcount);

	/**
	 * @brief 1秒一次定时处理
	 * @return
	 */
	int Tick();
public:
	/** 初始化房间
	 * @brief
	 * @param gameId
	 * @param gameName
	 * @param roomId
	 * @param roomName
	 * @param deskCount
	 * @param sitNum
	 * @param maxUserNum
	 * @return
	 */
	int Init(uint32_t gameId, const std::string& gameName, uint32_t roomId, const std::string& roomName, uint32_t deskCount, uint32_t sitNum, uint32_t maxUserNum);

	/** 初始化桌子
	 * @brief
	 * @param deskCount
	 * @param sitNum
	 * @param maxUserNum
	 * @return
	 */
	int InitDesks(uint32_t deskCount, uint32_t sitNum, uint32_t maxUserNum);
public:
	/**
	 * @brief 游戏开始时，通知平台
	 * @param iDeskId
	 * @return
	 */
	int OnGameBegin(int iDeskId);

	/**
	 * @brief 游戏结束时，通知平台
	 * @param iDeskId
	 * @return
	 */
	int OnGameFinish(int iDeskId);
public:
	/**
	 * @brief 判断座位是否有人玩游戏
	 * @param iDeskId
	 * @param iDeskStation
	 * @return
	 */
	bool IsPlayGame(int iDeskId, int iDeskStation);

	/**
	 * @brief 判断座位上的玩家是否可以离开游戏
	 * @param iDeskId
	 * @param iDeskStation
	 * @return
	 */
	bool IsPlayGameCanLeave(int iDeskId, int iDeskStation);
public:
	/**
	 * @brief 清理闲逛人员
	 * @param playerId
	 * @return
	 */
	int ClearIdleUser(uint64_t playerId);

	/**
	 * @brief 清理用户异常退出后的残留的脏数据
	 * @param playerId
	 * @return
	 */
	int ClearDirtyData(uint64_t playerId);

	/**
	 * @brief 清理超时不操作用户
	 * @param playerId
	 * @return
	 */
	int ClearTimeOutUser(uint64_t playerId);

	/**
	 * @brief 清理不在线用户
	 * @param playerId
	 * @return
	 */
	int ClearOfflineUser(uint64_t playerId);

	/**
	 * @brief 因某种原因踢出用户
	 * @param playerId
	 * @param nReasonCode
	 */
	void KickUser(uint64_t playerId, int nReasonCode);
public:
	/**
	 * @brief 更改玩家金钱信息
	 * @param deskId
	 * @param playerId
	 * @param changeType
	 * @param moneyChange
	 * @return
	 */
	int UpdateUserMoney(int32_t deskId, uint64_t playerId, uint32_t changeType, uint64_t moneyChange);

	/**
	 * @brief 更新玩家信息
	 * @param deskId
	 * @param playerId
	 * @param pPlayerDetail
	 * @return
	 */
	int UpdateUserInfo(int32_t deskId, uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s* pPlayerDetail);
public:
	/**
	 * @brief
	 * @param iDeskId
	 * @return
	 */
	NFGameDesk* GetGameDesk(int32_t iDeskId); //客户端传来的deskIndex是从1开始

	/**
	 * @brief
	 * @return
	 */
	int GetDeskCount();
public:
	/**
	 * @brief 为玩家寻找一个合适的桌子，位置
	 * @param playerId
	 * @param iDeskIndex
	 * @param iDeskStation
	 * @return
	 */
	int LookingSuitSeatForPlayer(uint64_t playerId, int& iDeskIndex, int& iDeskStation);

	/**
	 * @brief 预定位置
	 * @param playerId
	 * @param iDeskId
	 * @param iDeskStation
	 * @return
	 */
	int ReserveSeat(uint64_t playerId, int iDeskId, int iDeskStation);
public:
	/**
	 * @brief 清理房间统计
	 * @return
	 */
	int ClearGameRoomStatInfo();

	/**
	 * @brief 房间统计数据修改
	 * @param cur_fee
	 * @param cur_pour
	 * @param cur_win
	 * @return
	 */
	int GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win);
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
	 * @brief 处理玩家请求桌子
	 * @param playerId
	 * @param autoChairId
	 * @param respone
	 * @return
	 */
	int OnHandleReqDeskList(uint64_t playerId, uint32_t autoChairId, proto_ff::DeskListRsp& respone);
public:
	/**
	 * @brief 请求进入游戏
	 * @param playerId
	 * @param deskId
	 * @param chairId
	 * @return
	 */
	int EnterGame(uint64_t playerId, int deskId, int chairId, proto_ff_s::GamePlayerDetailData_s& playerDetail);

	/**
	 * @brief 退出游戏
	 * @param playerId
	 * @return
	 */
	int ExitGame(uint64_t playerId);

	/**
	 * @brief
	 * @param playerId
	 * @return
	 */
	int RecomeGame(uint64_t playerId, uint32_t deskId);

	/**
	 * @brief
	 * @param playerId
	 * @param deskId
	 * @param chairId
	 * @return
	 */
	int CheckDeskStation(uint64_t playerId, int deskId, int chairId);
public:
	/**
	 * @brief 重连
	 * @param playerId
	 * @param iDeskId
	 * @return
	 */
	int UserReconDesk(uint64_t playerId, int iDeskId);

	/**
	 * @brief 掉线
	 * @param playerId
	 * @param iDeskId
	 * @return
	 */
	int UserDisconnect(uint64_t playerId, int iDeskId);
public:
	/**
	 * @brief 处理游戏客户端协议
	 * @return
	 */
	virtual int OnHandleClientMessage(uint32_t deskId, uint64_t playerId, NFDataPackage& packet);

	/**
	 * @brief 处理游戏服务器协议
	 * @return
	 */
	virtual int OnHandleServerMessage(uint32_t deskId, uint64_t playerId, NFDataPackage& packet);
public:
	uint32_t m_gameId;
	uint32_t m_roomId;
	NFCommonStr m_gameName;
	NFCommonStr m_roomName;
	NFShmVector<int, MAX_ONE_ROOM_DESK_NUM> m_AryDesks; //desk global id
	proto_ff_s::GameRoomStat_s m_roomStatInfo;
	int m_tickTimer;
};
