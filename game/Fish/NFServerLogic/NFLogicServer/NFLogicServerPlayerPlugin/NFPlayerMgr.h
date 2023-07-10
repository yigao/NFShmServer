// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayerIDHashTable.h
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayerIDHashTable.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include <vector>

class NFPlayer;
class NFPlayerMgr : public NFShmObj {
public:
    NFPlayerMgr();

    virtual ~NFPlayerMgr();

    int CreateInit();

    int ResumeInit();

public:
    int UserTick();
    virtual int OnTimer(int timeId, int callcount) override;

    NFPlayer *GetPlayer(uint64_t playerId);

    NFPlayer *CreatePlayer(uint64_t playerId);

    int DeletePlayer(NFPlayer *pPlayer);

private:
    int m_playerTickTimer;
DECLARE_IDCREATE(NFPlayerMgr)
};