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

NFCGamePlayerModule::NFCGamePlayerModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFCGamePlayerModule::~NFCGamePlayerModule()
{

}

bool NFCGamePlayerModule::Awake()
{
    NFGameConfig::Instance(m_pObjPluginManager)->LoadConfig(m_luaModule);

    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);
    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);
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

int NFCGamePlayerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE)
        {
            NFGameRoomMgr::Instance(m_pObjPluginManager)->CreateAllRoom();
            NFGameRoomMgr::Instance(m_pObjPluginManager)->RegisterAllRoomToWorldServer();
        }
    }
    return 0;
}
