// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoom.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameRoom.h
//
// -------------------------------------------------------------------------

#pragma once

#include <NFComm/NFPluginModule/NFServerDefine.h>
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFArray.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFComm/NFMessageDefine/NFGameConfig.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFMessageDefine/ResMeta_s.h"

class NFGameDesk;
class NFGameSession;

//桌子与座位对应节点
typedef struct stDeskStationNode {
    int m_nDeskIndex;     //桌子索引
    int m_nDeskStation;   //位置信息

} TDeskStationNode;

#define ONE_GAME_ROOM_MAX_DESK_COUNT 255

class NFGameRoom : public NFShmObj 
{
public:
    NFGameRoom();

    virtual ~NFGameRoom();

    int CreateInit();

    int ResumeInit();

public:
    int Init(uint32_t gameId, const std::string& gameName, uint32_t roomId, const std::string& roomName, uint32_t deskCount, uint32_t sitNum, uint32_t maxUserNum);

    int InitGameDesks(uint32_t deskCount, uint32_t sitNum, uint32_t maxUserNum);

    bool AddMessageCallBack(uint16_t subMsgId);

    int OnHandleClientMsg(int32_t deskId, uint64_t playerId, uint16_t nMsgId, const char *msg, uint32_t nLen);

    int OnHandleServerMsg(int32_t deskId, uint64_t playerId, uint32_t nMsgId, const char *msg, uint32_t nLen);

public:

    int SendMsgToClient(uint64_t playerId, uint16_t nSubMsgId, const google::protobuf::Message &xData);

	int BroadCastMsgToRoom(uint16_t nSubMsgId, const google::protobuf::Message &xData, int32_t chairId = INVALID_ID);

	int BroadCastMsgToDesk(int32_t deskId, uint16_t nSubMsgId, const google::protobuf::Message &xData, int32_t chairId = INVALID_ID);

	int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId = 0);

	int SendMsgToLogicServer(uint32_t nMsgId, uint32_t busId, const google::protobuf::Message &xData);

	int SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId = 0);
public:
    //int OnHandleEnterGameAutoJoinMsg(uint64_t playerId, const proto_ff::EnterGameAutoJoinReq xMsg);
	int OnHandleReqDeskListFromClient(uint64_t playerId, uint32_t autoChairId);

	int OnHandleEnterGameMsg(NFGameSession *pPlayer, int deskId, int chairId);
	int OnHandleUserReComeMsg(uint64_t playerId);
	int OnHandleExitGameMsg(uint64_t playerId);


public:
    int LookingSuitSeatForPlayer(uint64_t playerId, int &iDeskIndex, int &iDeskStation);
	int LookingSuitSeatForRobot(uint64_t playerId, int &iDeskIndex, int &iDeskStation, int maxRobotPerDesk, bool bIsNeedRealPlayer /*= true*/);
	void GetDeadRobots(std::vector<uint64_t>& vec);

    int ReserveSeat(uint64_t playerId, int iDeskId, int iDeskStation);

    int UserReconDesk(uint64_t playerId, int iDeskId);

    int UserDisconnect(uint64_t playerId, int iDeskId);

	int UpdateUserMoney(int32_t deskId, uint64_t playerId, uint32_t changeType, uint64_t moneyChange);

    int PaoMaDengNotify(const std::string& playerName, uint64_t winJetton);

    int SetUserManagerInfo(int32_t deskId, uint64_t playerId, const proto_ff_s::tbGameUserManagerData_s* pUserManagerData);

    int UpdateUserInfo(int32_t deskId, uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s* pUserManagerData);

    int SetGmCtrlGiveData(int32_t deskId, uint64_t playerId, const proto_ff_s::tbGmCtrlGiveCtrlData_s* pGmCtrlGiveDta);
public:
    NFGameDesk *GetGameDesk(int32_t iDeskId);//客户端传来的deskIndex是从1开始
	int GetDeskCount();
    //must be virtual
    virtual void OnTimer(int timeId, int callcount);
    int SendGameRoomStatInfo();
    int ClearGameRoomStatInfo();
public:
    //游戏开始时，通知平台
    int OnGameBegin(int iDeskId);

    //游戏结束时，通知平台
    int OnGameFinish(int iDeskId);

    //判断座位是否有人玩游戏
    bool IsPlayGame(int iDeskId, int iDeskStation);

	bool IsPlayGameCanLeave(int iDeskId, int iDeskStation);

    //清理闲逛人员
    int ClearIdleUser(uint64_t playerId);

    //清理用户异常退出后的残留的脏数据
    int ClearDirtyData(uint64_t playerId);

    //清理超时不操作用户
    int ClearTimeOutUser(uint64_t playerId);

    //清理不在线用户
    int ClearOfflineUser(uint64_t playerId);

    //因某种原因踢出用户
    void KickUser(uint64_t playerId, int nReasonCode);

    int ClearJiangChi();
    int ChangeJiangChi(int64_t jiangchi);

    //抽水计算，结果为抽水后玩家赢得钱
    int GameDataCommit(uint64_t cur_fee, uint64_t cur_ach, int64_t cur_win);

    const proto_ff_s::GameRoomDesc_s* GetRoomConfig();
public:
    uint32_t m_gameId;
    uint32_t m_roomId;
    NFSizeString<128> m_gameName;
    NFSizeString<128> m_roomName;
    NFArray<int, ONE_GAME_ROOM_MAX_DESK_COUNT> m_AryDesks; //desk global id

    proto_ff_s::GameRoomStat_s m_roomStatInfo;
    int m_statTimer;
    int m_lastSendTime;
DECLARE_IDCREATE(NFGameRoom)
};