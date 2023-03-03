// -------------------------------------------------------------------------
//    @FileName         :    NFLoginModule.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoginModule
//
// -------------------------------------------------------------------------

#include <NFComm/NFPluginModule/NFIMessageModule.h>
#include <NFComm/NFShmCore/NFISharedMemModule.h>
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include <ClientServerCmd.pb.h>
#include <ClientServer.pb.h>
#include <NFLogicCommon/NFServerFrameTypeDefines.h>
#include <NFComm/NFPluginModule/NFCheck.h>
#include <ServerInternalCmd.pb.h>
#include <ServerInternalCmd2.pb.h>
#include <Scene.pb.h>
#include <Move.pb.h>
#include "NFLoginModule.h"

#include "Trans/NFTransGetRoleList.h"
#include "ServerInternal2.pb.h"
#include "Trans/NFTransCreateRole.h"
#include "Trans/NFTransGetRole.h"
#include "Player/NFPlayerMgr.h"
#include "Player/NFPlayer.h"
#include "Trans/NFTransEnterScene.h"
#include "NFLogicCommon/NFSceneDefine.h"


NFLoginModule::NFLoginModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFLoginModule::~NFLoginModule()
{

}

bool NFLoginModule::Awake()
{
    RegisterServerMessage(NF_ST_LOGIC_SERVER, proto_ff::WORLD_TO_LOGIC_GET_ROLE_LIST_REQ);
    RegisterServerMessage(NF_ST_LOGIC_SERVER, proto_ff::WORLD_TO_LOGIC_CREATE_ROLE_INFO_REQ);
    RegisterServerMessage(NF_ST_LOGIC_SERVER, proto_ff::WORLD_TO_LOGIC_LOGIN_REQ);
    RegisterServerMessage(NF_ST_LOGIC_SERVER, proto_ff::WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT);
    RegisterServerMessage(NF_ST_LOGIC_SERVER, proto_ff::WORLD_TO_LOGIC_LOGIN_FINISH_NOTIFY);

    /**
     * @brief 一帧处理200个玩家的tick
     */
    NFPlayerMgr::Instance(m_pObjPluginManager)->Init(1, 200);
    return true;
}

bool NFLoginModule::Execute()
{
    NFPlayerMgr::Instance(m_pObjPluginManager)->Execute();
    return true;
}

bool NFLoginModule::OnDynamicPlugin()
{
    return true;
}

int NFLoginModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (msgId)
    {
        default:
        {
            break;
        }
    }

    return true;
}

int NFLoginModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch(msgId)
    {
        case proto_ff::WORLD_TO_LOGIC_GET_ROLE_LIST_REQ:
        {
            OnHandleGetRoleList(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::WORLD_TO_LOGIC_CREATE_ROLE_INFO_REQ:
        {
            OnHandleCreateRole(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::WORLD_TO_LOGIC_LOGIN_REQ:
        {
            OnHandleLoginRole(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT:
        {
            OnHandlePlayerDisconnect(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::WORLD_TO_LOGIC_LOGIN_FINISH_NOTIFY:
        {
            OnHandleLoginFinishNotify(msgId, packet, param1, param2);
            break;
        }
        default:
        {
            break;
        }
    }

    return 0;
}


int NFLoginModule::OnHandleGetRoleList(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToLogicGetRoleList clogin;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, clogin);

    NFTransGetRoleList* pTrans = dynamic_cast<NFTransGetRoleList *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_TRANS_LOGIC_GET_ROLE_LIST));
    CHECK_EXPR(pTrans, -1, "CreateTrans NFTransGetRoleList failed!");
    pTrans->Init(0, clogin.uid(), packet.nMsgId, 0, param1);
    int iRetCode = pTrans->HandleCSMsgReq(&clogin);
    CHECK_ERR_AND_FIN_TRANS(iRetCode, pTrans, "pTrans->HandleCSMsgReq(&clogin) failed");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFLoginModule::OnHandleCreateRole(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToLogicCreateRoleReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFTransCreateRole* pTrans = dynamic_cast<NFTransCreateRole *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_TRANS_LOGIC_CREATE_ROLE));
    CHECK_EXPR(pTrans, -1, "CreateTrans NFTransCreateRole failed!");
    pTrans->Init(xMsg.cid(), xMsg.uid(), packet.nMsgId);
    int iRetCode = pTrans->HandleCSMsgReq(&xMsg);
    CHECK_ERR_AND_FIN_TRANS(iRetCode, pTrans, "pTrans->HandleCSMsgReq(&clogin) failed");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFLoginModule::OnHandleLoginRole(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToLogicLoginReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFPlayer *pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(xMsg.cid());
    if (pPlayer)
    {
        pPlayer->SetProxyId(xMsg.proxy_id());
        pPlayer->OnLogin(false);
    }
    else {
        NFTransGetRole* pTrans = dynamic_cast<NFTransGetRole *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_TRANS_LOGIC_GET_ROLE));
        CHECK_EXPR(pTrans, -1, "CreateTrans NFTransCreateRole failed!");
        pTrans->Init(xMsg.cid(), xMsg.uid(), packet.nMsgId);
        int iRetCode = pTrans->HandleCSMsgReq(&xMsg);
        CHECK_ERR_AND_FIN_TRANS(iRetCode, pTrans, "pTrans->HandleCSMsgReq(&clogin) failed");
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFLoginModule::OnHandlePlayerDisconnect(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToOtherServerDisconnectNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFPlayer *pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(xMsg.roleid());
    if (pPlayer)
    {
        pPlayer->OnDisconnect(xMsg.reason());
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFLoginModule::OnHandleLoginFinishNotify(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToLogicLoginFinishNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    CharLoginInfo loginInfo;
    loginInfo.sceneid = xMsg.scene_id();
    loginInfo.mapid = xMsg.map_id();
    loginInfo.pos.x = xMsg.pos().x();
    loginInfo.pos.y = xMsg.pos().y();
    loginInfo.pos.z = xMsg.pos().z();
    //
    loginInfo.uid = xMsg.uid();
    loginInfo.gateId = xMsg.proxy_id();
    //
    loginInfo.transParam.transType = ETransType_Born;
    loginInfo.transParam.srcMapId = loginInfo.lastMapId;

    NFPlayerMgr::Instance(m_pObjPluginManager)->EnterGame(xMsg.cid(), loginInfo);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}
