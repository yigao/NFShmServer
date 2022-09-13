// -------------------------------------------------------------------------
//    @FileName         :    NFUserDetailHashTable.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFUserDetailHashTable.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include <vector>
#include <NFServer/NFCommHead/NFCommLogicHead.h>
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFMessageDefine/proto_svr_login.pb.h"

class NFUserDetail;

class NFUserDetailMgr : public NFShmObj {
public:
    NFUserDetailMgr();

    virtual ~NFUserDetailMgr();

    int CreateInit();

    int ResumeInit();

public:
	int UserLogin(NFUserDetail *pPlayer, bool isLoadDB);
	int OnUserLogin(NFUserDetail *pPlayer, bool isLoadDB);
	int OnUserEventLogLogin(NFUserDetail *pPlayer, bool isLoadDB);
	int UserLogout(NFUserDetail *pPlayer);
	int OnUserLogout(NFUserDetail *pPlayer);
    int UserDisConnect(NFUserDetail *pPlayer);
    int OnUserDisConnect(NFUserDetail *pPlayer);
    int UserReconnect(NFUserDetail *pPlayer);
    int OnUserReconnect(NFUserDetail *pPlayer);

    int HandleAddJetton(NFUserDetail *pPlayer, uint32_t gameId, uint32_t roomId, uint32_t deskId, uint32_t chairId, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime);
    int HandleDeduceJetton(NFUserDetail *pPlayer, uint32_t gameId, uint32_t roomId, uint32_t deskId, uint32_t chairId, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime);

    int HandleAddBankJetton(NFUserDetail *pPlayer, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime);
    int HandleDeduceBankJetton(NFUserDetail *pPlayer,uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime);

    int HandleAddJetton(NFUserDetail *pPlayer, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime);
    int HandleDeduceJetton(NFUserDetail *pPlayer, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime);

    int HandleSaveJettonToBankJetton(NFUserDetail *pPlayer, uint64_t moneyChange);
    int HandleGetJettonFromBankJetton(NFUserDetail *pPlayer, uint64_t moneyChange);
public:
	virtual void OnTimer(int timeId, int callcount) override;

	int UserTick();
	int DayTick();
	int WeekTick();
	int MonthTick();
	int SaveUserDetailToDB();
public:
    NFUserDetail *GetUser(uint64_t userId);

    NFUserDetail *CreateUser(uint64_t userId);

    int DeleteUser(NFUserDetail *pPlayer);
private:
	int m_saveDBTimer;
	int m_userTickTimer;
	int m_dayTickTimer;
	int m_weekTickTimer;
	int m_monthTickTimer;
DECLARE_IDCREATE(NFUserDetailMgr)
};