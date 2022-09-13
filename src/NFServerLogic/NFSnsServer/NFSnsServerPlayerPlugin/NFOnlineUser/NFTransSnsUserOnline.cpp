// -------------------------------------------------------------------------
//    @FileName         :    NFTransSnsUserOnline.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransSnsUserOnline.cpp
//
// -------------------------------------------------------------------------

#include "NFTransSnsUserOnline.h"
#include "NFUserSimple/NFSnsUserSimpleUtil.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_common.pb.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFOnlineUser.h"
#include "NFOnlineUserMgr.h"
#include "NFUserSimple/NFSnsUserSimple.h"
#include "NFUserSimple/NFSnsUserSimpleUtil.h"
#include "NFOnlineModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransSnsUserOnline, EOT_TRANS_SNS_USER_ONLINE, NFTransSnsBase)

NFTransSnsUserOnline::NFTransSnsUserOnline() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NFTransSnsUserOnline::~NFTransSnsUserOnline() {

}

int NFTransSnsUserOnline::CreateInit() {
	m_userId = 0;
	m_logicServerId = 0;
	m_lastLoginTime = 0;
	m_lastLogoutTime = 0;
	m_cmd = 0;
    m_newPlayer = false;
	return 0;
}


int NFTransSnsUserOnline::ResumeInit() {
	return 0;
}

int NFTransSnsUserOnline::UserLogin(const proto_ff::Proto_LogicToSnsLoginReq& req)
{
	m_userId = req.player_id();
	m_query.Add(req.player_id());
	m_cmd = proto_ff::NF_LTS_PLAYER_LOGIN_REQ;
	m_logicServerId = req.logic_bus_id();
	m_lastLoginTime = req.last_login_time();
	m_lastLogoutTime = req.last_logout_time();
	proto_ff_s::UserSimpleData_s::read_from_pbmsg(req.simple_data(), m_simpleData);
	QueryRole();
	return 0;
}

int NFTransSnsUserOnline::UserModifyName(const proto_ff::LTSnsChangeNickNameNotify& req)
{
    m_userId = req.user_id();
    m_query.Add(req.user_id());
    m_cmd = proto_ff::NF_LTSns_CHANGE_NICKNAME_NOTIFY;
    m_simpleData.nickname = req.nick_name();
    QueryRole();
    return 0;
}

int NFTransSnsUserOnline::OnUserModifyName(int iRunLogicRetCode)
{
    NFSnsUserSimple*  pUserSimple = NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(m_userId, false);
    CHECK_NULL(pUserSimple);

    pUserSimple->m_userData.nickname = m_simpleData.nickname.GetString();
    pUserSimple->MarkDirty();
    return 0;
}

int NFTransSnsUserOnline::UserModifyVipLevel(const proto_ff::LTSnsChangeVipLevelNotify& req)
{
    m_userId = req.user_id();
    m_query.Add(req.user_id());
    m_cmd = proto_ff::NF_LTS_PLAYER_VIPLVEL_CHANGE_NOTIFY;
    m_simpleData.vip_level = req.vip_level();
    QueryRole();
    return 0;
}

int NFTransSnsUserOnline::UserModifyUserId(const proto_ff::LTSnsChangeUserIdNotify& req)
{
    m_userId = req.user_id();
    m_query.Add(req.user_id());
    m_cmd = proto_ff::NF_LTSns_CHANGE_USERID_NOTIFY;
    m_simpleData.show_userid = req.show_userid();
    QueryRole();
    return 0;
}

int NFTransSnsUserOnline::OnUserModifyUserId(int iRunLogicRetCode)
{
    NFSnsUserSimple*  pUserSimple = NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(m_userId, false);
    CHECK_NULL(pUserSimple);

    pUserSimple->m_userData.show_userid = m_simpleData.show_userid;
    pUserSimple->MarkDirty();
    return 0;
}

int NFTransSnsUserOnline::OnUserModifyVipLevel(int iRunLogicRetCode)
{
    NFSnsUserSimple*  pUserSimple = NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(m_userId, false);
    CHECK_NULL(pUserSimple);

    pUserSimple->m_userData.vip_level = m_simpleData.vip_level;
    pUserSimple->MarkDirty();
    return 0;
}

int NFTransSnsUserOnline::UserReconnect(const proto_ff::LTSNotifyPlayerReconnectReq& req)
{
    m_userId = req.player_id();
    m_query.Add(req.player_id());
    m_cmd = proto_ff::NF_LTS_PLAYER_RECONNECT_MSG;
    m_logicServerId = req.logic_bus_id();
    m_lastLoginTime = req.last_login_time();
    m_lastLogoutTime = req.last_logout_time();
    proto_ff_s::UserSimpleData_s::read_from_pbmsg(req.simple_data(), m_simpleData);
    QueryRole();
    return 0;
}

int  NFTransSnsUserOnline::OnUserLogin(int iRunLogicRetCode)
{
	proto_ff::Proto_SnsToLogicLoginRsp rsp;

	rsp.set_player_id(m_userId);
	rsp.set_result(proto_ff::ERR_CODE_OK);

	if (iRunLogicRetCode)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_userId, "user:{} login err:{}", m_userId, iRunLogicRetCode);
		rsp.set_result(-1);
		NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_SNS_SERVER, m_logicServerId, proto_ff::NF_STL_PLAYER_LOGIN_RSP, rsp);
		return 0;
	}

	NFOnlineUser* pUser = NFOnlineUserMgr::GetInstance()->Find(m_userId);
	if (pUser)
	{
		pUser->Init(m_userId, m_logicServerId, m_lastLoginTime, m_lastLogoutTime);
		rsp.set_result(0);
	}
	else if (NFOnlineUserMgr::GetInstance()->IsFull())
	{
	    NFLogError(NF_LOG_SYSTEMLOG, m_userId, "NFOnlineUserMgr::GetInstance()->IsFull()");
		rsp.set_result(-1);
        NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_SNS_SERVER, m_logicServerId, proto_ff::NF_STL_PLAYER_LOGIN_RSP, rsp);
		return 0;
	}
	else
	{
		pUser = NFOnlineUserMgr::GetInstance()->Insert(m_userId);
		CHECK_NULL(pUser);
		pUser->Init(m_userId, m_logicServerId, m_lastLoginTime, m_lastLogoutTime);
	}

	NFSnsUserSimple*  pUserSimple = NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(m_userId, false);
	CHECK_NULL(pUserSimple);

	pUserSimple->SetLogicRoleSimpleInfo(m_simpleData);

	FindModule<NFCOnlineModule>()->OnPlayerLogin(pUserSimple, pUser);

	if (m_newPlayer)
    {
        FindModule<NFCOnlineModule>()->OnNewPlayer(pUserSimple, pUser);
    }

    NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_SNS_SERVER, m_logicServerId, proto_ff::NF_STL_PLAYER_LOGIN_RSP, rsp);

	return 0;
}

int  NFTransSnsUserOnline::OnUserReconnect(int iRunLogicRetCode)
{
    if (iRunLogicRetCode)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_userId, "user:{} reonenct err:{}", m_userId, iRunLogicRetCode);
        return 0;
    }

    NFOnlineUser* pUser = NFOnlineUserMgr::GetInstance()->Find(m_userId);
    if (pUser)
    {
        pUser->Init(m_userId, m_logicServerId, m_lastLoginTime, m_lastLogoutTime);
    }
    else if (NFOnlineUserMgr::GetInstance()->IsFull())
    {
        return 0;
    }
    else
    {
        pUser = NFOnlineUserMgr::GetInstance()->Insert(m_userId);
        CHECK_NULL(pUser);
        pUser->Init(m_userId, m_logicServerId, m_lastLoginTime, m_lastLogoutTime);
    }

    NFSnsUserSimple*  pUserSimple = NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(m_userId, false);
    CHECK_NULL(pUserSimple);

    pUserSimple->SetLogicRoleSimpleInfo(m_simpleData);

    FindModule<NFCOnlineModule>()->OnPlayerLogin(pUserSimple, pUser);
    return 0;
}

int NFTransSnsUserOnline::QueryRole_CallBack(tagQueryRole &query) {
	NFSnsUserSimple*  pUserSimple = NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(m_userId, false);
	CHECK_NULL(pUserSimple);

	return 0;
}

int NFTransSnsUserOnline::HandleGetRoleRes(int iRunLogicRetCode, uint64_t userId) {
	if (iRunLogicRetCode == proto_ff::ERR_CODE_PLAYER_NOT_EXIST)
	{
        proto_ff_s::tbUserSimpleData_s userData_s;
        memset(&userData_s, 0, sizeof(userData_s));

		proto_ff::tbUserSimpleData userData;
        proto_ff_s::tbUserSimpleData_s::write_to_pbmsg(userData_s, userData);
		userData.set_userid(userId);
		
		return NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_SNS_SERVER,
			proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_USER_SIMPLE, NF_DEFAULT_MYSQL_DB_NAME, "tbUserSimpleData", userData,
			GetGlobalID(), 0, userId);
	}
	else
	{
		return NFTransSnsBase::HandleGetRoleRes(iRunLogicRetCode, userId);
	}

	return 0;
}

int NFTransSnsUserOnline::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
	uint32_t seq,
	uint32_t err_code) {
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");

	int iRetCode = 0;
	if (cmd == proto_ff::E_STORESVR_S2C_INSERT) {
		if (table_id == proto_ff::E_TABLE_USER_SIMPLE) {
			iRetCode = ProInsertSimpleDataRes((const storesvr_sqldata::storesvr_ins_res*)pSSMsgRes, err_code);
		}
		else
		{
			iRetCode = -1;
		}
	}
	else
	{
		iRetCode = -1;
	}
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
	return iRetCode;
}

int NFTransSnsUserOnline::OnTransFinished(int iRunLogicRetCode)
{
	if (m_cmd == proto_ff::NF_LTS_PLAYER_LOGIN_REQ)
	{
		OnUserLogin(iRunLogicRetCode);
	}
	else if (m_cmd == proto_ff::NF_LTS_PLAYER_RECONNECT_MSG)
    {
        OnUserReconnect(iRunLogicRetCode);
    }
	else if (m_cmd == proto_ff::NF_LTSns_CHANGE_NICKNAME_NOTIFY)
    {
        OnUserModifyName(iRunLogicRetCode);
    }
	else if (m_cmd == proto_ff::NF_LTSns_CHANGE_USERID_NOTIFY)
    {
        OnUserModifyUserId(iRunLogicRetCode);
    }
	else if (m_cmd == proto_ff::NF_LTS_PLAYER_VIPLVEL_CHANGE_NOTIFY)
    {
        OnUserModifyVipLevel(iRunLogicRetCode);
    }

	return 0;
}

int NFTransSnsUserOnline::ProInsertSimpleDataRes(const storesvr_sqldata::storesvr_ins_res *pRsp, uint32_t err_code)
{
	CHECK_EXPR(err_code == 0, -1, "user simple info insert failed, err_code:{}", err_code);

	m_newPlayer = true;

	QueryRole();
	return 0;
}