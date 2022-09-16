//------------------------------------------------------------------------ -
//    @FileName         :    NFNetPlugin.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFNetPlugin
//
// -------------------------------------------------------------------------

#include "NFNetPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFCNetMessageDriverModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
	CREATE_PLUGIN(pm, NFNetPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
	DESTROY_PLUGIN(pm, NFNetPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

int NFNetPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFNetPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFNetPlugin);
}

bool NFNetPlugin::IsDynamicLoad()
{
	return false;
}

void NFNetPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFIMessageDriver, NFCNetMessageDriverModule);
}

void NFNetPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFIMessageDriver, NFCNetMessageDriverModule);
}
