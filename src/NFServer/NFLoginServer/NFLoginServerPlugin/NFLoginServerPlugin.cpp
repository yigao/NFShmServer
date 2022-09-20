// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFLoginServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFLoginServerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFLoginServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFLoginServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFLoginServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFLoginServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFLoginServerPlugin);
}

void NFLoginServerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFILoginServerModule, NFCLoginServerModule);
}

void NFLoginServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFILoginServerModule, NFCLoginServerModule);
}

bool NFLoginServerPlugin::InitShmObjectRegister()
{
	return true;
}