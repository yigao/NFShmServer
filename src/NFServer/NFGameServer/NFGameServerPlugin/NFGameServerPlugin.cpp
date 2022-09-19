// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFGameServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFGameServerModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFGameServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFGameServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFGameServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFGameServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFGameServerPlugin);
}

void NFGameServerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFIGameServerModule, NFCGameServerModule);
}

void NFGameServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFIGameServerModule, NFCGameServerModule);
}

bool NFGameServerPlugin::InitShmObjectRegister()
{
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
	NF_ASSERT(pConfig);

	return true;
}
