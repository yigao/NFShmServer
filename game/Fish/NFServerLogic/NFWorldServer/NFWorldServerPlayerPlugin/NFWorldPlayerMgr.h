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
#include <NFLogicCommon/NFLogicShmTypeDefines.h>

class NFWorldPlayer;

class NFWorldPlayerMgr : public NFShmObjTemplate<NFWorldPlayerMgr, EOT_WORLD_PLAYER_MGR_ID, NFShmObj>
{
public:
	NFWorldPlayerMgr();

	virtual ~NFWorldPlayerMgr();

	int CreateInit();

	int ResumeInit();
public:
	int UserTick();
	virtual int OnTimer(int timeId, int callcount) override;

	NFWorldPlayer* GetPlayer(uint64_t playerId);

	NFWorldPlayer* CreatePlayer(uint64_t playerId);

	int DeletePlayer(NFWorldPlayer* pPlayer);
private:
	int m_playerTickTimer;
};
