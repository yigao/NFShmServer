// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetUserDetail.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransGetUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFTransSaveDB.h"

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"

#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"

#include "NFUserDetail.h"
#include "NFUserDetailMgr.h"
#include "NFTransCreateUserDetail.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransSaveDB, EOT_TRANS_SAVE_USER_DETAIL, NFTransLogicUserBase)

NFTransSaveDB::NFTransSaveDB() {
	if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NFTransSaveDB::~NFTransSaveDB() {

}

int NFTransSaveDB::CreateInit() {
	return 0;
}

int NFTransSaveDB::ResumeInit() {
	return 0;
}

int NFTransSaveDB::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq) {
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTransSaveDB::HandleDispSvrRes(const google::protobuf::Message *pSSMsgRes) {
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTransSaveDB::ProHandleSaveDB(TRANS_SAVEROLEDETAIL_REASON iReason)
{
	NFUserDetail* pUser = UserDetail();
	CHECK_EXPR(pUser, -1, "Save Money Failed! Can't find user detail data, userId:", m_userId);
	
	m_reason = iReason;
	pUser->SetUserDetailSaveDBTime(NFTime::Now().UnixSec());

	proto_ff::tbUserDetailData userDetail;
	userDetail.set_userid(m_userId);
	pUser->MakeUserDataCS(userDetail);

	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Ready Create Account InTo Mysql:{}", userDetail.DebugString());

	NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                     proto_ff::E_STORESVR_C2S_MODIFYOBJ, proto_ff::E_TABLE_USER_DETAIL, NF_DEFAULT_MYSQL_DB_NAME, "tbUserDetailData", userDetail,
                                                     GetGlobalID(), pUser->GetCurSeq(), m_userId);
	return 0;
}

int NFTransSaveDB::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
	uint32_t seq,
	uint32_t err_code) {
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	int iRetCode = 0;
	if (cmd == proto_ff::E_STORESVR_S2C_MODIFYOBJ) {
		if (table_id == proto_ff::E_TABLE_USER_DETAIL) {
				iRetCode = ProSaveDBRes(err_code, seq);
		}
		else
		{
			iRetCode = -1;
			NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0,
				"Get User Detial InTo Failed From Mysql, cmd:{} tableid:{} err_code:{}", cmd, table_id,
				err_code);
		}
	}
	else
	{
		iRetCode = -1;
		NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0,
			"Get User Detial InTo Failed From Mysql, cmd:{} tableid:{} err_code:{}", cmd, table_id,
			err_code);
	}

	SetFinished(iRetCode);
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return iRetCode;
}

int NFTransSaveDB::ProSaveDBRes(uint32_t err_code, uint32_t seq)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	int iRetCode = 0;
	if (err_code == proto_ff::E_STORESVR_ERRCODE_OK) {
		NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
		if (pUserDetail) {
			pUserDetail->OnUserDetailSaved(true, seq);

			if (m_reason == TRANS_SAVEROLEDETAIL_LOGOUT && pUserDetail->GetOnlineStatus() == PLAYER_STATUS_LOGOUT)
			{
				NFUserDetailMgr::GetInstance()->UserLogout(pUserDetail);
			}
		}
	}
	else {
		iRetCode = -1;
	}

	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return iRetCode;
}

int NFTransSaveDB::HandleTransFinished(int iRunLogicRetCode) {
	if (iRunLogicRetCode != 0) {
		NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
		if (pUserDetail) {
			pUserDetail->OnUserDetailSaved(false, 0);
		}
		return -1;
	}

	return 0;
}
