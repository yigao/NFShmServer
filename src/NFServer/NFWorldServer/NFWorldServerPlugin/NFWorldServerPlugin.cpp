// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WORLD_SERVER);
    NF_ASSERT(pConfig);

    //uint32_t maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;
	return true;
}
