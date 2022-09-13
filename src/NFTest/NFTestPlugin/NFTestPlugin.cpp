// -------------------------------------------------------------------------
//    @FileName         :    NFTestPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTestPlugin
//
// -------------------------------------------------------------------------

#include "NFTestPlugin.h"
#include "NFCTestModule.h"
//
//
#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
	CREATE_PLUGIN(pm, NFTestPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
	DESTROY_PLUGIN(pm, NFTestPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

int NFTestPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFTestPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFTestPlugin);
}

void NFTestPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFCTestModule, NFCTestModule);
}

void NFTestPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFCTestModule, NFCTestModule);
}