// -------------------------------------------------------------------------
//    @FileName         :    NFGlobalServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGlobalServerPlugin
//
// -------------------------------------------------------------------------

#include "NFGlobalServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

#include "NFGlobalServerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFGlobalServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFGlobalServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFGlobalServerPlugin::GetPluginVersion()
{
    return 0;
}

std::string NFGlobalServerPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFGlobalServerPlugin);
}

void NFGlobalServerPlugin::Install()
{
    REGISTER_MODULE(m_pPluginManager, NFGlobalServerModule, NFGlobalServerModule)
}

void NFGlobalServerPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pPluginManager, NFGlobalServerModule, NFGlobalServerModule)
}
