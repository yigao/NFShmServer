// -------------------------------------------------------------------------
//    @FileName         :    NFProxyServerPlayerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyServerPlugin
//
// -------------------------------------------------------------------------

#include "NFMMOProxyPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFProxyPlayerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMMOProxyPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFMMOProxyPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMMOProxyPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFMMOProxyPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFMMOProxyPlayerPlugin);
}

void NFMMOProxyPlayerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFCProxyPlayerModule, NFCProxyPlayerModule);
}

void NFMMOProxyPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFCProxyPlayerModule, NFCProxyPlayerModule);
}
