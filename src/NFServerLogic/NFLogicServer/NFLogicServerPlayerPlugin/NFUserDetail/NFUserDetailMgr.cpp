// -------------------------------------------------------------------------
//    @FileName         :    NFUserDetailHashTable.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFUserDetailHashTable.cpp
//
// -------------------------------------------------------------------------

#include "NFUserDetailMgr.h"
#include "NFUserDetail.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFTransGetEventLog.h"
#include "NFMoneyLogHandle.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFUserDetailMgr, EOT_USER_DETAIL_HASH_TABLE_ID, NFShmObj)

NFUserDetailMgr::NFUserDetailMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFUserDetailMgr::~NFUserDetailMgr()
{
	if (m_saveDBTimer != INVALID_ID)
	{
		DeleteTimer(m_saveDBTimer);
		m_saveDBTimer = INVALID_ID;
	}

	if (m_userTickTimer != INVALID_ID)
	{
		DeleteTimer(m_userTickTimer);
		m_userTickTimer = INVALID_ID;
	}

	if (m_dayTickTimer != INVALID_ID)
    {
	    DeleteTimer(m_dayTickTimer);
	    m_dayTickTimer = INVALID_ID;
    }

	if (m_weekTickTimer != INVALID_ID)
    {
	    DeleteTimer(m_weekTickTimer);
        m_weekTickTimer = INVALID_ID;
    }

	if (m_monthTickTimer != INVALID_ID)
    {
	    DeleteTimer(m_monthTickTimer);
        m_monthTickTimer = INVALID_ID;
    }
}

int NFUserDetailMgr::CreateInit() {
	m_saveDBTimer = SetTimer(60 * 1000, 0, 0, 0, 1, 0);
	m_userTickTimer = SetTimer(100, 0, 0, 0, 1, 0);
	m_dayTickTimer = SetDayCalender(0, 0, 0, 0);
	m_weekTickTimer = SetWeekCalender(0, 1, 0, 0, 0);
	m_monthTickTimer = SetMonthCalender(0, 1, 0, 0, 0);
    return 0;
}

int NFUserDetailMgr::ResumeInit() {
    return 0;
}

NFUserDetail *NFUserDetailMgr::GetUser(uint64_t userId)
{
    return dynamic_cast<NFUserDetail*>(NFShmMgr::Instance()->GetObjFromHashKey(userId, EOT_USER_DETAIL_ID));
}

NFUserDetail *NFUserDetailMgr::CreateUser(uint64_t userId)
{
    NFUserDetail *pPlayer = GetUser(userId);
    CHECK_EXPR(pPlayer == NULL, NULL, "Create User Detail Failed, player exist, palyerId:{}", userId);

    pPlayer = dynamic_cast<NFUserDetail *>(NFShmMgr::Instance()->CreateObj(userId, EOT_USER_DETAIL_ID));
    CHECK_EXPR(pPlayer, NULL, "Create User Detail Obj Failed, playerID:{}", userId);

    pPlayer = GetUser(userId);
    CHECK_EXPR(pPlayer, NULL, "Create User Detail Success, buf can't find user:{}", userId);

    pPlayer->m_userData.userid = userId;
    NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0, "Add User Detail Success, userId:{} globalId:{}", userId,
              pPlayer->GetGlobalID());
    return pPlayer;
}

int NFUserDetailMgr::DeleteUser(NFUserDetail *pPlayer)
{
    CHECK_NULL(pPlayer);

    NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0, "Delete Detail Info, UserId:{}, gloablId:{}", pPlayer->m_userData.userid, pPlayer->GetGlobalID());

    NFShmMgr::Instance()->DestroyObj(pPlayer);

    return 0;
}

void NFUserDetailMgr::OnTimer(int timeId, int callcount)
{
	if (m_saveDBTimer == timeId)
	{
		SaveUserDetailToDB();
	}
	else if (m_userTickTimer == timeId)
	{
		UserTick();
	}
	else if (m_dayTickTimer == timeId)
    {
	    DayTick();
    }
	else if (m_weekTickTimer == timeId)
    {
	    WeekTick();
    }
	else if (m_monthTickTimer == timeId)
    {
	    MonthTick();
    }
}

int NFUserDetailMgr::UserTick()
{
    std::vector<uint64_t> deadPlayerList;
    NFUserDetail* pPlayer = dynamic_cast<NFUserDetail *>(NFShmMgr::Instance()->GetHeadObj(EOT_USER_DETAIL_ID));
    while (pPlayer)
    {
        pPlayer->Tick();
        if (pPlayer->GetOnlineStatus() == PLAYER_STATUS_DEAD)
        {
            deadPlayerList.push_back(pPlayer->GetUserId());
        }
        pPlayer = dynamic_cast<NFUserDetail *>(NFShmMgr::Instance()->GetNextObj(EOT_USER_DETAIL_ID, pPlayer));
    }

    for(int i = 0; i < (int)deadPlayerList.size(); i++)
    {
        NFUserDetail* pPlayer = GetUser(deadPlayerList[i]);
        if (pPlayer)
        {
            DeleteUser(pPlayer);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Dead Player, buf GetUser:{} Failed", deadPlayerList[i]);
        }
    }
	return 0;
}

int NFUserDetailMgr::DayTick()
{
    NFUserDetail* pPlayer = dynamic_cast<NFUserDetail *>(NFShmMgr::Instance()->GetHeadObj(EOT_USER_DETAIL_ID));
    while (pPlayer)
    {
        pPlayer->DayTick();
        pPlayer = dynamic_cast<NFUserDetail *>(NFShmMgr::Instance()->GetNextObj(EOT_USER_DETAIL_ID, pPlayer));
    }

    return 0;
}

int NFUserDetailMgr::WeekTick()
{
    NFUserDetail* pPlayer = dynamic_cast<NFUserDetail *>(NFShmMgr::Instance()->GetHeadObj(EOT_USER_DETAIL_ID));
    while (pPlayer)
    {
        pPlayer->WeekTick();
        pPlayer = dynamic_cast<NFUserDetail *>(NFShmMgr::Instance()->GetNextObj(EOT_USER_DETAIL_ID, pPlayer));
    }

    return 0;
}

int NFUserDetailMgr::MonthTick()
{
    NFUserDetail* pPlayer = dynamic_cast<NFUserDetail *>(NFShmMgr::Instance()->GetHeadObj(EOT_USER_DETAIL_ID));
    while (pPlayer)
    {
        pPlayer->MonthTick();
        pPlayer = dynamic_cast<NFUserDetail *>(NFShmMgr::Instance()->GetNextObj(EOT_USER_DETAIL_ID, pPlayer));
    }

    return 0;
}

int NFUserDetailMgr::SaveUserDetailToDB()
{
    NFUserDetail* pPlayer = dynamic_cast<NFUserDetail *>(NFShmMgr::Instance()->GetHeadObj(EOT_USER_DETAIL_ID));
    while (pPlayer)
    {
        pPlayer->SaveToDB();
        pPlayer = dynamic_cast<NFUserDetail *>(NFShmMgr::Instance()->GetNextObj(EOT_USER_DETAIL_ID, pPlayer));
    }
	return 0;
}

int NFUserDetailMgr::UserLogin(NFUserDetail *pPlayer, bool isLoadDB)
{
	CHECK_NULL(pPlayer);

	pPlayer->UserLogin(isLoadDB);
	OnUserLogin(pPlayer, isLoadDB);
    OnUserEventLogLogin(pPlayer, isLoadDB);

    pPlayer->SaveToDB(TRANS_SAVEROLEDETAIL_NORMAL, true);
	return 0;
}

int NFUserDetailMgr::OnUserLogin(NFUserDetail *pPlayer, bool isLoadDB)
{
	CHECK_NULL(pPlayer);
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_NULL(pConfig);

	proto_ff::Proto_LogicToSnsLoginReq reqMsg;
	reqMsg.set_player_id(pPlayer->GetUserId());
	reqMsg.set_logic_bus_id(pConfig->mBusId);
	reqMsg.set_game_bus_id(pPlayer->m_gameBusId);
	reqMsg.set_last_login_time(pPlayer->GetLastLoginTime());
	reqMsg.set_last_logout_time(pPlayer->GetLastLogoutTime());
    proto_ff::UserSimpleData* pSimpleData = reqMsg.mutable_simple_data();
    pSimpleData->set_userid(pPlayer->GetUserId());
    pSimpleData->set_face(pPlayer->GetFaceId());
    pSimpleData->set_nickname(pPlayer->GetNickName());
    pSimpleData->set_gender(pPlayer->GetGender());
    pSimpleData->set_age(pPlayer->GetAge());
    pSimpleData->set_show_userid(pPlayer->GetShowUserId());
	NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTS_PLAYER_LOGIN_REQ, reqMsg);
	return 0;
}

int NFUserDetailMgr::OnUserEventLogLogin(NFUserDetail *pPlayer, bool isLoadDB)
{
    CHECK_NULL(pPlayer);
    if (!isLoadDB)
    {
        return 0;
    }

    NFTransGetEventLog* pTrans = (NFTransGetEventLog*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_GET_EVENT_LOG_ID);
    CHECK_EXPR(pTrans, -1, "Create Msg Trans Failed! UsedItem:{}", NFTransGetEventLog::GetUsedCount());

    pTrans->Init(pPlayer, 0, 0);
    pTrans->GetAllEventLog(pPlayer->GetUserId());

    return 0;
}

int NFUserDetailMgr::UserDisConnect(NFUserDetail *pPlayer)
{
    CHECK_NULL(pPlayer);

    pPlayer->UserDisConnect();
    OnUserDisConnect(pPlayer);

    return 0;
}

int NFUserDetailMgr::OnUserDisConnect(NFUserDetail *pPlayer)
{
    CHECK_NULL(pPlayer);

    proto_ff::NotifyPlayerDisconnect xMsg;
    xMsg.set_player_id(pPlayer->m_userData.userid);

    NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTS_PLAYER_DISCONNECT_MSG, xMsg);
    return 0;
}

int NFUserDetailMgr::UserReconnect(NFUserDetail *pPlayer)
{
    CHECK_NULL(pPlayer);

    pPlayer->UserReconnect();
    OnUserReconnect(pPlayer);

    return 0;
}

int NFUserDetailMgr::OnUserReconnect(NFUserDetail *pPlayer)
{
    CHECK_NULL(pPlayer);
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_NULL(pConfig);

    proto_ff::LTSNotifyPlayerReconnectReq xMsg;
    xMsg.set_player_id(pPlayer->GetUserId());
    xMsg.set_logic_bus_id(pConfig->mBusId);
    xMsg.set_game_bus_id(pPlayer->m_gameBusId);
    xMsg.set_last_login_time(pPlayer->GetLastLoginTime());
    xMsg.set_last_logout_time(pPlayer->GetLastLogoutTime());

    proto_ff::UserSimpleData* pSimpleData = xMsg.mutable_simple_data();
    pSimpleData->set_userid(pPlayer->GetUserId());
    pSimpleData->set_face(pPlayer->GetFaceId());
    pSimpleData->set_nickname(pPlayer->GetNickName());
    pSimpleData->set_gender(pPlayer->GetGender());
    pSimpleData->set_age(pPlayer->GetAge());
    pSimpleData->set_show_userid(pPlayer->GetShowUserId());

    NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTS_PLAYER_RECONNECT_MSG, xMsg);

    return 0;
}

int NFUserDetailMgr::UserLogout(NFUserDetail *pPlayer)
{
	CHECK_NULL(pPlayer);
	NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetUserId(), "User Logout Success, Status={}", pPlayer->GetOnlineStatus());

	pPlayer->UserLogout();
	OnUserLogout(pPlayer);

	pPlayer->SetOnlineStatus(PLAYER_STATUS_DEAD);
	return 0;
}

int NFUserDetailMgr::OnUserLogout(NFUserDetail *pPlayer)
{
	CHECK_NULL(pPlayer);
	proto_ff::Proto_LogicToSnsLogoutReq reqMsg;
	reqMsg.set_player_id(pPlayer->GetUserId());

	NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTS_PLAYER_LOGOUT_REQ, reqMsg);

	proto_ff::Proto_LogicToWorldLogoutReq wReqMsg;
	wReqMsg.set_player_id(pPlayer->GetUserId());
	NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTW_PLAYER_LOGOUT_REQ, wReqMsg);

	return 0;
}

int NFUserDetailMgr::HandleAddJetton(NFUserDetail *pPlayer, uint32_t gameId, uint32_t roomId, uint32_t deskId,
                                     uint32_t chairId, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason,
                                     uint32_t changeTime) {
    CHECK_NULL(pPlayer);

    int iRetCode = pPlayer->HandleAddJetton(moneyChange, opt_type, opt_reason, changeTime);
    CHECK_RET(iRetCode, "player:{} HandleAddJetton Failed! moneyChange:{}", moneyChange);

    pPlayer->SaveMoneyToDB();
    pPlayer->SendMoneyToClient();

    NFMoneyLogHandle::Instance()->UserMoneyChange(pPlayer, gameId, roomId, deskId, chairId, proto_ff::E_ACCOUNT_TYPE_JETTON, moneyChange, opt_type, opt_reason);

    proto_ff::Proto_PlayerJettonChangeStatReq statReq;
    statReq.set_player_id(pPlayer->GetUserId());
    statReq.set_account_type(proto_ff::E_ACCOUNT_TYPE_JETTON);
    statReq.set_opt_type(opt_type);
    statReq.set_opt_reason(opt_reason);
    statReq.set_money_change(moneyChange);

    NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_STSNS_PlayerJettonChangeStatReq, statReq);
    return 0;
}

int NFUserDetailMgr::HandleDeduceJetton(NFUserDetail *pPlayer, uint32_t gameId, uint32_t roomId, uint32_t deskId,
                                        uint32_t chairId, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason,
                                        uint32_t changeTime) {
    CHECK_NULL(pPlayer);

    int iRetCode = pPlayer->HandleDeduceJetton(moneyChange, opt_type, opt_reason, changeTime);
    CHECK_RET(iRetCode, "player:{} HandleDeduceJetton Failed! moneyChange:{}", moneyChange);

    pPlayer->SaveMoneyToDB();
    pPlayer->SendMoneyToClient();

    NFMoneyLogHandle::Instance()->UserMoneyChange(pPlayer, gameId, roomId, deskId, chairId, proto_ff::E_ACCOUNT_TYPE_JETTON, moneyChange, opt_type, opt_reason);

    proto_ff::Proto_PlayerJettonChangeStatReq statReq;
    statReq.set_player_id(pPlayer->GetUserId());
    statReq.set_account_type(proto_ff::E_ACCOUNT_TYPE_JETTON);
    statReq.set_opt_type(opt_type);
    statReq.set_opt_reason(opt_reason);
    statReq.set_money_change(moneyChange);

    NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_STSNS_PlayerJettonChangeStatReq, statReq);
    return 0;
}

int NFUserDetailMgr::HandleAddJetton(NFUserDetail *pPlayer, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime)
{
    CHECK_NULL(pPlayer);

    int iRetCode = pPlayer->HandleAddJetton(moneyChange, opt_type, opt_reason, changeTime);
    CHECK_RET(iRetCode, "player:{} HandleAddJetton Failed! moneyChange:{}", moneyChange);

    pPlayer->SaveMoneyToDB();
    pPlayer->SendMoneyToClient();

    proto_ff::Proto_PlayerJettonChangeStatReq statReq;
    NFMoneyLogHandle::Instance()->UserMoneyChange(pPlayer, 0, 0, 0, 0, proto_ff::E_ACCOUNT_TYPE_JETTON, moneyChange, opt_type, opt_reason);
    if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_RECHARGE)
    {
        if (opt_reason == proto_ff::E_RECHARGE_PAY_TYPE_WEB_ZHUANGZHANG_PLATFORM)
        {
            NFMoneyLogHandle::Instance()->WebZhuangZhangRecharge(pPlayer, moneyChange, 0);
        }

        if (opt_reason == proto_ff::E_RECHARGE_PAY_TYPE_POINTCARD)
        {
            NFMoneyLogHandle::Instance()->WebRedeemCodeRecharge(pPlayer, moneyChange, 0);
        }

        if (!pPlayer->GetData()->first_recharge)
        {
            pPlayer->GetData()->first_recharge = true;
            statReq.set_is_first_recharge(true);
        }

        pPlayer->NotifyGameMoneyChange();
    }
    else if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_WEB_GIVE_MONEY)
    {
        NFMoneyLogHandle::Instance()->WebGiveMoney(pPlayer, opt_reason, moneyChange, 0);
        pPlayer->NotifyGameMoneyChange();
    }

    statReq.set_player_id(pPlayer->GetUserId());
    statReq.set_account_type(proto_ff::E_ACCOUNT_TYPE_JETTON);
    statReq.set_opt_type(opt_type);
    statReq.set_opt_reason(opt_reason);
    statReq.set_money_change(moneyChange);

    NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_STSNS_PlayerJettonChangeStatReq, statReq);
    return 0;
}

int NFUserDetailMgr::HandleDeduceJetton(NFUserDetail *pPlayer, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime)
{
    CHECK_NULL(pPlayer);

    if (pPlayer->GetJetton() < moneyChange)
    {
        moneyChange = pPlayer->GetJetton();
    }

    int iRetCode = pPlayer->HandleDeduceJetton(moneyChange, opt_type, opt_reason, changeTime);
    CHECK_RET(iRetCode, "player:{} HandleDeduceJetton Failed! moneyChange:{}", moneyChange);

    pPlayer->SaveMoneyToDB();
    pPlayer->SendMoneyToClient();

    NFMoneyLogHandle::Instance()->UserMoneyChange(pPlayer, 0, 0, 0, 0, proto_ff::E_ACCOUNT_TYPE_JETTON, moneyChange, opt_type, opt_reason);
    if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_RECHARGE)
    {
        if (opt_reason == proto_ff::E_RECHARGE_PAY_TYPE_WEB_ZHUANGZHANG_PLATFORM)
        {
            NFMoneyLogHandle::Instance()->WebZhuangZhangRecharge(pPlayer, (int64_t)moneyChange * -1, 0);

            proto_ff::Proto_PlayerJettonChangeStatReq statReq;
            statReq.set_player_id(pPlayer->GetUserId());
            statReq.set_account_type(proto_ff::E_ACCOUNT_TYPE_JETTON);
            statReq.set_opt_type(opt_type);
            statReq.set_opt_reason(opt_reason);
            statReq.set_money_change((int64_t)moneyChange * -1);

            NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_STSNS_PlayerJettonChangeStatReq, statReq);
            pPlayer->NotifyGameMoneyChange();

            return 0;
        }

        pPlayer->NotifyGameMoneyChange();
    }

    proto_ff::Proto_PlayerJettonChangeStatReq statReq;
    statReq.set_player_id(pPlayer->GetUserId());
    statReq.set_account_type(proto_ff::E_ACCOUNT_TYPE_JETTON);
    statReq.set_opt_type(opt_type);
    statReq.set_opt_reason(opt_reason);
    statReq.set_money_change(moneyChange);

    NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_STSNS_PlayerJettonChangeStatReq, statReq);
    return 0;
}

int NFUserDetailMgr::HandleAddBankJetton(NFUserDetail *pPlayer, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason,
                                         uint32_t changeTime) {
    CHECK_NULL(pPlayer);

    int iRetCode = pPlayer->HandleAddBankJetton(moneyChange, opt_type, opt_reason, changeTime);
    CHECK_RET(iRetCode, "player:{} HandleAddBankJetton Failed! moneyChange:{}", moneyChange);

    pPlayer->SaveMoneyToDB();
    pPlayer->SendMoneyToClient();

    NFMoneyLogHandle::Instance()->UserMoneyChange(pPlayer, 0, 0, 0, 0, proto_ff::E_ACCOUNT_TYPE_BANK_JETTON, moneyChange, opt_type, opt_reason);

    proto_ff::Proto_PlayerJettonChangeStatReq statReq;
    statReq.set_player_id(pPlayer->GetUserId());
    statReq.set_account_type(proto_ff::E_ACCOUNT_TYPE_BANK_JETTON);
    statReq.set_opt_type(opt_type);
    statReq.set_opt_reason(opt_reason);
    statReq.set_money_change(moneyChange);

    NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_STSNS_PlayerJettonChangeStatReq, statReq);
    return 0;
}

int NFUserDetailMgr::HandleDeduceBankJetton(NFUserDetail *pPlayer, uint64_t moneyChange, uint32_t opt_type,
                                            uint32_t opt_reason, uint32_t changeTime) {
    CHECK_NULL(pPlayer);

    if (pPlayer->GetBankJetton() < moneyChange)
    {
        moneyChange = pPlayer->GetBankJetton();
    }

    int iRetCode = pPlayer->HandleDeduceBankJetton(moneyChange, opt_type, opt_reason, changeTime);
    CHECK_RET(iRetCode, "player:{} HandleDeduceBankJetton Failed! moneyChange:{}", moneyChange);

    pPlayer->SaveMoneyToDB();
    pPlayer->SendMoneyToClient();

    NFMoneyLogHandle::Instance()->UserMoneyChange(pPlayer, 0, 0, 0, 0, proto_ff::E_ACCOUNT_TYPE_BANK_JETTON, moneyChange, opt_type, opt_reason);

    proto_ff::Proto_PlayerJettonChangeStatReq statReq;
    statReq.set_player_id(pPlayer->GetUserId());
    statReq.set_account_type(proto_ff::E_ACCOUNT_TYPE_BANK_JETTON);
    statReq.set_opt_type(opt_type);
    statReq.set_opt_reason(opt_reason);
    statReq.set_money_change(moneyChange);

    NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_STSNS_PlayerJettonChangeStatReq, statReq);
    return 0;
}

int NFUserDetailMgr::HandleSaveJettonToBankJetton(NFUserDetail *pUserDetail, uint64_t moneyChange)
{
    CHECK_NULL(pUserDetail);

    int ret = HandleDeduceJetton(pUserDetail, moneyChange, proto_ff::E_USER_JETTON_OPER_TYPE_EXCHANGE, proto_ff::E_EXCHANGE_REASON_SAVE_MONEY, NFTime::Now().UnixSec());
    if (ret == 0)
    {
        ret = HandleAddBankJetton(pUserDetail, moneyChange, proto_ff::E_USER_JETTON_OPER_TYPE_EXCHANGE, proto_ff::E_EXCHANGE_REASON_SAVE_MONEY, NFTime::Now().UnixSec());
        if (ret != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, pUserDetail->GetUserId(), "HandleAddBankJetton Failed, user bank jetton:{} add jetton:{}", pUserDetail->GetBankJetton(), moneyChange);
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, pUserDetail->GetUserId(), "HandleDeduceJetton Failed, user jetton:{} deduce jetton:{}", pUserDetail->GetJetton(), moneyChange);
    }

    return 0;
}

int NFUserDetailMgr::HandleGetJettonFromBankJetton(NFUserDetail *pUserDetail, uint64_t moneyChange)
{
    CHECK_NULL(pUserDetail);

    int ret = HandleDeduceBankJetton(pUserDetail, moneyChange, proto_ff::E_USER_JETTON_OPER_TYPE_EXCHANGE, proto_ff::E_EXCHANGE_REASON_DRAW_MONEY, NFTime::Now().UnixSec());
    if (ret == 0)
    {
        ret = HandleAddJetton(pUserDetail, moneyChange, proto_ff::E_USER_JETTON_OPER_TYPE_EXCHANGE, proto_ff::E_EXCHANGE_REASON_DRAW_MONEY, NFTime::Now().UnixSec());
        if (ret != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, pUserDetail->GetUserId(), "HandleAddJetton Failed, user bank jetton:{} add jetton:{}", pUserDetail->GetBankJetton(), moneyChange);
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, pUserDetail->GetUserId(), "HandleDeduceBankJetton Failed, user jetton:{} deduce jetton:{}", pUserDetail->GetJetton(), moneyChange);
    }

    return 0;
}




