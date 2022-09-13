// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFLoginServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFLoginServerModule.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"

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
	REGISTER_MODULE(m_pPluginManager, NFILoginServerModule, NFCLoginServerModule);
}

void NFLoginServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFILoginServerModule, NFCLoginServerModule);
}

bool NFLoginServerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_LOGIN_SERVER);
    NF_ASSERT(pConfig);

    //uint32_t maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;
	return true;
}