// -------------------------------------------------------------------------
//    @FileName         :    NFProxyServerPlayerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyServerPlugin
//
// -------------------------------------------------------------------------

#include "NFProxyPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFProxyPlayerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFProxyPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFProxyPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFProxyPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFProxyPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFProxyPlayerPlugin);
}

void NFProxyPlayerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFIProxyPlayerModule, NFCProxyPlayerModule);
}

void NFProxyPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFIProxyPlayerModule, NFCProxyPlayerModule);
}
