// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFWorldServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFWorldServerModule.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFWorldServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFWorldServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFWorldServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFWorldServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFWorldServerPlugin);
}

void NFWorldServerPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFIWorldServerModule, NFCWorldServerModule);
}

void NFWorldServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFIWorldServerModule, NFCWorldServerModule);
}

bool NFWorldServerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    NF_ASSERT(pConfig);

    //uint32_t maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;
	return true;
}
