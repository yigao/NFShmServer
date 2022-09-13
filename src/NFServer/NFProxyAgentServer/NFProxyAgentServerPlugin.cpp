// -------------------------------------------------------------------------
//    @FileName         :    NFProxyAgentServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFProxyAgentServerPlugin
//
// -------------------------------------------------------------------------

#include "NFProxyAgentServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFProxyAgentServerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFProxyAgentServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFProxyAgentServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFProxyAgentServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFProxyAgentServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFProxyAgentServerPlugin);
}

void NFProxyAgentServerPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFCProxyAgentServerModule, NFCProxyAgentServerModule);
}

void NFProxyAgentServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFCProxyAgentServerModule, NFCProxyAgentServerModule);
}
