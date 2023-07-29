// -------------------------------------------------------------------------
//    @FileName         :    NFCGamePlayerModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFCGamePlayerModule
//
// -------------------------------------------------------------------------

#include "NFCGamePlayerModule.h"
#include "Config/NFGameConfig.h"
#include "Room/NFGameRoomMgr.h"

#define GAME_SERVER_REGISTER_ROOM_INFO_TO_WORLD_SERVER "Game Server Register Room Info to World Server"

NFCGamePlayerModule::NFCGamePlayerModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFCGamePlayerModule::~NFCGamePlayerModule()
{

}

bool NFCGamePlayerModule::Awake()
{
    NFGameConfig::Instance(m_pObjPluginManager)->LoadConfig(m_luaModule);

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    NF_ASSERT(pConfig);

    /**
     * @brief 确保服务器没完全启动前也能处理房间注册信息
     */
    NFGlobalSystem::Instance()->RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_GTW_REGISTER_ROOM_INFO_REQ);
    NFGlobalSystem::Instance()->RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_WTG_REGISTER_ROOM_INFO_RSP);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_ff::NF_WTG_REGISTER_ROOM_INFO_RSP, this,
                                                       &NFCGamePlayerModule::OnHandleRoomRegisterRps);

    m_pObjPluginManager->RegisterAppTask(NF_ST_GAME_SERVER, APP_INIT_REGISTER_WORLD_SERVER,
                                         NF_FORMAT("{} {}", pConfig->ServerName, GAME_SERVER_REGISTER_ROOM_INFO_TO_WORLD_SERVER),
                                         APP_INIT_STATUS_SERVER_REGISTER);

    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_CONNECT_TASK_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);
    return true;
}

bool NFCGamePlayerModule::Execute()
{
    return NFIModule::Execute();
}

bool NFCGamePlayerModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFCGamePlayerModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleClientMessage(msgId, packet, param1, param2);
}

int NFCGamePlayerModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleServerMessage(msgId, packet, param1, param2);
}

int NFCGamePlayerModule::OnHandleRoomRegisterRps(uint64_t unLinkId, NFDataPackage &packet)
{
    proto_ff::Proto_WTG_RegisterRoomInfoRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    if (xMsg.result() == 0)
    {
        m_pObjPluginManager->FinishAppTask(NF_ST_GAME_SERVER, APP_INIT_REGISTER_WORLD_SERVER, APP_INIT_STATUS_SERVER_REGISTER);
        return 0;
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Register Room Info To World Server Failed, please check config");
    }

    return 0;
}

int
NFCGamePlayerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_CONNECT_TASK_FINISH)
        {
            NFGameRoomMgr::Instance(m_pObjPluginManager)->CreateAllRoom();
            NFGameRoomMgr::Instance(m_pObjPluginManager)->RegisterAllRoomToWorldServer();
        }
    }
    return 0;
}
