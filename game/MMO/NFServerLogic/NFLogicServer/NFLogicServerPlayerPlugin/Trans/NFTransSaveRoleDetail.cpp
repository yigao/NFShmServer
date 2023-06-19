// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetUserDetail.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransGetUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFTransSaveRoleDetail.h"

#include <NFServerComm/NFServerCommon/NFIServerMessageModule.h>
#include <NFComm/NFPluginModule/NFIConfigModule.h>
#include <NFComm/NFCore/NFCommon.h>
#include <ClientServer.pb.h>
#include <ServerInternal.pb.h>
#include <ServerInternalCmd.pb.h>
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFLogicCommon/NFICommLogicModule.h"
#include "Player/NFPlayer.h"
#include "Player/NFPlayerMgr.h"
#include "ServerInternal2.pb.h"
#include "ServerInternalCmd2.pb.h"
#include "DBProto2.pb.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"


IMPLEMENT_IDCREATE_WITHTYPE(NFTransSaveRoleDetail, EOT_TRANS_LOGIC_SAVE_ROLE, NFTransBase)

NFTransSaveRoleDetail::NFTransSaveRoleDetail() : NFTransPlayerBase()
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFTransSaveRoleDetail::~NFTransSaveRoleDetail()
{

}

int NFTransSaveRoleDetail::CreateInit()
{
    SetState(TRANS_SAVE_ROLE_DETAIL_STATE_INIT);
    m_reason = TRANS_SAVE_ROLE_DETAIL_NORMAL;
    return 0;
}

int NFTransSaveRoleDetail::ResumeInit()
{
    return 0;
}

std::string NFTransSaveRoleDetail::DebugString() const
{
    return NF_FORMAT("reason:{} NFTransPlayerBase:{}", m_reason, NFTransPlayerBase::DebugString());
}

int NFTransSaveRoleDetail::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransSaveRoleDetail::SaveRoleDetail(TRANS_SAVE_ROLE_DETAIL_REASON iReason)
{
    int iRetCode = 0;
    CHECK_EXPR(GetState() == TRANS_SAVE_ROLE_DETAIL_STATE_INIT, -1, "{}", DebugString());

    auto pPlayer = GetPlayer();
    CHECK_EXPR(pPlayer, -1, "SaveRoleDetail Failed! Can't find role detail data, {}", DebugString());

    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_EXPR(pServerConfig, -1, "FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER) Failed");

    m_reason = iReason;
    pPlayer->SetLastSendRoleDetailSavedTime(NFTime::Now().UnixSec());

    proto_ff::RoleDBData xData;
    pPlayer->SaveDB(xData);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "Save Role Info To Mysql:{}", xData.DebugString());

    iRetCode = FindModule<NFIServerMessageModule>()->SendTransToStoreServer(NF_ST_LOGIC_SERVER, 0,
                                                                            proto_ff::NF_STORESVR_C2S_MODIFYOBJ, 0, pServerConfig->DefaultDBName,
                                                                            "RoleDBData", xData, GetGlobalId(), pPlayer->GetCurRoleDetailSeq(), m_roleId);

    SetState(TRANS_SAVE_ROLE_DETAIL_STATE_SAVING_ROLE);
    return iRetCode;
}

int NFTransSaveRoleDetail::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                  uint32_t seq,
                                  int32_t err_code)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    int iRetCode = 0;
    if (cmd == proto_ff::NF_STORESVR_S2C_MODIFYOBJ)
    {
        iRetCode = HandleSaveRoleDetailRes(err_code, seq);
    }
    else
    {
        iRetCode = -1;
        NFLogTrace(NF_LOG_SYSTEMLOG, 0,
                   "Save Role Detial InTo Failed, cmd:{} tableid:{} err_code:{}", cmd, table_id,
                   err_code);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return iRetCode;
}

int NFTransSaveRoleDetail::HandleSaveRoleDetailRes(uint32_t err_code, uint32_t seq)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    if (err_code != 0)
    {
        return proto_ff::ERR_CODE_SVR_SYSTEM_DATABASE_ERROR;
    }

    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    pPlayer->SetRoleDetailSavedSeq(seq);
    pPlayer->SetRoleDetailSavingDBTime(0);



    SetFinished(0);
    SetState(TRANS_SAVE_ROLE_DETAIL_FIN_OK);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransSaveRoleDetail::HandleTransFinished(int iRunLogicRetCode)
{
    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);
    pPlayer->SetRoleDetailSavingDBTime(0);

    NFTransPlayerBase::HandleTransFinished(iRunLogicRetCode);
    if (iRunLogicRetCode != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Save Role Detail To DB Failed!, iRunLogicRetCode:{} debug string:{}", iRunLogicRetCode, DebugString());
    }

    if (iRunLogicRetCode == 0)
    {
        if (m_reason == TRANS_SAVE_ROLE_DETAIL_LOGOUT && pPlayer->GetStatus() == PLAYER_STATUS_LOGOUT)
        {
            NFPlayerMgr::Instance(m_pObjPluginManager)->OnLogout(pPlayer);
        }
    }

    return 0;
}
