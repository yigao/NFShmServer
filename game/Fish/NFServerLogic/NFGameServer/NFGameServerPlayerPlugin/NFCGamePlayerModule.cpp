// -------------------------------------------------------------------------
//    @FileName         :    NFCGamePlayerModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFCGamePlayerModule
//
// -------------------------------------------------------------------------

#include "NFCGamePlayerModule.h"

NFCGamePlayerModule::NFCGamePlayerModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFCGamePlayerModule::~NFCGamePlayerModule()
{

}

bool NFCGamePlayerModule::Awake()
{
    return NFIModule::Awake();
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
