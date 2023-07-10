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

class NFLogicPlayer;
class NFLogicPlayerMgr : public NFShmObj {
public:
    NFLogicPlayerMgr();

    virtual ~NFLogicPlayerMgr();

    int CreateInit();

    int ResumeInit();

public:
    int UserTick();
    virtual int OnTimer(int timeId, int callcount) override;

    NFLogicPlayer *GetPlayer(uint64_t playerId);

    NFLogicPlayer *CreatePlayer(uint64_t playerId);

    int DeletePlayer(NFLogicPlayer *pPlayer);

private:
    int m_playerTickTimer;
DECLARE_IDCREATE(NFLogicPlayerMgr)
};