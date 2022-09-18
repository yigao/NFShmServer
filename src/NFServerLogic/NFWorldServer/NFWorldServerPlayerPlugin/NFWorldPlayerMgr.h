// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayerIDHashTable.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayerIDHashTable.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include <vector>
#include <NFServer/NFCommHead/NFCommLogicHead.h>

class NFWorldPlayer;
class NFWorldPlayerMgr : public NFShmObj {
public:
    NFWorldPlayerMgr();

    virtual ~NFWorldPlayerMgr();

    int CreateInit();

    int ResumeInit();

public:
    int UserTick();
    virtual void OnTimer(int timeId, int callcount) override;

    NFWorldPlayer *GetPlayer(uint64_t playerId);

    NFWorldPlayer *CreatePlayer(uint64_t playerId);

    int DeletePlayer(NFWorldPlayer *pPlayer);
private:
    int m_playerTickTimer;
DECLARE_IDCREATE(NFWorldPlayerMgr)
};