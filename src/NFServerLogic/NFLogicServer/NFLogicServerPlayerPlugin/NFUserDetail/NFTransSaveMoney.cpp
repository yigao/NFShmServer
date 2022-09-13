// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetUserDetail.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransGetUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFTransSaveMoney.h"

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"

#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"

#include "NFUserDetail.h"
#include "NFUserDetailMgr.h"
#include "NFTransCreateUserDetail.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransSaveMoney, EOT_TRANS_SAVE_USER_MONEY, NFTransLogicUserBase)

NFTransSaveMoney::NFTransSaveMoney() {
	if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NFTransSaveMoney::~NFTransSaveMoney() {

}

int NFTransSaveMoney::CreateInit() {
	return 0;
}

int NFTransSaveMoney::ResumeInit() {
	return 0;
}

int NFTransSaveMoney::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq) {
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTransSaveMoney::HandleDispSvrRes(const google::protobuf::Message *pSSMsgRes) {
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTransSaveMoney::ProHandleSaveMoney()
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

	NFUserDetail* pUser = UserDetail();
	CHECK_EXPR(pUser, -1, "Save Money Failed! Can't find user detail data, userId:", m_userId);

	proto_ff::tbUserDetailData userDetail;
	userDetail.set_userid(m_userId);
	userDetail.set_jetton(pUser->GetJetton());
	userDetail.set_bank_jetton(pUser->GetBankJetton());

	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Ready Create Account InTo Mysql:{}", userDetail.DebugString());

	NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                     proto_ff::E_STORESVR_C2S_MODIFYOBJ, proto_ff::E_TABLE_USER_DETAIL, NF_DEFAULT_MYSQL_DB_NAME, "tbUserDetailData", userDetail,
                                                     GetGlobalID(), 0, m_userId);
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTransSaveMoney::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
	uint32_t seq,
	uint32_t err_code) {
	if (cmd == proto_ff::E_STORESVR_S2C_MODIFYOBJ) {
		if (table_id == proto_ff::E_TABLE_USER_DETAIL) {
			const storesvr_sqldata::storesvr_modobj_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_modobj_res *>(pSSMsgRes);
			CHECK_EXPR(pRes, -1, "pRes == NULL");

			if (err_code != 0) {
				NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0,
					"NFTransSaveMoney Failed From Mysql, cmd:{} tableid:{} err_code:{}", cmd, table_id,
					err_code);

				SetFinished(-1);
				return 0;
			}

			SetFinished(0);
			return 0;
		}
	}
	return 0;
}

int NFTransSaveMoney::HandleTransFinished(int iRunLogicRetCode) {
	if (iRunLogicRetCode != 0) {
		return -1;
	}

	return 0;
}
