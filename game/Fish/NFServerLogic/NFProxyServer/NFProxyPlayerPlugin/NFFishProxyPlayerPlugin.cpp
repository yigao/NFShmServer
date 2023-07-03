// -------------------------------------------------------------------------
//    @FileName         :    NFProxyServerPlayerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyServerPlugin
//
// -------------------------------------------------------------------------

#include "NFFishProxyPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFProxyPlayerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFFishProxyPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFFishProxyPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFFishProxyPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFFishProxyPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFFishProxyPlayerPlugin);
}

void NFFishProxyPlayerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFIProxyPlayerModule, NFCProxyPlayerModule);
}

void NFFishProxyPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFIProxyPlayerModule, NFCProxyPlayerModule);
}
