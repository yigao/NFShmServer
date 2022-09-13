// -------------------------------------------------------------------------
//    @FileName         :    NFMonitorServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMonitorServerPlugin.cpp
//
// -------------------------------------------------------------------------


#include "NFMonitorServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFMonitorServerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMonitorServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFMonitorServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMonitorServerPlugin::GetPluginVersion()
{
    return 0;
}

std::string NFMonitorServerPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFMonitorServerPlugin);
}

void NFMonitorServerPlugin::Install()
{
    REGISTER_MODULE(m_pPluginManager, NFCMonitorServerModule, NFCMonitorServerModule);
}

void NFMonitorServerPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pPluginManager, NFCMonitorServerModule, NFCMonitorServerModule);
}

