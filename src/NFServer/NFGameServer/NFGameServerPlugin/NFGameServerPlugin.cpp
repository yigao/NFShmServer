// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFGameServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFGameServerModule.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"

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
	REGISTER_MODULE(m_pPluginManager, NFIGameServerModule, NFCGameServerModule);
}

void NFGameServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFIGameServerModule, NFCGameServerModule);
}

bool NFGameServerPlugin::InitShmObjectRegister()
{
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_GAME_SERVER);
	NF_ASSERT(pConfig);

	//uint32_t maxRoomNum = pConfig->GetMaxRoomNum();
	//uint32_t maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;
	//uint32_t maxDeskCount = pConfig->GetMaxDeskNum();
	return true;
}
