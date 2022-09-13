// -------------------------------------------------------------------------
//    @FileName         :    NFTransSaveSimpleDB.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransSaveSimpleDB.cpp
//
// -------------------------------------------------------------------------

#include "NFTransSaveSimpleDB.h"

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"

#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"

#include "NFSnsUserSimple.h"
#include "NFSnsUserSimpleUtil.h"


IMPLEMENT_IDCREATE_WITHTYPE(NFTransSaveSimpleDB, EOT_TRANS_SAVE_USER_SIMPLEL, NFTransBase)

NFTransSaveSimpleDB::NFTransSaveSimpleDB() {
	if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NFTransSaveSimpleDB::~NFTransSaveSimpleDB() {

}

int NFTransSaveSimpleDB::CreateInit() {
	m_userId = 0;
	return 0;
}

int NFTransSaveSimpleDB::ResumeInit() {
	return 0;
}

int NFTransSaveSimpleDB::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq) {
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTransSaveSimpleDB::HandleDispSvrRes(const google::protobuf::Message *pSSMsgRes) {
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTransSaveSimpleDB::Init(NFSnsUserSimple* pUser)
{
	CHECK_NULL(pUser);
	m_userId = pUser->GetUserId();
	return 0;
}

NFSnsUserSimple* NFTransSaveSimpleDB::UserSimple()
{
	return NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(m_userId, false);
}

int NFTransSaveSimpleDB::ProHandleSaveDB()
{
	NFSnsUserSimple* pUser = UserSimple();
	CHECK_EXPR(pUser, -1, "Save simple Failed! Can't find user simple data, userId:", m_userId);

	proto_ff::tbUserSimpleData userSimple;
	userSimple.set_userid(m_userId);
	pUser->MakeUserDataCS(userSimple);


	NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_SNS_SERVER,
                                                     proto_ff::E_STORESVR_C2S_MODIFYOBJ, proto_ff::E_TABLE_USER_SIMPLE, NF_DEFAULT_MYSQL_DB_NAME, "tbUserSimpleData", userSimple,
                                                     GetGlobalID(), pUser->GetCurSeq(), m_userId);
	return 0;
}

int NFTransSaveSimpleDB::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
	uint32_t seq,
	uint32_t err_code) {
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	int iRetCode = 0;
	if (cmd == proto_ff::E_STORESVR_S2C_MODIFYOBJ) {
		if (table_id == proto_ff::E_TABLE_USER_SIMPLE) {
			iRetCode = ProSaveDBRes(err_code, seq);
		}
		else
		{
			iRetCode = -1;
			NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0,
				"Get User Simple InTo Failed From Mysql, cmd:{} tableid:{} err_code:{}", cmd, table_id,
				err_code);
		}
	}
	else
	{
		iRetCode = -1;
		NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0,
			"Get User Simple InTo Failed From Mysql, cmd:{} tableid:{} err_code:{}", cmd, table_id,
			err_code);
	}

	SetFinished(iRetCode);
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return iRetCode;
}

int NFTransSaveSimpleDB::ProSaveDBRes(uint32_t err_code, uint32_t seq)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	int iRetCode = 0;
	if (err_code == proto_ff::E_STORESVR_ERRCODE_OK) {
		NFSnsUserSimple* pUser = UserSimple();
		if (pUser) {
			pUser->OnUserSimpleSaved(true, seq);
		}
	}
	else {
		iRetCode = -1;
	}

	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return iRetCode;
}

int NFTransSaveSimpleDB::HandleTransFinished(int iRunLogicRetCode) {
	if (iRunLogicRetCode != 0) {
		NFSnsUserSimple* pUser = UserSimple();
		if (pUser) {
			pUser->OnUserSimpleSaved(false, 0);
		}
		return -1;
	}

	return 0;
}
