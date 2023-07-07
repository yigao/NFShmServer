// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayerIDHashTable.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFWorldPlayerIDHashTable.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include <vector>

class NFWorldPlayer;
class NFWorldPlayerMgr : public NFShmObj {
public:
    NFWorldPlayerMgr();

    virtual ~NFWorldPlayerMgr();

    int CreateInit();

    int ResumeInit();

public:
    int UserTick();
    virtual int OnTimer(int timeId, int callcount) override;

    NFWorldPlayer *GetPlayer(uint64_t playerId);

    NFWorldPlayer *CreatePlayer(uint64_t playerId);

    int DeletePlayer(NFWorldPlayer *pPlayer);

private:
    int m_playerTickTimer;
DECLARE_IDCREATE(NFWorldPlayerMgr)
};