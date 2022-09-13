// -------------------------------------------------------------------------
//    @FileName         :    NFTransCreateRobot.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransCreateRobot.cpp
//
// -------------------------------------------------------------------------

#include "NFTransCreateRobot.h"

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_game.pb.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFCore/NFMD5.h"

#include "NFGameSession.h"
#include "NFGameSessionMgr.h"
#include "NFGameRoom.h"
#include "NFGameRoomMgr.h"
#include "NFGameDesk.h"
#include "NFGameRobotMgr.h"
#include "NFGameRobot.h"
#include "NFRobotMgr.h"
#include "NFRobotCommon.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransCreateRobot, EOT_GAME_CREATE_ROBOT_TRANS_ID, NFTransBase)

NFTransCreateRobot::NFTransCreateRobot() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFTransCreateRobot::~NFTransCreateRobot() {

}

int NFTransCreateRobot::CreateInit() {
    m_userId = 0;
    m_gameId = 0;
    m_roomId = 0;
    return 0;
}

int NFTransCreateRobot::ResumeInit() {
    return 0;
}

int NFTransCreateRobot::HandleTransFinished(int iRunLogicRetCode) {
    return 0;
}

int NFTransCreateRobot::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                       uint32_t seq, uint32_t err_code) {
    int iRetCode = 0;
    if (cmd == proto_ff::E_STORESVR_S2C_INSERT) {
        if (table_id == proto_ff::E_TABLE_ACCOUNT_PLAYER) {
            const storesvr_sqldata::storesvr_ins_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_ins_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");
            if (err_code != 0) {
                NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "Create Robot Account Failed From Mysql, cmd:{} tableid:{} err_code:{}", cmd, table_id, err_code);
                return -1;
            }

            iRetCode = ProGetAccountInfoReq();
        }
        else if (table_id == proto_ff::E_TABLE_USER_DETAIL) {
            const storesvr_sqldata::storesvr_ins_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_ins_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            if (err_code != 0) {
                NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "Create Robot Detial InTo Failed From Mysql, cmd:{} tableid:{} err_code:{}", cmd, table_id, err_code);
                return -1;
            }

            iRetCode = ProGetDetailInfoReq();
        }
        else if (table_id == proto_ff::E_TABLE_USER_SIMPLE) {
            const storesvr_sqldata::storesvr_ins_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_ins_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            if (err_code != 0) {
                NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "Create Robot SimpleData InTo Failed From Mysql, cmd:{} tableid:{} err_code:{}", cmd, table_id, err_code);
                return -1;
            }

            iRetCode = ProGetSimpleInfoReq();
        }
    }
    else if (cmd == proto_ff::E_STORESVR_S2C_SELECTOBJ) {
        if (table_id == proto_ff::E_TABLE_ACCOUNT_PLAYER) {
            const storesvr_sqldata::storesvr_selobj_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_selobj_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            iRetCode = ProGetAccountInfoRes(pRes, cmd, table_id, err_code);
        }
        else if (table_id == proto_ff::E_TABLE_USER_DETAIL) {
            const storesvr_sqldata::storesvr_selobj_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_selobj_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            iRetCode = ProGetDetailInfoRes(pRes, cmd, table_id, err_code);
        }
        else if (table_id == proto_ff::E_TABLE_USER_SIMPLE) {
            const storesvr_sqldata::storesvr_selobj_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_selobj_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            iRetCode = ProGetSimpleInfoRes(pRes, cmd, table_id, err_code);
        }
    }

    return iRetCode;
}

int NFTransCreateRobot::ProGetSimpleInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    if (err_code != 0)
    {
        return -1;
    }

    proto_ff::tbUserSimpleData simpleData;
    bool ok = simpleData.ParseFromString(pSelRsp->sel_record());
    CHECK_EXPR(ok, -1, "ParseFromString Faield!");

    std::string init_jetton = FindModule<NFICommLogicModule>()->GetConstValue(proto_ff::EN_CONST_USER_INIT_JETTON);

    NFRobotCommon* pRobotCommon = NFRobotMgr::Instance()->GetRobotCommon(m_gameId, m_roomId);
    if (pRobotCommon)
    {
        pRobotCommon->AddRobot(simpleData.userid(), simpleData.nickname(), simpleData.face(), simpleData.age(), simpleData.gender(), NFCommon::strto<uint64_t>(init_jetton));
    }

    SetFinished(0);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransCreateRobot::ProGetDetailInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    if (err_code != 0)
    {
        return -1;
    }

    proto_ff::tbUserDetailData userDetail;
    userDetail.ParseFromString(pSelRsp->sel_record());

    CreateRobotSimpleDetail(userDetail);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransCreateRobot::ProGetAccountInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    if (err_code != 0)
    {
        return -1;
    }

    proto_ff::tbAccountTable accountInfo;
    accountInfo.ParseFromString(pSelRsp->sel_record());

    m_userId = accountInfo.player_id();
    CreateRobotDetail();
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransCreateRobot::CreateRobotDetail()
{
    proto_ff::tbUserDetailData userDetail;
    userDetail.set_userid(m_userId);
    userDetail.set_isrobot(true);
    userDetail.set_nickname(FindModule<NFICommLogicModule>()->GetRandomName());
    userDetail.set_age(18);
    userDetail.set_gender(0);
    userDetail.set_bank_jetton(0);
    userDetail.set_isrobot(true);
    userDetail.set_regdate(NFTime::Now().UnixSec());
    userDetail.set_phonenum(123456789);

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
    userDetail.set_jetton(0);
    userDetail.set_bank_password(init_bankpass);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "Ready Create Robot Deail InTo Mysql:{}", userDetail.DebugString());

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_GAME_SERVER,
                                                     proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_USER_DETAIL, NF_DEFAULT_MYSQL_DB_NAME, "tbUserDetailData", userDetail,
                                                     GetGlobalID(), 0, m_userId);

    return 0;
}

int NFTransCreateRobot::CreateRobotSimpleDetail(const proto_ff::tbUserDetailData& userDetail)
{
    proto_ff::tbUserSimpleData userData;
    userData.set_userid(userDetail.userid());
    userData.set_nickname(userDetail.nickname());
    userData.set_face(userDetail.faceid());
    userData.set_age(userDetail.age());
    userData.set_create_time(NFTime::Now().UnixSec());
    userData.set_gender(userDetail.gender());
    userData.set_is_robot(true);

    return NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_GAME_SERVER,
                                                            proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_USER_SIMPLE, NF_DEFAULT_MYSQL_DB_NAME, "tbUserSimpleData", userData,
                                                            GetGlobalID(), 0, userDetail.userid());
    return 0;
}

int NFTransCreateRobot::ProCreateAccountRes(const storesvr_sqldata::storesvr_ins_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    if (err_code != 0)
    {
        NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "Create Robot Account Failed In Mysql, Account:{}", mAccount.GetString());
        return -1;
    }

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "Create Robot Account Success In Mysql, Account:{}", mAccount.GetString());

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return ProGetAccountInfoReq();
}

int NFTransCreateRobot::ProGetAccountInfoReq()
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::tbAccountTable accountInfo;
    accountInfo.set_account(mAccount.GetString());

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_GAME_SERVER,
                                                     proto_ff::E_STORESVR_C2S_SELECTOBJ, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
                                                     GetGlobalID());
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransCreateRobot::ProGetDetailInfoReq()
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::tbUserDetailData userDetail;
    userDetail.set_userid(m_userId);

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_GAME_SERVER,
                                                     proto_ff::E_STORESVR_C2S_SELECTOBJ,
                                                     proto_ff::E_TABLE_USER_DETAIL, NF_DEFAULT_MYSQL_DB_NAME, "tbUserDetailData",
                                                     userDetail,
                                                     GetGlobalID(), 0, m_userId);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransCreateRobot::ProGetSimpleInfoReq()
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::tbUserSimpleData userSimple;
    userSimple.set_userid(m_userId);

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_GAME_SERVER,
                                                     proto_ff::E_STORESVR_C2S_SELECTOBJ, proto_ff::E_TABLE_USER_SIMPLE, NF_DEFAULT_MYSQL_DB_NAME, "tbUserSimpleData", userSimple,
                                                     GetGlobalID(), 0, m_userId);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransCreateRobot::CreateRobotAccount() {
    mAccount = NFMD5::md5str(NFConfigMgr::Instance()->GetGameDbName(NF_ST_GAME_SERVER) + "_robot_" + NFRandomString(8) + NFCommon::tostr(NFGetTime()));
    proto_ff::tbAccountTable accountInfo;
    accountInfo.set_account(mAccount.GetString());
    accountInfo.set_password(NFMD5::md5str(accountInfo.account() + NFRandomString(8)));
    accountInfo.set_account_type(proto_ff::E_ROBOT);
    accountInfo.set_device_id(NFMD5::md5str(accountInfo.password() + NFRandomString(8)));
    accountInfo.set_phonenum(123456789);
    accountInfo.set_real_player_id(1);

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Ready Create Robot Account InTo Mysql:{}", accountInfo.DebugString());

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_GAME_SERVER,
                                                     proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
                                                     GetGlobalID());
    return 0;
}

int NFTransCreateRobot::Init(uint32_t gameId, uint32_t roomId)
{
    m_gameId = gameId;
    m_roomId = roomId;
    CreateRobotAccount();
    return 0;
}

