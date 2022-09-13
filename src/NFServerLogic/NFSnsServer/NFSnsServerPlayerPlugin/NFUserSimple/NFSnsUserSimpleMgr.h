// -------------------------------------------------------------------------
//    @FileName         :    NFUserSimleHashTable.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFUserSimleHashTable.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"
#include <vector>
#include <NFServer/NFCommHead/NFCommLogicHead.h>
#include <NFComm/NFShmCore/NFShmStaticList.hpp>

#define FREE_COUNT_MIN 	1000

class NFSnsUserSimple;

class NFSnsUserSimpleMgr : public NFShmObj {
public:
    NFSnsUserSimpleMgr();

    virtual ~NFSnsUserSimpleMgr();

    int CreateInit();

    int ResumeInit();

    int Init();

	virtual void OnTimer(int timeId, int callcount) override;
	int SaveUserSimpleToDB();
	int DayTick();
	int WeekTick();
	int MonthTick();
public:
	int ReleaseCount(int num);

    NFSnsUserSimple *GetUser(uint64_t userId);

    NFSnsUserSimple *CreateUser(uint64_t userId);

    int DeleteUser(NFSnsUserSimple *pPlayer);
private:
	int m_saveDBTimer;
	int m_dayTick;
	int m_weekTick;
	int m_monthTick;
DECLARE_IDCREATE(NFSnsUserSimpleMgr)
};