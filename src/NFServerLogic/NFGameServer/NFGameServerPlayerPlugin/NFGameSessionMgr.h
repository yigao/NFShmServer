// -------------------------------------------------------------------------
//    @FileName         :    NFGamePlayerIDHashTable.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGamePlayerIDHashTable.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include <vector>
#include <NFServer/NFCommHead/NFCommLogicHead.h>

class NFGameSession;

class NFGameSessionMgr : public NFShmObj {
public:
    NFGameSessionMgr();

    virtual ~NFGameSessionMgr();

    int CreateInit();

    int ResumeInit();

public:
	virtual void OnTimer(int timeId, int callcount) override;

	int CheckOfflineUser();

	int ClearAllGamePlayer();
public:

    NFGameSession *GetPlayer(uint64_t playerId);

    NFGameSession *CreatePlayer(uint64_t playerId);

    int DeletePlayer(NFGameSession *pPlayer);

    std::vector<NFGameSession*> GetAllPlayer();
    uint32_t GetPlayerCount();
private:
	int m_clearOfflineTimer;
DECLARE_IDCREATE(NFGameSessionMgr)
};