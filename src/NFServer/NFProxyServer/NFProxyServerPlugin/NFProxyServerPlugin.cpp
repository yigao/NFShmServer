// -------------------------------------------------------------------------
//    @FileName         :    NFProxyServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFProxyServerPlugin
//
// -------------------------------------------------------------------------

#include "NFProxyServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFProxyServerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFProxyServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFProxyServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFProxyServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFProxyServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFProxyServerPlugin);
}

void NFProxyServerPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFIProxyServerModule, NFCProxyServerModule);
}

void NFProxyServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFIProxyServerModule, NFCProxyServerModule);
}
