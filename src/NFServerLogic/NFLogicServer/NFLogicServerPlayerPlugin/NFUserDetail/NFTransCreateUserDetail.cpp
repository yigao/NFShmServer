// -------------------------------------------------------------------------
//    @FileName         :    NFTransCreateUserDetail.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransCreateUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFTransCreateUserDetail.h"

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFTransGetUserDetail.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFCore/NFRandom.hpp"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransCreateUserDetail, EOT_TRANS_CREATE_USER_DETAIL, NFTransLogicUserBase)

NFTransCreateUserDetail::NFTransCreateUserDetail() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFTransCreateUserDetail::~NFTransCreateUserDetail() {

}

int NFTransCreateUserDetail::CreateInit() {
    return 0;
}

int NFTransCreateUserDetail::ResumeInit() {
    return 0;
}

int NFTransCreateUserDetail::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq) {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    CreateUserDetail();
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransCreateUserDetail::HandleDispSvrRes(const google::protobuf::Message *pSSMsgRes) {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransCreateUserDetail::CreateUserDetail() {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff_s::tbUserDetailData_s userDetail_s;
    memset(&userDetail_s, 0, sizeof(userDetail_s));
    proto_ff::tbUserDetailData userDetail;

    //初始化所有的变量
    proto_ff_s::tbUserDetailData_s::write_to_pbmsg(userDetail_s, userDetail);

    userDetail.set_userid(m_userId);
    userDetail.set_show_userid(m_userId);
    userDetail.set_nickname(FindModule<NFICommLogicModule>()->GetRandomName());
    userDetail.set_age(18);
    userDetail.set_gender(0);
    userDetail.set_bank_jetton(0);
    userDetail.set_isrobot(false);
    userDetail.set_regdate(NFTime::Now().UnixSec());
    userDetail.set_is_ban(0);
    userDetail.set_no_transfer(0);

    std::string init_jetton = FindModule<NFICommLogicModule>()->GetConstValue(proto_ff::EN_CONST_USER_INIT_JETTON);
    std::string init_face_vec = FindModule<NFICommLogicModule>()->GetConstValue(proto_ff::EN_CONST_USER_INIT_FACE);
    std::vector<std::string> vecFace;
    NFStringUtility::Split(init_face_vec, ",", &vecFace);
    for(int i = 0; i < (int)vecFace.size(); i++)
    {
        NFStringUtility::Trim(vecFace[i]);
    }

    int index = NFRandInt((int)0, (int)vecFace.size());
    if (index >= 0 && index < (int)vecFace.size())
    {
        userDetail.set_faceid(NFCommon::strto<uint32_t>(vecFace[index]));
    }
    else
    {
        if (vecFace.size() > 0)
        {
            userDetail.set_faceid(NFCommon::strto<uint32_t>(vecFace[0]));
        }
        else
        {
            userDetail.set_faceid(1);
        }
    }


    std::string init_bankpass = FindModule<NFICommLogicModule>()->GetConstValue(proto_ff::EN_CONST_USER_INIT_BANK_JETTON);
    userDetail.set_jetton(NFCommon::strto<uint64_t>(init_jetton));
    userDetail.set_bank_password(init_bankpass);

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Ready Create Account InTo Mysql:{}", userDetail.DebugString());

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                           proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_USER_DETAIL, NF_DEFAULT_MYSQL_DB_NAME, "tbUserDetailData", userDetail,
                                                           GetGlobalID(), 0, m_userId);
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransCreateUserDetail::CreateUserDetail(const std::string& nickName, uint64_t phoneNum, const proto_ff_s::LoginCommonData_s& loginData)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff_s::tbUserDetailData_s userDetail_s;
    memset(&userDetail_s, 0, sizeof(userDetail_s));
    proto_ff::tbUserDetailData userDetail;

    //初始化所有的变量
    proto_ff_s::tbUserDetailData_s::write_to_pbmsg(userDetail_s, userDetail);

    userDetail.set_userid(m_userId);
    userDetail.set_show_userid(m_userId);
    if (nickName.empty())
    {
        userDetail.set_nickname(FindModule<NFICommLogicModule>()->GetRandomName());
    }
    else
    {
        userDetail.set_nickname(nickName);
    }
    userDetail.set_age(18);
    userDetail.set_gender(0);
    userDetail.set_bank_jetton(0);
    userDetail.set_isrobot(false);
    userDetail.set_regdate(NFTime::Now().UnixSec());
    userDetail.set_phonenum(phoneNum);
    userDetail.set_aread_id(loginData.aread_id);
    userDetail.set_agent_id(loginData.agent_id);
    userDetail.set_channel_id(loginData.channel_id);
    userDetail.set_referrer_id(loginData.referral_code);
    userDetail.set_platform_os(loginData.platform_os.GetString());
    userDetail.set_country(loginData.country.GetString());
    userDetail.set_city(loginData.city.GetString());
    userDetail.set_province(loginData.province.GetString());
    userDetail.set_ip(loginData.ip.GetString());
    userDetail.set_phone_model(loginData.phone_mode.GetString());
    userDetail.set_is_ban(0);
    userDetail.set_no_transfer(0);
    userDetail.set_device_id(loginData.device_id.GetString());
    userDetail.set_reg_ip(loginData.ip.GetString());
    userDetail.set_reg_device_id(loginData.device_id.GetString());

    std::string init_jetton = FindModule<NFICommLogicModule>()->GetConstValue(proto_ff::EN_CONST_USER_INIT_JETTON);
    std::string init_face_vec = FindModule<NFICommLogicModule>()->GetConstValue(proto_ff::EN_CONST_USER_INIT_FACE);
    std::vector<std::string> vecFace;
    NFStringUtility::Split(init_face_vec, ",", &vecFace);
    for(int i = 0; i < (int)vecFace.size(); i++)
    {
        NFStringUtility::Trim(vecFace[i]);
    }

    int index = NFRandInt((int)0, (int)vecFace.size());
    if (index >= 0 && index < (int)vecFace.size())
    {
        userDetail.set_faceid(NFCommon::strto<uint32_t>(vecFace[index]));
    }
    else
    {
        if (vecFace.size() > 0)
        {
            userDetail.set_faceid(NFCommon::strto<uint32_t>(vecFace[0]));
        }
        else
        {
            userDetail.set_faceid(1);
        }
    }


    std::string init_bankpass = FindModule<NFICommLogicModule>()->GetConstValue(proto_ff::EN_CONST_USER_INIT_BANK_JETTON);
    userDetail.set_jetton(NFCommon::strto<uint64_t>(init_jetton));
    userDetail.set_bank_password(init_bankpass);

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Ready Create Account InTo Mysql:{}", userDetail.DebugString());

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                     proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_USER_DETAIL, NF_DEFAULT_MYSQL_DB_NAME, "tbUserDetailData", userDetail,
                                                     GetGlobalID(), 0, m_userId);
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransCreateUserDetail::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                         uint32_t seq,
                                         uint32_t err_code) {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    if (cmd == proto_ff::E_STORESVR_S2C_INSERT) {
        if (table_id == proto_ff::E_TABLE_USER_DETAIL) {
            const storesvr_sqldata::storesvr_ins_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_ins_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            if (err_code != 0) {
                NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Create User Detial InTo Failed From Mysql, cmd:{} tableid:{} err_code:{}", cmd, table_id, err_code);

                SetFinished(0);
                return 0;
            }

            NFTransGetUserDetail* pTrans = (NFTransGetUserDetail *) NFShmMgr::Instance()->GetTrans(m_reqTransId);
            CHECK_EXPR(pTrans, ERR_TRANS_RUNED_TOO_MUCH, "Get NFTransGetUserDetail Trans Failed! Maybe timeout, Used Item:{}",
                       NFTransGetUserDetail::GetUsedCount());

            pTrans->Init(m_userId, m_cmd);
            int iRetCode = pTrans->ProGetUserDetailReq();
            if (iRetCode) {
                pTrans->SetFinished(iRetCode);
                return iRetCode;
            }
            SetFinished(0);
            return 0;
        }
    }
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransCreateUserDetail::OnTransFinished(int iRunLogicRetCode) {
    return 0;
}

