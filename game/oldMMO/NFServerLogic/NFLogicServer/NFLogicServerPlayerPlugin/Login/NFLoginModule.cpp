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
#include "NFLoginModule.h"

#include "Trans/NFTransGetRoleList.h"


NFLoginModule::NFLoginModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFLoginModule::~NFLoginModule()
{

}

bool NFLoginModule::Awake()
{
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, NF_MODULE_NONE, proto_ff::WORLD_TO_LOGIC_GET_ROLE_LIST_REQ, this,
                                                       &NFLoginModule::OnHandleGetRoleList);
    return true;
}

bool NFLoginModule::Execute()
{
    return true;
}

bool NFLoginModule::OnDynamicPlugin()
{
    return true;
}

int NFLoginModule::OnHandleGetRoleList(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToLogicGetRoleList clogin;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, clogin);

    NFTransGetRoleList* pTrans = dynamic_cast<NFTransGetRoleList *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_TRANS_LOGIC_GET_ROLE_LIST));
    CHECK_EXPR(pTrans, -1, "CreateTrans NFTransGetRoleList failed!");
    pTrans->Init(clogin.player_id(), 0, packet.nMsgId);
    int iRetCode = pTrans->HandleCSMsgReq(&clogin);
    CHECK_ERR_AND_FIN_TRANS(iRetCode, pTrans, "pTrans->HandleCSMsgReq(&clogin) failed");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}
