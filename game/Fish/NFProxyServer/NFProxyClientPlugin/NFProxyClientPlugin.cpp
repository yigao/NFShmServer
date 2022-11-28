// -------------------------------------------------------------------------
//    @FileName         :    NFProxyServerPlayerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFProxyServerPlugin
//
// -------------------------------------------------------------------------

#include "NFProxyClientPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFProxyClientModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFProxyClientPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFProxyClientPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFProxyClientPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFProxyClientPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFProxyClientPlugin);
}

void NFProxyClientPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFIProxyClientModule, NFCProxyClientModule);
}

void NFProxyClientPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFIProxyClientModule, NFCProxyClientModule);
}
