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
#include "DBProxy.pb.h"
#include <vector>

class NFPlayer;
class NFPlayerMgr : public NFShmObj {
public:
    NFPlayerMgr();

    virtual ~NFPlayerMgr();

    int CreateInit();

    int ResumeInit();

public:
    virtual int OnTimer(int timeId, int callcount) override;
public:
    NFPlayer *GetPlayer(uint64_t cid);

    NFPlayer *CreatePlayer(uint64_t cid, const proto_ff::RoleDBData& dbData, bool bCreatePlayer);

    int DeletePlayer(NFPlayer *pPlayer);
public:
    int Tick();

    int DailyZeroUpdate();

    int WeekZeroUpdate();

    int MonthZeroUpdate();
private:
    int m_playerTickTimer;
    int m_dayTickTimer;
    int m_weekTickTimer;
    int m_monthTickTimer;
DECLARE_IDCREATE(NFPlayerMgr)
};