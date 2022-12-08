// -------------------------------------------------------------------------
//    @FileName         :    NFTransCreateRole.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-29
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransCreateRole
//
// -------------------------------------------------------------------------

#include "NFTransCreateRole.h"

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
#include "NFTransGetRole.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransCreateRole, EOT_TRANS_LOGIC_CREATE_ROLE, NFTransBase)

NFTransCreateRole::NFTransCreateRole():NFTransPlayerBase()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFTransCreateRole::~NFTransCreateRole()
{
}

int NFTransCreateRole::CreateInit()
{
    return 0;
}

int NFTransCreateRole::ResumeInit()
{
    return 0;
}

int NFTransCreateRole::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{
    const proto_ff::WorldToLogicCreateRoleReq* pCreateRole = dynamic_cast<const proto_ff::WorldToLogicCreateRoleReq*>(pCSMsgReq);
    CHECK_EXPR(pCreateRole, -1, "dynamic_cast<proto_ff::WorldToLogicCreateRoleReq*>(pCSMsgReq) Failed");

    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_EXPR(pServerConfig, -1, "FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER) Failed");

    NFPlayer *pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(m_roleId);
    if (pPlayer)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Create Role But Find The Role Player Data Exist, roleId:{} uid:{}", m_roleId, m_uid);
        return -1;
    }

    proto_ff::RoleDBData xData;
    xData.set_cid(m_roleId);
    xData.set_uid(m_uid);
    xData.set_zid(pCreateRole->zid());
    
    auto protobase = xData.mutable_base();
    protobase->set_level(pCreateRole->level());
    protobase->set_prof(pCreateRole->prof()) ;
    protobase->set_createtime(NFTime::Now().UnixSec());
    protobase->set_name(pCreateRole->name());
    protobase->set_exp(0);
    protobase->set_hp(0);
    protobase->set_fight(0);
    protobase->set_vip_level(0);
    protobase->set_logintime(NFTime::Now().UnixSec());
    protobase->set_logouttime(0);
    protobase->mutable_facade()->set_color(pCreateRole->color());

    protobase->set_enter_scene_id(pCreateRole->enter_scene_id());
    protobase->set_enter_map_id(pCreateRole->enter_map_id());
    protobase->set_enterposx(pCreateRole->enterposx());
    protobase->set_enterposy(pCreateRole->enterposy());
    protobase->set_enterposz(pCreateRole->enterposz());

    protobase->set_lastsceneid(pCreateRole->lastsceneid());
    protobase->set_lastmapid(pCreateRole->lastmapid());
    protobase->set_lastposx(pCreateRole->lastposx());
    protobase->set_lastposy(pCreateRole->lastposy());
    protobase->set_lastposz(pCreateRole->lastposz());
    

    FindModule<NFIServerMessageModule>()->SendTransToStoreServer(NF_ST_LOGIC_SERVER, 0,
                                                                 proto_ff::E_STORESVR_C2S_INSERT, 0, pServerConfig->DefaultDBName,
                                                                 "RoleDBData", xData,GetGlobalID(), 0, m_roleId);
    return 0;
}

int NFTransCreateRole::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                       uint32_t seq, uint32_t err_code)
{
    if (cmd == proto_ff::E_STORESVR_S2C_INSERT)
    {
        const storesvr_sqldata::storesvr_ins_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_ins_res *>(pSSMsgRes);
        CHECK_EXPR(pRes, -1, "pRes == NULL");

        if (err_code != 0)
        {
            return err_code;
        }

        NFPlayer *pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(m_roleId);
        if (pPlayer)
        {
            return -1;
        }

        NFTransGetRole* pTrans = dynamic_cast<NFTransGetRole *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_TRANS_LOGIC_GET_ROLE));
        CHECK_EXPR(pTrans, -1, "CreateTrans NFTransCreateRole failed!");

        pTrans->Init( m_roleId, m_uid, m_cmd, 0);

        SetFinished(0);
    }

    return 0;
}

int NFTransCreateRole::HandleTransFinished(int iRunLogicRetCode)
{
    if (iRunLogicRetCode != 0)
    {
        proto_ff::LogicToWorldCreateRoleRsp xData;
        xData.set_ret_code(proto_ff::RET_LOGIN_CHARACTER_CREATE_FAILED);
        xData.set_uid(m_uid);
        xData.set_cid(m_roleId);
        FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, proto_ff::LOGIC_TO_WORLD_CREATE_ROLE_INFO_RSP, xData, m_uid);
    }
    return 0;
}