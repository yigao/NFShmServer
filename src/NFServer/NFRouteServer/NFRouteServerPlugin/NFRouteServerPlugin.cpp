// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFRouteServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFCRouteServerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFRouteServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFRouteServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFRouteServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFRouteServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFRouteServerPlugin);
}

void NFRouteServerPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFIRouteServerModule, NFCRouteServerModule);
}

void NFRouteServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFIRouteServerModule, NFCRouteServerModule);
}
