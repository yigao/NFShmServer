// -------------------------------------------------------------------------
//    @FileName         :    NFLogicServerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicServerPlugin
//
// -------------------------------------------------------------------------

#include "NFLogicServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFLogicServerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFLogicServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFLogicServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFLogicServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFLogicServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFLogicServerPlugin);
}

void NFLogicServerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFILogicServerModule, NFCLogicServerModule);
}

void NFLogicServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFILogicServerModule, NFCLogicServerModule);
}

bool NFLogicServerPlugin::InitShmObjectRegister()
{
	return true;
}