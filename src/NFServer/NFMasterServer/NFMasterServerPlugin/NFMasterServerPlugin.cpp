// -------------------------------------------------------------------------
//    @FileName         :    NFMasterServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMasterServerPlugin
//
// -------------------------------------------------------------------------

#include "NFMasterServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFMasterServerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMasterServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFMasterServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMasterServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFMasterServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFMasterServerPlugin);
}

void NFMasterServerPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFIMasterServerModule, NFCMasterServerModule)
}

void NFMasterServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFIMasterServerModule, NFCMasterServerModule)
}
