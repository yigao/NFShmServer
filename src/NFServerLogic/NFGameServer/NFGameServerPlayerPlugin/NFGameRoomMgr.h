// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoomIDHashTable.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameRoomIDHashTable.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include <vector>
#include <NFServer/NFCommHead/NFCommLogicHead.h>
#include "NFComm/NFMessageDefine/proto_common_s.h"

class NFGameRoom;
class NFIPluginManager;

class NFGameRoomMgr : public NFShmObj {
public:
    NFGameRoomMgr();

    virtual ~NFGameRoomMgr();

    int CreateInit();

    int ResumeInit();

public:
	virtual void OnTimer(int timeId, int callcount) override;

	int ClearTimeOutUser(uint64_t playerId);

	int ClearOfflineUser(uint64_t playerId);

	int ClearDirtyData(uint64_t playerId);

	int ClearIdleUser(uint64_t playerId);

	bool IsPlayGame(uint32_t gameId, uint32_t roomId, int32_t deskId, int32_t chairId);

	bool IsPlayGameCanLeave(uint32_t gameId, uint32_t roomId, int32_t deskId, int32_t chairId);

	int	ModifyGameMoney(uint32_t gameId, uint32_t roomId, int32_t deskId, uint64_t playerId, uint32_t unChageType, uint64_t un64MoneyChange);

	int SetUserManagerInfo(uint32_t gameId, uint32_t roomId, int32_t deskId, uint64_t playerId, const proto_ff_s::tbGameUserManagerData_s* pUserManagerData);

    int UpdateUserInfo(uint32_t gameId, uint32_t roomId, int32_t deskId, uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s* pUserManagerData);

    int SetGmCtrlGiveData(uint32_t gameId, uint32_t roomId, int32_t deskId, uint64_t playerId, const proto_ff_s::tbGmCtrlGiveCtrlData_s* pGmCtrlGiveDta);
public:
    NFGameRoom *GetGameRoom(uint32_t gameId, uint32_t roomId);

    NFGameRoom *CreateGameRoom(uint32_t gameId, uint32_t roomId);

    int DeleteGameRoom(NFGameRoom *pRoomInfo);

    std::vector<NFGameRoom*> GetAllRoom();
protected:
    int GetUseCount();

    uint64_t GetIndexId(uint32_t gameId, uint32_t tableId);

DECLARE_IDCREATE(NFGameRoomMgr)
};