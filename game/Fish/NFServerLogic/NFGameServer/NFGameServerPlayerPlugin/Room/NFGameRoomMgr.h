// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoomMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameRoomMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFGameRoom.h"
#include "DescStore/RoomRoomDesc.h"




class NFGameRoomMgr : public NFShmObj
{
public:
    NFGameRoomMgr();

    virtual ~NFGameRoomMgr();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnTimer(int timeId, int callcount) override;

    int ClearTimeOutUser(uint64_t playerId);

    int ClearOfflineUser(uint64_t playerId);

    int ClearDirtyData(uint64_t playerId);

    int ClearIdleUser(uint64_t playerId);

    bool IsPlayGame(uint32_t gameId, uint32_t roomId, int32_t deskId, int32_t chairId);

    bool IsPlayGameCanLeave(uint32_t gameId, uint32_t roomId, int32_t deskId, int32_t chairId);
public:
    /**
     * @brief 游戏中获得金币，消耗金币，调用接口
     * @param gameId
     * @param roomId
     * @param deskId
     * @param playerId
     * @param unChageType
     * @param un64MoneyChange
     * @return
     */
    int	ModifyGameMoney(uint32_t gameId, uint32_t roomId, int32_t deskId, uint64_t playerId, uint32_t unChageType, uint64_t un64MoneyChange);
public:
    NFGameRoom *GetGameRoom(uint32_t gameId, uint32_t roomId);

    NFGameRoom *CreateGameRoom(uint32_t gameId, uint32_t roomId);

    int DeleteGameRoom(NFGameRoom *pRoomInfo);
public:
    int CreateAllRoom();
    int RegisterAllRoomToWorldServer();
private:
    bool m_inited;
    int m_registerRoomTimer;
DECLARE_IDCREATE(NFGameRoomMgr)
};