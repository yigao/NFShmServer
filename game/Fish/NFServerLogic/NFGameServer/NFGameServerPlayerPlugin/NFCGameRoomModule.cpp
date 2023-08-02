// -------------------------------------------------------------------------
//    @FileName         :    NFCGameRoomModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFCGameRoomModule
//
// -------------------------------------------------------------------------

#include "NFCGameRoomModule.h"


NFCGameRoomModule::NFCGameRoomModule(NFIPluginManager* p): NFFishDynamicModule(p)
{

}

NFCGameRoomModule::~NFCGameRoomModule()
{
}

bool NFCGameRoomModule::Awake()
{
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_CS_MSG_DeskListReq>(NF_ST_GAME_SERVER, this, &NFCGameRoomModule::OnHandleDeskListReq);
    return true;
}

bool NFCGameRoomModule::Execute()
{
    return NFIModule::Execute();
}

bool NFCGameRoomModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFCGameRoomModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleClientMessage(msgId, packet, param1, param2);
}

int NFCGameRoomModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleServerMessage(msgId, packet, param1, param2);
}

int NFCGameRoomModule::OnHandleDeskListReq(proto_ff::DeskListReq &request, proto_ff::DeskListRsp &respone, uint64_t param1, uint64_t param2)
{
    return 0;
}



