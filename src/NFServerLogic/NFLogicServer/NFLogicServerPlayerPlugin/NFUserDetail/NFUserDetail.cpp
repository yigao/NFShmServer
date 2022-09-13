// -------------------------------------------------------------------------
//    @FileName         :    NFUserDetail.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFUserDetail.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFTransSaveMoney.h"
#include "NFTransSaveDB.h"
#include "NFUserDetailMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFMoneyLogHandle.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFUserDetail, EOT_USER_DETAIL_ID, NFShmObj)

NFUserDetail::NFUserDetail()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFUserDetail::~NFUserDetail()
{

}

int NFUserDetail::CreateInit()
{
    memset(&m_userData, 0, sizeof(m_userData));
	m_iStatus = PLAYER_STATUS_NONE;
    m_createTime = NFTime::Now().UnixSec();
	m_lastDiconnectTime = 0;
	m_bDetailInited = false;
	m_iTransNum = 0;
	m_gameBusId = 0;
    m_proxyBusId = 0;
	ResetCurSeq();
	m_userDetailInfoSavingDBTime = 0;
    m_bCheckedBankPassword = false;
    m_lastUpdateGoldRankTime = 0;
    m_needUpdateGoldRank = true;
    return 0;
}

int NFUserDetail::ResumeInit()
{
    return 0;
}

void NFUserDetail::IncreaseTransNum()
{
	++m_iTransNum;
}


void NFUserDetail::DecreaseTransNum()
{
	--m_iTransNum;
	if (m_iTransNum < 0)
	{
		m_iTransNum = 0;
	}
}

int NFUserDetail::InitUserDetailData(const proto_ff::tbUserDetailData& data)
{
   proto_ff_s::tbUserDetailData_s::read_from_pbmsg(data, m_userData);
   m_bDetailInited = true;
   m_userDetailInfoSavingDBTime = NFTime::Now().UnixSec();
   return 0;
}

int NFUserDetail::MakeUserDataCS(proto_ff::tbUserDetailData &data) {
    proto_ff_s::tbUserDetailData_s::write_to_pbmsg(m_userData, data);
    return 0;
}

int NFUserDetail::SaveMoneyToDB()
{
	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
	NFTransSaveMoney* pSave = (NFTransSaveMoney*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_SAVE_USER_MONEY);
	CHECK_EXPR(pSave, -1, "Create Trans:NFTransSaveMoney Failed! ");

	pSave->Init(this, 0);
	pSave->ProHandleSaveMoney();
	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFUserDetail::SaveGameRoomToDB()
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::tbUserDetailData userDetail;
    userDetail.set_userid(GetUserId());
    userDetail.set_game_id(m_userData.game_id);
    userDetail.set_room_id(m_userData.room_id);

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                     proto_ff::E_STORESVR_C2S_MODIFYOBJ, proto_ff::E_TABLE_USER_DETAIL,
                                                     NF_DEFAULT_MYSQL_DB_NAME, "tbUserDetailData", userDetail,
                                                     0, 0, GetUserId());
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFUserDetail::SendMoneyToClient()
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFUserDetail::SaveToDB(TRANS_SAVEROLEDETAIL_REASON iReason, bool bForce)
{
	if (m_bDetailInited && IsUrgentNeedSave())
	{
		if (bForce || NFTime::Now().UnixSec() - m_userDetailInfoSavingDBTime >= 60)
		{
			SaveUserDetailToDB(iReason);
		}
	}
	return 0;
}

int NFUserDetail::SaveUserDetailToDB(TRANS_SAVEROLEDETAIL_REASON iReason)
{
	NFTransSaveDB* pSave = (NFTransSaveDB*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_SAVE_USER_DETAIL);
	CHECK_EXPR(pSave, -1, "Create Trans:NFTransSaveMoney Failed! ");

	pSave->Init(this, 0);
	int iRet = pSave->ProHandleSaveDB(iReason);
	if (iRet != 0)
	{
		pSave->SetFinished(-1);
	}

	return iRet;
}

int NFUserDetail::OnUserDetailSaved(bool success, uint32_t seq)
{
	m_userDetailInfoSavingDBTime = 0;
	if (success && seq == GetCurSeq())
	{
		ClearUrgent();
	}
	return 0;
}

int NFUserDetail::HandleAddJetton(uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime)
{
	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");

	if (moneyChange <= 0)
	{
		NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "moneyChange = 0");
        return proto_ff::ERR_CODE_MODIFY_MONEY_LESS_ZERO;
	}

	uint32_t nowTime = NFTime::Now().UnixSec();
	uint32_t timeDiff = 0;
	if (changeTime >= nowTime)
	{
		timeDiff = changeTime - nowTime;
	}
	else
	{
		timeDiff = nowTime - changeTime;
	}

	if (timeDiff > 600)
	{
		NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "the money chane time invalid");
        return proto_ff::ERR_CODE_MODIFY_MONEY_TIMEOUT;
	}

	m_userData.jetton += moneyChange;
    m_needUpdateGoldRank = true;

    if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_GAME_BALANCED_WIN)
    {
        m_userData.today_win += (int64_t)moneyChange;
        m_userData.week_win += (int64_t)moneyChange;
        m_userData.month_win += (int64_t)moneyChange;
        m_userData.all_win += (int64_t)moneyChange;
    }
    else if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_RECHARGE)
    {
        m_userData.today_recharge += (int64_t)moneyChange;
        m_userData.week_recharge += (int64_t)moneyChange;
        m_userData.month_recharge += (int64_t)moneyChange;
        m_userData.all_recharge += (int64_t)moneyChange;
    }
    else if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_WEB_GIVE_MONEY || opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_GIVE_JETTON)
    {
        m_userData.today_give += (int64_t)moneyChange;
        m_userData.week_give += (int64_t)moneyChange;
        m_userData.month_give += (int64_t)moneyChange;
        m_userData.all_give += (int64_t)moneyChange;
    }

	MarkDirty();

	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFUserDetail::HandleDeduceJetton(uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime)
{
	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");

	if (moneyChange <= 0)
	{
		//NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "moneyChange = 0");
		return proto_ff::ERR_CODE_MODIFY_MONEY_LESS_ZERO;
	}

	uint32_t nowTime = NFTime::Now().UnixSec();
	uint32_t timeDiff = 0;
	if (changeTime >= nowTime)
	{
		timeDiff = changeTime - nowTime;
	}
	else
	{
		timeDiff = nowTime - changeTime;
	}

	if (timeDiff > 600)
	{
		NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "the money chane time invalid");
		return proto_ff::ERR_CODE_MODIFY_MONEY_TIMEOUT;
	}

	if (m_userData.jetton > moneyChange)
	{
		m_userData.jetton -= moneyChange;
	}
	else
	{
		m_userData.jetton = 0;
	}
    m_needUpdateGoldRank = true;

    if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_GAME_BALANCED_LOST)
    {
        m_userData.today_win -= (int64_t)moneyChange;
        m_userData.week_win -= (int64_t)moneyChange;
        m_userData.month_win -= (int64_t)moneyChange;
        m_userData.all_win -= (int64_t)moneyChange;
    }
    else if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_WEB_DEDUCT_NONEY)
    {
        m_userData.today_draw += (int64_t)moneyChange;
        m_userData.week_draw += (int64_t)moneyChange;
        m_userData.month_draw += (int64_t)moneyChange;
        m_userData.all_draw += (int64_t)moneyChange;
    }

	MarkDirty();

	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFUserDetail::HandleAddBankJetton(uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");

    if (moneyChange <= 0)
    {
        NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "moneyChange = 0");
        return proto_ff::ERR_CODE_MODIFY_MONEY_LESS_ZERO;
    }

    uint32_t nowTime = NFTime::Now().UnixSec();
    uint32_t timeDiff = 0;
    if (changeTime >= nowTime)
    {
        timeDiff = changeTime - nowTime;
    }
    else
    {
        timeDiff = nowTime - changeTime;
    }

    if (timeDiff > 600)
    {
        NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "the bank jetton chane time invalid");
        return proto_ff::ERR_CODE_MODIFY_MONEY_TIMEOUT;
    }

    m_userData.bank_jetton += moneyChange;

    if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_TRANSFER)
    {
        if (opt_reason == proto_ff::E_TRANSFER_REASON_VIP_ZHUANCHU)
        {
            m_userData.today_vip_zhuanchu += (uint64_t)moneyChange;
            m_userData.week_vip_zhuanchu += (int64_t)moneyChange;
            m_userData.month_vip_zhuanchu += (int64_t)moneyChange;
            m_userData.all_vip_zhuanchu += (int64_t)moneyChange;
        }
        else if (opt_reason == proto_ff::E_TRANSFER_REASON_VIP_ZHUANRU
			|| opt_reason == proto_ff::E_TRANSFER_REASON_VIP_TO_VIP)
        {
            m_userData.today_vip_zhuanru += (uint64_t)moneyChange;
            m_userData.week_vip_zhuanru += (int64_t)moneyChange;
            m_userData.month_vip_zhuanru += (int64_t)moneyChange;
            m_userData.all_vip_zhuanru += (int64_t)moneyChange;
        }
    }
    else if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_DRAW)
    {
        m_userData.today_draw += (int64_t)moneyChange;
        m_userData.week_draw += (int64_t)moneyChange;
        m_userData.month_draw += (int64_t)moneyChange;
        m_userData.all_draw += (int64_t)moneyChange;
    }
    else if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_RECHARGE)
    {
        m_userData.today_recharge += (int64_t)moneyChange;
        m_userData.week_recharge += (int64_t)moneyChange;
        m_userData.month_recharge += (int64_t)moneyChange;
        m_userData.all_recharge += (int64_t)moneyChange;
    }

    MarkDirty();

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFUserDetail::HandleDeduceBankJetton(uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");

    if (moneyChange <= 0)
    {
        NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "moneyChange = 0");
        return proto_ff::ERR_CODE_MODIFY_MONEY_LESS_ZERO;
    }

    uint32_t nowTime = NFTime::Now().UnixSec();
    uint32_t timeDiff = 0;
    if (changeTime >= nowTime)
    {
        timeDiff = changeTime - nowTime;
    }
    else
    {
        timeDiff = nowTime - changeTime;
    }

    if (timeDiff > 600)
    {
        NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "the bank jetton chane time invalid");
        return proto_ff::ERR_CODE_MODIFY_MONEY_TIMEOUT;
    }

    if (m_userData.bank_jetton > moneyChange)
    {
        m_userData.bank_jetton -= moneyChange;
    }
    else
    {
        m_userData.bank_jetton = 0;
    }

    if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_TRANSFER)
    {
        if (opt_reason == proto_ff::E_TRANSFER_REASON_VIP_ZHUANCHU
			|| opt_reason == proto_ff::E_TRANSFER_REASON_VIP_TO_VIP)
        {
            m_userData.today_vip_zhuanchu += (uint64_t)moneyChange;
            m_userData.week_vip_zhuanchu += (int64_t)moneyChange;
            m_userData.month_vip_zhuanchu += (int64_t)moneyChange;
            m_userData.all_vip_zhuanchu += (int64_t)moneyChange;
        }
        else if (opt_reason == proto_ff::E_TRANSFER_REASON_VIP_ZHUANRU)
        {
            m_userData.today_vip_zhuanru += (uint64_t)moneyChange;
            m_userData.week_vip_zhuanru += (int64_t)moneyChange;
            m_userData.month_vip_zhuanru += (int64_t)moneyChange;
            m_userData.all_vip_zhuanru += (int64_t)moneyChange;
        }
    }
    else if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_DRAW)
    {
        m_userData.today_draw += (int64_t)moneyChange;
        m_userData.week_draw += (int64_t)moneyChange;
        m_userData.month_draw += (int64_t)moneyChange;
        m_userData.all_draw += (int64_t)moneyChange;
    }
    else if (opt_type == proto_ff::E_USER_JETTON_OPER_TYPE_RECHARGE)
    {
        m_userData.today_recharge += (int64_t)moneyChange;
        m_userData.week_recharge += (int64_t)moneyChange;
        m_userData.month_recharge += (int64_t)moneyChange;
        m_userData.all_recharge += (int64_t)moneyChange;
    }

    MarkDirty();

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFUserDetail::UserLogin(bool isLoadDB)
{
    SetOnlineStatus(PLAYER_STATUS_ONLINE);
    SetOnline(true);
    SetLastLoginTime(NFTime::Now().UnixSec());
    MarkDirty();

	return 0;
}

int NFUserDetail::UserLogout()
{
	return 0;
}

int NFUserDetail::UserDisConnect()
{
    switch (GetOnlineStatus())
    {
        case PLAYER_STATUS_NONE:
        case PLAYER_STATUS_ONLINE:
        {
            SetOnlineStatus(PLAYER_STATUS_OFFLINE);
            SetLastDisconnectTime(NFTime::Now().UnixSec());
            SetOnline(false);
            MarkDirty();
        }
            break;
        case PLAYER_STATUS_OFFLINE:
            break;
        case PLAYER_STATUS_LOGOUT:
        case PLAYER_STATUS_DEAD:
        default:
            break;
    }

    m_proxyBusId = 0;
    SaveToDB();
    return 0;
}

int NFUserDetail::UserReconnect()
{
    if (GetOnlineStatus() != PLAYER_STATUS_ONLINE)
    {
        SetOnlineStatus(PLAYER_STATUS_ONLINE);
        SetOnline(true);
    }
    return 0;
}

void  NFUserDetail::Tick()
{
	switch (m_iStatus)
	{
	case PLAYER_STATUS_NONE:
	{
        if ((uint64_t)NFTime::Now().UnixSec() - m_createTime < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME)
            break;

        if (m_iTransNum > 0)
        {
            if ((uint64_t)NFTime::Now().UnixSec() - m_createTime < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                break;
        }

        if (IsInGaming())
        {
            if ((uint64_t)NFTime::Now().UnixSec() - m_createTime < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                break;
        }

        SetOnlineStatus(PLAYER_STATUS_LOGOUT);
	}
	break;
	case PLAYER_STATUS_ONLINE:
	{
		LogicTick();
	}
	break;
	case PLAYER_STATUS_OFFLINE:
	{
		if ((uint64_t)NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME)
			break;

		if (m_iTransNum > 0)
        {
            if ((uint64_t)NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                break;
        }

		if (IsInGaming())
        {
            if ((uint64_t)NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                break;
        }

		SetOnlineStatus(PLAYER_STATUS_LOGOUT);
        SetLastLogoutTime(NFTime::Now().UnixSec());
	}
	break;
	case PLAYER_STATUS_LOGOUT:
	{
		if (!IsUrgentNeedSave())
		{
			if (m_iTransNum <= 0)
			{
				NFUserDetailMgr::GetInstance()->UserLogout(this);
			}
		}
		else if (!IsInSaving())
		{
		    if (m_userDetailInfoSavingDBTime + 60 < (uint64_t)NFTime::Now().UnixSec() && m_userDetailInfoSavingDBTime + 86400 > (uint64_t)NFTime::Now().UnixSec())
            {
                SaveUserDetailToDB(TRANS_SAVEROLEDETAIL_LOGOUT);
            }
		}
		break;
	}
    case PLAYER_STATUS_DEAD:
    {

    }
    default:
	break;
	}
}

void NFUserDetail::DayTick()
{
    m_userData.today_win = 0;
    m_userData.today_recharge = 0;
    m_userData.today_give = 0;
    m_userData.today_draw = 0;
    MarkDirty();
}

void NFUserDetail::WeekTick()
{
    m_userData.week_win = 0;
    m_userData.week_recharge = 0;
    m_userData.week_give = 0;
    m_userData.week_draw = 0;
    MarkDirty();
}

void NFUserDetail::MonthTick()
{
    m_userData.month_win = 0;
    m_userData.month_recharge = 0;
    m_userData.month_give = 0;
    m_userData.month_draw = 0;
    MarkDirty();
}

void NFUserDetail::LogicTick()
{
    m_eventLog.Tick(this);
}

int NFUserDetail::SendErrToClient(uint32_t nMsgId, proto_ff::Proto_CS_ErrorCode errCode)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::Proto_CSErrorRsp rspMsg;
    rspMsg.set_req_msg_id(nMsgId);
    rspMsg.set_error(errCode);

    SendMsgToClient(proto_ff::E_CS_ERROR, rspMsg);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFUserDetail::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    if (m_proxyBusId > 0)
    {
        return NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIC_SERVER, m_proxyBusId, nMsgId, xData, m_userData.userid);
    }
    NFLogDebug(NF_LOG_SYSTEMLOG, m_userData.userid, "proxy bus id error, busId:{} nMsgId:{} data:{}", m_proxyBusId, nMsgId, xData.DebugString());
    return -1;
}

int NFUserDetail::SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData) {
    return NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, nMsgId, xData);
}

int NFUserDetail::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData) {
    return NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, nMsgId, xData);
}

int NFUserDetail::SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData) {
    return NFMessageMgr::Instance()->SendMsgToGameServer(NF_ST_LOGIC_SERVER, m_gameBusId, nMsgId, xData);
}

int NFUserDetail::ChangeBankPassword(const std::string& newPass)
{
    if (newPass.size() < 6 || (int)newPass.size() >= m_userData.bank_password.MaxSize())
    {
       return proto_ff::ERR_CODE_BANK_PASSWORD_FORMAT_NOT_RIGHT;
    }

    m_userData.bank_password.Copy(newPass);
    MarkDirty();
    return 0;
}

void NFUserDetail::SetLastLoginTime(uint64_t time)
{
   m_userData.last_login_time = time;
   MarkDirty();
}

void NFUserDetail::SetLastLogoutTime(uint64_t time)
{
   m_userData.last_logout_time = time;
   MarkDirty();
}

void NFUserDetail::ClearTmpPhoneData()
{
    m_userData.misc_data.auth_code_stamp = 0;
    m_userData.misc_data.tmp_auth_code = 0;
    m_userData.misc_data.tmp_code_success = false;
    m_userData.misc_data.tmp_code_type = 0;
    m_userData.misc_data.tmp_phone_num = 0;
}

int NFUserDetail::NotifyGameMoneyChange()
{
    if (IsInGaming())
    {

    }
    return 0;
}
