// -------------------------------------------------------------------------
//    @FileName         :    NFCenterServerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2023-10-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFCenterServerPlugin
//
// -------------------------------------------------------------------------

#include "NFCenterServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFCenterServerModule.h"


#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFCenterServerPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFCCenterServerModule)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFCenterServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFCenterServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFCenterServerPlugin);
}

void NFCenterServerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFICenterServerModule, NFCCenterServerModule);
}

void NFCenterServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFICenterServerModule, NFCCenterServerModule);
}

bool NFCenterServerPlugin::InitShmObjectRegister()
{
    return true;
}