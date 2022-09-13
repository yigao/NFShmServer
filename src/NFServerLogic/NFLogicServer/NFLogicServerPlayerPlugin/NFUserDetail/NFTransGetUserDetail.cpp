// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetUserDetail.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransGetUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFTransGetUserDetail.h"

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"

#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"

#include "NFUserDetail.h"
#include "NFUserDetailMgr.h"
#include "NFTransCreateUserDetail.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransGetUserDetail, EOT_TRANS_GET_USER_DETAIL, NFTransLogicUserBase)

NFTransGetUserDetail::NFTransGetUserDetail() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFTransGetUserDetail::~NFTransGetUserDetail() {

}

int NFTransGetUserDetail::CreateInit() {
	m_add = false;
	m_moneyChange = 0;
	m_gameId = 0;
	m_roomId = 0;
	m_deskId = 0;
	m_chairId = 0;
	m_accountType = 0;
	m_optType = 0;
	m_optReason = 0;
	m_gameBusId = 0;
    m_proxyBusId = 0;
	m_changeTime = 0;
    m_isLoadDB = false;
    m_loginBusId = 0;
    m_loginReqTransId = 0;
    m_phoneNum = 0;
    memset(&m_loginData, 0, sizeof(m_loginData));
    m_agentId = 0;
    return 0;
}

int NFTransGetUserDetail::ResumeInit() {
    return 0;
}

int NFTransGetUserDetail::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq) {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

	switch (m_cmd)
	{
	case proto_ff::NF_WTL_PLAYER_LOGIN_REQ:
	{
		const proto_ff::Proto_WorldToLogicLoginReq *pLoginReq = dynamic_cast<const proto_ff::Proto_WorldToLogicLoginReq *>(pCSMsgReq);
		CHECK_EXPR(pLoginReq, -1, "pLoginReq = NULL");

		ProGetUserDetailReq(pLoginReq);
	}
		break;
    case proto_ff::NF_WTL_REGISTER_USER_TO_LOGIC_REQ:
    {
        const proto_ff::Proto_WTLRegisterUserReq *pLoginReq = dynamic_cast<const proto_ff::Proto_WTLRegisterUserReq *>(pCSMsgReq);
        CHECK_EXPR(pLoginReq, -1, "pLoginReq = NULL");

        ProGetUserDetailReq(pLoginReq);
    }
    break;
    case proto_ff::NF_SNSTLOGIC_CHANGE_AGENT_NOTIFY:
    {
        const proto_ff::Proto_NotifyChangeAgent *pLoginReq = dynamic_cast<const proto_ff::Proto_NotifyChangeAgent *>(pCSMsgReq);
        CHECK_EXPR(pLoginReq, -1, "pLoginReq = NULL");

        ProGetUserDetailReq(pLoginReq);
    }
    break;
	case proto_ff::NF_LTL_PLAYER_DEVICE_CHANGE_NOTIFY:
    {
        const proto_ff::LTLPlayerDeviceChangeNotify *pLoginReq = dynamic_cast<const proto_ff::LTLPlayerDeviceChangeNotify *>(pCSMsgReq);
        CHECK_EXPR(pLoginReq, -1, "pLoginReq = NULL");

        ProGetUserDetailReq(pLoginReq);
    }
    break;
	default:
		ProGetUserDetailReq();
		break;
	}

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetUserDetail::ProGetUserDetailReq() {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::tbUserDetailData userDetail;
    userDetail.set_userid(m_userId);

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                           proto_ff::E_STORESVR_C2S_SELECTOBJ,
                                                           proto_ff::E_TABLE_USER_DETAIL, NF_DEFAULT_MYSQL_DB_NAME, "tbUserDetailData",
                                                           userDetail,
                                                           GetGlobalID(), 0, m_userId);
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetUserDetail::ProGetUserDetailReq(const proto_ff::Proto_WTLRegisterUserReq *pLoginReq)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pLoginReq, -1, "pLoginReq = NULL");

    m_loginBusId = pLoginReq->login_bus_id();
    m_loginReqTransId = pLoginReq->req_trans_id();
    mNickName.Copy(pLoginReq->nick_name());
    m_phoneNum = pLoginReq->phone_num();
    proto_ff_s::LoginCommonData_s::read_from_pbmsg(pLoginReq->ext_data(), m_loginData);

    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
    if (pUserDetail) {
        SetFinished(0);
    }
    else
    {
        ProGetUserDetailReq();
    }
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetUserDetail::ProGetUserDetailReq(const proto_ff::LTLPlayerDeviceChangeNotify* pNotify)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pNotify, -1, "pNotify = NULL");

    m_loginData.device_id = pNotify->device_id();

    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
    if (pUserDetail) {
        SetFinished(0);
    }
    else
    {
        ProGetUserDetailReq();
    }
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetUserDetail::ProGetUserDetailReq(const proto_ff::Proto_WorldToLogicLoginReq *pLoginReq) {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pLoginReq, -1, "pLoginReq = NULL");
	
	m_gameId = pLoginReq->game_id();
	m_roomId = pLoginReq->room_id();
	m_gameBusId = pLoginReq->game_bus_id();
	m_proxyBusId = pLoginReq->proxy_bus_id();
    m_loginData.aread_id = pLoginReq->ext_data().aread_id();
    m_loginData.agent_id = pLoginReq->ext_data().agent_id();
    m_loginData.channel_id = pLoginReq->ext_data().channel_id();
    m_loginData.referral_code = pLoginReq->ext_data().referral_code();
    m_loginData.platform_os.Copy(pLoginReq->ext_data().platform_os());
    m_loginData.country.Copy(pLoginReq->ext_data().country());
    m_loginData.province.Copy(pLoginReq->ext_data().province());
    m_loginData.city.Copy(pLoginReq->ext_data().city());
    m_loginData.ip.Copy(pLoginReq->client_ip());
    m_loginData.phone_mode.Copy(pLoginReq->ext_data().phone_mode());
    m_loginData.device_id.Copy(pLoginReq->ext_data().device_id());

    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
    if (pUserDetail) {
        SetFinished(0);
    }
    else
    {
        ProGetUserDetailReq();
    }
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetUserDetail::ProGetUserDetailReq(const proto_ff::Proto_NotifyChangeAgent *pJettonReq)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pJettonReq, -1, "pJettonReq = NULL");

    m_agentId = pJettonReq->agent_id();
    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
    if (pUserDetail) {
        SetFinished(0);
    }
    else
    {
        ProGetUserDetailReq();
    }
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetUserDetail::ProGetUserDetailReq(uint64_t moneyChange, uint32_t optType, uint32_t optReason, uint32_t changeTime)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    m_moneyChange = moneyChange;
    m_optType = optType;
    m_optReason = optReason;
    m_changeTime = changeTime;
    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
    if (pUserDetail) {
        SetFinished(0);
    }
    else
    {
        ProGetUserDetailReq();
    }
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetUserDetail::CreateUserDetail() {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    NFTransCreateUserDetail *pTrans = (NFTransCreateUserDetail *) NFShmMgr::Instance()->CreateTrans(
            EOT_TRANS_CREATE_USER_DETAIL);
    CHECK_EXPR(pTrans, ERR_TRANS_RUNED_TOO_MUCH, "Create NFTransGetUserDetail Trans Failed! Used Item:{}",
               NFTransCreateUserDetail::GetUsedCount());

    pTrans->Init(m_userId, m_cmd, 0, GetGlobalID());
    int iRetCode = pTrans->CreateUserDetail(mNickName.GetString(), m_phoneNum, m_loginData);
    if (iRetCode) {
        pTrans->SetFinished(iRetCode);
        return iRetCode;
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetUserDetail::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                         uint32_t seq,
                                         uint32_t err_code) {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    if (cmd == proto_ff::E_STORESVR_S2C_SELECTOBJ) {
        if (table_id == proto_ff::E_TABLE_USER_DETAIL) {
            const storesvr_sqldata::storesvr_selobj_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_selobj_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            if (err_code != 0) {
                if (err_code == proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY) {
                    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "userId:{} not exist in db", m_userId);
					if (m_cmd == proto_ff::NF_WTL_PLAYER_LOGIN_REQ || m_cmd == proto_ff::NF_WTL_REGISTER_USER_TO_LOGIC_REQ)
					{
						CreateUserDetail();
						return 0;
					}
					else
					{
						SetFinished(-1);
					}
                    return 0;
                } else {
                    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0,
                               "Get User Detial InTo Failed From Mysql, cmd:{} tableid:{} err_code:{}", cmd, table_id,
                               err_code);

                    SetFinished(-1);
                    return 0;
                }
            }

            proto_ff::tbUserDetailData userDetail;
            userDetail.ParseFromString(pRes->sel_record());

            NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
            if (pUserDetail) {
                pUserDetail->InitUserDetailData(userDetail);
            } else {
                m_isLoadDB = true;
                pUserDetail = NFUserDetailMgr::GetInstance()->CreateUser(m_userId);
                if (pUserDetail) {
                    pUserDetail->InitUserDetailData(userDetail);
                } else {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "NFUserDetailHashTable Create UserDetail Failed!");
                    SetFinished(-1);
                    return 0;
                }
            }

            SetFinished(0);
            return 0;
        }
    }
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetUserDetail::HandleTransFinished(int iRunLogicRetCode) {
    if (iRunLogicRetCode != 0) {
        if (m_cmd == proto_ff::NF_WTL_PLAYER_LOGIN_REQ) {
			proto_ff::Proto_LogicToWorldLoginRsp rspMsg;
			rspMsg.set_user_id(m_userId);
			rspMsg.set_result(iRunLogicRetCode);
			NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTW_PLAYER_LOGIN_RSP, rspMsg);
        }
        else if (m_cmd == proto_ff::NF_WTL_REGISTER_USER_TO_LOGIC_REQ)
        {
            proto_ff::Proto_LTLRegisterUserRsp rspMsg;
            rspMsg.set_result(iRunLogicRetCode);
            rspMsg.set_user_id(m_userId);

            NFMessageMgr::Instance()->SendTransToLoginServer(NF_ST_LOGIC_SERVER, m_loginBusId, proto_ff::NF_LTL_REGISTER_USER_TO_LOGIN_RSP, rspMsg, 0, m_loginReqTransId);
        }

        return -1;
    }

    if (m_cmd == proto_ff::NF_WTL_REGISTER_USER_TO_LOGIC_REQ) {
        NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
        if (pUserDetail) {
            pUserDetail->m_userData.nickname = mNickName;
            pUserDetail->m_userData.phonenum = m_phoneNum;
            pUserDetail->m_userData.country = m_loginData.country;
            pUserDetail->m_userData.province = m_loginData.province;
            pUserDetail->m_userData.city = m_loginData.city;
            pUserDetail->m_userData.aread_id = m_loginData.aread_id;
            pUserDetail->m_userData.channel_id = m_loginData.channel_id;
            pUserDetail->m_userData.platform_os = m_loginData.platform_os;
            pUserDetail->m_userData.phone_model = m_loginData.phone_mode;
            pUserDetail->SetOnlineStatus(PLAYER_STATUS_NONE);
            pUserDetail->MarkDirty();

            proto_ff::Proto_LTLRegisterUserRsp rspMsg;
            rspMsg.set_result(0);
            rspMsg.set_user_id(m_userId);

            NFMessageMgr::Instance()->SendTransToLoginServer(NF_ST_LOGIC_SERVER, m_loginBusId, proto_ff::NF_LTL_REGISTER_USER_TO_LOGIN_RSP, rspMsg, 0, m_loginReqTransId);
        }
    }
    else if (m_cmd == proto_ff::NF_WTL_PLAYER_LOGIN_REQ) {
        NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
        if (pUserDetail) {
			pUserDetail->m_userData.game_id = m_gameId;
			pUserDetail->m_userData.room_id = m_roomId;
			pUserDetail->m_gameBusId = m_gameBusId;
			pUserDetail->m_proxyBusId = m_proxyBusId;
			pUserDetail->m_userData.ip = m_loginData.ip;
			pUserDetail->m_userData.country = m_loginData.country;
			pUserDetail->m_userData.province = m_loginData.province;
			pUserDetail->m_userData.city = m_loginData.city;
			pUserDetail->m_userData.aread_id = m_loginData.aread_id;
			pUserDetail->m_userData.channel_id = m_loginData.channel_id;
			pUserDetail->m_userData.platform_os = m_loginData.platform_os;
			pUserDetail->m_userData.phone_model = m_loginData.phone_mode;
			pUserDetail->SetOnlineStatus(PLAYER_STATUS_ONLINE);
            pUserDetail->MarkDirty();

            pUserDetail->SetOnline(true);

            proto_ff::Proto_LogicToWorldLoginRsp rspMsg;
            rspMsg.set_result(0);

            rspMsg.set_user_id(m_userId);
            if (pUserDetail->m_userData.is_ban > 0)
            {
                rspMsg.set_result(proto_ff::ERR_CODE_USER_IS_BAN);
                NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTW_PLAYER_LOGIN_RSP, rspMsg);
            }
            else
            {
                auto pDetailData = rspMsg.mutable_detail_data();
                pDetailData->set_nick_name(pUserDetail->GetNickName());
                pDetailData->set_face_id(pUserDetail->GetFaceId());
                pDetailData->set_gender(pUserDetail->GetGender());
                pDetailData->set_jetton(pUserDetail->GetJetton());
                pDetailData->set_bank_jetton(pUserDetail->GetBankJetton());
                pDetailData->set_agent_id(pUserDetail->GetAgentId());
                pDetailData->set_phonenum(pUserDetail->GetPhonenum());
                pDetailData->set_vip_level(pUserDetail->GetVipLevel());
                pDetailData->set_aread_id(pUserDetail->GetAreadId());
                pDetailData->set_referrer_id(pUserDetail->GetRefererId());
                pDetailData->set_first_recharge(pUserDetail->IsFirstRecharge());
                pDetailData->set_show_userid(pUserDetail->GetShowUserId());
                NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTW_PLAYER_LOGIN_RSP, rspMsg);

                NFUserDetailMgr::GetInstance()->UserLogin(pUserDetail, m_isLoadDB);
            }
        }
    }
	else if (m_cmd == proto_ff::NF_SNSTLOGIC_CHANGE_AGENT_NOTIFY)
    {
        NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
        if (pUserDetail) {
            pUserDetail->m_userData.agent_id = m_agentId;
            pUserDetail->MarkDirty();
            pUserDetail->SaveToDB(TRANS_SAVEROLEDETAIL_NORMAL, true);
        }
    }
	else if (m_cmd == proto_ff::NF_LTL_PLAYER_DEVICE_CHANGE_NOTIFY)
    {
        NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
        if (pUserDetail) {
            pUserDetail->m_userData.device_id = m_loginData.device_id.GetString();
            pUserDetail->MarkDirty();
            pUserDetail->SaveToDB(TRANS_SAVEROLEDETAIL_NORMAL, true);
        }
    }

    return 0;
}
