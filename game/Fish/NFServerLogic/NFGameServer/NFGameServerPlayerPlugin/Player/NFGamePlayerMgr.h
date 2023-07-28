// -------------------------------------------------------------------------
//    @FileName         :    NFGamePlayerMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGamePlayerMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFGamePlayer.h"

class NFGamePlayerMgr : public NFShmObj
{
public:
    NFGamePlayerMgr();

    virtual ~NFGamePlayerMgr();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnTimer(int timeId, int callcount) override;

    int CheckOfflineUser();

    int ClearAllGamePlayer();
public:

    NFGamePlayer *GetPlayer(uint64_t playerId);

    NFGamePlayer *CreatePlayer(uint64_t playerId);

    int DeletePlayer(NFGamePlayer *pPlayer);
private:
    int m_clearOfflineTimer;
DECLARE_IDCREATE(NFGamePlayerMgr)
};