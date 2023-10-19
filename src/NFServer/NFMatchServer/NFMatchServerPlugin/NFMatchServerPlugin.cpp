// -------------------------------------------------------------------------
//    @FileName         :    NFMatchServerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2023-10-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFMatchServerPlugin
//
// -------------------------------------------------------------------------

#include "NFMatchServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFMatchServerModule.h"


#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMatchServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFMatchServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMatchServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFMatchServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFMatchServerPlugin);
}

void NFMatchServerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFIMatchServerModule, NFCMatchServerModule);
}

void NFMatchServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFIMatchServerModule, NFCMatchServerModule);
}

bool NFMatchServerPlugin::InitShmObjectRegister()
{
    return true;
}